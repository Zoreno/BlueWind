/*
* IDENTIFIERING
*
* Filnamn:    UIChatBox.cpp
* Enhetsnamn: UIChatBox
* Typ:        Definitioner h�rande till klass UIChatBox
* Revision:   1
* Skriven av: Joakim Bertils, Johannes Grundell
*
*
* BESKRIVNING
*
* Denna implementeringsfil definierar medlemsfunktioner f�r klassen UIChatBox.
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

#include "UIChatBox.h"
#include <iostream>

using namespace std;

/*
* KONSTRUKTOR UIChatBox(UserInterface* uiPtr, Player* playerPtr)
*
* BESKRIVNING
*
* Denna konstruktor konstruerar en m�tare.
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

UIChatBox::UIChatBox(UserInterface* uiPtr, Player* playerPtr)
	:UIComponent{ sf::Vector2f(10,450), sf::Vector2f(300,100), uiPtr, playerPtr }
{}

/*
* FUNKTION UIChatBox::handleKeyEvent(sf::Event ev)
*
* BESKRIVNING
*
* Hanterar tangenth�ndelser.
*
* INDATA
*
* ev:	Eventobjekt som ska behandlas
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

void UIChatBox::handleKeyEvent(sf::Event ev) {}

/*
* FUNKTION UIChatBox::update()
*
* BESKRIVNING
*
* Uppdaterar textrutan.
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

void UIChatBox::update()
{
	if (inputBuffer_.size() > 4)
	{
		inputBuffer_.pop_back();
	}
}

/*
* FUNKTION UIChatBox::render(GameWindow & window)
*
* BESKRIVNING
*
* Ritar upp textrutan p� f�nstret window.
*
* INDATA
*
* window:	F�nster som textrutan ska ritas p�.
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

void UIChatBox::render(GameWindow & window)
{
	sf::RectangleShape frame{ size_ };
	frame.setPosition(position_);
	frame.setFillColor(sf::Color{ 200,200,200,150 });
	frame.setOutlineColor(sf::Color{ 100,100,100,255 });
	frame.setOutlineThickness(4.0f);
	window.draw(frame);

	for (int i{ 0 }; i < (min(4, (int)inputBuffer_.size())); ++i)
	{
		sf::Text conversationText{ inputBuffer_.at(i), ui_->getFont(), 20 };
		conversationText.setPosition(position_ + sf::Vector2f(0, 24.0f*(3 - i)));
		conversationText.setColor(sf::Color::Black);
		window.draw(conversationText);
	}
}

/*
* FUNKTION UIChatBox::setConversation(const std::string& newConversation)
*
* BESKRIVNING
*
* L�gger till en textstr�ng i textrutan. Om textstr�ngen b�rjar med en '*' kommer
* bufferten att t�mmas innan ins�ttning.
*
* INDATA
*
* newConversation:	textstr�ng som ska s�ttas in
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

void UIChatBox::setConversation(const std::string& newConversation)
{
	if (newConversation.at(0) == '*')
	{
		inputBuffer_.clear();
		inputBuffer_.push_front(newConversation.substr(1, newConversation.length() - 1));
		return;
	}
	inputBuffer_.push_front(newConversation);
}

/*
* SLUT P� FILEN UIChatBox.cpp
*/