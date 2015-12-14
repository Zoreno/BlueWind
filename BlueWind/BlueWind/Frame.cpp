/*
* IDENTIFIERING
*
* Filnamn:    Frame.cpp
* Enhetsnamn: Frame
* Typ:        Definitioner h�rande till klassen Frame
* Revision:   1
* Skriven av: Joakim Bertils, Johannes Grundell
*
*
* BESKRIVNING
*
* Denna implementeringsfil definierar medlemsfunktioner f�r klassen Frame.
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

#include "Frame.h"

using namespace std;

/*
* KONSTRUKTOR rame::Frame(Application* appPtr)
*
* BESKRIVNING
*
* Denna konstruktor skapar ett Frame-objekt.
*
* INDATA
*
* appPtr: Pekare till applikationen.
*
* UTDATA
*
* -
*
* SIDOEFFEKTER
*
* -
*
* UTNYTTJAR
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

Frame::Frame(Application* appPtr)
	: appPointer_(appPtr)
{
}

/*
* DESTRUKTOR Frame::~Frame()
*
* BESKRIVNING
*
* Denna destruktor destruerar ett Frame-objekt
*
* INDATA
*
* -
*
* UTDATA
*
* -
*
* SIDOEFFEKTER
*
* -
*
* UTNYTTJAR
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

Frame::~Frame()
{
	while (!buttons_.empty())
	{
		delete buttons_.back();
		buttons_.pop_back();
	}
}

/*
* FUNKTION Frame::addButton(sf::Vector2f pos, sf::Vector2f size, std::string normalFile, std::string hoverFile, std::function<void(Application*)> callback)
*
* BESKRIVNING
*
* L�gger till en knapp i Frame-objektet.
*
* INDATA
*
* pos:			Knappens position.
* size:			Knappens storlek.
* normalFile:	Fil som inneh�ller knappens "normalTexture_".
* hoverFile:	Fil som inneh�ller knappens "hoverTexture_".
* callback		Funktionen som anropas d� knappen klickas p�.
*
* UTDATA
*
* -
*
* SIDOEFFEKTER
*
* -
*
* UTNYTTJAR
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

void Frame::addButton(sf::Vector2f pos, sf::Vector2f size, std::string normalFile, std::string hoverFile, std::function<void(Application*)> callback)
{
	buttons_.push_back(new FrameButton(appPointer_, pos, size, normalFile, hoverFile, callback));
}

/*
* SLUT P� FILEN Frame.cpp
*/