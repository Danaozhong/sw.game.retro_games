/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* rgInput.cpp 
* Definition zu rgInput.h
*/

#include "rgCommon/rgGlobals.h"

#include "rgBase/gfx/rgGfx.h"

#include "rgBase/input/rgMouseInput.h"
#include "rgbase/input/rgKeyboardInput.h"
#include "rgBase/input/rgInput.h"

void getInput()
{
	resetKeys();
	static bool isKeyboardInitalized = false;
	static bool isMouseInitalized = false;

	// Pruefe ob Tastatur aktiviert ist
	if (true == config.keyboardEnabled)
	{
		if (false == isKeyboardInitalized)
		{
			initKeyBoard();
			isKeyboardInitalized = true;
		}
		getKeyBoardInput();
	}

	//	zusaetzliche Eingabegeraete z.B. Maus aktivieren
	if (true == config.mouseEnabled)
	{
		if (false == isMouseInitalized)
		{
			initMouse();
			isMouseInitalized = true;
		}
		getMouseInput();
	}
}

void resetKeys()
{
	keys.keyLeft = false;
	keys.keyUp = false;
	keys.keyRight = false;
	keys.keyDown = false;
	keys.keyEscape = false;
	keys.keySpace = false;
	keys.keyBackspace = false;
	keys.keyReturn = false;
	keys.keyA = false;
	keys.keyB = false;
	keys.keyC = false;
	keys.keyD = false;
	keys.keyE = false;
	keys.keyF = false;
	keys.keyG = false;
	keys.keyH = false;
	keys.keyI = false;
	keys.keyJ = false;
	keys.keyK = false;
	keys.keyL = false;
	keys.keyM = false;
	keys.keyN = false;
	keys.keyO = false;
	keys.keyP = false;
	keys.keyQ = false;
	keys.keyR = false;
	keys.keyS = false;
	keys.keyT = false;
	keys.keyU = false;
	keys.keyV = false;
	keys.keyW = false;
	keys.keyX = false;
	keys.keyY = false;
	keys.keyZ = false;
}
