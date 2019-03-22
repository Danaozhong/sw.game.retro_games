/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* rgAudio.h
* Bietet alle Audio-Funktionalitaeten fuer das Programm. Diese Audio-SChnittstelle basiert auf 
* der FMOD-Audio-Libary.
*/

#ifndef _RGAUDIO_
#define _RGAUDIO_

#include <string>

using namespace std;

/** 
* Initialisiert FMOD
*/
void initAudio(void);

/** 
* Erstellt einen Audiobuffer aus einer Datei.
* \param filename	Name der zu ladenden Audiodatei
* \param audiotype	Typ des Buffers: 1 fuer Soundbuffer; 2 fuer Musikbuffer
* \return			Rückgabewert = ID des Audiobuffers; -1 fuer Audioausgabe ausgeschaltet, -2, wenn die Datei nicht
* existiert
*/
int createAudioBufferFromFile(const string &filename, int audiotype);

/** 
* Spielt einen Audiobuffer ab
* \param bufferId	ID des Audiobuffers
* \param loop		false (Standardwert) fuer einmal abspielen; 1 fuer Endlosschleife		
* \return			1, wenn erfolgreich, -1, wenn der Buffer unbelegt ist, -2, wenn die eingegebene BufferId ungueltig ist
*/
int playAudioBuffer(int bufferId, bool loop = false);

/** 
* Stoppt einen Audiobuffer
* \param bufferId	ID des Audiobuffers
* \return			1 wenn erfolgreich; -3 ungueltige BufferId angegeben
*/
int stopAudioBuffer(int bufferId);

/** 
* Beendet FMOD
* \return			0 wenn erfolgreich;
*/
int stopAudio(void);

/** 
* Setzt die Lautstaerke eines Audiobuffers
* \param bufferId	ID des Audiobuffers
* \param volume		Ganzzahliger Wert fuer die Lautstaerke zwischen 0 (aus) und 100 (laut)
* \return			1, wenn erfolgreich, -1, wenn der Buffer unbelegt ist, -2, wenn der eingegebene Volumenwert ungueltig ist
*/
int setAudioBufferVolume(int bufferId, int volume=50);

/** 
* setzt die Lautstaerke aller Audiobuffer eines Typs
* \param audiotype	Das Volumen welcher Buffer gesetzt werden soll: 0 fuer alle; 1 fuer Sound; 2 fuer Musikbuffer
* \param volume		Ganzzahliger Wert fuer die Lautstaerke zwischen 0 (aus) und 100 (laut)
*/
int setAllAudioBufferVolume(int audiotype=0,int volume=50);

/** 
* Loescht einen bestimmten Audiobuffer
* \param bufferId	ID des Audiobuffers
*/
int deleteAudioBuffer(int bufferId);


/** 
* Stoppt alle Audiobuffer eines Typs
* \param audiotype	Das Volumen welcher Buffer gesetzt werden soll: 0 fuer alle; 1 fuer Sound; 2 fuer Musikbuffer
*/
int stopAllAudioBuffer(int audiotype=0);

#endif