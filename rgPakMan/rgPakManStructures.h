/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* rgPakManStructures.h
* Hier werden saemtliche Strukturen fuer das Spiel PakMan definiert
*/


#ifndef _RGPAKMANSTRUCTURES_
#define _RGPAKMANSTRUCTURES_

#include "rgBase/structures/rgStructures.h"


/**
* Struktur fuer den allgemeinen Spielablauf
*/
struct pmPakMan
{
	unsigned int lives;
	unsigned int points;
	unsigned int pointGhostMultiplicator;
	unsigned int eatenDrops;
	unsigned int megaPillCountDownTimerHandle;
	unsigned int megaPillActiveCounter;
	unsigned int megaPillBlinkTimerHandle;

	unsigned int waitTimerHandle;
	unsigned int waitTime;

	bool megaPillBlinkingState;
	int gameMode;

	unsigned int pakmanGamexMin, pakmanGamexMax, pakmanGameyMin, pakmanGameyMax;
	unsigned int ghostHeadquarterx, ghostHeadquartery;


	// Alle Audiobuffer
	int musicBuffer;

	int soundBufferEatDrop;
	int soundBufferIntro;
	int soundBufferLost;
	int soundBufferGameOver;
	int soundBufferGhostEaten;
};

/**
* Struktur fuer ein Wandstueck 
*/
struct rgWall
{
	rgPosition pos;
	char symbol;
};

/**
* Struktur fuer ein Drop 
*/
struct rgDrop
{
	rgPosition pos;
	char symbol;
	bool eaten;
	bool isMegaPill;
};

/**
* Struktur fuer die Spielfigur PakPak
*/
struct rgPakPak
{
	rgPosition pos;
	char symbol;
	unsigned int desiredDirection;
	unsigned int direction;
	double speed;

	unsigned int currentSymbol;
	char eatSymbols[8];

	unsigned int walkSpeedTimerHandle;
	unsigned int walkAnimationTimerHandle;
};

/**
* Struktur fuer die Spielfigur Geist
*/
struct rgGhost
{
	rgPosition pos;
	char defaultSymbol;
	char eatemSymbol;
	unsigned int direction;
	unsigned int desiredDirection;
	unsigned int defaultColor;
	unsigned int afraidColor;
	unsigned int eatenColor;
	double currentSpeed; // Felder pro Sekunde
	double defaultSpeed; // Felder pro Sekunde
	double afraidSpeed; // Felder pro Sekunde
	double eatenSpeed; // Felder pro Sekunde
	int mode;

	unsigned int walkSpeedTimerHandle;
	unsigned int directionChangeTimerHandle;
};

#endif