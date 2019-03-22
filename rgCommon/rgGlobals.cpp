/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* Definition zu rgGlobals.h
*/

#include "rgCommon/rgGlobals.h"

int programMode;
int gameMode;
rgConfig config;

unsigned int gameMaxFPS;
double currentFPS;
int currentSleepTime;

rgGameField gameField[rgGameFieldxMax + 1][rgGameFieldyMax + 1];

unsigned int timerIncrement;

rgKeyboard keys;

int mnCurrentDisplayedMenu;

rgHighScore highScorePakMan[10];
rgHighScore highScoreSnake[10];
unsigned int highScorePoints; 
int highScoreGame;

