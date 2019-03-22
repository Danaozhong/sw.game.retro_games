/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* Definition zu rgMisc.h
*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "rgBase/cast/rgCast.h"

using namespace std;

unsigned int getRandomValue(unsigned int min, unsigned int max)
{
	unsigned int value = rand() % (max - min + 1);
	return value + min;
}

std::string getDateAsString()
{
	string result;
	struct tm *localTime;
	time_t globalTime;
	time(&globalTime);
	localTime = localtime(&globalTime);

	return (ToString(localTime->tm_mday) + "."
			+ ToString(localTime->tm_mon + 1) + "."
			+ ToString(localTime->tm_year + 1900));
}