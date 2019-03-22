/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* Hier werden die Basisfunktionalitaeten der Spieleanwendung gespeichert.
*/

#include "rgCommon/rgGlobals.h"
#include "rgBase/cast/rgCast.h"
#include "rgBase/gfx/rgGfx.h"
#include "rgBase/input/rgInput.h"
#include "rgBase/timedriver/rgTimeDriver.h"
#include "rgBase/audio/rgAudio.h"
#include "rgBase/filesystem/rgFilesystem.h"

#include "rgPakMan/rgPakMan.h"
#include "rgMenu/rgMenu.h"
#include "rgSnake/rgSnake.h"

using namespace std;

/**
* Dies ist die Hauptprogrammebene. Hier befindet sich neben der Initialisierung und Speicherfreigabe auch
* die Spielschleife, in welcher zuerst in Eingabe abgeholt wird, der Programmablauf an das jeweilige Spiel
* weitergegeben wird und zudem die Grafikausgabe an das Konsolenfenster (darin befindet sich auch die 
* Frame-Raten-Anpassung) aufgerufen wird.
*/
int main(void)
{
	// globale Variablen des Spielablaufs setzen:
	programMode = rgRunning;
	gameMode = rgMenu;

	// Framerate setzen:
	setFPS(10);

	// Initialisierungen setzen:
	initConfig();
	loadHighscore();
	initTimers();

	while (rgStopped != programMode)
	{
		// Eingaben abholen
		getInput();

		if (rgMenu == gameMode)
		{
			runMenu();
		}
		else if (rgPakMan == gameMode)
		{
			runPakMan();
		}
		else if (rgSnake == gameMode)
		{
			runSnake();
		}

#ifdef RGDEBUGMODE 
		drawHLine(1,24, "FPS: " + ToString(currentFPS), rgLightGrey);
		drawHLine(40,24, "SleepTime: " + ToString(currentSleepTime), rgLightGrey);
#endif
		
		//Ausgabe erledigen
		drawOutput();
		clearBackBuffer();
	}

	saveConfig();
	saveHighscore();
	stopAudio();

	return 0;
}