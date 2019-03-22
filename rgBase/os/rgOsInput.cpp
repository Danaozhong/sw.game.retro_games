/*
* (c) 2011 Hochschule Karlsruhe - Technik und Wirtschaft
* Teamorientierte Projektstudienarbeit "Retro Games"
* SS 2011
* 
* rgOsInput.cpp 
* Definition zu rgOsInput.h
*/

#include <windows.h>
#include <winuser.h>
#pragma comment(lib,"user32")

#include "rgBase/os/rgOsInput.h"

void getKeyState(short* flags)
{	
	/*
		GetAsyncKeyState() ist in der Library winuser.h definiert.
		GetAsyncKeyState(PARAMETER) gibt den aktuellen Status einer Taste als short zurueck. 	
		PARAMETER ist jeweils aus der "Virtual Key Code" - Tabelle zu entnehmen.
	*/
	flags[0] = GetAsyncKeyState(VK_LEFT);
	flags[1] = GetAsyncKeyState(VK_UP);
	flags[2] = GetAsyncKeyState(VK_RIGHT);
	flags[3] = GetAsyncKeyState(VK_DOWN);
	flags[4] = GetAsyncKeyState(VK_ESCAPE);
	flags[5] = GetAsyncKeyState(VK_SPACE);
	flags[6] = GetAsyncKeyState(VK_BACK);
	flags[7] = GetAsyncKeyState(VK_RETURN);
	flags[8] = GetAsyncKeyState('A');
	flags[9] = GetAsyncKeyState('B');
	flags[10] = GetAsyncKeyState('C');
	flags[11] = GetAsyncKeyState('D');
	flags[12] = GetAsyncKeyState('E');
	flags[13] = GetAsyncKeyState('F');
	flags[14] = GetAsyncKeyState('G');
	flags[15] = GetAsyncKeyState('H');
	flags[16] = GetAsyncKeyState('I');
	flags[17] = GetAsyncKeyState('J');
	flags[18] = GetAsyncKeyState('K');
	flags[19] = GetAsyncKeyState('L');
	flags[20] = GetAsyncKeyState('M');
	flags[21] = GetAsyncKeyState('N');
	flags[22] = GetAsyncKeyState('O');
	flags[23] = GetAsyncKeyState('P');
	flags[24] = GetAsyncKeyState('Q');
	flags[25] = GetAsyncKeyState('R');
	flags[26] = GetAsyncKeyState('S');
	flags[27] = GetAsyncKeyState('T');
	flags[28] = GetAsyncKeyState('U');
	flags[29] = GetAsyncKeyState('V');
	flags[30] = GetAsyncKeyState('W');
	flags[31] = GetAsyncKeyState('X');
	flags[32] = GetAsyncKeyState('Y');
	flags[33] = GetAsyncKeyState('Z');
}

void osInitMouse()
{
    DWORD mode;
    GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE),&mode);
    SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE),mode|ENABLE_MOUSE_INPUT);
}


void osGetMouseInputs(int* x, int* y, bool* left, bool* right)
{	
	DWORD count;
	INPUT_RECORD ir;

	GetNumberOfConsoleInputEvents(GetStdHandle(STD_INPUT_HANDLE), &count);

	// Wenn es keine Ereignisse gab, abbrechen
	if (0 == count)
	{
		return;
	}
	ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE),&ir,1,&count);

	if (MOUSE_EVENT == ir.EventType)
	{
		/*
		Abfrage nach der "Linken Maustaste" (LMT) 
		Die LMT ersetzt die RETURN-TASTE, wenn das Spiel mit der Maus gespielt wird.
		*/	
		if(ir.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
		{	
			*left = true;
		}
		/*
		Abfrage nach der "Rechten Maustaste" (RMT) 
		Die RMT ersetzt die ESCAPE-TASTE, wenn das Spiel mit der Maus gespielt wird.
		*/	
		if(ir.Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED)
		{
			*right = true;
		}
		*x = ir.Event.MouseEvent.dwMousePosition.X;
		*y = ir.Event.MouseEvent.dwMousePosition.Y;		
	}	
}