
#include "rgCommon/rgMisc.h"
#include "rgCommon/rgHighScore.h"
#include "rgCommon/rgGlobals.h"

void returnToMenuFromGame(unsigned int points, int gameType)
{
	if (true == isInHighScore(points, gameType))
	{
		mnCurrentDisplayedMenu = 4;
		highScoreGame = gameType;
		highScorePoints = points;
	}
	else
	{
		mnCurrentDisplayedMenu = 0;
	}
	gameMode = rgMenu;
}

bool isInHighScore(unsigned int points, int gameType)
{
	if (rgPakMan == gameType)
	{
		return (highScorePakMan[9].points < points);
	}
	else
	{
		return (highScoreSnake[9].points < points);
	}
}
void addHighscore(string name, unsigned int points, int gameType)
{
	// gameType = 0 -> PakMan
	// gameType = 1 -> Snake
	rgHighScore* currentHighScore;

	// Speicheradressen kopieren:
	if (rgPakMan == gameType)
	{
		currentHighScore = highScorePakMan;
	}
	else
	{
		currentHighScore = highScoreSnake;
	}

	unsigned int hsPosition = -1;
	unsigned int i;
	for (i = 0; i < 10; ++i)
	{
		if (currentHighScore[i].points < points)
		{
			// HighScoreliste aktualisieren
			hsPosition = i;
			break;
		}
	}

	if (hsPosition != -1)
	{
		for (i = 9; i > hsPosition; --i)
		{
			currentHighScore[i] = currentHighScore[i - 1];
		}
		currentHighScore[hsPosition].player = name;
		currentHighScore[hsPosition].points = points;
		currentHighScore[hsPosition].date = getDateAsString();
	}
}

