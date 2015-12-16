/*
* IDENTIFIERING
*
* Filnamn:    Main.cpp
* Enhetsnamn: Main
* Typ:        Utg�ngspunkt f�r k�rning av programmet.
* Revision:   1
* Skriven av: Joakim Bertils
*
*
* BESKRIVNING
*
* Denna fil k�r applikationen som tillhandah�ller spelet.
*
* REVISIONSBER�TTELSE
*
* Revision     Datum   F�r�ndringar
*
* 1            151112  Ursprungsversion
*/

/*
* REFERERADE BIBLIOTEK OCH MODULER
*/

#include <Windows.h>
#include "Application.h"

using namespace std;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char*, int nShowCmd)
{
	try
	{
		Application app;
		app.run();
	}
	catch (const exception& e)
	{
		//TODO filstr�m
		e.what();
	}
	
	return 0;
}

/*
* SLUT P� FILEN Main.cpp
*/