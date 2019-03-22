/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* rgPakManDynamics.h
* Hier befinden sich alle Funktionen, welche mit der Bewegung von Objekten
* verbunden sind, d.h. Kollisionspruefungen, KI,
*/

#ifndef _RGPAKMANDYNAMICS_
#define _RGPAKMANDYNAMICS_

/**
* Uebernimmt eine Menge an Wahrscheinlichkeiten und gibt abhaengig von
* der Wahrscheinlichkeit zufallsgesteuert den Index des gewaehlten Elementes
* aus chances zurueck
* \param chances Eine Liste mit den moeglichen Chancen
* \param numOfChances Die Anzahl der Chancen
* \return Den Index des gewaehlten Elements
*/
unsigned int randomResult(unsigned int* chances, unsigned int numOfChances);

/**
* Ermittelt die Gegenrichtung einer gegebenen Richtung
* \param direction Die Eingaberichtung
* \return die entgegengesetzt Richtung zu der Eingaberichtung
*/
unsigned int getReverseDirection(unsigned int direction);

/**
* Prueft, ob ein Spielfeld von einer Spielfigur betreten werden kann
* \param x Die x-Koordinate des zu pruefenden Feldes
* \param y Die y-Koordinate des zu pruefenden Feldes
* \param figureType Der Typ der Spielfigur (figureGhost(1) / figurePakPak (0))
*/
bool isPassable(unsigned int x, unsigned int y, int figureType);

/**
* Prueft Kollision zwischen allen Geistern und PakPak.
* \return Die ID des Geistes, mit dem PakPak momentan kollidiert, bei keiner Kollision -1
*/
int checkCollisionPakPakGhost();

/**
* Verschiebt eine Figur unter Beachtung der Wunschrichtung. Wenn das Feld in Wunschrichtung frei ist,
* wird die Figur ihre Richtung aendern und sich in Wunschrichtugn weiterbewegen. Falls nicht,
* versucht die Figur, in bisheriger Richtung weiterzugehen. Bis auf figureType sind
* alle Parameter als byReference uebergeben und werden in dieser Funktion manipuliert.
* \param x Die x-Koordinate der Spielfigur
* \param y Die y-Koordinate der Spielfigur
* \param direction Die Richtung der Spielfigur
* \param desiredDirection Die Wunschrichtung der Spielfigur
* \param figureType Der Typ der Spielfigur (figureGhost(1) / figurePakPak (0))
* \return true, wenn die Spielfigur sich um ein Feld bewegt hat, ansonsten false
*
*/
bool moveFigure(unsigned int &x, 
				unsigned int &y, 
				unsigned int &direction, 
				unsigned int &desiredDirection, 
				unsigned int figureType);


#endif