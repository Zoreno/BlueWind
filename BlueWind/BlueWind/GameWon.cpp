/*
* IDENTIFIERING
*
* Filnamn:    GameWon.cpp
* Enhetsnamn: GameWon
* Typ:        Definitioner h�rande till klassen GameWon
* Revision:   1
* Skriven av: Simon Arkholt, Fredrik Gustafsson
*
*
* BESKRIVNING
*
* Denna implementeringsfil definierar medlemsfunktioner f�r klassen GameWon.
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

#include "GameWon.h"
#include "Application.h"

using namespace std;

/*
* CALLBACK-FUNKTIONER (DEKLARATIONER)
*/

void mainMenuCallback(Application*);	// Funktionen som k�rs d� man klickar p� knappen "Main Menu"

/*
* KONSTRUKTOR GameWon::GameWon(Application* appPtr)
*
* BESKRIVNING
*
* Denna konstruktor skapar ett GameWon-objekt.
*
* INDATA
*
* appPtr: Pekare till applikationen som GameWon-objektet �r en del av.
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

GameWon::GameWon(Application* appPtr)
	: Frame{ appPtr }
{
	addButton(sf::Vector2f(400 - 175, 350), sf::Vector2f(350, 100), "res/textures/menuButton.png", "res/textures/menuButtonHover.png", mainMenuCallback);
	appPtr->getSoundHandler().playMusic("gameWonMusic");
}

/*
* FUNKTION GameWon::handleKeyEvent(sf::Event event)
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

void GameWon::handleKeyEvent(sf::Event event) {}

/*
* FUNKTION GameWon::handleMouseEvent(sf::Event event)
*
* BESKRIVNING
*
* Hanterar musklick (v�nster) p� menyns knappar.
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

void GameWon::handleMouseEvent(sf::Event event)
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
* FUNKTION GameWon::update()
*
* BESKRIVNING
*
* Uppdaterar menyns knappar.
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

void GameWon::update()
{
	for (auto it : buttons_)
	{
		it->update();
	}
}

/*
* FUNKTION GameWon::render(GameWindow& window)
*
* BESKRIVNING
*
* Ritar upp menyn.
*
* INDATA
*
* window: F�nster som menyn ska ritas upp i.
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

void GameWon::render(GameWindow& window)
{
	sf::Texture bTexture;
	if (!bTexture.loadFromFile("res/textures/GameWon.png"))
		throw FrameException("Kunde inte l�sa in bild f�r GameWon: res/textures/GameWon.png");

	background_.setTexture(bTexture);
	window.draw(background_);

	for (auto it : buttons_)
	{
		it->render(window);
	}
}

/*
* FUNKTION mainMenuCallback(Application* ptr)
*
* BESKRIVNING
*
* Funktionen som k�rs d� man klickar p� knappen "Main Menu". G�r ur menyn och �ppnar startmenyn.
*
* INDATA
*
* ptr: Pekare till applikationen som menyn �r en del av.
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

void mainMenuCallback(Application* ptr)
{
	ptr->setNextFrame(new Menu(ptr));
}

/*
* SLUT P� FILEN GameWon.cpp
*/