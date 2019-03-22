/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* rgCharSet.h
* Hier befinden sich alle Funktionen, welche nicht-unicode-Sonderzeichen 
* je nach Betriebssystem zurueckgeben
*/
#ifndef _RGCHARSET_
#define _RGCHARSET_

/// CS850-Zeichen fuer eine horizontale Wand
const unsigned char wallH = 205;

/// CS850-Zeichen fuer eine vertikale Wand
const unsigned char wallV = 186;

/// CS850-Zeichen fuer eine Wandkreuzung
const unsigned char wallHV = 206;

/// CS850-Zeichen fuer eine Wandecke links/unten
const unsigned char wallLeftDown = 187;

/// CS850-Zeichen fuer eine Wandecke links/oben
const unsigned char wallLeftUp = 188;

/// CS850-Zeichen fuer eine Wandecke rechts/unten
const unsigned char wallRightDown = 201;

/// CS850-Zeichen fuer eine Wandecke rechts/oben
const unsigned char wallRightUp = 200;

/// CS850-Zeichen fuer eine horizontale Wand mit einer Verbindung nach unten
const unsigned char wallHDown = 203;

/// CS850-Zeichen fuer eine horizontale Wand mit einer Verbindung nach oben
const unsigned char wallHUp = 202;

/// CS850-Zeichen fuer eine vertikale Wand mit einer Verbindung nach links
const unsigned char wallVLeft = 185;

/// CS850-Zeichen fuer eine vertikale Wand mit einer Verbindung nach rechts
const unsigned char wallVRight = 204;

/// CS850-Zeichen fuer ein Herz
const unsigned char hearth = 3;

/// CS850-Zeichen fuer eine Spielfigur
const unsigned char figure = 1;
#endif
