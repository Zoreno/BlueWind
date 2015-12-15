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

#include "Application.h"

using namespace std;

int main()
{
	try
	{
		Application app;
		app.run();
	}
	catch (const exception& e)
	{
		cerr << e.what() << endl;
	}
	

	return 0;
}

/*
* SLUT P� FILEN Main.cpp
*/