/*
* IDENTIFIERING
*
* Filnamn:    GameWon.h
* Enhetsnamn: GameWon
* Typ:        Moduldeklaration
* Revision:   1
* Skriven av: Simon Arkeholt, Fredrik Gustafsson
*
*
* BESKRIVNING
*
* Denna modul representerar en meny som visas d� spelaren vinner spelet.
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

#include "Frame.h"
#include "GameWindow.h"

/*
* Fram�tdeklarationer
*/

class Application;

/*
* KLASS GameWon
*
* BASKLASSER
*
* Frame
*
* BESKRIVNING
*
* Klassen representerar en meny som visas d� spelaren vinner spelet.
*
* KONSTRUKTORER
*
* GameWon(Application*)
*
* DATAMEDLEMMAR
*
* background_: Menyns bakgrundsbild.
*
* REVISIONSBER�TTELSE
*
* Revision     Datum   F�r�ndringar
*
* 1            151214  Ursprungsversion
*
*/

class GameWon : public Frame
{
public:
	GameWon(Application*);
	GameWon(const GameWon&) = delete;
	GameWon& operator=(const GameWon&) = delete;

	void handleKeyEvent(sf::Event) override;
	void handleMouseEvent(sf::Event) override;

	void update() override;
	void render(GameWindow&) override;
private:
	sf::Sprite background_;
}; // class GameWon

/*
* SLUT P� FILEN GameWon.h
*/