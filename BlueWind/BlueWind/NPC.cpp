/* IDENTIFIERING
*
* Filnamn:    NPC.cpp
* Enhetsnamn: NPC
* Typ:        Definitioner h�rande till klass NPC
* Revision:   1
* Skriven av: Simon Arkeholt, Fredrik Gustafsson
*
*
* BESKRIVNING
*
* Denna implementeringsfil definierar medlemsfunktioner f�r klassen NPC.
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

#include "NPC.h"
#include "World.h"
#include "Universe.h"
#include "Game.h"

using namespace std;

/*
* KONSTRUKTOR NPC(int level, int health, int damage, int ID, std::string name, sf::Vector2f position, World * worldPtr, sf::Texture& texture, string conversation, std::function<void(NPC*)> callbackFunc)
*
* BESKRIVNING
*
* Denna konstruktor konstruerar en NPC.
*
* INDATA
*
* level:		NPC:ns level.
* health:		NPC:ns h�lsa.
* damage:		NPC:ns skadeverkan.
* ID:			NPC:ns ID.
* name:			NPC:ns namn.
* position:		NPC:ns position.
* worldPtr:		pekare till NPC:ns v�rld.
* texture:		NPC:ns textur.
* conversation:	NPC:ns konversation.
* callbackFunc:	NPC:ns interaktionsfunktion.
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

NPC::NPC(int level, int health, int damage, int ID, std::string name, sf::Vector2f position, World * worldPtr, sf::Texture& texture, string conversation, std::function<void(NPC*)> callbackFunc)
	: Entity(level, health, damage, ID, name, position, worldPtr, texture), 
	conversation_{ conversation }, 
	callback_{ callbackFunc }
{
	sprite_.setOrigin(sf::Vector2f(0.0f, 0.0f));
	sprite_.setPosition(position);
	sprite_.setTexture(texture);
}

/*
* FUNKTION NPC::update()
*
* BESKRIVNING
*
* Uppdaterar NPC:n.
*
* INDATA
*
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

void NPC::update()
{
}

/*
* FUNKTION NPC::render(GameWindow & window)
*
* BESKRIVNING
*
* Ritar NPC:n.
*
* INDATA
*
* window:		F�nster som NPC:n ska ritas p�.
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

void NPC::render(GameWindow & window)
{
	sprite_.setPosition(position_);
	window.draw(sprite_);
}

/*
* FUNKTION NPC::talk() const
*
* BESKRIVNING
*
* L�gger till NPC:ns konversation till chatboxen.
*
* INDATA
*
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

void NPC::talk() const
{
	if (conversation_.size() == 0) return;
	worldPointer_->getUniverse()->getGame()->getUserInterface()->addStringToChatBox(conversation_);
}

/*
* FUNKTION NPC::interact()
*
* BESKRIVNING
*
* Kallar p� talk och NPC:ns callbackfunktion.
*
* INDATA
*
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

void NPC::interact()
{
	talk();
	callback_(this);
}

/*
* FUNKTION NPC::die()
*
* BESKRIVNING
*
* Tar bort NPC:n fr�n spelv�rlden.
*
* INDATA
*
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

void NPC::die()
{
	worldPointer_->removeNPC(this);
}

/*
* SLUT P� FILEN NPC.cpp
*/
