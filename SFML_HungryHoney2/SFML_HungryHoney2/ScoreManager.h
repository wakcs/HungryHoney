#pragma once
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

class ScoreManager
{
public:
	static void WriteScore(int score);
	static int ReadScore();

private:
};

