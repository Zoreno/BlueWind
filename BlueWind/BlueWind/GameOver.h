/*
* IDENTIFIERING
*
* Filnamn:    GameOver.h
* Enhetsnamn: GameOver
* Typ:        Moduldeklaration
* Revision:   1
* Skriven av: Simon Arkeholt, Fredrik Gustafsson
*
*
* BESKRIVNING
*
* Denna modul representerar en meny som visas d� spelaren f�rlorar spelet.
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
* KLASS GameOver
*
* BASKLASSER
*
* Frame
*
* BESKRIVNING
*
* Klassen representerar en meny som visas d� spelaren f�rlorar spelet.
*
* TILLST�ND
*
* -
*
* KONSTRUKTORER
*
* GameOver(Application*)
*
* OPERATIONER
*
* -
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

class GameOver : public Frame
{
public:
	GameOver(Application*);
	GameOver(const GameOver&) = delete;
	GameOver& operator=(const GameOver&) = delete;

	void handleKeyEvent(sf::Event) override;
	void handleMouseEvent(sf::Event) override;

	void update() override;
	void render(GameWindow&) override;

private:
	sf::Sprite background_;
}; // class GameOver

/*
* SLUT P� FILEN GameOver.h
*/