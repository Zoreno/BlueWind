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
* Denna modul representerar ett f�nster p� anv�ndargr�nssnittet som visar
* spelarens f�rem�l.
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

/*
* KLASS UIInventoryFrame
*
* BASKLASSER
*
* UIComponent
*
* BESKRIVNING
*
* Klassen representerar ett f�nster f�r att visa spelarens f�rem�l.
*
* KONSTRUKTORER
*
* UIInventoryFrame(UserInterface * uiPtr, Player * playerPtr)
*
* DATAMEDLEMMAR
*
* playerInventory_:		Pekare till spelarens inventory
* inventorySize_:		Maxstorlek p� spelarens inventory
*
* REVISIONSBER�TTELSE
*
* Revision     Datum   F�r�ndringar
*
* 1            151120  Ursprungsversion
*
*/

class UIInventoryFrame : public UIComponent
{
public:
	UIInventoryFrame(UserInterface*, Player*);
	UIInventoryFrame() = delete;
	UIInventoryFrame(const UIInventoryFrame&) = delete;
	UIInventoryFrame& operator=(const UIInventoryFrame&) = delete;

	void update();
	void render(GameWindow&);
	void handleKeyEvent(const sf::Event&);

private:
	Inventory* playerInventory_;
	unsigned int inventorySize_;
};//class UIInventoryFrame

/*
* SLUT P� FILEN UI�nventoryFrame.h
*/

