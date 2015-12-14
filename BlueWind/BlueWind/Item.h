/*
* IDENTIFIERING
*
* Filnamn:    Item.h
* Enhetsnamn: Item
* Typ:        Moduldeklaration
* Revision:   1
* Skriven av: Joakim Bertils, Johannes Grundell
*
*
* BESKRIVNING
*
* Denna modul representerar f�rem�l i spelet.
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

#include "GameWindow.h"
#include <string>
#include <SFML\Graphics.hpp>

/*
* KLASS Item
*
* BASKLASSER
*
* -
*
* BESKRIVNING
*
* Klassen representerar f�rem�l i spelet
*
* TILLST�ND
*
* -
*
* KONSTRUKTORER
*
* Item(int, std::string name, sf::Texture& texture);
*
* OPERATIONER
*
* -
*
* DATAMEDLEMMAR
*
* name_:	Anger namnet p� f�rem�let.
* ID_:		Anger f�rem�lets ID.
* sprite_:	Spriten som anv�nds som ikon f�r f�rem�let.
*
* REVISIONSBER�TTELSE
*
* Revision     Datum   F�r�ndringar
*
* 1            151120  Ursprungsversion
*
*/

class Item
{
public:
	Item(int, std::string, sf::Texture&);
	Item() = delete;
	Item(const Item&) = delete;
	Item& operator=(const Item&) = delete;

	const std::string& getName();
	const int getID();
	const sf::Sprite& getSprite() const;

	void render(GameWindow&, sf::Vector2f);

private:
	std::string name_;
	int ID_;
	sf::Sprite sprite_;
};//class Item

/*
  * SLUT P� FILEN Item.h
	  */