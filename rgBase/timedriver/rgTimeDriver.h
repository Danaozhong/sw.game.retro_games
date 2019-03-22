/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* rgTimeDriver.h
* Diese Datei enthaelt alle Funktionen, welche fuer die virtuelle
* in-game Zeitmessung wichtig sind.
*/

#ifndef _RGTIMEDRIVER_
#define _RGTIMEDRIVER_

void initTimers();

/**
* Diese Funktion erhoeht alle Timer bei jedem Durchlauf
*/
void incrementTimer();

/** 
* Funktion createTimer erstellt einen neuen Timer und gibt ein Handle zurueck
* \param ms Zeit des Timers in ms
* \return 1, wennn erfolgreich, -1 wenn Speicher voll dann gibt aus 
*/
int createTimer(unsigned int ms);

/**
*Funktion deleteTimer setzt die Reservierung eines Timers zurueck
* \param id Der Index des Timers, welcher freigegeben werden soll wird
* \return 1, wenn erfolgreich, 
* -1, das Speicher wurde nicht benutzt,
* -2 Index ausserhalb des gueltigen Bereichs
*/
int deleteTimer(unsigned int &id);

/**
* Ueberpruft ob ein Timer aktuell fertig ist
* \param id Index des Timers, welcher uberprueft wird
* \return 1 Timer ist fertig, 0 - Timer nicht fertig, -1 -Index ausserhalb des gueltigen Bereichs
*/
int finishedTimer(unsigned int id);

/**
* Stoppt einen Timer.
* \param id Index des timer
* \return 1 Der Timer wurde abgeschaltet
* -1 Timer wurde nicht erzeugt
* -2 Index ausserhalb des gueltigen Bereichs
*/
int stopTimer (unsigned int id);

/**
* Startet einen Timer
* \param id Index des timer
* \return  1 - Timer wurde gestartet
* -1 - Timer wurde nicht erzeugt
* -2 - Index ausserhalb des gueltigen Bereichs
*/
int runTimer (unsigned int id);

#endif