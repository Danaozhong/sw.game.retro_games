/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* rgHighScore.h
* Hier werden alle Funktionen deklariert, welche mit der Sortierung,
* Pruefung und Aufnahme in die Highscore zu tun haben.
*/

#ifndef _RGHIGHSCORE_
#define _RGHIGHSCORE_


#include <string>

using namespace std;

/**
* Diese Funktion sollte immer aufgerufen werden, wenn ein Spiel beendet wird.
* Es wird die uebergebene Punktzahl geprueft und je nach Aufnahme in die 
* Highscore entweder ein Eingabebildschirm oder das Hauptmenue angezeigt.
* \param points Die erreichte Punktzahl des Spiels
* \param gameType Das Spiel, welches gerade gespielt wurde (rgSnake oder rgPakMan)
*/
void returnToMenuFromGame(unsigned int points, int gameType);

/**
* Diese Funktion prueft, ob eine Punktezahl eines Spieles ausreichend ist,
* um in die Highscore aufgenommen zu werden.
* \param points Die Punktezahl
* \param gameType Das Spiel, dessen HighScore-Liste geprueft werden soll
*/
bool isInHighScore(unsigned int points, int gameType);

/**
* Diese Funktion fuegt eine Punktzahl in eine HighScoreliste hinzu. Wenn
* die Punktezahl nicht ausreichend ist, bricht die Funktion ohne Aktion ab.
* \param name Der Name des Spielers
* \param points Die einzutragende Punktezahl
* \param gameType Das Spiel, dessen HighScore-Liste genutzt werden soll
*/
void addHighscore(string name, unsigned int points, int gameType);

#endif