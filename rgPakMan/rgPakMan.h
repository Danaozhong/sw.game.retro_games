/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* rgPakMan.h
* Hier befinden sich die Steuerstrukturen des Spielablaufs des Spiel PakMan
*/
#ifndef _RGPAKMAN_
#define _RGPAKMAN_


/**
* Ablaufprozedur, welche den aktuellen Status des Spiels kontrolliert
* und die jeweiligen Hilfsfunktionen aufruft.
*/
void runPakMan();

/**
* Fraegt die Eingabegeraete ab und setzt PakPaks Wunschrichtung 
*/
void getPakPakDesiredDirection();

/**
* Uebernimmt die Modusaenderung des Spiels, z.B. den Wechsel von get-Ready
* in den Normalmodus.
*/
void changeGameMode(int gameMode);

/**
* Diese Funktion setzt die Anfangswerte fuer PakMan, d.h. das Labyrinth wird
* erzeugt, die Spielfiguren erstellt und an ihre Ausgangsposition gesetzt
* sowie die Timer gesetzt.
*/
void initPakMan();

/**
* Ablaufprozedur, welche aufgerufen wird, wenn das Spiel laeuft. Hier befindet
* sich der komplette Spielablauf sowie das Management der Spielelemente.
*/
void runGame();

/**
* Ablaufprozedur, welche aufgerufen wird, wenn das Spiel verloren ist.
* In diesem Fall werden zwei Sekunden gewartet, bevor das Spiel beendet wird.
*/
void overGame();

/**
* Ablaufprozedur, welche aktiv ist, wenn das Spiel in der "get ready"-Phase ist.
*/
void getReadyGame();

/**
* Ablaufprozedur, welche aktiv ist, wenn PakMan gewonnen ist.
*/
void winGame();

/**
* Ablaufprozedur, welche aktiv ist, wenn das Spiel pausiert ist.
*/
void pauseGame();

/**
* Diese Prozedur uebernimmt die Steuerung des Verlassens von PakMan:
* Die Ruecksetzfunkion wird aufgerufen und die Kontrolle des Programms
* an das Menue zurueckgegeben.
*/
void quitGame();

/**
* Loescht die Timer sowie´saemtliche Spielelemente - und Zustaende. 
*/
void clearValues();

#endif

