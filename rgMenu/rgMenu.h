
/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* rgMenu.h
* Hier werden die Menufunktionalitaeten definiert
*/

#ifndef _RGMENU_
#define _RGMENU_

/**
*Mit dieser  Funktion wird je nach der Variable currentDisplayedMenu
*entweder das Hauptmenue, Configurationsmenue, Highscoresmenue oder Team Retro-Games angezeigt
*/
void runMenu();

/**
*Diese Funktion zeigt das Hauptmenu an
*/
void displayMainMenu();

/**
*Diese Funktion zeigt das Configurationsmenue an 
*/
void displayConfigMenu();

/**
*Diese Funktion zeigt das Highscorelisten Menue an 
*/
void displayHighscore();

/**
*Diese Funktion zeigt die Highscoreliste von PakMan an 
*/
void displayHighscorePakMan();

/**
*Diese Funktion zeigt die Highscoreliste von Snake an 
*/
void displayHighscoreSnake();

/**
*Diese Funktion zeigt das Team Retro-Games an
*/
void diplayTeamRetroGames();

/**
*Diese Funktion zeigt den Curser Des Mainmenues 
*/
void drawMainMenu();

/**
*Diese Funktion zeigt den Curser des Configurationsmenus  
*/
void drawConfigMenu();

/**
*Mit dieser Funktion kann man den Balken fuer die Volumenregelung des Sounds bzw. der Music regelen 
*/
void drawVolumeBar(unsigned int &volume, int y);

/**
*Diese Funktion zeigt den Curser des Team Retro-Games 
*/
void drawTeamRetroGames();

/**
*Diese Funktion zeigt die Aufforderung zur Namenseingabe an
*/
void displayNameInput();

/**
* Diese Funktion uebernimmt die von dem Basissystem gegebenen Tastensignale und baut daraus den Namen des 
* Spielers zusammen und gibt ihn nach einem Druck auf Enter an die Highscore weiter.
*/
void highScoreInput();

#endif