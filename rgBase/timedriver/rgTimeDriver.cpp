/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* Definition zu rgTimeDriver.h
*/

#include "rgBase/timedriver/rgTimeDriver.h"
#include "rgCommon/rgGlobals.h"


// rgTimer is eine Struktur die Eigenschaften der Timre speicher
struct rgTimer 
{
	bool reserved;  // Ist der Timer reserviert?
	bool finished;  // Sobald der Timer abgelaufen ist, wird finished true
	bool enabled;	// AN oder AUS
	int time;		// laufende Zeit in ms
	int max;	    // Sollwert der Zeit in ms
};

static rgTimer timers[100];

void initTimers()
{
	for (int i=0; i<100; i++)
	{
		timers[i].enabled = false;
		timers[i].finished = false;
		timers[i].max = 0;
		timers[i].reserved = false;
		timers[i].time = 0;
	}
}

void incrementTimer()
{
	for (int i=0; i<100; i++)
	{
		if (timers[i].enabled && timers[i].reserved)
		{
			timers[i].time += timerIncrement;        // erhoehe jedes Mal um x ms
			if (timers[i].time >= timers[i].max)
			{
				// Timer ist fertig
				timers[i].enabled = false;
				timers[i].finished = true;
				timers[i].time = 0;
			}
		}
	}
}

int createTimer(unsigned int ms)
{
	for (int i = 0; i < 100; ++i)
	{
		if (false == timers[i].reserved)
		{

			timers[i].finished = false;  
			timers[i].reserved = true;  // Timer wird benutzt
			timers[i].enabled = false;  // Timer wird noch nicht aktiviert
			timers[i].time = 0;         // timer startet von 0
			timers[i].max = ms;         // reset value wird auf den Eingabeparameter gestellt
			return i;					// gibt aus das indize von speicher benutzt
		}
	}
	return -1;                   //es wurde kein freier Speicher gefunden
}

int deleteTimer(unsigned int &id)
{
	if (id < 100)                      //ueberprueft wenn es kleiner das die maximale grosse nicht uberschritten ist
	{
		if (true == timers[id].reserved) // wenn das Speicher mt  Index id noch nicht benutzt wird dann gib aus -1
		{
			timers[id].enabled = false;
			timers[id].reserved = false;
			timers[id].finished = false; 
			timers[id].max=0;
			timers[id].time=0;
			id = 0;
			return 1;
		}
		else
		{	
			return -1;
		}
	}
	else
	{
		return -2; // Index groesser als maximale Groesse, gibt aus -2
	}
}

int finishedTimer(unsigned int id)
{
	if (id > 100)
	{
		return -2; // Index ungueltig
	}
	else
	{
		if (true == timers[id].finished)
		{
			timers[id].finished = false;
			return 1;
		}                  
		else
		{
			return -1;
		}
	}
}

int stopTimer(unsigned int id)
{
	if (id < 100) // Ueberprueft ob die maximale grosse nicht uberschritten ist
	{
		if (false == timers[id].reserved) // wenn der Speicher mit  Index iz noch nicht benutzt wird, dann gib aus 1, sonst -1
		{
			return -1;
		}
		else
		{
			// Timer anhalten
			timers[id].enabled = false;
			timers[id].finished = false;
			timers[id].time = 0;
			return 1;
		}
	}
	else
	{	
		return -2; // Index ungueltig
	}
}

int runTimer (unsigned int id)
{
	if (id<100)  // Ueberprueft ob die maximale grosse nicht uberschritten ist
	{
		if (false == timers[id].reserved) 
		{
			return -1;
		}
		else
		{
			timers[id].time = 0;
			timers[id].finished = false;
			timers[id].enabled = true;
			return 1;
		}
	}
	else
	{
		return -2; // Index groesser als maximale Groesse
	}
}