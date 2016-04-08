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
	HKEY hKey;
	wstring result[50];
	DWORD dwBuffer = 8192, dwType, dwSize;
	LONG status = RegOpenKeyEx(HKEY_CURRENT_USER, TEXT("Software\\GeertCocu\\HungryHoney\\HighScore"), 0, KEY_ALL_ACCESS, &hKey);
	if (status == ERROR_SUCCESS) {
		RegQueryValueExW(hKey, TEXT("HighScore"), NULL, &dwType, (BYTE*)&result, &dwSize);
	}
	return 0;
}
