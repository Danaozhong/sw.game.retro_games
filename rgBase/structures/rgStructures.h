/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* rgStructures.h 
* Hier werden die Datentypen definiert.
*/
#ifndef _RGSTRUCTURES_
#define _RGSTRUCTURES_

#include <string>

using namespace std;

/**
* Datenelement fuer eine Position
*/
struct rgPosition
{
	unsigned int x,y;	
};

/**
* Datenelement fuer ein Spielfeld
*/
struct rgGameField
{
	int flag01;
	int flag02;
};

struct rgKeyboard
{
	bool keyLeft;
	bool keyUp;
	bool keyRight;
	bool keyDown;
	bool keyEscape;
	bool keyBackspace;
	bool keySpace;
	bool keyReturn;
	bool keyA;
	bool keyB;
	bool keyC;
	bool keyD;
	bool keyE;
	bool keyF;
	bool keyG;
	bool keyH;
	bool keyI;
	bool keyJ;
	bool keyK;
	bool keyL;
	bool keyM;
	bool keyN;
	bool keyO;
	bool keyP;
	bool keyQ;
	bool keyR;
	bool keyS;
	bool keyT;
	bool keyU;
	bool keyV;
	bool keyW;
	bool keyX;
	bool keyY;
	bool keyZ;
};


struct rgConfig
{
	bool musicEnabled;
	bool soundEnabled;
	int musicVolume; 
	int soundVolume;
	bool joystickEnabled;
	bool keyboardEnabled;
	bool mouseEnabled;
};

struct rgHighScore
{
	string player;
	string date;
	unsigned int points;
};

#endif