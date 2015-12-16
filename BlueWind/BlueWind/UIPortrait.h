/*
* IDENTIFIERING
*
* Filnamn:    UIInventoryFrame.h
* Enhetsnamn: UIInventoryFrame
* Typ:        Moduldeklaration
* Revision:   1
* Skriven av: Joakim Bertils, Johannes Grundell
*
*
* BESKRIVNING
*
* Denna modul representerar en ruta p� anv�ndargr�nssnittet som visar
* spelarens attribut.
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
#include "UIBar.h"
#include "UserInterface.h"

/*
* KLASS UIPortrait
*
* BASKLASSER
*
* UIComponent
*
* BESKRIVNING
*
* Klassen representerar en ruta p� anv�ndargr�nssnittet som visar
* spelarens attribut.
*
* TILLST�ND
*
* -
*
* KONSTRUKTORER
*
* UIPortrait(UserInterface * uiPtr, Player * playerPtr)
*
* OPERATIONER
*
* -
*
* DATAMEDLEMMAR
*
* healthBar_:	M�tarobjekt som visar spelarens h�lsa.
* manaBar_:		M�tarobjekt som visar spelarens energi.
* expBar_:		M�tarobjekt som visar spelarens erfarenhet.
*
* REVISIONSBER�TTELSE
*
* Revision     Datum   F�r�ndringar
*
* 1            151120  Ursprungsversion
*
*/

class UIPortrait : public UIComponent
{
public:
	UIPortrait(UserInterface*, Player*);
	UIPortrait() = delete;
	UIPortrait(const UIPortrait&) = delete;
	UIPortrait& operator=(const UIPortrait&) = delete;

	void handleKeyEvent(const sf::Event&) override;
	void update() override;
	void render(GameWindow&) override;

private:
	UIBar healthBar_;
	UIBar manaBar_;
	UIBar expBar_;
};//class UIInventoryFrame

/*
 * SLUT P� FILEN UI�nventoryFrame.h
 */