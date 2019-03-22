/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* Definition zu rgPakManOutput.h
*/


#include "rgBase/cast/rgCast.h"

#include "rgBase/gfx/rgGfx.h"
#include "rgbase/os/rgCharSet.h"

#include "rgPakMan/rgPakManGlobals.h"
#include "rgPakMan/rgPakManOutput.h"

void drawPakManGame()
{
		
	unsigned int i;
	// Alle Spielelemente ausgeben:
	for (i = 0; i < wallCount; ++i)
	{
		drawSymbol(walls[i].pos.x, walls[i].pos.y, walls[i].symbol);
	}

	for (i = 0; i < dropCount; ++i)
	{
		if (false == drops[i].eaten) 
		{
			drawSymbol(drops[i].pos.x, drops[i].pos.y, drops[i].symbol);
		}
	}

	for (i = 0; i < ghostCount; ++i)
	{
		int color = 0;
		char symbol = ' ';

		switch (ghosts[i].mode)
		{
		case ghostDefault:
			color = ghosts[i].defaultColor;
			symbol = ghosts[i].defaultSymbol;
			break;
		case ghostAfraid:
			if (false == pakManGame.megaPillBlinkingState)
			{
				color = ghosts[i].defaultColor;
				symbol = ghosts[i].defaultSymbol;
			}
			else
			{
				color = ghosts[i].afraidColor;
				symbol = ghosts[i].defaultSymbol;
			}
			break;
		case ghostEaten:
			color = ghosts[i].eatenColor;
			symbol = ghosts[i].eatemSymbol;
		}

		drawSymbol(ghosts[i].pos.x, ghosts[i].pos.y, symbol, color);
	}

	// PakPak zeichnen
	
	/* 
	* Aufgrund der Anordnung der Symbole in eatSymbols ist
	* hier keine switch-case noetig, es reicht eine einfache 
	* mathematische Berechnung.
	*/
	pakpak.symbol = pakpak.eatSymbols[2*(pakpak.direction - 1) + pakpak.currentSymbol];

	drawSymbol(pakpak.pos.x, pakpak.pos.y, pakpak.symbol, rgYellow);


	// HUD zeichen
	for (i = 0; i < maxPakManLives; i++)
	{
		int color = rgDarkRed;
		if (pakManGame.lives > i)
		{
			color = rgRed;
		}
		drawSymbol(50+ 2*i, 10, hearth, color);
	}

	drawHLine(50, 8, "Punktzahl: " + ToString(pakManGame.points));
}
