/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* Definition zu rgMenu.h
*/

#include "rgBase/gfx/rgGfx.h"
#include "rgPakMan/rgPakMan.h"
#include "rgSnake/rgSnake.h"
#include "rgBase/filesystem/rgFilesystem.h"
#include "rgMenu/rgMenu.h"

#include "rgCommon/rgGlobals.h"
#include "rgBase/cast/rgCast.h"
#include "rgCommon/rgHighScore.h"


bool mnJoystickEnabled ;
bool mnMouseEnabled ;
bool mnMusicEnabled;
bool mnSoundEnabled;
bool mnKeyboardEnabled ;

unsigned int mnSoundVolume ;
unsigned int mnMusicVolume ;
int mnCurrentSubMenu = 0;

string mnInputName;

void displayMainMenu() // Hauptmenue 
{

	drawHLine(20, 2, "Retro-Games");
	drawHLine(20, 4, "Hauptmenue");
	drawHLine(6, 7, "PakMan Starten");
	drawHLine(6, 8, "Snake Starten");
	drawHLine(6, 9, "Optionen");
	drawHLine(6, 10, "Highscore-Listen");
	drawHLine(6, 11,"Team Retro-Games");
	drawHLine(6, 13, "Beenden");
	
	drawHLine(20, 20, "Projekt Retro-Games ");
	drawHLine(20, 21, "Betreuer Prof. Dr. Weber");
	drawHLine(20, 22, "Betreuer Prof. Dr. Kriesten");
}

string boolToOnOff(bool mnInput) // 
{
	if (true == mnInput)
	{
		return "EIN";
	}
	else
	{
		return "AUS";
	}
}


void displayNameInput()
{
	drawHLine(20,2, "Bitte geben Sie Ihren Namen ein:");
	drawHLine(20,10, mnInputName, rgRed);
}

void displayConfigMenu()  // Configurationsmenu Display
{

	drawHLine(20, 2, "Retro-Games");
	drawHLine(20, 4, "Optionsmenue");
	drawHLine(6, 7, "Musik"); 
	drawHLine(6, 8, "Musiklautstaerke"); 
	drawHLine(9, 9, "-----------");
	drawHLine(6, 10, "Sound"); 
	drawHLine(6, 11, "Soundlautstaerke");
	drawHLine(9, 12, "-----------");
	drawHLine(6, 13, "Maus"); 
	//drawHLine(6, 14, "Joystick"); 
	drawHLine(6, 15, "Uebernehmen");
	drawHLine(6, 16, "Zurueck"); 
	drawHLine(20, 20, "Projekt Retro-Games ");
	drawHLine(20, 21, "Betreuer Prof. Dr. Weber");
	drawHLine(20, 22, "Betreuer Prof. Dr. Kriesten");

	// fuer die Status
	drawHLine (30,7,boolToOnOff(mnMusicEnabled),5);		// Music EIN oder AUS 
	drawHLine (30,10,boolToOnOff(mnSoundEnabled),5);	// Sound EIN oder AUS
	drawHLine (30,13,boolToOnOff(mnMouseEnabled),5);	//MAUS EIN oder AUS
	//drawHLine (30,14,boolToOnOff(mnJoystickEnabled),5); //Joystick EIN oder AUS
	// Die Farben des Balken wenn EIN -> farbe rot 
	//						 wenn AUS -> farbe grau
	int color;
	if(true == mnMusicEnabled)
	{
		color = rgRed;
	}
	else
	{
		color = rgGrey;
	}
	drawSymbol(mnMusicVolume / 10 + 9, 9, '|', color); // Music Balken

	if(true == mnSoundEnabled)
	{
		color = rgRed;
	}
	else
	{
		color = rgGrey;
	}
	drawSymbol(mnSoundVolume / 10 + 9, 12, '|', color); // Sound Balken

} 
void displayHighscore() // Highscore Menu 
{
	drawHLine(20, 2, "Retro-Games");
	drawHLine(20, 4,"Highscore-Listen" );
	drawHLine(6, 7, "Highscore PakMan");
	drawHLine(6, 8, "Highscore Snake");
	drawHLine(6, 10, "Zurueck"); 
	drawHLine(20, 20, "Projekt Retro-Games ");
	drawHLine(20, 21, "Betreuer Prof. Dr. Weber");
	drawHLine(20, 22, "Betreuer Prof. Dr. Kriesten");			
}
void displayHighscorePakMan()
{
	drawHLine(20, 2, "Retro-Games");
	drawHLine(20, 4, "PakMan Highscore-Liste");
	drawLine(10 , 52,7 ,7 , '-', 2);
	drawLine(13 , 13,6 ,17, '|', 2);
	drawLine(30 , 30,6 ,17, '|', 2);
	drawLine(40 , 40,6 ,17, '|', 2);
	drawHLine(10,6,"Nr:",3);
	drawHLine(18,6,"Spieler:",3);
	drawHLine(32,6,"Punkte:",3);
	drawHLine(44,6,"Datum:" ,3);
	drawHLine(60, 15, "Zurueck");
	drawHLine(59,15,">",rgGreen);
	drawHLine(20, 20, "Projekt Retro-Games ");
	drawHLine(20, 21, "Betreuer Prof. Dr. Weber");
	drawHLine(20, 22, "Betreuer Prof. Dr. Kriesten");
}
void displayHighscoreSnake()
{
	drawHLine(20, 2, "Retro-Games");
	drawHLine(20, 4, "Snake Highscore-Liste");
	drawLine(10 , 48,7 ,7 , '-', 2);
	drawLine(13 , 13,6 ,17, '|', 2);
	drawLine(30 , 30,6 ,17, '|', 2);
	drawLine(40 , 40,6 ,17, '|', 2);
	drawHLine(10,6,"Nr:",3);
	drawHLine(18,6,"Spieler:",3);
	drawHLine(32,6,"Punkte:",3);
	drawHLine(42,6,"Datum:" ,3);
	drawHLine(60, 15, "Zurueck");
	drawHLine(59,15,">",rgGreen);
	drawHLine(20, 20, "Projekt Retro-Games ");
	drawHLine(20, 21, "Betreuer Prof. Dr. Weber");
	drawHLine(20, 22, "Betreuer Prof. Dr. Kriesten");
	
}

void diplayTeamRetroGames()
{
	drawHLine(20, 2, "Retro-Games");
	drawHLine(20, 4, "Team Retro-Games");
	
	drawHLine (6, 7, "Jihad Alayan");
	drawHLine (6, 8, "Thanh Di Duong ");
	drawHLine (6, 9, "Robin Krumm");
	drawHLine (6, 10, "Ciurus Sever");
	drawHLine (6, 11, "Clemens Zangl");

	drawHLine (6, 13, "Zurueck");
	drawHLine (20,16, "Wir wuenschen euch viel Erfolg !!",2);
	drawHLine (20,17, "Retro-Games Team",2); 
	drawHLine (20, 20, "Projekt Retro-Games ");
	drawHLine (20, 21, "Betreuer Prof. Dr. Weber");
	drawHLine (20, 22, "Betreuer Prof. Dr. Kriesten");
	
}
void drawMainMenu()
{
		//Steuerung des Cursers
		static int mnCurrentMenu = 1;
		if (true == keys.keyUp)
			{
				 --mnCurrentMenu;
			}
		else if (true == keys.keyDown)
			{
				 ++mnCurrentMenu;
			}

//Y-Position des Cursors setzen:
	
	int ypos;
	if (1 > mnCurrentMenu)
	{
		mnCurrentMenu = 6;
	}
	if (7 ==  mnCurrentMenu)
	{
		 mnCurrentMenu = 1;
	}

	switch (mnCurrentMenu)
			{

			case 1: //PaKMan starten
					ypos = 7;
					if(true == keys.keyReturn)
					{
						initPakMan(); // Spiel PakMan wird gestartet
						gameMode = rgPakMan;
					}
					break;					
			case 2: //Snake starten
					ypos = 8;
				
					if(true == keys.keyReturn)
					{
						
						startSnake(); // Spiel Snake wird gestartet
						gameMode = rgSnake;
					}
					break;
			case 3://Optionen Menu
					ypos = 9;
					if(true == keys.keyReturn)
					{
						mnCurrentDisplayedMenu = 1; // => OptionenMenu wird angezeigt siehe runMenu();
						mnSoundEnabled = config.soundEnabled;
						mnMusicEnabled = config.musicEnabled;
						mnKeyboardEnabled = config.keyboardEnabled;
						mnMouseEnabled = config.mouseEnabled;
						mnJoystickEnabled = config.joystickEnabled;
						mnSoundVolume = config.soundVolume;
						mnMusicVolume = config.musicVolume;
					}
					break;
					
			case 4: //Highscore-Listen
					ypos = 10;
					if(true == keys.keyReturn)
					{
						mnCurrentDisplayedMenu = 2;// Highscore-Listen Menu wird angezeigt siehe runMenu();
					}
					break;
			case 5:  //Team Retro Games
					ypos = 11;
					if(true == keys.keyReturn)
					{
						mnCurrentDisplayedMenu = 3;// Team Retro-Games wird angezeigt siehe runMenu();
					}
					break;
					
			case 6://Beenden
					ypos = 13;
					if(true == keys.keyReturn)
					{
							programMode = rgStopped;
					}
					break;			
		}//for switch
		
// Cursor anzeigen:
drawSymbol(5, ypos, '>', rgGreen); 	
}

void drawConfigMenu()
{
	// Steuerung der Pfeiltasten 
	static int mnOldMenu;
	static int mnCurrentConfigMenu = 1;
	
	mnOldMenu = mnCurrentConfigMenu;

	if (true == keys.keyUp)
		{
			 --mnCurrentConfigMenu;
		}
	else if (true == keys.keyDown)
		{
			 ++mnCurrentConfigMenu;
		}
	//YPosition des Cursors setzen:
	int ypos;
	int xpos;// Da die X-Koordinate nicht immer Konstant ist, ist es hier als variable definiert

	if (mnCurrentConfigMenu < 1)// wenn der Curser oben im Auswahl ist,und der obere Pfeiltaste betaetigt ist , springe nach unten.
	{
		mnCurrentConfigMenu = 7;
	}

	else if (2 == mnCurrentConfigMenu && false == mnMusicEnabled) // wenn Music Aus ueberspringt er den Musicregler
	{
		if (mnOldMenu == 1)
		{
			mnCurrentConfigMenu = 3;
		}
		else
		{
			mnCurrentConfigMenu = 1;
		}
	}
	else if (4 == mnCurrentConfigMenu && false == mnSoundEnabled)// wenn Sound Aus ueberspringt er den Soundregler
	{
		if (mnOldMenu == 3)
		{
			mnCurrentConfigMenu = 5;
		}
		else
		{
			mnCurrentConfigMenu = 3;
		}
	}
	else if(8 == mnCurrentConfigMenu) // wenn der Curser unten im Auswahl ist , und untere Pfeiltaste betäetigt springe nach oben 
	{
		mnCurrentConfigMenu = 1;
	}

	switch (mnCurrentConfigMenu)
	{
	case 1:// Enable Music
		ypos = 7;
		xpos = 5;
		if (true == keys.keyReturn)
		{
			mnMusicEnabled = !mnMusicEnabled; // invertiert wenn true und enter gedruekt wird 							// wird currentStatus false
		}
		break;	
	case 2://Music Balken
		ypos = 9;
		xpos = 8;							// Der Curser ist eine Stelle vor dem Volumenregler ----------
		drawVolumeBar(mnMusicVolume, 9);					// Mit dieser Funktion wird der Balken gesteuert und angezeigt
		break;	  
	case 3: //Enable Sound
		ypos = 10;
		xpos = 5;
		if (true == keys.keyReturn)
		{
			mnSoundEnabled = !mnSoundEnabled;  // invertiert wenn true und enter gedruekt wird 							 // wird currentStatus false
		}
		break;
	case 4://Sound Balken 
		ypos = 12;						// Der Curser ist eine Stelle vor dem Volumenregler ----------
		xpos = 8;						
		drawVolumeBar(mnSoundVolume, 12);
		break;
	case 5: //Enable Mouse
		ypos = 13;
		xpos = 5;
		if (true == keys.keyReturn)
		{	
			mnMouseEnabled = !mnMouseEnabled; //Invertiert
		}					
		break;
	/*
	case 6://Enable Joystick
		ypos = 14;
		xpos = 5;
		if (true == keys.keyReturn)
		{
			mnJoystickEnabled = !mnJoystickEnabled; //Invertiert
		}
		break;
		*/
	case 6: //speichern
		ypos = 15;
		xpos = 5;
		if(true == keys.keyReturn)
		{
			// Konfiguration uebernehmen:
			config.keyboardEnabled = mnKeyboardEnabled;
			config.mouseEnabled = mnMouseEnabled;
			config.musicEnabled = mnMusicEnabled;
			config.soundEnabled = mnSoundEnabled;
			config.musicVolume = mnMusicVolume;
			config.soundVolume = mnSoundVolume;
			config.joystickEnabled = mnJoystickEnabled;
			mnCurrentDisplayedMenu = 0; // springt in Main Menu
		}
		break;
	case 7: //zurueck
		ypos = 16;
		xpos = 5;
		if(true == keys.keyReturn)
		{
			mnCurrentDisplayedMenu = 0; // MainMenu wird angezeigt siehe runMenu();
		}
		break;
	}//for switch
	drawSymbol(xpos, ypos, '>', rgGreen); 	// Cursor anzeigen:
}
void drawHighscore()
{
		static int mnCurrentHighscore = 1;
		if (true == keys.keyUp)
			{
				 --mnCurrentHighscore;
			}
		else if (true == keys.keyDown)
			{
				 ++mnCurrentHighscore;
			}

//YPosition des Cursors setzen:
	
	int ypos;
	if ( 1 > mnCurrentHighscore)
	{
		mnCurrentHighscore = 3;
	}
	if (4 == mnCurrentHighscore)
	{
		mnCurrentHighscore = 1;
	}
	switch (mnCurrentHighscore)
			{
			case 1:// Highscore PakMan
					ypos =7;
					if(true == keys.keyReturn)
					{	
						mnCurrentSubMenu = 1;	
					}
					break;					
			case 2://Highscore Snake
					ypos = 8;
					if(true == keys.keyReturn)
					{
						mnCurrentSubMenu = 2;	
					}
					break;
					
			case 3: //Return
					ypos = 10;
					if(true == keys.keyReturn)
					{
						mnCurrentDisplayedMenu = 0;
					}
					break;
		}//for switch
// Cursor anzeigen:
drawSymbol(5, ypos, '>', rgGreen); 	
}

void drawTeamRetroGames()// Team Reto-Games
{
	//Curser anzeigen
	drawSymbol(5, 13, '>', rgGreen); 	
	if(true == keys.keyReturn)
		{
			mnCurrentDisplayedMenu = 0;
		}
}
void drawHighscorePakMan()// Team Reto-Games
{
	//Curser anzeigen
	drawHLine(59,15,">",rgGreen);	
	if(true == keys.keyReturn)
		{
				mnCurrentSubMenu = 0;
		}
	for(int k =0; k < 10  ; k++)
	{
			drawHLine (11,k + 8,ToString(k + 1) , rgBlue);
			//drawHLine(18,k+8, mnInputName, rgRed);
			drawHLine(18,k+8, highScorePakMan[k].player, rgRed);
			drawHLine(32,k+8, ToString(highScorePakMan[k].points), rgPurple);
			drawHLine(42,k+8, highScorePakMan[k].date, rgGreen);

	}
}
void drawHighscoreSnake()// Team Reto-Games
{
	//Curser anzeigen
	drawHLine(59,15,">",rgGreen);	
	if(true == keys.keyReturn)
		{
			mnCurrentSubMenu = 0;
		}
		for(int k =0; k < 10  ; k++)
	{
			drawHLine (11,k + 8,ToString(k + 1) , rgBlue);
			drawHLine(18,k+8, highScoreSnake[k].player, rgRed);
			drawHLine(32,k+8, ToString(highScoreSnake[k].points), rgPurple);
			drawHLine(42,k+8, highScoreSnake[k].date, rgGreen);

	}
}

void drawVolumeBar(unsigned int &volume, int y)
{
	int mnCurrentStatus;
	mnCurrentStatus = volume / 10; 
	//Steuerung des Cursers
	if (true == keys.keyLeft)
	{
		 --mnCurrentStatus;
	}
	else if (true == keys.keyRight)
	{
		 ++mnCurrentStatus;
	}
	// Volumen wird nur zwischen 0 und 10  geregelt
	if (mnCurrentStatus >= 10)
	{
		mnCurrentStatus = 10;
	}
	else if (mnCurrentStatus < 0)
	{
		mnCurrentStatus = 0;
	}

	int xpos = mnCurrentStatus;
	volume = xpos * 10; // wenn Curser an der ersten Stelle ist ist Volumen gleich 10 ...
 }
void runHighscore()
{
	switch(mnCurrentSubMenu)
	{
	case 0 :
		displayHighscore();
		drawHighscore();
		break;
	case 1:
		displayHighscorePakMan();
		drawHighscorePakMan();
		break;		
	case 2:
		displayHighscoreSnake();
		drawHighscoreSnake();
		break;
	}
}

void highScoreInput()
{
	
	if (true == keys.keyA)
	{
		mnInputName += "A";
	}
	else if(true == keys.keyB)
	{
		mnInputName += "B";
	}
	else if (true == keys.keyC)
	{
		mnInputName += "C";
	}
	else if(true == keys.keyD)
	{
		mnInputName += "D";
	}
	else if (true == keys.keyE)
	{
		mnInputName += "E";
	}
	else if (true == keys.keyF)
	{
		mnInputName += "F";
	}
	else if (true == keys.keyG)
	{
		mnInputName += "G";
	}
	else if(true == keys.keyH)
	{
		mnInputName += "H";
	}
	else if (true == keys.keyI)
	{
		mnInputName += "I";
	}
	else if(true == keys.keyJ)
	{
		mnInputName += "J";
	}
	else if (true == keys.keyK)
	{
		mnInputName += "K";
	}
	else if (true == keys.keyL)
	{
		mnInputName += "L";
	}
	else if(true == keys.keyM)
	{
		mnInputName += "M";
	}
	else if (true == keys.keyN)
	{
		mnInputName += "N";
	}
	else if(true == keys.keyO)
	{
		mnInputName += "O";
	}
	else if (true == keys.keyP)
	{
		mnInputName += "P";
	}
	else if (true == keys.keyQ)
	{
		mnInputName += "Q";
	}
	else if (true == keys.keyR)
	{
		mnInputName += "R";
	}
	else if(true == keys.keyS)
	{
		mnInputName += "S";
	}
	else if (true == keys.keyT)
	{
		mnInputName += "T";
	}
	else if(true == keys.keyU)
	{
		mnInputName += "U";
	}
	else if (true == keys.keyV)
	{
		mnInputName += "V";
	}
	else if (true == keys.keyW)
	{
		mnInputName += "W";
	}
	else if(true == keys.keyX)
	{
		mnInputName += "X";
	}
	else if (true == keys.keyY)
	{
		mnInputName += "Y";
	}
	else if (true == keys.keyZ)
	{
		mnInputName += "Z";
	}
	else if (true == keys.keyBackspace)
	{
		mnInputName = mnInputName.substr(0, mnInputName.length() - 1);
	}
	else if (true == keys.keySpace)
	{
		mnInputName += " ";
	}
	if (mnInputName.length() > 10)
	{
		mnInputName = mnInputName.substr(0,10);
	}

	if (true == keys.keyReturn)
	{
		addHighscore(mnInputName, highScorePoints, highScoreGame);
		mnInputName = "";
		mnCurrentDisplayedMenu = 0;
	}
}

void runMenu()
{
	//welches Menue soll angezeigt werden ? 
	switch (mnCurrentDisplayedMenu)
	{
	case 0:
		// wenn currentDisplayedMenu = 0, Main Menue und der Mainmenu Curser  werden dargestellt
		displayMainMenu();
		drawMainMenu();
		break;
	case 1:
		// wenn currentDisplayedMenu = 1, ConfigurationsMenu und der Configurationsmenu Curser werden dargestellt
		displayConfigMenu();
		drawConfigMenu();
		break;
	case 2:
		// wenn currentDisplayedMenu = 2, Highscore Menu und der Highscorescurser werden dargestellt
		runHighscore();
		break;
	case 3:
		// wenn currentDisplayedMenu = 3, Die Namensliste wird dargestellt
		diplayTeamRetroGames();
		drawTeamRetroGames();
		break;
	case 4:
		// wenn currentDisplayedMenu = 4, kann der Spieler seinen Namen eintragen.
		displayNameInput();
		highScoreInput();
		break;
	}
}
