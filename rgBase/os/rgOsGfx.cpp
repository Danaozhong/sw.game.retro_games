/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* Definition zu rgOsGfx.h
*/

#include <windows.h>
#include <string>
#include "rgBase/os/rgOsGfx.h"
#include "rgCommon/rgGlobals.h"
using namespace std;


void osDrawCharPosition(const int x, const int y, const char letter, const int color)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = {x, y};

	SetConsoleCursorPosition(hStdOut, coord);
	
	WORD colorAttributes;

	if (color == rgWhite)
	{
		colorAttributes = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY;
	}
	else if (color == rgLightGrey)
	{
		colorAttributes = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED;
	}
	else if (color == rgGrey)
	{
		colorAttributes = FOREGROUND_INTENSITY;
	}
	else if (color == rgRed)
	{
		colorAttributes = FOREGROUND_RED | FOREGROUND_INTENSITY;
	}
	else if (color == rgDarkRed)
	{
		colorAttributes = FOREGROUND_RED;
	}
	else if (color == rgBlue)
	{
		colorAttributes = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
	}
	else if (color == rgDarkBlue)
	{
		colorAttributes = FOREGROUND_BLUE;
	}
	else if (color == rgGreen)
	{
		colorAttributes = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
	}
	else if (color == rgDarkGreen)
	{
		colorAttributes = FOREGROUND_GREEN;
	}
	else if (color == rgPink)
	{
		colorAttributes = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY;
	}
	else if (color == rgPurple)
	{
		colorAttributes = FOREGROUND_BLUE | FOREGROUND_RED;
	}
	else if (color == rgYellow)
	{
		colorAttributes = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
	}
	else if (color == rgCyan)
	{
		colorAttributes = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
	}
	else
	{
		colorAttributes = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY;
	}

	SetConsoleTextAttribute(hStdOut, colorAttributes);

	WriteFile(hStdOut, &letter, 1, 0, 0);
}

long osGetTickCount()
{
	return GetTickCount();
}