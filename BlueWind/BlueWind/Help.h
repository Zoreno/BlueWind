/*
* IDENTIFIERING
*
* Filnamn:    Help.h
* Enhetsnamn: Help
* Typ:        Moduldeklaration
* Revision:   1
* Skriven av: Simon Arkeholt, Fredrik Gustafsson
*
*
* BESKRIVNING
*
* Denna modul representerar en undermeny till spelets startmeny d�r spelets kontroller visas.
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
* KLASS Help
*
* BASKLASSER
*
* Frame
*
* BESKRIVNING
*
* Klassen representerar en undermeny till spelets startmeny d�r spelets kontroller visas.
*
* TILLST�ND
*
* -
*
* KONSTRUKTORER
*
* Help(Application*)
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

class Help : public Frame
{
public:
	Help(Application*);
	Help(const Help&) = delete;
	Help& operator=(const Help&) = delete;

	void handleKeyEvent(sf::Event) override;
	void handleMouseEvent(sf::Event) override;

	void update() override;
	void render(GameWindow&) override;

private:
	sf::Sprite background_;
}; // class Help

   /*
   * SLUT P� FILEN Menu.h
   */