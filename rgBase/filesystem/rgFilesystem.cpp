/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* Definition zu rgFilesystem.h
*/






#include<iostream>
#include<string>
#include<fstream>

#include "rgBase/filesystem/rgFilesystem.h"
#include "rgCommon/rgGlobals.h"
#include "rgBase/cast/rgCast.h"
#include "rgBase/gfx/rgGfx.h"
#include "rgBase/input/rgInput.h"
#include "rgBase/structures/rgStructures.h"

using namespace std;


int saveConfig()
{
	
	fstream datei;
	datei.open("config.ini", ios::out); 
	{
		if(datei != 0)
		{
			datei << "MUSICENABLED="	<< boolToStr(config.musicEnabled) << endl;
			datei << "MUSICVOLUME="		<< config.musicVolume << endl;
			datei << "SOUNDENABLED="	<< boolToStr(config.soundEnabled) << endl;
			datei << "SOUNDVOLUME="		<< config.soundVolume << endl;
			datei << "KEYBOARDENABLED=" << boolToStr(config.keyboardEnabled) << endl;
			datei << "MOUSEENABLED="	<< boolToStr(config.mouseEnabled) << endl;
			datei << "JOYSTICKENABLED=" << boolToStr(config.joystickEnabled) << endl;
		}
		else
		{
		return -1; // Ich habe keinen zugriff auf die config Datei
		}
		datei.close();	
		return 1;
	}
}

void initConfig()
{
	config.soundEnabled = false;
	config.musicVolume = 0;
	config.musicEnabled = false;
	config.keyboardEnabled = true;
	config.joystickEnabled =false;
	config.mouseEnabled = false;
	config.soundVolume = 0;
	
	loadConfig();
}

int loadConfig()
{
	fstream datei;
	datei.open("config.ini", ios::in);
	if(true == datei.good())
	{
		datei.seekg(0, ios::beg);// Er soll vom Anfang der Datei anfangen

		string currentLine, command, value;
		int position;
		
		while(!datei.eof())
		{
			char currentLineC[1024];
			datei.getline(currentLineC, 1024);
			currentLine = currentLineC;

			if ("" != currentLine)
			{
				position = currentLine.find("="); // Sucht in currentLine das Zeichen "=" und gibt dessen Position im string zurueck
				if (0 != position)
				{
					command = currentLine.substr(0, position); // Kopiere die Zeichenkette vor dem "="
					value = currentLine.substr(position + 1); // Kopiere alles nach dem "=" ! TODO Jihad: Testen!
					if ("MUSICENABLED" == command)
					{
						config.musicEnabled = stringToBool(value);
					}
					else if ("SOUNDENABLED" == command)
					{
						config.soundEnabled = stringToBool(value);
					}
					else if ("MUSICVOLUME" == command)
					{
						config.musicVolume = stringToInt(value);
					}
					else if ("SOUNDVOLUME" == command)
					{
						config.soundVolume = stringToInt(value);
					}
					else if ("JOYSTICKENABLED" == command)
					{
						config.joystickEnabled = stringToBool(value);
					}
					else if ("MOUSEENABLED" == command)
					{
						config.mouseEnabled = stringToBool(value);
					}
					else if ("KEYBOARDENABLED" == command)
					{
						config.keyboardEnabled = stringToBool(value); 
					}
				
				}
			// Schleife Ende
			}
		}
		datei.close();	
		return 1;
	}
	else 
	
		return -1;
	
}

int saveHighscore()
{
	fstream Highscore;
	if(Highscore != 0) //wenn die Datei vorhanden sind => mach die untere Anweisung ! und return 1 wenn nicht return -1 
	{
		Highscore.open("highscore.ini", ios::out);
		{
			for (int i = 0; i<2; ++i)
				{
					if (0 == i)
					{
						// Schreibe highscore fur rgPakMan
						Highscore << "GAME=PAKMAN" << endl;
						for (int k = 0; k<10; ++k)
						{
							Highscore << "NR=" << k << endl; 
							Highscore << "NAME=" << highScorePakMan[k].player << endl;
							Highscore << "POINTS=" << highScorePakMan[k].points << endl;
							Highscore << "DATE=" << highScorePakMan[k].date << endl;
						}

					}
					else 
					{
						// Schreibe highscore fur Snake
						Highscore << "GAME=SNAKE" << endl;
						for (int k=0; k < 10; ++k)
						{
							Highscore << "NR=" << k << endl;
							Highscore << "NAME=" << highScoreSnake[k].player << endl;
							Highscore << "POINTS=" << highScoreSnake[k].points << endl; 
							Highscore << "DATE=" << highScoreSnake[k].date << endl;
						}
					}//fuer else
				}// fuer for 
			Highscore.close();	
			return 1;
		}//fuer highscore
	}
	else
	{
		return -1; // Ich habe keinen Zugriff auf die Datei => spieler hat Pech.
	}
}// fuer die gesamte funktion

int loadHighscore()
{
	fstream datei;
	datei.open("highscore.ini", ios::in); 
	if(true == datei.good())
	{
		datei.seekg(0, ios::beg);// Er soll vom Anfang der Datei anfangen

		string currentLine, command, value;
		int position, currentGame, currentItem;
		currentGame = 0;
		currentItem = 0;
		
		while(!datei.eof())
		{
			char currentLineC[1024];
			datei.getline(currentLineC, 1024);
			currentLine = currentLineC;
		
			if ("" != currentLine)
			{
				position = currentLine.find("="); // Sucht in currentLine das Zeichen "=" und gibt dessen Position im string zurueck
				if (0 != position)
				{
					command = currentLine.substr(0, position); // Kopiere die Zeichenkette vor dem "="
					value = currentLine.substr(position + 1); // Kopiere alles nach dem "=" ! TODO Jihad: Testen!
					if ("GAME" == command)
					{	
						if ("PAKMAN" == value)
						{
							currentGame = 0; 
						}
						else if ("SNAKE" == value)
						{
							currentGame = 1;
						}
					}
					else if ("NR" == command)
					{
						currentItem = stringToInt(value);
						if (currentItem < 0 || currentItem >= 10)
						{
							// Fehler! Nr falsch angegeben -> Datei beschaedigt, Standardwert laden
							currentItem = 0;
						}
					}
					else if ("NAME" == command)
					{
						if (0 == currentGame)
						{
							highScorePakMan[currentItem].player = value; // Schreibe Pakman
						}
						else
						{
							highScoreSnake[currentItem].player = value; // Schreibe Snake
						}
					}
					else if("POINTS" == command)
					{
						if (0 == currentGame)
						{
							highScorePakMan[currentItem].points = stringToInt(value); // Schreibe Pakman
						}
						else
						{
							highScoreSnake[currentItem].points = stringToInt(value); // Schreibe Snake
						}
					}
					else if("DATE" == command)
					{
						if (0 == currentGame)
						{
							highScorePakMan[currentItem].date = value; // Schreibe Pakman
						}
						else
						{
							highScoreSnake[currentItem].date = value; // Schreibe Snake
						}
					}
				}
			}
		}
		datei.close();
		return 1;
	}
	else
	{
		return -1;
	}
}