/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* Definition zu rgPakManDynamics.h
*/

#include "rgPakMan/rgPakManDynamics.h"
#include "rgPakMan/rgPakManGlobals.h"

unsigned int randomResult(unsigned int* chances, unsigned int numOfChances)
{
	unsigned int i, sumOfChances = 0;
	
	for (i = 0; i < numOfChances; ++i)
	{
		sumOfChances += chances[i]; 	
	}

	if (0 == sumOfChances || 0 == numOfChances)
	{
		return 0;
	}
	unsigned int value = (rand() % sumOfChances) + 1; // von 1..sumOfChances
	
	sumOfChances = 0;
	//unsigned int lastSumOfChances;
	for (i = 0; i < numOfChances; ++i)
	{
		//lastSumOfChances = sumOfChances;
		sumOfChances += chances[i]; 
		if (value <= sumOfChances) // <= value)
		{
			return i;
		}	
	}
	return 0;
}



unsigned int getReverseDirection(unsigned int direction)
{
	switch (direction)
	{
		case directionUp:
			return directionDown;
		case directionRight:
			return directionLeft;
		case directionDown:
			return directionUp;
		case directionLeft:
			return directionRight;
		default:
			return directionUndefined;
	}
}



bool isPassable(unsigned int x, unsigned int y, int figureType)
{
	if (	(	(figureType == figurePakPak 
				&& gameField[x][y].flag01 != pmFieldHeadquarter)
			|| figureType == figureGhost)
		&& gameField[x][y].flag01 != pmFieldWall)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int checkCollisionPakPakGhost()
{
	static rgPosition lastGhostPos[maxGhostCount];
	static rgPosition lastPakPakPos;

	unsigned int i;
	int collisionGhost = -1;

	for (i = 0; i < ghostCount; ++i)
	{
		// Eine Kollision kann in zwei Faellen stattfinden:
		// Entweder die Figuren liegen uebereinander, oder die Figuren haben 
		// ihre Plaetze getauscht. Dies kann der Fall sein, wenn zum Zeitpunkt 0
		// PakPak und Geist auf horizontal oder vertikal benachbarten Feldern sitzen
		// und sich in einem Frame aufeinander zubewegen. Da die Geschwindigkeit einer
		// Figur auf ein Feld beschraenkt ist, sitzt nun der PakPak auf der alten Position
		// des Geistes und der Geist auf der alten Position von PakPak.
		if ((pakpak.pos.x == ghosts[i].pos.x && pakpak.pos.y == ghosts[i].pos.y)
			|| (lastPakPakPos.x == ghosts[i].pos.x 
			    && lastPakPakPos.y == ghosts[i].pos.y 
				&& pakpak.pos.x == lastGhostPos[i].x
				&& pakpak.pos.y == lastGhostPos[i].y))
		{
			collisionGhost = i;
		}

		lastGhostPos[i] = ghosts[i].pos;
	}

	lastPakPakPos = pakpak.pos;


	return collisionGhost;
}


bool moveFigure(unsigned int &x, unsigned int &y, unsigned int &direction, unsigned int &desiredDirection, unsigned int figureType)
{
	int newX = x;
	int newY = y;

	if (directionUndefined != desiredDirection)
	{
		switch(desiredDirection)
		{
		case directionUp:
			--newY;
			break;
		case directionRight:
			++newX;
			break;
		case directionDown:
			++newY;
			break;
		case directionLeft:
			--newX;
			break;
		}
	
		if (true == isPassable(newX, newY, figureType))
		{
			// Richtung aendern:
			direction = desiredDirection;
			desiredDirection = directionUndefined;
		}
	}
	
	newX = x;
	newY = y;
	// Einfach weiterlaufen:
	switch(direction)
	{
	case directionUp:
		--newY;
		break;
	case directionRight:
		++newX;
		break;
	case directionDown:
		++newY;
		break;
	case directionLeft:
		--newX;
		break;
	}

	if (true == isPassable(newX, newY, figureType))
	{
		x = newX;
		y = newY;
		// Spielbegrenzungskoordinaten pruefen	
		if (x > pakManGame.pakmanGamexMax) x = pakManGame.pakmanGamexMin;
		if (x < pakManGame.pakmanGamexMin) x = pakManGame.pakmanGamexMax;
		if (y > pakManGame.pakmanGameyMax) y = pakManGame.pakmanGameyMin;
		if (y < pakManGame.pakmanGameyMin) y = pakManGame.pakmanGameyMax;
		return true;
	}
	else
	{
		return false;
	}
}