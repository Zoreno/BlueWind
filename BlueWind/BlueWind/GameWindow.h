/*
* IDENTIFIERING
*
* Filnamn:    GameWindow.h
* Enhetsnamn: GameWindow
* Typ:        Moduldeklaration
* Revision:   1
* Skriven av: Joakim Bertils, Johannes Grundell
*
*
* BESKRIVNING
*
* Denna modul representerar ett spelf�nster.
*
* REVISIONSBER�TTELSE
*
* Revision     Datum   F�r�ndringar
*
* 1            151214  Ursprungsversion
*
*/

#pragma once

/*
* REFERERADE BIBLIOTEK OCH MODULER
*/

#include <SFML\Graphics.hpp>
#include <string>

/*
* KLASS GameWindow
*
* BASKLASSER
*
* sf::RenderWindow
*
* BESKRIVNING
*
* Klassen representerar ett spelf�nster.
*
* KONSTRUKTORER
*
* GameWindow(sf::VideoMode, std::string)
*
* DATAMEDLEMMAR
*
* -
*
* REVISIONSBER�TTELSE
*
* Revision     Datum   F�r�ndringar
*
* 1            151214  Ursprungsversion
*
*/

class GameWindow : public sf::RenderWindow
{
public:
	GameWindow(sf::VideoMode, std::string);
	GameWindow(const GameWindow&) = delete;
	GameWindow& operator=(const GameWindow&) = delete;
};

/*
* SLUT P� FILEN GameWindow.h
*/