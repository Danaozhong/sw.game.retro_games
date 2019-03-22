/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* rgKeyboardInput.h 
* Hier werden die benoetigten Funktionen fuer die 
* Tastatureingabe definiert.
*/

#ifndef _RGKEYBOARDINPUT_
#define _RGKEYBOARDINPUT_

/** 
* Diese Funktion initialisiert alle benoetigten Tasten.
*/
void initKeyBoard();

/**
* Dieses Funktion ueberprueft die Tastatureingaben und registert die zuletzt gedrueckte Taste. 
*/
void getKeyBoardInput();

#endif