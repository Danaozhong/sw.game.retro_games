/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* rgPakManWalls.h
* Hier werden die Funktionen zum Kontrollieren von Waenden realisiert.
*/


#ifndef _RGPAKMANMAP_
#define _RGPAKMANMAP_

/**
* Fuegt ein Wandelement an einer definierten Position hinzu.
* Befindet sich an der gewuenschten Stelle bereits ein 
* Spielelement, wird der Vorgangg abgebrochen.
* \param x Die x-Position des Wandelements
* \param y Die y-Position des Wandelements
*/
void addWall(unsigned int x, unsigned int y);

/**
* Vernetzt saemtliche Wandelemente miteinander, indem 
* nebeneinander liegende Wandelemente erkannt werden und
* deren Symbole anhand der benachbarten Wandstuecke so
* gewaehlt werden, dass grafisch eine erkennbare Wand 
* entsteht.
*/
void createMesh();

/**
* Erstellt eine komplette Mauer von Punkt 1 zu Punkt 2.
* Dabei wird zuerst in horizontaler Richtung die Differenz
* zwischen x1 und x2 in Hoehe von y1 mit Wandelemente gefuellt,
* anschlieﬂend der vertikale Abstand zwischen y1 und y2 bei der
* x-Koordinate x2.
* \param x1 Die x-Koordinate des Punktes 1
* \param x2 Die x-Koordinate des Punktes 2
* \param y1 Die y-Koordinate des Punktes 1
* \param y2 Die y-Koordinate des Punktes 2
*/
void createWall(int x1, 
				int x2, 
				int y1, 
				int y2);

/**

*/
void createWallSquare(unsigned int x1, 
					  unsigned int x2, 
					  unsigned int y1, 
					  unsigned int y2);

/**
* Fuegt ein Drop oder eine Megapille an einer bestimmten Position, sofern
* diese bisher nicht verwendet ist, hinzu. Befindet sich an der Position 
* bereits ein Drop, wird dessen Art je nach Wert von isMegaPill geaendert.
* \param x Die x-Position des Drops/der Megapille
* \param y Die y-Position des Drops/der Megapille
* \param isMegaPill Wenn true, wird anstelle eines Drops eine Megapille
* erzeugt.
*/
void addDrop(unsigned int x, unsigned int y, bool isMegaPill = false);

/**
* Zwischen beiden Punkten Punkt 1 und Punkt 2 wird ein 
* Rechteck aufgespannt, welches auf den freien Spielfeldern
* mit Drops gefuellt wird.
* \param x1 Die x-Koordinate des Punktes 1
* \param x2 Die x-Koordinate des Punktes 2
* \param y1 Die y-Koordinate des Punktes 1
* \param y2 Die y-Koordinate des Punktes 2
*/
void addDropArea(unsigned int x1, 
				 unsigned int x2, 
				 unsigned int y1, 
				 unsigned int y2);


/**
* Zwischen beiden Punkten Punkt 1 und Punkt 2 wird ein 
* Rechteck aufgespannt, welches, falls unbelegt, fuer
* das Hauptquartier der Geister reserviert wird.
* \param x1 Die x-Koordinate des Punktes 1
* \param x2 Die x-Koordinate des Punktes 2
* \param y1 Die y-Koordinate des Punktes 1
* \param y2 Die y-Koordinate des Punktes 2
*/
void addGhostHeadquarter(unsigned int x1, 
						 unsigned int x2, 
						 unsigned int y1, 
						 unsigned int y2);


#endif