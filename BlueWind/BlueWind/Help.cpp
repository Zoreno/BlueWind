/*
* IDENTIFIERING
*
* Filnamn:    Help.cpp
* Enhetsnamn: Help
* Typ:        Definitioner h�rande till klassen Help
* Revision:   1
* Skriven av: Simon Arkholt, Fredrik Gustafsson
*
*
* BESKRIVNING
*
* Denna implementeringsfil definierar medlemsfunktioner f�r klassen Help.
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

#include "Help.h"
#include "Application.h"

using namespace std;

/*
* CALLBACK-FUNKTIONER (DEKLARATIONER)
*/

void helpMenuCallback(Application*);	// Funktionen som k�rs d� man klickar p� knappen "Main Menu"

/*
* KONSTRUKTOR Help(Application* appPtr)
*
* BESKRIVNING
*
* Denna konstruktor skapar ett Help-objekt.
*
* INDATA
*
* appPtr: Pekare till applikationen som Help-objektet �r en del av.
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

Help::Help(Application* appPtr)
	: Frame{ appPtr }
{
	addButton(sf::Vector2f(400 - 175, 365), sf::Vector2f(350, 100), "res/textures/menuButton.png", "res/textures/menuButtonHover.png", helpMenuCallback);
}

/*
* FUNKTION Help::handleKeyEvent(sf::Event event)
*
* BESKRIVNING
*
* Hanterar ett tangenttryck genom att inte g�ra n�got med det.
*
* INDATA
*
* event: Ett tangenttryck
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

void Help::handleKeyEvent(sf::Event event) {}

/*
* FUNKTION Help::handleMouseEvent(sf::Event event)
*
* BESKRIVNING
*
* Hanterar musklick (v�nster) p� undermenyns knappar.
*
* INDATA
*
* event: Ett musklick
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

void Help::handleMouseEvent(sf::Event event)
{
	switch (event.mouseButton.button)
	{
	case sf::Mouse::Left:
	{
		sf::Vector2i mousePosition{ appPointer_->getGameWindow().mapPixelToCoords(sf::Mouse::getPosition(appPointer_->getGameWindow())) };

		for (auto it : buttons_)
		{
			if (it->mouseOnButton(mousePosition))
			{
				it->clicked();
				break;
			}
		}
	}
	default:
		break;
	}
}

/*
* FUNKTION Help::update()
*
* BESKRIVNING
*
* Uppdaterar undermenyns knappar.
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
* 1                    151214          Ursprungsversion
*
*/

void Help::update()
{
	for (auto it : buttons_)
	{
		it->update();
	}
}

/*
* FUNKTION Help::render(GameWindow& window)
*
* BESKRIVNING
*
* Ritar upp undermenyn.
*
* INDATA
*
* window: F�nster som undermenyn ska ritas upp i.
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

void Help::render(GameWindow& window)
{
	sf::Texture bTexture;
	if (!bTexture.loadFromFile("res/textures/help.png"))
		throw FrameException("Kunde inte l�sa in bild f�r Help: res/textures/help.png");

	background_.setTexture(bTexture);
	window.draw(background_);

	for (auto it : buttons_)
	{
		it->render(window);
	}
}

/*
* FUNKTION helpMenuCallback(Application* ptr)
*
* BESKRIVNING
*
* Funktionen som k�rs d� man klickar p� knappen "Main Menu". G�r ur undermenyn och �ppnar startmenyn.
*
* INDATA
*
* ptr: Pekare till applikationen som undermenyn �r en del av.
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

void helpMenuCallback(Application* ptr)
{
	ptr->setNextFrame(new Menu(ptr));
}

/*
* SLUT P� FILEN Help.cpp
*/