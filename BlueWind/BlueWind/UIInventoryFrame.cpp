/*
* IDENTIFIERING
*
* Filnamn:    UIInventoryFrame.cpp
* Enhetsnamn: UIInventoryFrame
* Typ:        Definitioner h�rande till klass UIInventoryFrame
* Revision:   1
* Skriven av: Joakim Bertils, Johannes Grundell
*
*
* BESKRIVNING
*
* Denna implementeringsfil definierar medlemsfunktioner f�r klassen UIInventoryFrame.
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

#include <algorithm>
#include <string>
#include "UIInventoryFrame.h"

using namespace std;

/*
* KONSTRUKTOR UIInventoryFrame(UserInterface * uiPtr, Player * playerPtr)
*
* BESKRIVNING
*
* Denna konstruktor konstruerar ett f�nster f�r spelarens f�rem�l.
*
* INDATA
*
* uiPtr:		Pekare till anv�ndargr�nssnittet.
* playerPtr:	Pekare till spelaren.
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

UIInventoryFrame::UIInventoryFrame(UserInterface * uiPtr, Player * playerPtr)
	:UIComponent{ sf::Vector2f(480,50), sf::Vector2f(300,500), uiPtr, playerPtr , false}
{
	playerInventory_ = playerPtr->getInventory();
	inventorySize_ = playerInventory_->getMaxSize();
}

/*
* FUNKTION UIInventoryFrame::update()
*
* BESKRIVNING
*
* Uppdaterar f�rem�lsf�nstret.
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

void UIInventoryFrame::update() {}

/*
* FUNKTION UIInventoryFrame::render(GameWindow & window)
*
* BESKRIVNING
*
* Ritar f�rem�lsf�nstret p� window.
*
* INDATA
*
* window:	F�nster som f�rem�lsf�nstret ska ritas p�.
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

void UIInventoryFrame::render(GameWindow & window)
{
	sf::RectangleShape frame{ size_ };
	frame.setPosition(position_);
	frame.setFillColor(sf::Color{ 200,200,200,200 });
	frame.setOutlineColor(sf::Color{ 100,100,100,255 });
	frame.setOutlineThickness(4.0f);
	window.draw(frame);

	sf::Text conversationText{ "Inventory", ui_->getFont(), 40 };
	conversationText.setPosition(position_ + sf::Vector2f(10, 16 ));
	conversationText.setColor(sf::Color::Black);
	window.draw(conversationText);

	for (int i{ 0 }; i <  (min((int)inventorySize_, playerInventory_->getSize())); ++i)
	{
		Item* item = playerInventory_->at(i);
		item->render(window, position_ + sf::Vector2f(10.0f, 80.0f + 52.0f * i));

		sf::Text conversationText{ item->getName(), ui_->getFont(), 30 };
		conversationText.setPosition(position_ + sf::Vector2f(80.0f, 82.0f + 52.0f * i));
		conversationText.setColor(sf::Color::Black);
		window.draw(conversationText);
	}
}

/*
* FUNKTION UIInventoryFrame::handleKeyEvent(const sf::Event& ev)
*
* BESKRIVNING
*
* Hanterar tangentbordsh�ndelser.
*
* INDATA
*
* ev:	H�ndelse som ska behandlas.
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

void UIInventoryFrame::handleKeyEvent(const	sf::Event& ev)
{
	switch (ev.key.code)
	{
	case sf::Keyboard::L:
		toggleVisible();
		break;
	}
}

/*
* SLUT P� FILEN UIInventoryFrame.cpp
*/