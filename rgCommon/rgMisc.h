/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* rgMisc.h 
* Hier befinden sich keine eindeutig kategorisierbare Funktionene, welche von 
* verschiedenen Programmteilen benoetigt werden.
*/

#include <string>

/**
* Liefert einen ganzzahligen, positiven Zufallswert zwischen min und max.
* \param min Minimaler Wert
* \param max Maximaler Wert
* \return Den Zufallswert zwischen Min und Max
*/
unsigned int getRandomValue(unsigned int min, unsigned int max);

/**
* Liefert das aktuelle Datum als DD.MM.YYYY-formatierter String.
*/
std::string getDateAsString();