/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* rgInput.h 
* Hier werden alle Funktionen definiert, die fuer die 
* Tastatureingabe bzw. Spielsteuerung benoetigt werden.
*/

#ifndef _RGINPUT_
#define _RGINPUT_

using namespace std;

/**
* Holt alle Eingaben ab und prueft dabei, welche Eingabegeraete verwendet werden.
* Bei aktivierter Konfiguration werden die Eingaben dieser Eingabegeraete abgeholt. 
* Momentan wird hier nur auf Tastatur und Maus ueberprueft.
*/
void getInput();

/**
* Dieses Funktion setzt alle Tasten der Tastatur zurueck.
*/
void resetKeys();

#endif