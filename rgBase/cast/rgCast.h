/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* rgCast.h 
* Hier werden alle Cast-Operationen definiert, die im Programm-
* ablauf haeufiger benoetigt werden, z.B. intToStr() o.ae.
*/
#ifndef _RGCAST_
#define _RGCAST_

#include <string>
#include <sstream>

using namespace std;

/**
* Konvertiert einen string in einen int-Wert. Ist der Wert ungueltig,
* wird 0 zurueckgegeben.
* \param value Der String, welcher in einen Int konvertiert werden soll
* \return Der in int konvertierte String
*/
int stringToInt(string value);

/**
* Funktion zur Umwandlung von einem Bool nach String
* \param value Die Variable, welche in einen String gewandelt werden soll
* \return Die boolsche Variable als string: "TRUE" oder "FALSE"
*/
string boolToStr(bool value);

/**
* Funktion zur Umwandlung von einem String nach Bool
* \param value Die Variable vom Typ string, welche in einen Bool gewandelt werden soll
* \return true, wenn var = "TRUE" ist, ansonsten false
*/
bool stringToBool(string value);

/**
* Funktion zur Umwandlung von einem beliebigen Datentyps in einen String
* \param value Die Variable, welche in einen String gewandelt werden soll
* \return Variable value als String
*/
template<typename T>
string ToString(T value)
{
	ostringstream output; 
	output << value;
	return output.str();
}

#endif