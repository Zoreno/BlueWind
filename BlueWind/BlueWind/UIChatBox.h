/*
* IDENTIFIERING
*
* Filnamn:    UIChatBox.h
* Enhetsnamn: UIChatBox
* Typ:        Moduldeklaration
* Revision:   1
* Skriven av: Joakim Bertils, Johannes Grundell
*
*
* BESKRIVNING
*
* Denna modul representerar en m�tare p� anv�ndargr�nssnittet.
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

#include "UIComponent.h"
#include "UserInterface.h"
#include <deque>

/*
* KLASS UIChatBox
*
* BASKLASSER
*
* UIComponent
*
* BESKRIVNING
*
* Klassen representerar en textruta p� anv�ndargr�nssnittet.
*
* TILLST�ND
*
* -
*
* KONSTRUKTORER
*
* UIChatBox(UserInterface* uiPtr, Player* playerPtr)
*
* OPERATIONER
*
* -
*
* DATAMEDLEMMAR
*
* inputBuffer_:	Buffer d�r texten i rutan lagras.
*
* REVISIONSBER�TTELSE
*
* Revision     Datum   F�r�ndringar
*
* 1            151120  Ursprungsversion
*
*/

class UIChatBox : public UIComponent
{
public:
	UIChatBox(UserInterface*, Player*);
	UIChatBox() = delete;
	UIChatBox(const UIChatBox&) = delete;
	UIChatBox& operator=(const UIChatBox&) = delete;

	void handleKeyEvent(const sf::Event&) override;
	void update() override;
	void render(GameWindow&) override;

	void setConversation(const std::string&);
private:
	std::deque<std::string> inputBuffer_;
}; //class UIChatBox

/*
 * SLUT P� FILEN UIChatBox.h
 */
