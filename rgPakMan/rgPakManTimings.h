/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* rgPakMan.h
* Hier befinden sich alle Strukturen und Funktionen fuer das Spiel PakMan
*/
#ifndef _RGPAKMANTIMINGS_
#define _RGPAKMANTIMINGS_

/**
* Nimmt einen beliebigen Timer und zaehlt beim Durchlauf des Timers 
* currentTime um einen Wert herunter. Sobald der Timer 0 erreicht, wird
* true zurueckgegeben.
* \param timerHandle die Handle-ID des zu nutzenden Timers
* \param currentTime Die aktuelle, ganzzahlige Zaehlvariable
* \return true, wenn man einem Timerdurchlauf die Zaehlervariable auf 0 ist, a
* ansonsten false
*/
bool doCountdown(unsigned int timerHandle, unsigned int* currentTime);

/**
* Erhoeht die Wirkungszeit der Megapillen. Prueft dabei auch, ob die Geister
* aktuell blinken und 
*
*/
void incrementMegaPillTimer(unsigned int seconds);

#endif