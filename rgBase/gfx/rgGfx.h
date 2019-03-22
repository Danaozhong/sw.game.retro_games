/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* rgGfx.h
* Hier befinden sich alle Funktionen, welche fuer die allgemeine
* Grafikausgabe zustaendig sind.
*/
#ifndef _RGGFX_
#define _RGGFX_

#include <string>

#include "rgCommon/rgGlobals.h"

using namespace std;

/**
* Setzt die maximale Framerate des Spiels. Wenn kein Parameter angegeben wird, wird die 
* Framerate auf 5 Frames / Sekunde gesetzt.
* \param frameRate Sollwert der Anzahl Frames/Sekunde
* \return		1 wenn erfolgreich, -1, wenn die Anzahl der FPS ungueltig ist
*/
int setFPS(unsigned int frameRate = 5);

/** 
* Uebernimmt die komplette Darstellfunktionalitaet, d.h. zeichnet das Bild neu. Gleichzeitig
* wird die FrameRate gemessen und die SleepTime angepasst.
*/
void drawOutput();

/**
* Loescht den Inhalt des Spielfeldes
* \param symbol Das ASCII-Zeichen, mit welchem der Bildschirminhalt ueberschrieben werden soll
*/
void clearBackBuffer(char symbol = ' ');

/**
* Zeichnet ein einzelnes Zeichen an die angegebene Position
* \param x		x-Position des Zeichens
* \param y		y-Position des Zeichens
* \param symbol Das ASCII-Zeichen, welches dargestellt werden soll
* \param color  Die Farbe des Zeichens. Siehe hierzu die in rgGlobals.h definierte Farbwerte.
* Wenn nicht gegeben, wird weiss genutzt
* \return		1 wenn erfolgreich, -1, wenn das Zeichen ausserhalb der Grenzen liegt
*/
int drawSymbol(int x, int y, char symbol, int color = rgWhite);

/**
* Zeichnet eine Zeichenkette horizontal nach rechts an die angegebene Position
* \param x		x-Position des Startpunktes
* \param y		y-Position des Startpunktes
* \param line   Die zu zeichnende Zeichenkette
* \param color  Die Farbe des Zeichens. Siehe hierzu die in rgGlobals.h definierte Farbwerte.
* Wenn nicht gegeben, wird weiss genutzt
* \return		1 wenn erfolgreich, -1, wenn ein Zeichen ausserhalb der Grenzen liegt
*/
int drawHLine(int x, int y, const string &line, int color = rgWhite);

/**
* Zeichnet eine Zeichenkette vertikal nach unten an die angegebene Position
* \param x		x-Position des Startpunktes
* \param y		y-Position des Startpunktes
* \param line   Die zu zeichnende Zeichenkette
* \param color  Die Farbe des Zeichens. Siehe hierzu die in rgGlobals.h definierte Farbwerte.
* Wenn nicht gegeben, wird weiss genutzt
* \return		1 wenn erfolgreich, -1, wenn ein Zeichen ausserhalb der Grenzen liegt
*/
int drawVLine(int x, int y, const string &line, int color = rgWhite);

/**
* Zeichnet mit einem Zeichen eine Linie von Punkt 1 zu Punkt 2. Dabei wird ausgehend von Punkt 1
* zuerst der horizontale Abstand waagrecht gezeichnet und anschlieﬂend eine vertikale Verbindung
* zu Punkt 2 gezeichnet
* \param x1		x-Position des Startpunktes
* \param x2		x-Position des Endpunktes
* \param y1		y-Position des Startpunktes
* \param y2		y-Position des Endpunktes
* \param symbol Das ASCII-Zeichen, welches dargestellt werden soll
* \param color  Die Farbe des Zeichens. Siehe hierzu die in rgGlobals.h definierte Farbwerte.
* Wenn nicht gegeben, wird weiss genutzt
* \return		1 wenn erfolgreich, -1, wenn ein Zeichen ausserhalb der Grenzen liegt
*/
int drawLine(int x1, int x2, int y1, int y2, char symbol, int color = rgWhite);

#endif