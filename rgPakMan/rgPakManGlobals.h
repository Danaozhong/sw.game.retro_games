/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* rgPakManGlobals.h
* Hier befinden sich alle fuer das Spiel PakMan notwendigen globalen Variablen
* sowie PakMan-spezifische Konstanten.
*/
#ifndef _RGPAKMANGLOBALS_
#define _RGPAKMANGLOBALS_

#include "rgCommon/rgGlobals.h"
#include "rgPakMan/rgPakManStructures.h"

/*
* Status eines Spielfeldes:
* Status	Flag1	Flag2
* unbelegt	0		0
* Wall		1		ID des Walls
* Drop		2		ID des Drops
* Geist-HQ	3		0
* 
*/

/// Wert eines Feldes, wenn dieses nicht benutzt wird
const int pmFieldUnused = 0;

/// Wert eines Feldes, wenn dieses ein Wandelement enthaelt 
const int pmFieldWall = 1;

/// Wert eines Feldes, wenn dieses ein Drop enthaelt  
const int pmFieldDrop = 2;

/// Wert eines Feldes, wenn dieses ein Drop enthaelt 
const int pmFieldHeadquarter = 3;

// Richtungskonstanten
const unsigned int directionUp = 1;
const unsigned int directionRight = 2;
const unsigned int directionDown = 3;
const unsigned int directionLeft = 4;

/**
* Undefinierte Bewegungsrichtung, im Fall der Wunschrichtung 
* bedeutet dies, dass die Spielfigur einfach weiter laeuft und
* keinen Richtungswechsel bestrebt.
*/
const unsigned int directionUndefined = 0;

/// Spielmodus: Normal
const int pakManGameRunning = 0;

/// Spielmodus: Pausiert
const int pakManGamePaused = 1;

/// Spielmodus: Game Over
const int pakManGameGameOver = 2;

/// Spielmodus: Countdown zu Spielbeginn
const int pakManGameWaiting = 3;

/// Spielmodus: Spiel gewonnen
const int pakManGameWin = 4;

/// Die Startposition des PakPaks (x)
const unsigned int pakPakStartPosx = 35;

/// Die Startposition des PakPaks (y)
const unsigned int pakPakStartPosy = 11;

/// Allgemeine Konstante zur Auswahl eines Geistes
const int figureGhost = 1;

/// Allgemeine Konstante zur Auswahl des PakPaks
const int figurePakPak = 0;

/// Die maximale Anzahl an Versuchen pro Spiel
const int maxPakManLives = 3;

/// Zustandskonstante fuer den Modus eines Geists: Normal
const int ghostDefault = 0;

/// Zustandskonstante fuer den Modus eines Geists: Veraengstigt
const int ghostAfraid = 1;

/// Zustandskonstante fuer den Modus eines Geists: Gefressen
const int ghostEaten = 2;

/// Anzahl der maximal moeglichen Geister
const unsigned int maxGhostCount = 5;

/// Dauer der Megapille in Sekunden
const unsigned int megaPillDuration = 15;

/// Blinkdauer der Geister, wenn die Wirkung der Megapille nachlaesst
const unsigned int megaPillWarningDuration = 5;

/// Wieviele Punkte das Fressen eines Drops liefert
const unsigned int pointsForADrop = 3;

/**
* Wieviele Punkte der erste nach Beginn der Wirkung der Megapille gefressene
* Geist bringt. Jeder weitere in der Wirkzeit der Megapille gefressene Geist
* bringt das doppelte des vorherigen Wertes.
*/
const unsigned int pointsForAGhost = 20;

/// Saemtliche Wandelemente
extern rgWall walls[rgGameFieldMaxElements];

/// Wieviele Wandelemente auf dem Spielfeld existieren
extern unsigned int wallCount;

/// Saemtliche Dops, dazu zaehlen auch die Megapillen
extern rgDrop drops[rgGameFieldMaxElements];

/// Wieviele Drops (gefressen und vorhanden) sich auf dem Spielfeld befinden
extern unsigned int dropCount;

/// Die Spielfigur des PakPaks
extern rgPakPak pakpak;

/// Die Spielfiguren der Geister
extern rgGhost ghosts[maxGhostCount];

/// Wieviele Geister auf dem Spielfeld existieren
extern unsigned int ghostCount;

/// Instanz der Spielvariable, hier werden saemtliche Spielinfos gespeichert.
extern pmPakMan pakManGame;
#endif