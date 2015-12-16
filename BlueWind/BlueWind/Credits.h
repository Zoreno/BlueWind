/*
* IDENTIFIERING
*
* Filnamn:    Credits.h
* Enhetsnamn: Credits
* Typ:        Moduldeklaration
* Revision:   1
* Skriven av: Simon Arkeholt, Fredrik Gustafsson
*
*
* BESKRIVNING
*
* Denna modul representerar en undermeny till spelets startmeny d�r en lista �ver det material som anv�nts i spelet visas.
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
* KLASS Credits
*
* BASKLASSER
*
* Frame
*
* BESKRIVNING
*
* Klassen representerar en undermeny till spelets startmeny d�r en lista �ver det material som anv�nts i spelet visas.
*
* TILLST�ND
*
* -
*
* KONSTRUKTORER
*
* Credits(Application*)
*
* OPERATIONER
*
* -
*
* DATAMEDLEMMAR
*
* background_: Undermenyns bakgrundsbild.
*
* REVISIONSBER�TTELSE
*
* Revision     Datum   F�r�ndringar
*
* 1            151214  Ursprungsversion
*
*/

class Credits : public Frame
{
public:
	Credits(Application*);
	Credits(const Credits&) = delete;
	Credits& operator=(const Credits&) = delete;

	void handleKeyEvent(sf::Event) override;
	void handleMouseEvent(sf::Event) override;

	void update() override;
	void render(GameWindow&) override;

private:
	sf::Sprite background_;
}; // class Credits

/*
* SLUT P� FILEN Credits.h
*/