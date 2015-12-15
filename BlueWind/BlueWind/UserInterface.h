/*
* IDENTIFIERING
*
* Filnamn:    UserInterface.h
* Enhetsnamn: UserInterface
* Typ:        Moduldeklaration
* Revision:   1
* Skriven av: Joakim Bertils, Johannes Grundell
*
*
* BESKRIVNING
*
* Denna modul representerar anv�ndargr�nssnitt i spelet.
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
#include <map>
#include "UIComponent.h"
#include "GameWindow.h"

/*
* KLASS UIException
*
* BASKLASSER
*
* logic_error
*
* BESKRIVNING
*
* Klassen hanterar undantag i UserInterface.
*
* TILLST�ND
*
* -
*
* KONSTRUKTORER
*
* �rver fr�n std::logic_error.
*
* OPERATIONER
*
* -
*
* DATAMEDLEMMAR
*
* -
*
* REVISIONSBER�TTELSE
*
* Revision     Datum   F�r�ndringar
*
* 1            151120  Ursprungsversion
*
*/

class UIException : public std::logic_error
{
public:
	using std::logic_error::logic_error;
};

/*
* KLASS UserInterface
*
* BASKLASSER
*
* -
*
* BESKRIVNING
*
* Klassen representerar anv�ndargr�nssnitt i spelet
*
* TILLST�ND
*
* -
*
* KONSTRUKTORER
*
* UserInterface(Player*)
*
* OPERATIONER
*
* -
*
* DATAMEDLEMMAR
*
* components_:		Lista �ver anv�nbdargr�nssnittets komponenter.
* uiFont_:			Anv�ndargr�nssnittets typsnitt.
* uiView_:			Anv�ndargr�nssnittets 2D-kamera.
*
* REVISIONSBER�TTELSE
*
* Revision     Datum   F�r�ndringar
*
* 1            151120  Ursprungsversion
*
*/

class UserInterface
{
public:
	UserInterface(Player*);
	UserInterface() = delete;
	UserInterface(const UserInterface&) = delete;
	UserInterface& operator=(const UserInterface&) = delete;
	~UserInterface();
	void handleKeyEvent(const sf::Event&);

	void addStringToChatBox(std::string);

	void update();
	void render(GameWindow&);

	sf::Font& getFont();
private:
	std::map<std::string,UIComponent*> components_;
	void loadComponents(Player*);
	sf::Font uiFont_;
	sf::View uiView_{ sf::FloatRect(0,0,800,600) };
};//class UserInterface

/*
 * SLUT P� FILEN UserInterface.h
 */