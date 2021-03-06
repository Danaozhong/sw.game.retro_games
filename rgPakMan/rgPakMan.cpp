/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* Definition zu rgPakMan.h
*/

#include "rgCommon/rgGlobals.h"
#include "rgCommon/rgMisc.h"
#include "rgBase/cast/rgCast.h"
#include "rgCommon/rgHighScore.h"

#include "rgBase/gfx/rgGfx.h"
#include "rgBase/timedriver/rgTimeDriver.h"
#include "rgBase/os/rgCharSet.h"
#include "rgBase/audio/rgAudio.h"

#include "rgPakMan/rgPakManStructures.h"
#include "rgPakMan/rgPakManGlobals.h"
#include "rgPakMan/rgPakManMap.h"
#include "rgPakMan/rgPakManGhosts.h"
#include "rgPakMan/rgPakManDynamics.h"
#include "rgPakMan/rgPakManTimings.h"
#include "rgPakMan/rgPakManOutput.h"
#include "rgPakMan/rgPakMan.h"

using namespace std;

void runPakMan()
{
	// Hole die Eingaben ab
	getPakPakDesiredDirection();
	
	// Gebe die Kontrolle des Spieles an die jeweiligen Funktionsteile ab
	switch (pakManGame.gameMode)
	{
	case pakManGameRunning:
		runGame();
		break;
	case pakManGamePaused:
		pauseGame();
		break;
	case pakManGameGameOver:
		overGame();
		break;
	case pakManGameWaiting:
		getReadyGame();
		break;
	case pakManGameWin:
		winGame();
		break;
	}
}

void getPakPakDesiredDirection()
{
	// Steuerung pruefen:
	if (true == keys.keyUp)
	{
		pakpak.desiredDirection = directionUp;
	}
	else if (true == keys.keyRight)
	{
		pakpak.desiredDirection = directionRight;

	}
	else if (true == keys.keyDown)
	{
		pakpak.desiredDirection = directionDown;

	}
	else if (true == keys.keyLeft)
	{
		pakpak.desiredDirection = directionLeft;

	}
}


void changeGameMode(int gameMode)
{

	// Beim Wechsel von warten in laufen muessen alle Timer gestartet werden
	
	// Beim Starten von Wechsel muss, wenn bisher nicht im Wechselmodus,
	// alle Positionen zurueckgesetzt werden und alle Timer gestoppt werden
	if (pakManGameWaiting == gameMode && pakManGame.gameMode != pakManGameWaiting)
	{
		// stoppe alle Timer und setzte Figuren zurueck
		for (unsigned int i = 0; i < ghostCount; ++i)
		{
			stopTimer(ghosts[i].directionChangeTimerHandle);
			setGhostMode(i, ghostDefault);
			ghosts[i].pos.x = pakManGame.ghostHeadquarterx;
			ghosts[i].pos.y = pakManGame.ghostHeadquartery;
		}
		pakManGame.megaPillActiveCounter = 0;
		pakManGame.megaPillBlinkingState = true;
		stopTimer(pakManGame.megaPillCountDownTimerHandle);
		stopTimer(pakManGame.megaPillBlinkTimerHandle);

		pakpak.pos.x = pakPakStartPosx;
		pakpak.pos.y = pakPakStartPosy;
		if (maxPakManLives == pakManGame.lives)
		{
			// Spielbeginn
			playAudioBuffer(pakManGame.soundBufferIntro);
		}
		else
		{
			// Leben verloren
			playAudioBuffer(pakManGame.soundBufferLost);
		}
	}

	if (pakManGameGameOver == gameMode
		|| pakManGameWaiting == gameMode
		|| pakManGameWin == gameMode)
	{
		pakManGame.waitTime = 3;
		runTimer(pakManGame.waitTimerHandle);
	}

	if (pakManGameGameOver == gameMode)
	{
		stopAudioBuffer(pakManGame.musicBuffer);
		playAudioBuffer(pakManGame.soundBufferGameOver);
	}

	pakManGame.gameMode = gameMode;	
}


void initPakMan()
{
	// Framerate setzen:
	clearValues();
	setFPS(20);
	

	//################################################################
	// Lanbyrinth erstellen
	//################################################################

	// Aeusserer Rahmen:
	createWall(18,3,3,10);
	createWall(20,38,3,10);
	createWall(18,3,20,12);
	createWall(20,38,20,12);
	

	// Hauptquartier der Monster:
	createWall(20,22,10,14);
	createWall(18,16,10,14);

	createWall(18,16,14,14);
	createWall(20,22,14,14);
	
	// Oben links erstes Labyrinth:
	createWallSquare(5,8,5,6);
	createWallSquare(10,14,5,6);

	createWallSquare(5,8,8,8);
	createWallSquare(3,6,10,10);
	createWall(14,10,10,8);
	createWall(12,16,8,5);
	
	createWall(20,18,8,8);
	createWall(20,20,6,5);
	createWall(18,18,6,5);

	// Oben rechts
	createWallSquare(36,33,5,6);
	createWallSquare(31,27,5,6);

	createWall(25,22,5,8);
	createWallSquare(24,25,7,10); 
	createWall(25,31,10,10);
	createWall(27,36,8,8);
	createWallSquare(33,36,8,10);
	
	// Unten links
	createWall(10, 8, 12, 10);
	createWallSquare(12,14,12,14);
	createWallSquare(5,6,12,14);
	createWall(8,10,14,18);
	createWall(8,5,18,16);
	createWall(7,8,16,16);
	createWall(12,18,16,16);
	createWall(16,16,18,16);
	createWall(14,14,18,20);
	createWall(12,12,16,18);
	createWall(18,18,18,20);

	// Unten rechts
	createWallSquare(22,24,12,14);
	createWall(30,26,14,12);
	createWall(28,32,12,16);
	createWall(30,32,16,16);
	createWall(28,28,16,20);

	createWall(20,20,16,18);
	createWall(22,24,16,16);
	createWall(22,26,18,16);
	createWallSquare(30,34,16,18);
	createWall(34,34,14,10);
	createWall(36,36,12,12);
	createWall(36,36,14,14);
	createWall(36,36,16,16);
	createWall(36,36,18,18);

	createMesh();

	//################################################################
	// Drops und Spielbereiche setzen
	//################################################################
	addDropArea(4, 37, 4, 8);
	addDropArea(4, 37, 16, 19);
	addDropArea(4, 14, 4, 19);
	addDropArea(24, 37, 4, 19);

	addDrop(4,4, true);
	addDrop(4,19, true);
	addDrop(37,4, true);
	addDrop(37,19, true);

	addGhostHeadquarter(16,22,10,14);

	//################################################################
	// Spielfiguren erstellen
	//################################################################
	addGhost(4.4, rgRed);
	addGhost(4.0);
	addGhost(3.6, rgDarkRed);
	addGhost(4.2, rgWhite);
	addGhost(5.0, rgLightGrey);

	pakpak.pos.x = pakPakStartPosx;
	pakpak.pos.y = pakPakStartPosy;
	pakpak.symbol = '>';
	pakpak.direction = 2;
	// Die Animationssymbole des PakPaks setzen:
	pakpak.eatSymbols[0] = 'U';
	pakpak.eatSymbols[1] = 'V';
	pakpak.eatSymbols[2] = '<';
	pakpak.eatSymbols[3] = 'C';
	pakpak.eatSymbols[4] = 'O';
	pakpak.eatSymbols[5] = 'A';
	pakpak.eatSymbols[6] = '>';
	pakpak.eatSymbols[7] = '=';
	pakpak.currentSymbol = 0;

	pakpak.speed = 5.8;
	// PakPaks Timer erzeugen:

	// Timer fuer die Animation der Figur, d.h. nach jedem Timerablauf aendert die Figur ihr Zeichen
	pakpak.walkAnimationTimerHandle = createTimer(static_cast<unsigned int>(1000 / 3));
	runTimer(pakpak.walkAnimationTimerHandle);
	
	// Timer fuer die Laufgeschwindigkeit von PakPak - nach Ablauf des Timers geht PakPak ein Feld weiter.
	pakpak.walkSpeedTimerHandle = createTimer(static_cast<unsigned int>(1000 / pakpak.speed));
	runTimer(pakpak.walkSpeedTimerHandle);

	//################################################################
	// Allgemeine Werte des Spiels setzen
	//################################################################
	pakManGame.lives = maxPakManLives;
	pakManGame.eatenDrops = 0;
	pakManGame.points = 0;

	// Erstelle einen Timer fuer den Countdown der Megapillen (Ein Zaehler mit 1 Sekunde Schrittweite)
	pakManGame.megaPillCountDownTimerHandle = createTimer(1000);
	/*
	* Erstelle einen Timer, welche die Geister gegen Ende der Wirkung 
	* der Megapille blinken lassen
	*/
	pakManGame.megaPillBlinkTimerHandle = createTimer(500);

	pakManGame.megaPillBlinkingState = true;
	
	// Timer fuer die Wartezeit, z.B. bei GameOver, get-Ready
	pakManGame.waitTimerHandle = createTimer(1000);
	

	//################################################################
	// Sounds laden
	//################################################################
	pakManGame.musicBuffer = createAudioBufferFromFile("res/music/pakman/music.mp3", 2);
	pakManGame.soundBufferEatDrop = createAudioBufferFromFile("res/sounds/pakman/eat.mp3", 1);
	pakManGame.soundBufferIntro = createAudioBufferFromFile("res/sounds/pakman/intro.mp3", 1);
	pakManGame.soundBufferLost = createAudioBufferFromFile("res/sounds/pakman/lost.mp3", 1);
	pakManGame.soundBufferGhostEaten = createAudioBufferFromFile("res/sounds/pakman/eat_ghost.mp3", 1);
	pakManGame.soundBufferGameOver = createAudioBufferFromFile("res/sounds/pakman/game_over.mp3", 1);

	setAllAudioBufferVolume(1, config.soundVolume);	
	setAllAudioBufferVolume(2, config.musicVolume);

	playAudioBuffer(pakManGame.musicBuffer, true);

	changeGameMode(pakManGameWaiting);
}


void runGame()
{
	// den Timer aktualisieren
	incrementTimer();
	
	// Wechsel bei Druck auf ESC in den Pause-Modus
	if (true == keys.keyEscape)
	{
		changeGameMode(pakManGamePaused);
	}
	
	//################################################################
	// MegaPillen-Timer pruefen
	//################################################################
	// Wenn die Geister blinken sollen, aendere nun deren Status
	if (1 == finishedTimer(pakManGame.megaPillBlinkTimerHandle))
	{
		pakManGame.megaPillBlinkingState = !pakManGame.megaPillBlinkingState;
		runTimer(pakManGame.megaPillBlinkTimerHandle);
	}

	// Pruefe auf MegaPillen-Zeit
	if (1 == finishedTimer(pakManGame.megaPillCountDownTimerHandle))
	{
		// 1 Sekunde ist vergangen, pruefe weitere Ereignisse
		runTimer(pakManGame.megaPillCountDownTimerHandle);
		--pakManGame.megaPillActiveCounter;

		// Die Zeit der MegaPillen ist abgelaufen -> setze alles zurueck
		if (0 == pakManGame.megaPillActiveCounter)
		{
			for (unsigned int i = 0; i < ghostCount; ++i)
			{
				if (ghostAfraid == ghosts[i].mode)
				{
					setGhostMode(i, ghostDefault);
				}
			}	
			// BlinkTimer stoppen
			pakManGame.pointGhostMultiplicator = 1;
			pakManGame.megaPillBlinkingState = true;
			stopTimer(pakManGame.megaPillCountDownTimerHandle);
			stopTimer(pakManGame.megaPillBlinkTimerHandle);
		}

		/* 
		* Zu einem bestimmten Zeitpunkt vor Ende (-> megaPillWarningDuration)
		* sollen die Geister anfangen zu blinken
		*/
		if (megaPillWarningDuration == pakManGame.megaPillActiveCounter)
		{
			runTimer(pakManGame.megaPillBlinkTimerHandle);
		}
	}

	//################################################################
	// Fortbewegung von PakPak pruefen
	//################################################################
	
	// Laeuft PakPak ein Feld weiter?
	if (1 == finishedTimer(pakpak.walkSpeedTimerHandle))
	{
		runTimer(pakpak.walkSpeedTimerHandle);	
		// Pruefe zunaechst, ob PakPak in die gewuenschte Richtung laufen kann
		bool moved = moveFigure(pakpak.pos.x, pakpak.pos.y, pakpak.direction, pakpak.desiredDirection, 0);
		
		if (true == moved && pmFieldDrop == gameField[pakpak.pos.x][pakpak.pos.y].flag01)
		{
			/*
			* Wenn PakMan sich bewegt hat und auf dem neuen Feld 
			* ein Drop liegt, entferne dieses und erhoehe die Punktzahl
			*/
			playAudioBuffer(pakManGame.soundBufferEatDrop);
			gameField[pakpak.pos.x][pakpak.pos.y].flag01 = 0;
			drops[gameField[pakpak.pos.x][pakpak.pos.y].flag02].eaten = true;
			++pakManGame.eatenDrops;
			pakManGame.points += pointsForADrop;

			// Ist der Drop eine Megapille?
			if (true == drops[gameField[pakpak.pos.x][pakpak.pos.y].flag02].isMegaPill)
			{
				incrementMegaPillTimer(megaPillDuration);
			}
			
			// Sind alle Drops gegessen, d.h. das Spiel gewonnen?
			if (pakManGame.eatenDrops == dropCount)
			{
				changeGameMode(pakManGameWin);
			}
		}
	}

	// Pruefe nun den Timer, um die Laufanimation von PakPak fortzusetzen:
	if (1 == finishedTimer(pakpak.walkAnimationTimerHandle))
	{
		runTimer(pakpak.walkAnimationTimerHandle);
		pakpak.currentSymbol++;
		if (2 == pakpak.currentSymbol)
		{
			pakpak.currentSymbol = 0;
		}
	}

	//################################################################
	// Fortbewegung der Geister pruefen
	//################################################################
	for (unsigned int i = 0; i < ghostCount; ++i)
	{
		// Die Geister aendern zu zufaelligen Zeiten ihre Richtung
		if (1 == finishedTimer(ghosts[i].directionChangeTimerHandle))
		{
			updateGhostDirectionChangeTimer(i);
			ghosts[i].desiredDirection = ghostRandomizeDirection(i, true);
		}
		
		// Pruefe, ob der Geist ein Feld weiterlaufen kann
		if (1 == finishedTimer(ghosts[i].walkSpeedTimerHandle))
		{
			runTimer(ghosts[i].walkSpeedTimerHandle);	
			// probiere solange zufallsgesteuert eine Bewegung, 
			// bis eine moegliche Bewegung durchgefuehrt wurde
			while (moveFigure(ghosts[i].pos.x, ghosts[i].pos.y, ghosts[i].direction, ghosts[i].desiredDirection, 1) == false)
			{
				ghosts[i].desiredDirection = ghostRandomizeDirection(i, false);
			}
		}

		/*
		* Wenn sich der Geist wieder im Hauptquartiert befindet,
		* regeneriert er sich wieder
		*/
		if(3 == gameField[ghosts[i].pos.x][ghosts[i].pos.y].flag01 
			&& ghosts[i].mode == ghostEaten)
		{
			setGhostMode(i, ghostDefault);
		}
	}
	
	//################################################################
	// Auf Kollisionen pruefen
	//################################################################
	int ghostId = checkCollisionPakPakGhost();
	if (-1 != ghostId)
	{
		// es gab eine Kollision zwischen PakPak und einem Geist!
		if (ghostDefault == ghosts[ghostId].mode)
		{
			// Wenn der Geist im Normalmodus ist, ziehe ein Leben von PakPak ab
			pakManGame.lives--;
			if (0 == pakManGame.lives)
			{
				changeGameMode(pakManGameGameOver);
			}
			else
			{
				// Setze das Spiel in den get-Ready-Modus
				changeGameMode(pakManGameWaiting);
			}
		}
		else if (ghostAfraid == ghosts[ghostId].mode)
		{
			// Wenn PakPak gerade Geister essen kann, ist der Geist gegessen.
			playAudioBuffer(pakManGame.soundBufferGhostEaten);
			setGhostMode(ghostId, ghostEaten);
			pakManGame.points += pakManGame.pointGhostMultiplicator * pointsForAGhost;
			++pakManGame.pointGhostMultiplicator;
		}
	}

	// Zuletzt alle Spielelemente ausgeben:
	drawPakManGame();
}


void overGame()
{
	// den Timer aktualisieren
	incrementTimer();

	// Wenn der Countdown beendet ist (siehe rgPakManTimings.h), zurueck ins Menu gehen
	if (true == doCountdown(pakManGame.waitTimerHandle, &pakManGame.waitTime))
	{
		quitGame();
	}

	drawPakManGame();
	drawHLine(20,13, "Game Over!");
}

void getReadyGame()
{
	incrementTimer();
	if (true == doCountdown(pakManGame.waitTimerHandle, &pakManGame.waitTime))
	{
		changeGameMode(pakManGameRunning);
	}
	drawPakManGame();
	drawHLine(20,13, "Get Ready!");
	drawHLine(20,15, ToString(pakManGame.waitTime));
	
}
void pauseGame()
{
	if (true == keys.keyEscape)
	{
		// Bei einem erneuten Druck auf ESC wird das Spiel beendet
		quitGame();
	}
	else if (keys.keyLeft || keys.keyUp || keys.keyDown || keys.keyRight)
	{
		// Bei einem Druck auf die Pfeiltasten wechsele in den aktiven Modus
		changeGameMode(pakManGameRunning);
	}
	drawPakManGame();
	drawHLine(20,13, "- Pause -");
	drawHLine(20,15, "Druecken Sie nochmals ESC, um zu beenden");
}


void winGame()
{	
	incrementTimer();
	if (true == doCountdown(pakManGame.waitTimerHandle, &pakManGame.waitTime))
	{
		quitGame();
	}

	drawPakManGame();
	drawHLine(20,13, "Sie haben gewonnen!");

}

void quitGame()
{
	// Uebergebe die Punktezahl und den Spieltyp an den HighScore-Handler
	returnToMenuFromGame(pakManGame.points, rgPakMan);

	// Loesche alle Daten
	clearValues();
}

void clearValues()
{
	unsigned int i, k;
	
	// Die Hilfsflags loeschen
	for (i = 0; i <= rgGameFieldxMax; ++i)
	{
		for (k = 0; k <= rgGameFieldyMax; ++k)
		{
			gameField[i][k].flag01 = 0;
			gameField[i][k].flag02 = 0;
		}
	}

	// Alle Timer freigeben
	for (i = 0; i < ghostCount; ++i)
	{
		deleteTimer(ghosts[i].walkSpeedTimerHandle);
		deleteTimer(ghosts[i].directionChangeTimerHandle);
	}
	
	ghostCount = 0;
	wallCount = 0;
	dropCount = 0;
	
	deleteTimer(pakpak.walkAnimationTimerHandle);
	deleteTimer(pakpak.walkSpeedTimerHandle);

	pakManGame.eatenDrops = 0;
	pakManGame.gameMode = 0;
	pakManGame.lives = 0;
	pakManGame.megaPillBlinkingState = false;
	pakManGame.pointGhostMultiplicator = 1;
	pakManGame.megaPillActiveCounter = 0;
	pakManGame.points = 0;
	pakManGame.waitTime = 0;

	deleteTimer(pakManGame.megaPillBlinkTimerHandle);
	deleteTimer(pakManGame.megaPillCountDownTimerHandle);
	deleteTimer(pakManGame.waitTimerHandle);

	deleteAudioBuffer(pakManGame.soundBufferEatDrop);
	deleteAudioBuffer(pakManGame.soundBufferIntro);
	deleteAudioBuffer(pakManGame.soundBufferLost);
	deleteAudioBuffer(pakManGame.soundBufferGameOver);
	deleteAudioBuffer(pakManGame.soundBufferGhostEaten);

	deleteAudioBuffer(pakManGame.musicBuffer);
}
