/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* rgPakManGhosts.h
* Hier befinden sich alle Funktionen, welche die Geisterzeugung/
* Steuerung/Modusaenderung betreffen.
*/
#ifndef _RGPAKMANGHOST_
#define _RGPAKMANGHOST_

#include "rgCommon/rgGlobals.h"

/**
* Gibt eine Bewegungsrichtung eines Geistes zurueck.
* Dabei wird die Gegenrichtung, d.h. der Geist laeuft rueckwaerts,
* nur moeglich, wenn es keine andere Moeglichkeit mehr gibt, d.h. wenn
* der Geist in einer Sackgasse ist.
* \param id Die ID des Geistes
* \param allowImpossible Wenn true, dann werden auch Richtungen moeglich,
* die momentan nicht betreten werden koennen. Wenn false, wird zwischen den
* aktuell moeglichen Richtungen gewaehlt
* \return Eine Bewegungsrichtung
*/
unsigned int ghostRandomizeDirection(unsigned int id, bool allowImpossible);

/**
* Hilfsfunktion, aendert die Geschwindigkeit des Richtungsaendertimers der Geister,
* d.h. je nach Modus aendern die Geister unterschiedlich schnell ihre Richtung.
* \param id Die ID des Geistes
*/
void updateGhostDirectionChangeTimer(unsigned int id);

/**
* Setzt des Modus eines Geistes, d.h. Normal / Flucht / Gefressen. Neben der
* Modusaenderung werden auch die Timer des Geistes an den neuen Modus angepasst.
* Wechselt der Geist vom Normalmodus in den Fluchtmodus, wird weiterhin die
* Bewegungsrichtung invertiert.
* \param id Die ID des Geistes
* \param ghostMode Der neue Modus des Geistes. Sollte eine der
* folgenden Konstanten sein:
* ghostDefault, ghostAfraid oder ghostEaten
*/
void setGhostMode(unsigned int id, int ghostMode);

/**
* Fuegt dem Spiel einen neuen Geist hinzu und setzt dessen Standard-Werte.
* \param speed Eine Geschwindigkeitsangabe in Felder pro Sekunde
* \param color Die Farbe des Geistes 
*/
void addGhost(double speed, unsigned int color = rgPink);
#endif