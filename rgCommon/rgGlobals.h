/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* rgGlobals.h 
* Hier werden die fuer alle Programmteile gemeinsamen Elemente deklariert, die
* global im Programm benoetigt werden
*/
#ifndef _RGGLOBALS_
#define _RGGLOBALS_

#include "rgBase/structures/rgStructures.h"

//################################################################
// Konstanten
//################################################################


// # Konstanten fuer das Programm allgemein #

/// Fuer alle Werte, welche auf das Spiel Snake weisen sollen
const int rgSnake = 0;

/// Fuer alle Werte, welche auf das Spiel PakMan weisen sollen
const int rgPakMan = 1;

/// Fuer alle Werte, welche auf das Menue weisen sollen
const int rgMenu = 2;

/// Wert fuer die Hauptschleife, wenn das Programm laeuft
const int rgRunning = 0;

/// Wert fuer die Hauptschleife, wenn das Programm beendet werden soll
const int rgStopped = 1;

// # Konstanten fuer die Grafik # 

/// Die Groesse des Konsolenfenster in x-Richtung
const unsigned int rgGameFieldxMax = 80;

/// Die Groesse des Konsolenfensters in y-Richtung
const unsigned int rgGameFieldyMax = 24;

/// Die maximale Anzahl moeglicher Elemente
const unsigned int rgGameFieldMaxElements = rgGameFieldxMax * rgGameFieldyMax; 

// Farbwerte fuer die Konsole
const int rgWhite = 0;
const int rgLightGrey = 1;
const int rgGrey = 2;
const int rgRed = 3;
const int rgDarkRed = 4;
const int rgBlue = 5;
const int rgDarkBlue = 6;
const int rgGreen = 7;
const int rgDarkGreen = 8;
const int rgPink = 9;
const int rgPurple = 10;
const int rgYellow = 11;
const int rgCyan = 12;


//################################################################
// globale Variablen
//################################################################

// # Variablen fuer das Programm allgemein #

/// speichert den Zustand des Programms (laeuft es oder soll es beendet werden)
extern int programMode;

/// speichert die aktuelle Spielwahl (PakMan, Snake oder das Menu)
extern int gameMode;

/// speichert das aktuell geoeffnete Menue
extern int mnCurrentDisplayedMenu;

/// Die aktuell verwendete Konfiguration
extern rgConfig config;

// # Variablen fuer die Grafik # 

/// Variable, um einen universellen Hilfsspeicher fuer die gesamte Bildflaeche zu haben
extern rgGameField gameField[rgGameFieldxMax + 1][rgGameFieldyMax + 1];

/// Der Sollwert der Bilder pro Sekunde
extern unsigned int gameMaxFPS;

/// Der Istwert an Frames pro Sekunde
extern double currentFPS;

/**
* Die momentane Zeit in ms, wie lange der Rechner zum Angleichen der Frames pro 
* Sekunde schlaeft
*/
extern int currentSleepTime;


// # Variablen fuer die Zeitmessung # 

/** Das aus den FPS errechente Inkrement eines Timer in ms pro Frame, damit
* der virtuelle Timer im Idealfall pro realer Sekunde eine Sekunde hochzaehlt.
* Ist der Rechner zu langsam, um das Spiel fluessig darzustellen, wird die 
* virtuelle Sekunde laenger.
*/
extern unsigned int timerIncrement;

// # Variablen fuer die Eingabe # 

/// Diese Instanz einer Struktur gibt an, welche Taste gerade gedrueckt wurde
extern rgKeyboard keys;

// # Variablen fuer die HighScore # 

/// Die HighScore fuer PakMan
extern rgHighScore highScorePakMan[10];

/// Die HighScore fuer Snake
extern rgHighScore highScoreSnake[10];

/**
* Die ans Menue uebergebene Punktezahl des Spiels, um auf Mitgliedschaft 
* in der HighScore zu pruefen (siehe rgHighScore.h).
*/
extern unsigned int highScorePoints; 

/**
* Der ans Menue uebergebene Typ des zuletzt gelaufenen Spiels, um auf 
* Mitgliedschaft  in der HighScore zu pruefen (siehe rgHighScore.h).
* Der Typ des Spieles muss uebergeben werden, da die HighScore unab-
* haengig von den Spielen funktioniert.
* 0 (entspricht der Konstanten rgSnake) entspricht dabei dem Spiel 
* Snake, 1 (entspricht der Konstante rgPakMan) dem Spiel PakMan.
*/
extern int highScoreGame;

#endif