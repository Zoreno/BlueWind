/*
* IDENTIFIERING
*
* Filnamn:    FrameButton.h
* Enhetsnamn: FrameButton
* Typ:        Moduldeklaration
* Revision:   1
* Skriven av: Simon Arkeholt, Fredrik Gustafsson
*
*
* BESKRIVNING
*
* Denna modul representerar en knapp i spelet.
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
#include "GameWindow.h"
#include <functional>
#include <stdexcept>

/*
* Fram�tdeklarationer
*/

class Application;

/*
* KLASS FrameButtonException
*
* BASKLASSER
*
* std::logic_error
*
* BESKRIVNING
*
* Klassen kastar undantag f�r FrameButton.
*
* TILLST�ND
*
* -
*
* KONSTRUKTORER
*
* default-konstruktor. TODO Hur??
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
* 1            151214  Ursprungsversion
*
*/

class FrameButtonException : public std::logic_error
{
public:
	using std::logic_error::logic_error;
}; // class FrameButtonException

/*
* KLASS FrameButton
*
* BASKLASSER
*
* -
*
* BESKRIVNING
*
* Klassen representerar en knapp i spelet.
*
* TILLST�ND
*
* -
*
* KONSTRUKTORER
*
* FrameButton(Application*,sf::Vector2f, sf::Vector2f, std::string, std::string, std::function<void (Application*)>)
*
* OPERATIONER
*
* -
*
* DATAMEDLEMMAR
*
* appPointer_:		Pekare till den applikation knappen �r en del av.
* position_:		Knappens position.
* size_:			Knappens storlek.
* normalTexture_:	Den textur som ska ritas upp p� knappen d� man EJ h�ller musen �ver den.
* hoverTexture_:	Den textur som ska ritas upp p� knappen d� man h�ller musen �ver den.
* sprite_:			Den bild som ska ritas upp p� knappen.
* callback_:		Den funktion som anropas d� knappen klickas p�.
*
* REVISIONSBER�TTELSE
*
* Revision     Datum   F�r�ndringar
*
* 1            151214  Ursprungsversion
*
*/

class FrameButton
{
public:
	FrameButton(Application*,sf::Vector2f, sf::Vector2f, std::string, std::string, std::function<void (Application*)>);
	FrameButton(const FrameButton&) = delete;
	FrameButton& operator=(const FrameButton&) = delete;

	sf::Vector2f getPosition() const;
	sf::Vector2f getSize() const;

	void update();
	void render(GameWindow&);
	void clicked();
	bool mouseOnButton(sf::Vector2i);

private:
	Application* appPointer_;
	sf::Vector2f position_;
	sf::Vector2f size_;
	sf::Texture normalTexture_;
	sf::Texture hoverTexture_;
	sf::Sprite sprite_;
	std::function<void(Application*)> callback_;
}; // class FrameButton

   /*
   * SLUT P� FILEN FrameButton.h
   */