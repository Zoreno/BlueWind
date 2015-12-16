/*
* IDENTIFIERING
*
* Filnamn:    GameWindow.cpp
* Enhetsnamn: GameWindow
* Typ:        Definitioner h�rande till klassen GameWindow
* Revision:   1
* Skriven av: Joakim Bertils, Johannes Grundell
*
*
* BESKRIVNING
*
* Denna implementeringsfil definierar medlemsfunktioner f�r klassen GameWindow.
*
* REVISIONSBER�TTELSE
*
* Revision     Datum   F�r�ndringar
*
* 1            151214  Ursprungsversion
*/

/*
* REFERERADE BIBLIOTEK OCH MODULER
*/

#include "GameWindow.h"

/*
* KONSTRUKTOR GameWindow::GameWindow(sf::VideoMode videoMode, std::string title)
*
* BESKRIVNING
*
* Denna konstruktor skapar ett spelf�nster.
*
* INDATA
*
* videoMode: Spelf�nstrets storlek. 
* title: Spelf�nstrets namn.
*
* UTDATA
*
* -
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151214          Ursprungsversion
*
*/

GameWindow::GameWindow(sf::VideoMode videoMode, std::string title)
	: sf::RenderWindow(videoMode, title)
{
}

/*
* SLUT P� FILEN GameWindow.cpp
*/