/*
* IDENTIFIERING
*
* Filnamn:    Animation.h
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

#pragma once

/*
* REFERERADE BIBLIOTEK OCH MODULER
*/

#include <vector>
#include <string>
#include <SFML\Graphics.hpp>
#include "GameWindow.h"

/*
* FRAM�TDEKLARATIONER
*/

class Entity;

/*
* KLASS Animation
*
* BASKLASSER
*
* -
*
* BESKRIVNING
*
* Klassen representerar en animation f�r ett entity-objekt
*
* TILLST�ND
*
* -
*
* KONSTRUKTORER
*
* Animation(Entity* entityPointer, sf::Texture& tex)
* entityPointer:		En pekare till det entity-objekt som animationen �r		
*						kopplad till
* tex:					Det texturobjekt som ska flyttas in i spriten.
*
* OPERATIONER
*
* -
*
* DATAMEDLEMMAR
*
* currentSprite_ :		Den nuvarande spriten som ska ritas ut.
* texture_ :			Texturen som anv�nds i spriten.
* counter_ :			R�knare som styr uppdateringsfrekvensen.
* animState_ :			State som h�ller reda p� vad vi ska plocka ur 
*						sprite-sheetet.
* attackCounter_ :		R�knare som h�ller kvar attack-spriten en 
*						liten extra stund.
*
* REVISIONSBER�TTELSE
*
* Revision     Datum   F�r�ndringar
*
* 1            151120  Ursprungsversion
*
*/

class Animation
{
public:
	Animation(Entity*, sf::Texture&);
	Animation() = delete;
	Animation(const Animation&) = delete;
	Animation& operator=(const Animation&) = delete;

	void update(int,int, bool);
	void render(GameWindow&);

private:
	sf::Sprite currentSprite_;
	sf::Texture& texture_;

	int counter_;
	int animState_;
	int attackCounter_;

	Entity* entityPtr_;
}; //Class Animation

  /*
  * SLUT P� FILEN Animation.h
  */