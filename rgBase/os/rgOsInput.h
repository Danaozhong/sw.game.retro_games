/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* rgOsInput.h 
* Hier wird alle betriebssystemspezifischen Funktion, 
* welche fuer die Eingabe notwendig sind, gespeichert
*/

/** 
* Zuweisung der Tastenzustaende
* \param flags 
* Uebergabe der Tasten als byReference
*/
void getKeyState(short* flags);

/** 
* Maus initialisieren
*/
void osInitMouse();

/**
* Uebernimmt alle fuer das Spiel relevaten Eingabedaten der Maus.
* Diese sind links, rechts, oben, unten und Maustaste Links und Rechts.
* Alle Parameter werden als ByReference uebergeben, um direkt gesetzt
* werden zu koennen.
* \param x Die x-Position der Maus
* \param y Die y-Position der Maus
* \param left Ob die linke Maustaste gedrueckt ist
* \param right Ob die rechte Maustaste gedrueckt ist
*/
void osGetMouseInputs(int* x, int* y, bool* left, bool* right);