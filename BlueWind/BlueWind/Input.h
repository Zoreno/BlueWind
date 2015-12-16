/*
* IDENTIFIERING
*
* Filnamn:    Input.h
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

#pragma once

/*
* REFERERADE BIBLIOTEK OCH MODULER
*/

#include <map>
#include "GameWindow.h"
#include "FrameButton.h"

/*
* KLASS Input
*
* BASKLASSER
*
* -
*
* BESKRIVNING
*
* Klassen hanterar input fr�n anv�ndaren
*
* KONSTRUKTORER
*
* Input(Application * appPtr)
* appPtr :				En pekare till applikationen
*
* DATAMEDLEMMAR
*
* appPointer_ :			En pekare till applikationen
* pressedButtons_ :		En map som inneh�ller de knappar som trycks ner
*
* REVISIONSBER�TTELSE
*
* Revision     Datum   F�r�ndringar
*
* 1            151120  Ursprungsversion
*
*/

class Input
{
public:
	Input(Application*);
	Input(const Input&) = delete;
	Input() = delete;
	Input& operator=(const Input&) = delete;

	bool isPressed(char) const;

	void update();

	void keyPressed(sf::Event);
	void mousePressed(sf::Event);

private:
	Application* appPointer_;
	std::map<char, bool> pressedButtons_;
};//Class Input

/*
* Slut p� filen Input.h
*/