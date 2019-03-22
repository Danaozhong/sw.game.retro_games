/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* rgSnake.h
* Hier befinden sich die Hauptfunktionalitaeten fuer das Spiel Snake
*/

#ifndef _RGSNAKE_
#define _RGSNAKE_

/**
* Stellt einen Ablauf im Spielablauf von Snake dar. Diese Funktion wird einmal
* pro Frame aufgerufen, solange Snake laeuft.
*/
void runSnake();

/**
* detectCollision ueberprueft ob das Kopf nicht ein anderen Segment getroffen hat
* /param ix die Koordinate x
* /param iy die Koordinate y
* /return true Die Schlange beruehrt sich selber, false, wenn keine Beruehrung aufgetreten ist
*/
bool detectCollision(int ix, int iy);

/**
* detectDrop ueberprueft ob das Kopf nicht ein Drops getroffen hat
* /return -1, wenn kein Drop beruehrt wurde, ansonsten die ID des Drops
*/
int detectDrop();

/**
* Funktion startSnake initialiesiert die Schlange
* initialisiert Erste 6 Segmente und die Richtung links
*/
void startSnake();

/**
* Loescht alle Variablen aus Snake und gibt den Speicher frei
*/
void quitSnake();

/**
* Funktion growSnake() wächst die Schlange mit ein Element
*/
void growSnake();

/**
* Funktion moveSnake() bewegt die Schlange mit ein Segment und wenn kein Colision ist wächst die Schlange 
*/
void moveSnake();

/**
*  Ausgabe der Schlange und der Drops
*/
void outputSnake();



#endif