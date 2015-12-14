/*
* IDENTIFIERING
*
* Filnamn:    UIBar.h
* Enhetsnamn: UIBar
* Typ:        Moduldeklaration
* Revision:   1
* Skriven av: Joakim Bertils, Johannes Grundell
*
*
* BESKRIVNING
*
* Denna modul representerar en m�tare p� anv�ndargr�nssnittet.
*
* REVISIONSBER�TTELSE
*
* Revision     Datum   F�r�ndringar
*
* 1            151120  Ursprungsversion
*
*/

#pragma once

/*
* REFERERADE BIBLIOTEK OCH MODULER
*/

#include <SFML\Graphics.hpp>
#include "GameWindow.h"
#include "UserInterface.h"

/*
* KLASS UIBar
*
* BASKLASSER
*
* -
*
* BESKRIVNING
*
* Klassen representerar en m�tare p� anv�ndargr�nssnittet.
*
* TILLST�ND
*
* -
*
* KONSTRUKTORER
*
* UIBar(sf::Vector2f position, sf::Vector2f size, sf::Color color, std::string postfix, UserInterface* uiPtr)
*
* OPERATIONER
*
* -
*
* DATAMEDLEMMAR
*
* fillLevel_:	Anger hur stor del av m�taren som ska vara ifylld.
* size_:		Storlek p� m�taren.
* position_:	Plats p� sk�rmen som m�taren kommer att ritas.
* color_:		F�rg p� m�taren.
* postfix_:		Str�ng som ska skrivas ut sist p� m�taren.
* text_:		Str�ng som ska skrivas ut p� m�taren.
* ui_:			Pekare till anv�ndargr�nssnittet som m�taren �r en del av.
*
* REVISIONSBER�TTELSE
*
* Revision     Datum   F�r�ndringar
*
* 1            151120  Ursprungsversion
* 
*/

class UIBar
{
public:
	UIBar(sf::Vector2f, sf::Vector2f, sf::Color, std::string, UserInterface*);
	UIBar() = delete;
	UIBar(UIBar&) = delete;
	UIBar& operator=(const UIBar&) = delete;

	void update(int, int);
	void render(GameWindow&);

private:
	float fillLevel_;
	sf::Vector2f size_;
	sf::Vector2f position_;
	sf::Color color_;
	std::string postfix_;
	std::string text_;

	UserInterface* ui_;
}; //class UIBar

/*
* SLUT P� FILEN UIBar.h
*/