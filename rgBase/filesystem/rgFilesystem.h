/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* rgFilesystem.h
* Diese Datei bietet die Datei Ein- und Ausgabeoperationen und sorgt fuer ein Speichern
* der Spielkonfiguration und der Highscore in einer Textdatei...
*/

#ifndef _RGFILESYSTEM_
#define _RGFILESYSTEM_


/**
*Hier werden alle Configurationen gespeichert 
*Standard Configuration sind auf False gesetzt.(siehe initConfig(); )
*\return 1 wenn erfolgreich, -1 wenn nicht.
*/
int saveConfig();

/**
*In dieser Funktion werden Configurationen(musicEnabled, soundEnabled,...) in einer Datei "config.ini"  gespeichert.
*\return 1, wenn erfolgreich, -1, wenn die Datei gesperrt ist(Kein Zugriff)
*/
int loadConfig();

/**
* Alle Configurationen die in der Datei "config.ini" geladen
*Beim Spiel Anfang werden Standard Configuration geladen
* \return 1, wenn erfolgreich, -1, wenn die Datei gesperrt ist, ...
*/
int saveHighscore();

/**
*Im Programm Retro Games sind zwei Spiele vorhanden.
*Erstens muss geprüft werden in welcher Highscoreliste muss geschreiben werden ? 
*HighscorelistePakman oder HighscorelisteSnake
*In der Datei Highscoreliste
*\return 1, wenn erfolgreich, -1, wenn die Datei gesperrt ist, ...
*/
int loadHighscore();

/**
*In dieser Funktion sind alle Standard Configurationen auf false gesetzt ausser Keyboard ist auf True.
*Music und Sounds Volumen sind auf 0.
*/
void initConfig();
#endif