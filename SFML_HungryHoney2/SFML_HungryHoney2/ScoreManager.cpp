#include "stdafx.h"
#include "ScoreManager.h"

void ScoreManager::WriteScore(int score)
{
	wstring value = to_wstring(score);
	HKEY hKey;
	DWORD dwDisposition;
	LONG status = RegCreateKeyEx(HKEY_CURRENT_USER, TEXT("Software\\GeertCocu\\HungryHoney\\HighScore"), 0, NULL, 0, KEY_WRITE, NULL, &hKey, &dwDisposition);
	if(status == ERROR_SUCCESS){
		RegSetValueExW(hKey, TEXT("HighScore"), 0, REG_SZ, (const BYTE*)value.c_str(), sizeof(value));
		RegCloseKey(hKey);
	}
}

int ScoreManager::ReadScore()
{
	int result = 0;
	wstring value;
	WCHAR szBuffer[512];
	DWORD dwBuffer = sizeof(szBuffer);
	ULONG nError;
	HKEY hKey;
	LONG status = RegOpenKeyEx(HKEY_CURRENT_USER, TEXT("Software\\GeertCocu\\HungryHoney\\HighScore"), 0, KEY_ALL_ACCESS, &hKey);
	if (status == ERROR_SUCCESS) {
		nError = RegQueryValueExW(hKey, TEXT("HighScore"), 0, NULL, (LPBYTE)szBuffer, &dwBuffer);
		if (nError == ERROR_SUCCESS) {
			value = szBuffer;
			result = stoi(value);
		}
	}
	return result;
}
