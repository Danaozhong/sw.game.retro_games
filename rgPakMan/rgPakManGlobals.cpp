/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* Definition zu rgPakManGlobals.h
*/

#include "rgPakMan/rgPakManStructures.h"
#include "rgPakMan/rgPakManGlobals.h"

rgWall walls[rgGameFieldMaxElements];
unsigned int wallCount;

rgDrop drops[rgGameFieldMaxElements];
unsigned int dropCount;

rgPakPak pakpak;
rgGhost ghosts[maxGhostCount];
unsigned int ghostCount;

pmPakMan pakManGame;

