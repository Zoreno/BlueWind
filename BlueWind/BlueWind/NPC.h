/* IDENTIFIERING
*
* Filnamn:    NPC.h
* Enhetsnamn: NPC
* Typ:        Moduldeklaration
* Revision:   1
* Skriven av: Simon Arkeholt, Fredrik Gustafsson
*
*
* BESKRIVNING
*
* Denna modul representerar en NPC i spelet.
*
* REVISIONSBER�TTELSE
*
* Revision     Datum   F�r�ndringar
*
* 1            151214  Ursprungsversion
*
*/

#pragma once

/*
* REFERERADE BIBLIOTEK OCH MODULER
*/

#include "Entity.h"
#include "GameWindow.h"
#include <functional>

/*
* KLASS NPC
*
* BASKLASSER
*
* Entity
*
* BESKRIVNING
*
* Klassen representerar en NPC i spelet.
*
* TILLST�ND
*
* -
*
* KONSTRUKTORER
*
* NPC(int, int, int, int, std::string, sf::Vector2f, World*, sf::Texture&, std::string, std::function<void(NPC*)>)
* position:		Plats p� sk�rm d�r m�taren ska ritas.
* size:			Storlek p� m�taren.
* color:		F�rg p� m�taren.
* postfix:		Text som ska skrivas sist p� m�taren.
* uiPtr:		Pekare till anv�ndargr�nssnittet som m�taren �r en del av.
*
* OPERATIONER
*
* -
*
* DATAMEDLEMMAR
*
* sprite_:			Anger NPC:ns sprite.
* conversation_:	Anger NPC:ns konversation.
* callback_:		NPC:ns callbackfunktion.
*
* REVISIONSBER�TTELSE
*
* Revision     Datum   F�r�ndringar
*
* 1            151214  Ursprungsversion
*
*/

class NPC : public Entity
{
public:
	NPC(int, int, int, int, std::string, sf::Vector2f, World*, sf::Texture&, std::string, std::function<void(NPC*)>);
	NPC() = delete;
	NPC(const NPC&) = delete;
	NPC& operator=(const NPC&) = delete;

	void update() override;
	void render(GameWindow&) override;
	void talk() const;
	void interact();

	void die() override;
private:
	sf::Sprite sprite_;
	std::string conversation_;
	std::function<void(NPC*)> callback_;
}; //class NPC

   /*
   * SLUT P� FILEN NPC.h
   */
