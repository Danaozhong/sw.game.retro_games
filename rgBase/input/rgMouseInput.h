/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* rgMouseInput.h 
* Hier werden die  Funktionen, die fuer die Mausbedienung benoetigt werden definiert.
*/

#ifndef _RGMOUSEINPUT_
#define _RGMOUSEINPUT_

/** 
* Initialisiert die Maus sowie die beiden Standard-Maustasten (LMT und RMT)
*/
void initMouse();

/** 
* Abfrage der Mausbewegung bzw. Maus-Eingabe in der Ebene.
*/
void getMouseInput();

#endif