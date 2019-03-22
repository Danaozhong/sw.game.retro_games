/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* Definition zu rgPakManMap.h
*/

#include "rgBase/os/rgCharSet.h"

#include "rgPakMan/rgPakManStructures.h"
#include "rgPakMan/rgPakManGlobals.h"
#include "rgPakMan/rgPakManMap.h"

void addWall(unsigned int x, unsigned int y)
{
	if (rgGameFieldMaxElements > wallCount && pmFieldUnused == gameField[x][y].flag01)
	{
		walls[wallCount].pos.x = x;
		walls[wallCount].pos.y = y;
		walls[wallCount].symbol = 'X';
		gameField[x][y].flag01 = pmFieldWall;
		gameField[x][y].flag02 = wallCount;
		wallCount++;

		if (wallCount == 1)
		{
			pakManGame.pakmanGamexMin = x;
			pakManGame.pakmanGamexMax = x;
			pakManGame.pakmanGameyMin = y;
			pakManGame.pakmanGameyMax = y;
		}
		if (pakManGame.pakmanGamexMin > x)
		{
			pakManGame.pakmanGamexMin = x;
		}
		if (pakManGame.pakmanGamexMax < x)
		{
			pakManGame.pakmanGamexMax = x;
		}
		if (pakManGame.pakmanGameyMin > y)
		{
			pakManGame.pakmanGameyMin = y;
		}
		if (pakManGame.pakmanGameyMax < y)
		{
			pakManGame.pakmanGameyMax = y;
		}
	}
}

void createMesh()
{
	for (unsigned int i = 0; i < wallCount; ++i)
	{
		bool left = false;
		bool right = false;
		bool top = false;
		bool bottom = false;
		for (unsigned int k = 0; k < wallCount; k++)
		{
			if (walls[k].pos.x == walls[i].pos.x - 1 && walls[k].pos.y == walls[i].pos.y) 
			{
				left = true;
			}
			else if (walls[k].pos.x == walls[i].pos.x + 1 && walls[k].pos.y == walls[i].pos.y) 
			{
				right = true;
			}
			else if (walls[k].pos.y == walls[i].pos.y + 1 && walls[k].pos.x == walls[i].pos.x) 
			{
				bottom = true;
			}
			else if (walls[k].pos.y == walls[i].pos.y - 1 && walls[k].pos.x == walls[i].pos.x) 
			{
				top = true;
			}
		}
		char currentItem = wallH;
		if (left && right && top && bottom)
		{
			currentItem = wallHV;	
		}
		else if (left && right && top && !bottom)
		{
			currentItem = wallHUp;
		}
		else if (left && right && !top && bottom)
		{
			currentItem = wallHDown;
		}
		else if (left && right && !top && !bottom)
		{
			//currentItem = wallH;
		}
		else if (left && !right && top && bottom)
		{
			currentItem = wallVLeft;
		}
		else if (left && !right && top && !bottom)
		{
			currentItem = wallLeftUp;
		}
		else if (left && !right && !top && bottom)
		{
			currentItem = wallLeftDown;
		}
		else if (left && !right && !top && !bottom)
		{
			//currentItem = wallH;
		}
		else if (!left && right && top && bottom)
		{
			currentItem = wallVRight;
		}
		else if (!left && right && top && !bottom)
		{
			currentItem = wallRightUp;
		}
		else if (!left && right && !top && bottom)
		{
			currentItem = wallRightDown;
		}
		else if (!left && right && !top && !bottom)
		{
			//currentItem = wallH;
		}
		else if (!left && !right && top && bottom)
		{
			currentItem = wallV;
		}
		else if (!left && !right && top && !bottom)
		{
			currentItem = wallV;
		}
		else if (!left && !right && !top && bottom)
		{
			currentItem = wallV;
		}
		else if (!left && right && !top && !bottom)
		{
			//currentItem = walllH;
		}
		walls[i].symbol = currentItem;
	}
}


void createWall(int x1, int x2, int y1, int y2)
{
	unsigned int xmin = 0;
	unsigned int xmax = 0;
	unsigned int ymin = 0;
	unsigned int ymax = 0;
	unsigned int i = 0;

	// Nach Groesse sortieren:
	xmax = max(x1, x2);
	xmin = min(x1, x2);
	ymax = max(y1, y2);
	ymin = min(y1, y2);

	// zuerst die horizontale Linie zeichnen:
	for (i = xmin; i <= xmax; ++i)
	{
		addWall(i, y1);
	}

	// nun die vertikale Linie zeichnen:
	for (i = ymin; i <= ymax; ++i)
	{
		addWall(x2, i);
	}
}

void createWallSquare(unsigned int x1, unsigned int x2, unsigned int y1, unsigned int y2)
{
	unsigned int xmin = 0;
	unsigned int xmax = 0;
	unsigned int ymin = 0;
	unsigned int ymax = 0;
	unsigned int i, k  = 0;

	// Nach Groesse sortieren:
	xmax = max(x1, x2);
	xmin = min(x1, x2);
	ymax = max(y1, y2);
	ymin = min(y1, y2);

	// zuerst die horizontale Linie zeichnen:
	for (i = xmin; i <= xmax; ++i)
	{
		for (k = ymin; k <= ymax; ++k)
		{
			addWall(i, k);
		}
	}

}


void addDrop(unsigned int x, unsigned int y, bool isMegaPill)
{
	if (rgGameFieldMaxElements > dropCount)
	{
		if (pmFieldUnused == gameField[x][y].flag01 
			|| pmFieldDrop == gameField[x][y].flag01)
		{
			unsigned int dropId;
			if(pmFieldDrop == gameField[x][y].flag01)
			{
				
				dropId = gameField[x][y].flag02;
			}
			else
			{
				drops[dropCount].pos.x = x;
				drops[dropCount].pos.y = y;
				drops[dropCount].eaten = false;
				gameField[x][y].flag01 = pmFieldDrop;
				gameField[x][y].flag02 = dropCount;
				dropId = dropCount;
				dropCount++;
			}

			drops[dropId].isMegaPill = isMegaPill;
			if (true == isMegaPill)
			{
				drops[dropId].symbol = 'o';
			}
			else
			{
				drops[dropId].symbol = '.';
			}
		}
	}
}


void addDropArea(unsigned int x1, unsigned int x2, unsigned int y1, unsigned int y2)
{
	unsigned int xmin = 0;
	unsigned int xmax = 0;
	unsigned int ymin = 0;
	unsigned int ymax = 0;
	unsigned int i, k  = 0;
	
	xmax = max(x1, x2);
	xmin = min(x1, x2);
	ymax = max(y1, y2);
	ymin = min(y1, y2);

	// zuerst die horizontale Linie zeichnen:
	for (i = xmin; i <= xmax; ++i)
	{
		for (k = ymin; k <= ymax; ++k)
		{
			if (pmFieldUnused == gameField[i][k].flag01)
			{
				addDrop(i,k);
			}
		}
	}
}

void addGhostHeadquarter(unsigned int x1, unsigned int x2, unsigned int y1, unsigned int y2)
{
	unsigned int xmin = 0;
	unsigned int xmax = 0;
	unsigned int ymin = 0;
	unsigned int ymax = 0;
	unsigned int i, k  = 0;

	// Nach Groesse sortieren:
	xmax = max(x1, x2);
	xmin = min(x1, x2);
	ymax = max(y1, y2);
	ymin = min(y1, y2);

	pakManGame.ghostHeadquarterx = xmin + (xmax - xmin) / 2;
	pakManGame.ghostHeadquartery = ymin + (ymax - ymin) / 2;

	for (i = xmin; i <= xmax; ++i)
	{
		for (k = ymin; k <= ymax; ++k)
		{
			if (pmFieldUnused == gameField[i][k].flag01)
			{
				gameField[i][k].flag01 = pmFieldHeadquarter;
			}
		}
	}
}
