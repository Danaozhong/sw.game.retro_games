/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* Definition zu rgCast.h
*/

#include <string>
#include <sstream>
#include "rgBase/cast/rgCast.h"

using namespace std;

int stringToInt(string value)
{
	stringstream output(value);
	int result = 0;
	output >> result;
	return result;
}

string boolToStr(bool value)
{
	if (true == value)
	{
		return "TRUE";
	}
	else
	{
		return "FALSE";
	}
}

bool stringToBool(string value)
{
	if ("TRUE" == value)
	{
		return true;
	}
	else
	{
		return false;
	}
}