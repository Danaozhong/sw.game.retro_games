/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* Definition zu rgAudio.h
*/

#include <string>
#include <fstream>

#include "rgBase/audio/rgAudio.h"
#include "rgBase/structures/rgStructures.h"

#include "rgCommon/rgGlobals.h"

#include "lib/fmod/fmod.hpp"
#include "lib/fmod/fmod_errors.h"

using namespace std;

namespace
{
	/**
	* Hilfsfunktion, um die Rueckgabewerte der FMOD-Funktion zu pruefen
	*/
	void FmodErrorCheck(FMOD_RESULT result)
	{		
		if (result != FMOD_OK)
		{
			printf("FMOD Error! (%d) %s\n", result, FMOD_ErrorString(result));
			exit(-1);
		}
	}

	
	struct rgAudioBuffer
	{
		int type;
		FMOD::Sound* handle;
		int volume;
		bool used;
		int channelId;
	};

	struct rgAudioChannel
	{
		bool used;
		FMOD::Channel* audioChannel;
	};

	FMOD::System* fmodSystem;

	unsigned int audioBufferCount;
	rgAudioBuffer audioBuffer[100]; 

	unsigned int audioChannelCount;
	rgAudioChannel audioChannel[32]; 

	bool alreadyInitialized = false;
}

void initAudio(void)
{
	FMOD_RESULT result; 
	result = FMOD::System_Create(&fmodSystem);
	FmodErrorCheck(result);
 
	result = fmodSystem->init(32, FMOD_INIT_NORMAL, 0);
	FmodErrorCheck(result);
	alreadyInitialized = true;
}


int findFreeAudioBuffer()
{
	for (int i = 0; i < 100; ++i)
	{
		if (false == audioBuffer[i].used)
		{
			return i;
		}		
	}
	return -1;
}

int createAudioBufferFromFile(const string &filename, int audiotype)
{
	if(((true == config.soundEnabled)&&((audiotype ==1)||audiotype==0)) || ((true == config.musicEnabled)&&((audiotype ==2)||audiotype==0)))
	{	
		
		if (false == alreadyInitialized)
		{
			initAudio();
		}
		// Mache einen Dateitest
		ifstream FileTest(filename.c_str());
		if (FileTest)
		{
			FMOD_RESULT result;
			int audioBufferCount = findFreeAudioBuffer();

			result =  fmodSystem->createSound(filename.c_str(), FMOD_SOFTWARE,0, &audioBuffer[audioBufferCount].handle);
			FmodErrorCheck(result);
			audioBuffer[audioBufferCount].used = true;
			audioBuffer[audioBufferCount].type = audiotype;

			return audioBufferCount;
		}
		else
		{
			return -2;
		}
		
	}
	else
	{
		return -1;
	}
}

int findFreeAudioChannel()
{
	for (int i = 0; i < 32; ++i)
	{
		bool isPlaying = false;
		audioChannel[i].audioChannel->isPlaying(&isPlaying);

		if (false == isPlaying)
		{
			return i;
		}
	}
	return -1;
}

void setChannelVolume(int channelId, int volume)
{
	audioChannel[channelId].audioChannel->setVolume(volume / 100.0f);
}

int playAudioBuffer(int bufferId, bool loop)
{
	if (bufferId < 0 || bufferId >= 100)
	{
		return -2;
	}
	if (true == audioBuffer[bufferId].used) 
	{
		int channelId = findFreeAudioChannel();
		if (true == loop)
		{
			audioBuffer[bufferId].handle->setMode(FMOD_LOOP_NORMAL);
		}
		fmodSystem->playSound(FMOD_CHANNEL_FREE, audioBuffer[bufferId].handle, false, &audioChannel[channelId].audioChannel);
		audioBuffer[bufferId].channelId = channelId;
		setChannelVolume(channelId, audioBuffer[bufferId].volume);	
		return 1;	
	}			
	else
	{
		return -1;
	}
}


int setAudioBufferVolume(int bufferId, int volume)
{
	if ((0<=volume)&&(volume<=100))
	{
		if (true == audioBuffer[bufferId].used) 
		{	
			audioBuffer[bufferId].volume = volume;
			return 1;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return -2;
	}
}


int setAllAudioBufferVolume(int audiotype,int volume)
{
	if ((0<=volume)&&(volume<=100))
	{
		for (int i=0; i<100;++i)
		{
			if (true == audioBuffer[i].used)
			{
				// Aendere nur das Volumen, wenn der Buffer reserviert ist
				if ((audiotype==audioBuffer[i].type)||(audiotype==0))
				{
					setAudioBufferVolume(i, volume);
				}
			}
		}
	}
	return 1;
}



int stopAudioBuffer(int bufferId)
{	
	audioChannel[audioBuffer[bufferId].channelId].audioChannel->stop();
	return 1;
}

int stopAllAudioBuffer(int audiotype)
{
	for (int i=0; i<100;++i)
	{
		if (true == audioBuffer[i].used) 
		{
			if ((audiotype==audioBuffer[i].type)||(audiotype==0))
			{
				audioChannel[audioBuffer[i].channelId].audioChannel->stop();
			}
		}
	}
	return 1;
}

int deleteAudioBuffer(int bufferId)
{
	if(audioBuffer[bufferId].used == true)
	{
		stopAudioBuffer(bufferId);
		audioBuffer[bufferId].used = false;
		audioBuffer[bufferId].handle->release();		
	}
	return 1;
}

int stopAudio(void)
{
	for (int i = 0; i < 100; ++i)
	{
		deleteAudioBuffer(i);
	}
	fmodSystem->release();
	
	return 0;
}

