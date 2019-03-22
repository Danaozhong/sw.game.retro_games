/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* rgOsGfx.h
* Hier befinden sich alle Funktionen, welche betriebssystemspezifische
* Methodenaufrufe benoetigen und mit der Grafikausgabe zusammenhaengen.
*/
#ifndef _RGOSGFX_
#define _RGOSGFX_

#include <string>

#include "rgCommon/rgGlobals.h"

using namespace std;

/**
* Zeichnet ein definiertes Zeichen in einer bestimmten Farbe an eine bestimmte Position des Konsolenfensters.
* \param x		x-Position des Zeichens
* \param y		y-Position des Zeichens
* \param letter Das ASCII-Zeichen, welches dargestellt werden soll
* \param color  Die Farbe des Zeichens. Wenn nicht gegeben, wird weiss genutzt
*/
void osDrawCharPosition(const int x, const int y, const char letter, const int color = rgWhite);

/**
* Gibt die Zeit in ms seit Systemstart zurueck.
*/
long osGetTickCount();

#endif