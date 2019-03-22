/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* rgMouseInput.cpp 
* Definition zu rgMouseInput.h
*/


#include "rgCommon/rgGlobals.h"

#include "rgBase/cast/rgCast.h"
#include "rgBase/gfx/rgGfx.h"
#include "rgbase/os/rgOsInput.h"

#include "rgBase/input/rgMouseInput.h"

namespace
{
	/** 
	* Struktur fuer verschiede Mauspositionen
	*/
	struct mousePosition
	{
		int x;
		int y;
	};

	/** 
	* Deklaration von zwei Mauspositionen fuer die Differenzierung und
	* Richtungserfassung
	*/
	mousePosition position1;
	mousePosition position2;		
}

void initMouse()
{
	osInitMouse();
}
 
void getMouseInput()
{
	position2.x = position1.x;
	position2.y = position1.y;

	// Betriebssystemspezifische Funktion aufrufen
	osGetMouseInputs(&position1.x, &position1.y, &keys.keyReturn, &keys.keyEscape);

	/*
		Abfrage in positive x-Richtung (Links)
	*/
	if (0 < (-position2.x + position1.x) )
	{
		keys.keyRight = true;
	}
	/*
		Abfrage in negative y-Richtung (Oben)
	*/
	if (0 < (position2.y - position1.y) )
	{
		keys.keyUp = true;
	}
	/*
		Abfrage in negative x-Richtung (Rechts)
	*/
	if (0 < (position2.x - position1.x) )
	{
		keys.keyLeft = true;
	}
	/*
		Abfrage in positive y-Richtung (Unten)
	*/
	if (0 < (-position2.y + position1.y) )
	{
		keys.keyDown = true;
	}
}