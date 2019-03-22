/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* Definition zu rgGfx.h
*/

#include <string>
#include "rgCommon/rgGlobals.h"
#include "rgBase/os/rgOsGfx.h"

#include "rgBase/gfx/rgGfx.h"


namespace
{
	/** 
	* Prueft die Begrenzungen des Spielfeldes. Die Parameter entsprechen den 
	* Koordinaten des Feldes, welches geprueft werden soll. Wenn sich das Feld 
	* innerhalb der Begrenzungen befindet, wird true zurueckgegeben, ansonsten 
	* false.
	*/
	bool checkValidRange(unsigned int x, unsigned int y)
	{
		if (x > rgGameFieldxMax || x < 1 ||
			y > rgGameFieldyMax || y < 1)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	
	long currentTime, lastTime;
	int frames, timeDiff;
}



struct rgConsoleBuffer
{
	char letter;
	int color;
};

/**
* secondaryBuffer speichert den Inhalt des letzten Bildes, um somit Unterschiede speichern zu koennen.
*/
static rgConsoleBuffer secondaryBuffer[rgGameFieldxMax][rgGameFieldyMax];
static rgConsoleBuffer primaryBuffer[rgGameFieldxMax][rgGameFieldyMax];

int setFPS(unsigned int frameRate)
{
	if (frameRate > 100 || frameRate == 0)
	{
		return -1;
	}
	else
	{
		gameMaxFPS = frameRate;

		// Timerincrement aktualisieren:
		timerIncrement = static_cast<int>(1000 / gameMaxFPS);

		// FPS-Regelstandardwerte setzen:
		currentSleepTime = 1000 / gameMaxFPS;
		currentTime = osGetTickCount();
		lastTime = 0;
		frames = 0;
		timeDiff = 250;
		return 1;
	}
}

void drawOutput()
{
	string currentLine;
	for (unsigned int i = 0; rgGameFieldyMax > i; ++i)
	{
		// Alle Zeilen durchgehen
		currentLine = "";
		for (unsigned int k = 0; rgGameFieldxMax > k; ++k)
		{
			if (primaryBuffer[k][i].color != secondaryBuffer[k][i].color 
				|| primaryBuffer[k][i].letter != secondaryBuffer[k][i].letter)
			{
				// Dieses Zeichen muss aktualisiert werden
				osDrawCharPosition(k, i, primaryBuffer[k][i].letter, primaryBuffer[k][i].color);
				// Buffer speichern
				secondaryBuffer[k][i] = primaryBuffer[k][i];
			}
		}
	}

	// Frame-Rate-Anpassung durchfuehren:
	currentTime = osGetTickCount();

	while(osGetTickCount() < currentTime + currentSleepTime)
	{
	}

	//osSleep(currentSleepTime);
	frames++;
	currentTime = osGetTickCount();
	
	// In definierten Abstaenden die Zeitmessung aktualisieren:
	if(currentTime > lastTime + timeDiff)
	{
		if (lastTime != 0)
		{	
			// Die FrameRate berechnen:
			currentFPS =  frames * 1000.0 / (currentTime - lastTime);

			// Berechnungen fuer die FrameRate-Anpassung:
			double shouldPassedTime = frames * 1000.0 / gameMaxFPS;

			int oldSleepTime = currentSleepTime;
			currentSleepTime = currentSleepTime + static_cast<int>((shouldPassedTime - currentTime + lastTime) / (frames + 0.001));
			
			// Anstiegsbegrenzung hinzufuegen, um sprunghafte Aenderungen zu vermeiden:
			int maxSleepDiff = oldSleepTime / 10;
			if (abs(currentSleepTime - oldSleepTime) > maxSleepDiff)
			{
				if (currentSleepTime > oldSleepTime)
				{
					currentSleepTime = oldSleepTime + maxSleepDiff;	
				}
				else
				{
					currentSleepTime = oldSleepTime - maxSleepDiff;	
				}	
			}

		}

		if (currentSleepTime < 0)
		{
			currentSleepTime = 0;
		}
	
		lastTime = currentTime;
		frames = 0;
	}

}

void clearBackBuffer(char symbol)
{
	for (unsigned int i = 0; rgGameFieldyMax > i; ++i)
	{
		// Alle Zeilen durchgehen
		for (unsigned int k = 0; rgGameFieldxMax > k; ++k)
		{
			primaryBuffer[k][i].letter = symbol; 
		}
	}
}

int drawSymbol(int x, int y, char symbol, int color)
{
	if (true == checkValidRange(x,y))
	{
		/*
		* Eine Koordinatenanpassung ist hier notwendig, da das interne Array
		* outputWindow Indices von [0..79][0..23] besitzt, die Angaben allerdings
		* von [1..80][1..24] laufen sollen.
		*/
		primaryBuffer[x - 1][y - 1].letter = symbol; 
		primaryBuffer[x - 1][y - 1].color = color;
		return 1;
	}
	else
	{
		return -1;
	}
}

int drawHLine(int x, int y, const string &line, int color)
{
	if (true == checkValidRange(x,y) 
	 && true == checkValidRange(x + line.length(),y))
	{
		for (unsigned int i = 0; i < line.length(); ++i)
		{
			drawSymbol(x + i, y, line[i], color);
		}
		return 1;
	}
	else
	{
		return -1;
	}
}

int drawVLine(int x, int y, const string &line, int color)
{
	if (true == checkValidRange(x,y) 
	 && true == checkValidRange(x,y + line.length()))
	{
		for (unsigned int i = 0; i < line.length(); ++i)
		{
			drawSymbol(x, y + i, line[i], color);
		}
		return 1;
	}
	else
	{
		return -1;
	}
}

int drawLine(int x1, int x2, int y1, int y2, char symbol, int color)
{
	if (true == checkValidRange(x1,y1) 
	 && true == checkValidRange(x2,y2))
	{
		unsigned int xmin = 0;
		unsigned int xmax = 0;
		unsigned int ymin = 0;
		unsigned int ymax = 0;
		unsigned int i = 0;

		// Nach Groesse sortieren:
		if (x1 > x2)
		{
			xmin = x2;
			xmax = x1;
		}
		else
		{
			xmin = x1;
			xmax = x2;
		}
		if (y1 > y2)
		{
			ymin = y2;
			ymax = y1;
		}
		else
		{
			ymin = y1;
			ymax = y2;
		}

		// zuerst die horizontale Linie zeichnen:
		for (i = xmin; i <= xmax; ++i)
		{
			drawSymbol(i, y1, symbol, color);
		}

		// nun die vertikale Linie zeichnen:
		for (i = ymin; i <= ymax; ++i)
		{
			drawSymbol(x2, i, symbol, color);
		}

		return 1;
	}
	else
	{
		return -1;
	}
}