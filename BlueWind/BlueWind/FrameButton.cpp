/*
* IDENTIFIERING
*
* Filnamn:    FrameButton.cpp
* Enhetsnamn: FrameButton
* Typ:        Definitioner h�rande till klassen FrameButton
* Revision:   1
* Skriven av: Simon Arkholt, Fredrik Gustafsson
*
*
* BESKRIVNING
*
* Denna implementeringsfil definierar medlemsfunktioner f�r klassen FrameButton.
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

#include "FrameButton.h"
#include "Application.h"

using namespace std;

/*
* KONSTRUKTOR FrameButton::FrameButton(Application* appPtr, sf::Vector2f pos, sf::Vector2f size, std::string normalFile, std::string hoverFile, std::function<void(Application*)> callbackFunc)
*
* BESKRIVNING
*
* Denna konstruktor skapar en knapp.
*
* INDATA
*
* appPtr:		Pekare till applikationen som knappen ska vara en del av.
* pos:			Knappens position.
* size:			Knappens storlek.
* normalFile:	Fil som inneh�ller knappens "normalTexture_".
* hoverFile:	Fil som inneh�ller knappens "hoverTexture_".
* callbackFunc	Funktionen som anropas d� knappen klickas p�.
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

FrameButton::FrameButton(Application* appPtr, sf::Vector2f pos, sf::Vector2f size, std::string normalFile, std::string hoverFile, std::function<void(Application*)> callbackFunc)
	: appPointer_{ appPtr },
	position_{ pos },
	size_{ size },
	callback_{ callbackFunc }
{
	if (!normalTexture_.loadFromFile(normalFile))
		throw FrameButtonException("Kunde inte l�sa in textur f�r knapp fr�n fil:" + normalFile);
	if (!hoverTexture_.loadFromFile(hoverFile))
		throw FrameButtonException("Kunde inte l�sa in textur f�r knapp fr�n fil:" + hoverFile);
}

/*
* FUNKTION FrameButton::getPosition()
*
* BESKRIVNING
*
* H�mtar knappens position.
*
* INDATA
*
* -
*
* UTDATA
*
* sf::Vector2f: Knappens position.
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151214          Ursprungsversion
*
*/

sf::Vector2f FrameButton::getPosition() const
{
	return position_;
}

/*
* FUNKTION FrameButton::getSize()
*
* BESKRIVNING
*
* H�mtar knappens storlek.
*
* INDATA
*
* -
*
* UTDATA
*
* sf::Vector2f: Knappens storlek.
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151214          Ursprungsversion
*
*/

sf::Vector2f FrameButton::getSize() const
{
	return size_;
}

/*
* FUNKTION FrameButton::update()
*
* BESKRIVNING
*
* Uppdaterar knappen.
*
* INDATA
*
* -
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

void FrameButton::update()
{
	sf::Vector2i mousePosition{ appPointer_->getGameWindow().mapPixelToCoords(sf::Mouse::getPosition(appPointer_->getGameWindow())) };

	if (mouseOnButton(mousePosition))
		sprite_.setTexture(hoverTexture_);
	else
		sprite_.setTexture(normalTexture_);
}

/*
* FUNKTION FrameButton::render(GameWindow& window)
*
* BESKRIVNING
*
* Ritar upp knappen.
*
* INDATA
*
* window: F�nster som knappen ska ritas upp i.
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

void FrameButton::render(GameWindow& window)
{
	sprite_.setPosition(position_);
	window.draw(sprite_);
}

/*
* FUNKTION FrameButton::clicked()
*
* BESKRIVNING
*
* Funktionen som anropas d� knappen klickas p�.
*
* INDATA
*
* -
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

void FrameButton::clicked()
{
	appPointer_->getSoundHandler().playSound("menuClick");
	callback_(appPointer_);
}

/*
* FUNKTION FrameButton::mouseOnButton(sf::Vector2i mousePosition)
*
* BESKRIVNING
*
* Kontrollerar om musen h�lls �ver knappen.
*
* INDATA
*
* mousePosition: Musens position.
*
* UTDATA
*
* bool: Anger om musen h�lls �ver knappen (true) eller ej.
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151214          Ursprungsversion
*
*/

bool FrameButton::mouseOnButton(sf::Vector2i mousePosition)
{
	return (mousePosition.x > position_.x && mousePosition.x < position_.x + size_.x &&
			mousePosition.y > position_.y && mousePosition.y < position_.y + size_.y);
}

/*
* SLUT P� FILEN FrameButton.cpp
*/