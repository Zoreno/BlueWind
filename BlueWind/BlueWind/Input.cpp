/*
* IDENTIFIERING
*
* Filnamn:    Input.cpp
* Enhetsnamn: Input
* Typ:        Definitioner h�rande till klass Input
* Revision:   1
* Skriven av: Olle Andersson, Jonas Ehn
*
*
* BESKRIVNING
*
* Denna implementeringsfil definierar medlemsfunktioner f�r klassen Input.
*
* REVISIONSBER�TTELSE
*
* Revision     Datum   F�r�ndringar
*
* 1            151120  Ursprungsversion
*/

/*
* REFERERADE BIBLIOTEK OCH MODULER
*/

#include <SFML\Graphics.hpp>
#include "Input.h"
#include "Application.h"

using namespace std;

/*
* KONSTRUKTOR Input(Application * appPtr)
*
* BESKRIVNING
*
* Denna konstruktor konstruerar ett input-objekt.
*
* INDATA
*
* appPtr:		En pekare till applikationen
*
* UTDATA
*
* -
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

Input::Input(Application * appPtr)
	: appPointer_(appPtr)
{
	pressedButtons_.emplace('a', false);
	pressedButtons_.emplace('d', false);
	pressedButtons_.emplace('s', false);
	pressedButtons_.emplace('w', false);
}

/*
* FUNKTION Input::isPressed(char c) const
*
* BESKRIVNING
*
* �r den h�r knappen intryckt?
*
* INDATA
*
* c:		En knapp p� tangentbordet
*
* UTDATA
*
* bool :	Var knappen tryckt?
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

bool Input::isPressed(char c) const
{
	return pressedButtons_.find(c)->second;
}

/*
* FUNKTION Input::update()
*
* BESKRIVNING
*
* En funktion som uppdaterar input-objektet
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
* 1                    151120          Ursprungsversion
*
*/

void Input::update()
{
	try
	{
		pressedButtons_.at('w') = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
		pressedButtons_.at('a') = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
		pressedButtons_.at('s') = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
		pressedButtons_.at('d') = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	}
	catch (const out_of_range& e)
	{
		throw;
	}
}

/*
* FUNKTION Input::keyPressed(sf::Event event)
*
* BESKRIVNING
*
* En funktion som hanterar vad som h�nder d� en knapp trycks p� tangentbordet
*
* INDATA
*
* event :	Ett eventobjekt f�r input-h�ndelser
*
* UTDATA
*
* -
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

void Input::keyPressed(sf::Event event)
{
	appPointer_->getCurrentFrame()->handleKeyEvent(event);
}

/*
* FUNKTION Input::mousePressed(sf::Event event)
*
* BESKRIVNING
*
* En funktion som hanterar vad som h�nder d� en knapp trycks p� musen
*
* INDATA
*
* event :	Ett eventobjekt f�r input-h�ndelser
*
* UTDATA
*
* -
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

void Input::mousePressed(sf::Event event)
{
	appPointer_->getCurrentFrame()->handleMouseEvent(event);
}

/*
* Slut p� filen Input.cpp
*/