/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* Definition zu rgPakManTimings.h
*/

#include "rgBase/timedriver/rgTimedriver.h"


#include "rgPakMan/rgPakManGlobals.h"
#include "rgPakMan/rgPakManGhosts.h"
#include "rgPakMan/rgPakManTimings.h"

bool doCountdown(unsigned int timerHandle, unsigned int* currentTime)
{
	if (1 == finishedTimer(timerHandle))
	{
		--(*currentTime);
		runTimer(timerHandle);
		if (0 == (*currentTime))
		{
			return true;
		}
	}
	return false;
}

void incrementMegaPillTimer(unsigned int seconds)
{
	if (0 == seconds)
	{
		return;
	}

	if (pakManGame.megaPillActiveCounter == 0)
	{
		for (unsigned int k = 0; k < ghostCount; ++k)
		{
			setGhostMode(k, ghostAfraid);
		}
		
		pakManGame.megaPillBlinkingState = true;
		pakManGame.pointGhostMultiplicator = 1;
		runTimer(pakManGame.megaPillCountDownTimerHandle);
		

	}
	
	// Wenn im Blinkmodus, diesen beenden:
	if (pakManGame.megaPillActiveCounter > 0 
		&& pakManGame.megaPillActiveCounter <= megaPillWarningDuration 
		&& pakManGame.megaPillActiveCounter + seconds > megaPillWarningDuration)
	{
		pakManGame.megaPillBlinkingState = true;
		int res = stopTimer(pakManGame.megaPillBlinkTimerHandle);
		if (res != 1)
		{
			pakpak.pos.y = 10;
		}
	}
	pakManGame.megaPillActiveCounter += seconds;
}

