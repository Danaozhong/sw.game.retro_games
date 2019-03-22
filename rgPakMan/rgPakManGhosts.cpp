/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* Definition zu rgPakManGhosts.h
*/

#include "rgCommon/rgMisc.h"

#include "rgBase/timedriver/rgTimeDriver.h"
#include "rgBase/os/rgCharSet.h"

#include "rgPakMan/rgPakManDynamics.h"
#include "rgPakMan/rgPakManGhosts.h"
#include "rgPakMan/rgPakManGlobals.h"


unsigned int ghostRandomizeDirection(unsigned int id, bool allowImpossible)
{
	unsigned int xdiff, ydiff, xTarget, yTarget, determination;
	unsigned int chances[4] = {1, 1, 1, 1}; 
	
	if (ghostEaten == ghosts[id].mode)
	{
		xTarget = pakManGame.ghostHeadquarterx;
		yTarget = pakManGame.ghostHeadquartery;
		determination = 7;
	}
	else
	{
		xTarget = pakpak.pos.x;
		yTarget = pakpak.pos.y;
		determination = 3;
	}
		xdiff = abs(static_cast<int>(ghosts[id].pos.x - xTarget));
		ydiff = abs(static_cast<int>(ghosts[id].pos.y - yTarget));
		
		/*
		* Wenn Koordinaten gleich, sind die Chancen links und rechts gleich, aber die oben unten viel größer
		* Die andere Richtung wird jeweils mit 1/5 gewettet
		*/
		
	if (ghosts[id].pos.x > xTarget)
	{
		chances[3] += xdiff;
		chances[1] += xdiff / determination;
	}	
	else
	{
		chances[1] += xdiff;
		chances[3] += xdiff / determination;
	}

	if (ghosts[id].pos.y > yTarget)
	{
		chances[0] += ydiff;
		chances[2] += ydiff / determination;
	}	
	else
	{
		chances[2] += ydiff;
		chances[0] += ydiff / determination;
	}
		
	if (ghostAfraid == ghosts[id].mode)
	{
		// Die Geister sollen fliehen - die Chancen also gerade umdrehen
		swap(chances[0], chances[2]);
		swap(chances[1], chances[3]);
	}

	int impossibleCounter = 0;
	
	if (allowImpossible == false)
	{
		if (false == isPassable(ghosts[id].pos.x + 1, ghosts[id].pos.y, figureGhost)) 
		{
			chances[1] = 0;
			++impossibleCounter;
		}
		if (false == isPassable(ghosts[id].pos.x - 1, ghosts[id].pos.y, figureGhost)) 
		{
			chances[3] = 0;
			++impossibleCounter;
		}
		if (false == isPassable(ghosts[id].pos.x, ghosts[id].pos.y + 1, figureGhost)) 
		{
			chances[2] = 0;
			++impossibleCounter;
		}
		if (false == isPassable(ghosts[id].pos.x, ghosts[id].pos.y - 1, figureGhost))
		{
			chances[0] = 0;
			++impossibleCounter;
		}
	}

	if (impossibleCounter < 3)
	{
		// Solange noch moeglich, darf nicht rueckwarts gelaufen werden
		chances[getReverseDirection(ghosts[id].direction)-1] = 0;
	}

	return randomResult(chances, 4) + 1;
}


void updateGhostDirectionChangeTimer(unsigned int id)
{
	unsigned int directionChangeTime = 0;
	switch (ghosts[id].mode)
	{
	case ghostDefault:
		if (3 == gameField[ghosts[id].pos.x][ghosts[id].pos.y].flag01)
		{
			// So schnell wie möglich das HQ verlassen
			directionChangeTime = 1;
		}
		else
		{
			directionChangeTime = getRandomValue(500, 5000);
		}
		break;
	case ghostAfraid:
		directionChangeTime = getRandomValue(500, 5000);
		break;
	case ghostEaten:
		directionChangeTime = getRandomValue(100, 500);
		break;
	}

	// Die Geschwindigkeit des Richtungswechsel neu setzen:
	if (0 != ghosts[id].directionChangeTimerHandle)
	{
		// Falls bereits ein Timer vorhanden ist, diesen loeschen
		deleteTimer(ghosts[id].directionChangeTimerHandle);
	}

	ghosts[id].directionChangeTimerHandle = createTimer(directionChangeTime); 
	runTimer(ghosts[id].directionChangeTimerHandle);
}



void setGhostMode(unsigned int id, int ghostMode)
{
	
	double speed;
	switch (ghostMode)
	{
	case ghostDefault:
		speed = ghosts[id].defaultSpeed;
		break;
	case ghostAfraid:
		if (ghostDefault == ghosts[id].mode)
		{
			//Richtungsumkehr
			ghosts[id].desiredDirection = getReverseDirection(ghosts[id].direction);
		}
		speed = ghosts[id].afraidSpeed;
		break;
	case ghostEaten:
		speed = ghosts[id].eatenSpeed;
		break;
	default:
		return;
	}

	ghosts[id].mode = ghostMode;

	// Die Fortbewegungsgeschwindigkeit neu setzen:
	if (0 != ghosts[id].walkSpeedTimerHandle)
	{
		deleteTimer(ghosts[id].walkSpeedTimerHandle);
	}

	ghosts[id].currentSpeed = speed;
	ghosts[id].walkSpeedTimerHandle = createTimer(static_cast<unsigned int>(1000 / ghosts[id].currentSpeed));
	runTimer(ghosts[id].walkSpeedTimerHandle);

	updateGhostDirectionChangeTimer(id);
}

void addGhost(double speed, unsigned int color)
{
	if (ghostCount < maxGhostCount)
	{
		ghosts[ghostCount].defaultSymbol = figure;
		ghosts[ghostCount].eatemSymbol = 'X';
		ghosts[ghostCount].eatenColor = rgBlue;
		ghosts[ghostCount].defaultColor = color;
		ghosts[ghostCount].pos.x = pakManGame.ghostHeadquarterx;
		ghosts[ghostCount].pos.y = pakManGame.ghostHeadquartery;
		ghosts[ghostCount].direction = 3;
		ghosts[ghostCount].afraidColor = rgYellow;
		ghosts[ghostCount].defaultSpeed = speed;
		ghosts[ghostCount].afraidSpeed = speed * 0.4;
		ghosts[ghostCount].eatenSpeed = speed * 1.5;

		setGhostMode(ghostCount, ghostDefault);
		++ghostCount;
	}
}
