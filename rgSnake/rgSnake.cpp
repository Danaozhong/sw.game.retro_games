/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* Definition zu rgSnake.h
*/

/**
* Stellt einen Ablauf im Spielablauf von mySnake dar. Diese Funktion wird einmal
* pro Frame aufgerufen, solange mySnake laeuft.
*/

#include "rgBase/gfx/rgGfx.h"
#include "rgBase/timedriver/rgTimeDriver.h"
#include "rgBase/audio/rgAudio.h"

#include "rgCommon/rgGlobals.h"
#include "rgBase/cast/rgCast.h"
#include "rgCommon/rgMisc.h"
#include "rgCommon/rgHighScore.h"

#include "rgSnake/rgSnake.h"

struct snDrops                   //Struktur der Drops
{ 
	int x,y;                     //Koordinaten
	bool enabled;                //Aktiv , ein oder aus
	char symbol;                 //Symbol für Ausgabe
	int timerId;                 //Index des benutzten Index
};

struct snSegment  // Struktur jedes Segment der Schlange
{
	int x,y;                     //Koordinaten
	bool enabled;                //Aktiv , ein oder aus
	char symbol;                 //Symbol für Ausgabe
	bool head;                   //Kopf
};

struct snSnake
{
	snSegment segments[1920];     //Die Schlange , gespeichert in ein array
	int currentLength;			  // Anzahl der Segmente, die gerade existieren
	int desiredLength;			  // Anzahl der Semgente, die die Schlange lang werden soll
	int direction;                //Richtung der Schlange
};


//const unsigned int snakeGameFieldxmax
namespace
{
 snSnake snmySnake;  //Die Variabile Schlange
 const int snmaxDrops = 3;
 snDrops sndrops[snmaxDrops];
 int snGameOver;
 unsigned int sndropTimerHandle;
 bool snf=true;
 unsigned int sno;
 int snescap=0;
 unsigned int snHighScore;
 bool snpause=false;


 int snMusicBuffer;
 int snDropEatBuffer;
 int snGameOverBuffer;
}



/**
* detectCollision ueberprueft ob das Kopf nicht ein anderen Segment getroffen hat
* /param ix die Koordinate x
* /param iy die Koordinate y
* /return true Die Schlange beruehrt sich selber, false, wenn keine Beruehrung aufgetreten ist
*/
bool detectCollision(int ix,int iy)
{
	for(int i = 1; i < snmySnake.currentLength; ++i)
	{
		if ((snmySnake.segments[i].x==ix)&&(snmySnake.segments[i].y==iy))
		{
			return false;
		}
	}
	return true;
}
/**
* detectDrop ueberprueft ob das Kopf nicht ein Drops getroffen hat
* /return : -1, wenn kein Drop beruehrt wurde, ansonsten die ID des Drops
*/
int detectDrop()
{
	for (int i = 0; i < snmaxDrops; ++i)
	{
		if ((true == sndrops[i].enabled) && (snmySnake.segments[0].x==sndrops[i].x)&&(snmySnake.segments[0].y==sndrops[i].y))
		{
			playAudioBuffer(snDropEatBuffer); 
			sndrops[i].enabled=false;
			return i;
		}
	}
	return -1;
}


/*newDrop stellt ein neues Drop auf den Spielfeld
*/
void newDrop()
{
	int sndropId = 0;
	while(sndrops[sndropId].enabled == true)
	{
		if ((sndropId + 1) == snmaxDrops)
		{
			// Alle Drops sind bereits auf dem Spielfeld existent - breche daher ab.
			return;
		}
		++sndropId;
	}

	sndrops[sndropId].x = getRandomValue(1,rgGameFieldxMax);// Zufaeligen Wert fur x Koordinate
	sndrops[sndropId].y = getRandomValue(2,rgGameFieldyMax-1);//Zufaeligen Wert fur y Koordinate
	if(detectCollision(sndrops[sndropId].x,sndrops[sndropId].y)==false)  //uberpruffe ob die Drop nicht auf die Schlange steht
	{
		
		sndrops[sndropId].x = getRandomValue(1,rgGameFieldxMax);
	    sndrops[sndropId].y = getRandomValue(2,rgGameFieldyMax-1);
	}
	sndrops[sndropId].symbol='X';
	sndrops[sndropId].enabled=true;
	// TODO Sever: Hier muss noch ne Pruefung rein, damit kein Feld doppelt belegt wird und ein Drop nicht auf einer
	// Schlange entstehen kann.
}
/*Funktion startSnake() initialisiert die Schlange
* initialisiert Erste 6 Segmente und die Richtung links
*startet Musik und Sound-Efekte
*Stellt die Score auf 0
*/
void startSnake()
{
	setFPS(10);
	snHighScore=0;

	
	for(int i=1; i<1920; ++i)         //initialisiert das Rest der Schlange
	{
       snmySnake.segments[i].head=false;
	   snmySnake.segments[i].symbol=' ';
	   snmySnake.segments[i].enabled=false;
	}

	snmySnake.direction=2;                          //initialisiert Erste 6 Segmente und die Richtung links
	snmySnake.segments[0].head=true;                     
	snmySnake.segments[0].y=12;	
	snmySnake.segments[0].x=37;	
	snmySnake.segments[0].enabled=true;	
	snmySnake.segments[0].symbol='O';	
	snmySnake.currentLength = 6;
	snmySnake.desiredLength = 6;
	snGameOver=10;
	for(int i=1;i<snmySnake.currentLength;++i)
	{
		snmySnake.segments[i].enabled=true;
		snmySnake.segments[i].head=false;
	    snmySnake.segments[i].y=12;
	    snmySnake.segments[i].x=37+i;
	    snmySnake.segments[i].symbol='o';
	};
		sndropTimerHandle = createTimer(getRandomValue(1000, 2000));
	runTimer(sndropTimerHandle);
	snf=true;
	snmySnake.direction=2;
	
	snMusicBuffer = createAudioBufferFromFile("res/music/snake/music.mp3", 2);
	snDropEatBuffer = createAudioBufferFromFile("res/sounds/snake/grow.mp3", 1);
	snGameOverBuffer = createAudioBufferFromFile("res/sounds/snake/game_over.mp3", 1);

	setAllAudioBufferVolume(1, config.soundVolume);	
	setAllAudioBufferVolume(2,config.musicVolume);
	playAudioBuffer(snMusicBuffer, true); 
    runSnake();
}

void quitSnake()
{
	deleteAudioBuffer(snMusicBuffer);
	deleteAudioBuffer(snDropEatBuffer);
	deleteAudioBuffer(snGameOverBuffer);

	returnToMenuFromGame(snHighScore, rgSnake);

}

/*Funktion moveSnake() ubernimmt das Input und bearbeitet die bewegung der Schlange
*/
void moveSnake()
{
	int headNewX = snmySnake.segments[0].x;
	int headNewY = snmySnake.segments[0].y;
	
    if (keys.keyDown==true)
	{
		if (snmySnake.direction!=3)
		{
			snmySnake.direction=0;
		}
		
	}
	else if (keys.keyRight==true)
	{
		if (snmySnake.direction!=2)
		{
		snmySnake.direction=1;
		}
	}
	else if (keys.keyLeft==true)
	{
		if (snmySnake.direction!=1)
		{
		snmySnake.direction=2;
		}
	}	
	else if (keys.keyUp==true)
	{
		if (snmySnake.direction!=0)
		{
		snmySnake.direction=3;
		}
	}
	switch(snmySnake.direction)
	{
	case 0:
		headNewY++;     //Kopf geht nach rechts
			if (headNewY>23)
		{
			headNewY=2;
			/*mySnake.direction=3;*/
		};
		break;
	case 1:
		headNewX++;  //Kopf geht nach unten
		if (headNewX>80)
		{
			headNewX=1;
			/*mySnake.direction=2;*/
		};
		break;
	case 2:
		headNewX--;  //Kopf geht nach links
		if (headNewX<1)
		{
			headNewX=80;
			/*mySnake.direction=1;*/
		};
		break;
	case 3:
		headNewY--; //Kopf geht nach oben
		if (headNewY<2)
		{
			headNewY=23;
			/*mySnake.direction=0;*/
		};
		break;
	 }	



	if (snmySnake.desiredLength > snmySnake.currentLength)
	{
		growSnake();
	}

	for (int i = snmySnake.currentLength - 1; i > 0; --i)
	{
       snmySnake.segments[i].x=snmySnake.segments[i - 1].x;
	   snmySnake.segments[i].y=snmySnake.segments[i - 1].y;
	}
	
	snmySnake.segments[0].x = headNewX;
	snmySnake.segments[0].y = headNewY;
}
/* outputSnake()
*  Ausgabe der Schlange und der Drops
*
*/
void outputSnake(bool game)
{
	if (game==true)
	{
		int i;
		drawSymbol(snmySnake.segments[0].x, snmySnake.segments[0].y, snmySnake.segments[0].symbol,rgYellow);
		for (i=1;i<snmySnake.currentLength;++i)
		{
			
				drawSymbol(snmySnake.segments[i].x,snmySnake.segments[i].y, snmySnake.segments[i].symbol,rgGreen);
			
		}
		
		for (i = 0; i < snmaxDrops; ++i) //legt die Drops auf den Spielfeld
		{
			if (true == sndrops[i].enabled)
			{			
				drawSymbol(sndrops[i].x,sndrops[i].y,sndrops[i].symbol,getRandomValue(1, 16));						
			}
		}
	}
	else
	{
		drawHLine(36,12,"Game Over",rgRed);
		if (snGameOver !=0)
		{
			stopAudioBuffer(snMusicBuffer);
			playAudioBuffer(snGameOverBuffer, false);
			sno=createTimer(3000); //GameOver);
			runTimer(sno);
			snGameOver=0;
		}
		else
		{
			if (finishedTimer(sno)==1)
			{
				for (int i=0;i<snmaxDrops;i++)
				{
					sndrops[i].enabled=false;
				}
				deleteTimer(sno);
				quitSnake();
			}
		}
	}
}
/* Funktion growSnake() wächst die Schlange mit ein Element
*/
void growSnake()
{
	snmySnake.segments[snmySnake.currentLength].enabled=true;
	snmySnake.segments[snmySnake.currentLength].head=false;
	snmySnake.segments[snmySnake.currentLength].symbol='o';
	snmySnake.segments[snmySnake.currentLength].x=snmySnake.segments[snmySnake.currentLength-1].x;
	snmySnake.segments[snmySnake.currentLength].y=snmySnake.segments[snmySnake.currentLength-1].y;
	snmySnake.currentLength++;
	snHighScore++;
}
/* Main-Funktion des Spieles Snake , aufruft die wichtigsten Funktionen auf , wie moveSnake und outputSnake 
*Uebernimmt auch die Pause Funktion
*/
void runSnake()
{
	
	if ((keys.keyEscape==false)&&(snpause==false))
	{
		snescap=0;
	  incrementTimer();
	  if (1 == finishedTimer(sndropTimerHandle))
	  {
		deleteTimer(sndropTimerHandle);
			
		sndropTimerHandle = createTimer(getRandomValue(2000, 5000));

		runTimer(sndropTimerHandle);
		newDrop();
      }

	//int a= drawSymbol(10, 10, 65,rgWhite);
	  moveSnake();
	  int dropId = detectDrop();
	  if (-1 != dropId)
	  {
		  sndrops[dropId].symbol=' ';
		  sndrops[dropId].enabled=false;
		  snmySnake.desiredLength += 4;
	  }
	  int a=drawHLine(1,1,"Punktzahl: " + ToString(snHighScore));
	
	  if (snf==true)
	  {
	    snf=detectCollision(snmySnake.segments[0].x,snmySnake.segments[0].y);
	  }
	  if (snHighScore>1910)
      {
		 a=drawHLine(36,12,"YOU ARE A GOD , YOU HAVE WON",rgBlue);
	  }
	  outputSnake(snf);
	  }
	 else
	  {
		int a =drawHLine(36,12,"Pause",rgRed);
		snpause=true;
		if (keys.keySpace==true)
		 {
			a=drawHLine(36,12,"Pa",rgRed);
			snpause=false;
		 } 
		snescap++;
		
		if(keys.keyEscape==true&&(snescap>10))
		{
			for (int i=0;i<snmaxDrops;i++)
				{
					sndrops[i].enabled=false;
				}
			    snescap=0;
				
				snpause=false;
				quitSnake();
				
		}
	  }

	}
	


