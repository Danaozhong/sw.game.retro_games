/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* rgKeyboardInput.cpp 
* Definition zu rgKeyboardInput.h
*/

#include "rgBase/input/rgKeyboardInput.h"
#include "rgCommon/rgGlobals.h"
#include "rgBase/os/rgOsInput.h"

/**
* Initialisierung eines Tastenpuffers
*/
const unsigned int flagsize = 40;
namespace
{
	short flags[flagsize];
	short previousFlag[flagsize];
}

// Initialisierung aller benoetigen Tasten
void initKeyBoard()
{
	for (int i = 0; i < flagsize; ++i)
	{
		previousFlag[i] = 0;
		flags[i] = 0;
	}
}

// Ueberpruefung der Tastenabfrage
void getKeyBoardInput()
{

	int i;

	// Pruefe alle Tasten durch
	for (i = 0; i < 40; ++i)
	{					
		// "Steigende Flanke" soll hier detektiert werden.
		if (previousFlag[i] == 0 && flags[i] != 0)
		{

			switch(i)
			{
			case 0:
				keys.keyLeft = true;
				break;
			case 1:
				keys.keyUp = true;
				break;
			case 2:
				keys.keyRight = true;
				break;
			case 3:
				keys.keyDown = true;
				break;
			case 4:
				keys.keyEscape = true;
				break;
			case 5:
				keys.keySpace = true;
				break;
			case 6:
				keys.keyBackspace = true;
				break;
			case 7:
				keys.keyReturn = true;
				break;
			case 8:
				keys.keyA = true;
				break;
			case 9:
				keys.keyB = true;
				break;
			case 10:
				keys.keyC = true;
				break;
			case 11:
				keys.keyD = true;
				break;
			case 12:
				keys.keyE = true;
				break;
			case 13:
				keys.keyF = true;
				break;
			case 14:
				keys.keyG = true;
				break;
			case 15:
				keys.keyH = true;
				break;
			case 16:
				keys.keyI = true;
				break;
			case 17:
				keys.keyJ = true;
				break;
			case 18:
				keys.keyK = true;
				break;
			case 19:
				keys.keyL = true;
				break;
			case 20:
				keys.keyM = true;
				break;
			case 21:
				keys.keyN = true;
				break;
			case 22:
				keys.keyO = true;
				break;
			case 23:
				keys.keyP = true;
				break;
			case 24:
				keys.keyQ = true;
				break;
			case 25:
				keys.keyR = true;
				break;
			case 26:
				keys.keyS = true;
				break;
			case 27:
				keys.keyT = true;
				break;
			case 28:
				keys.keyU = true;
				break;
			case 29:
				keys.keyV = true;
				break;
			case 30:
				keys.keyW = true;
				break;
			case 31:
				keys.keyX = true;
				break;
			case 32:
				keys.keyY = true;
				break;
			case 33:
				keys.keyZ = true;
				break;
			default:
				break;
			}
		}

		// Sichern des aktuellen Tastenzustands
		previousFlag[i] = flags[i];
	}
	getKeyState(flags);
}

