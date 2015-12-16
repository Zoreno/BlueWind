/*
* IDENTIFIERING
*
* Filnamn:    Animation.cpp
* Enhetsnamn: Animation
* Typ:        Definitioner h�rande till klass Animation
* Revision:   1
* Skriven av: Joakim Bertils, Jonas Ehn
*
*
* BESKRIVNING
*
* Denna implementeringsfil definierar medlemsfunktioner f�r klassen Animation.
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

#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Entity.h"

using namespace std;

/*
* Animation(Entity* entityPointer, sf::Texture& tex)
*
* BESKRIVNING
*
* Denna konstruktor konstruerar en animation.
*
* INDATA
*
* entityPointer:		En pekare till det entity-objekt som animationen �r
*						kopplad till
* tex:					Det texturobjekt som ska flyttas in i spriten.
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

Animation::Animation(Entity* entityPointer, sf::Texture& tex)
	: entityPtr_{entityPointer}, 
	texture_{tex}
{
	currentSprite_.setTexture(tex);
}

/*
* FUNKTION update(int state, int dir, bool walking)
*
* BESKRIVNING
*
* Denna funktion uppdaterar den nuvarande spriten
*
* INDATA
*
* state:				Det nuvarande tillst�ndet
* dir:					Den riktining som entityn �r v�nd �t
* walking:				En bool som avg�r om vi r�r oss eller inte
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

void Animation::update(int state, int dir, bool walking)
{
	animState_ = state;
	if (state == Entity::STATES::attacking)
	{
		if (attackCounter_ % 15 == 14)
		{
			entityPtr_->animState_ = Entity::STATES::walking1;
			attackCounter_ = 0;
		}
		attackCounter_++;
		return;
	}
	if (state == Entity::STATES::spell)
	{
		if (attackCounter_ % 15 == 14)
		{
			entityPtr_->animState_ = Entity::STATES::walking1;
			attackCounter_ = 0;
		}
		attackCounter_++;
		return;
	}
	if (walking && (counter_ % 20) == 0)
	{
		switch (state)
		{
		case Entity::STATES::walking1:
			entityPtr_->animState_ = Entity::STATES::walking2;
			break;
		case Entity::STATES::walking2:
			entityPtr_->animState_ = Entity::STATES::walking1;
			break;
		case Entity::STATES::attacking:
			break;
		}
	}
	counter_++;
}

/*
* FUNKTION render(GameWindow& window)
*
* BESKRIVNING
*
* Denna funktion ritar upp den nuvarande spriten
*
* INDATA
*
* window:				F�nstret i vilket vi ska rita spriten.
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

void Animation::render(GameWindow& window)
{
	sf::Rect<int> rect(32 * (animState_ + 4 * entityPtr_->dir_), 0, 32, 32);
	currentSprite_.setTextureRect(rect);
	currentSprite_.setPosition(entityPtr_->getPosition());
	window.draw(currentSprite_);
}

/*
* SLUT P� FILEN Animation.cpp
*/