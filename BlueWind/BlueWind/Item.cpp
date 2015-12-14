/*
* IDENTIFIERING
*
* Filnamn:    Item.cpp
* Enhetsnamn: Item
* Typ:        Definitioner h�rande till klass Item
* Revision:   1
* Skriven av: Joakim Bertils, Johannes Grundell
*
*
* BESKRIVNING
*
* Denna implementeringsfil definierar medlemsfunktioner f�r klassen Item.
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

#include "Item.h"
#include "GameWindow.h"

using namespace std;

/*
* KONSTRUKTOR Item(int ID, string name, sf::Texture& texture)
*
* BESKRIVNING
*
* Denna konstruktor konstruerar ett f�rem�l.
*
* INDATA
*
* ID:		F�rem�lets ID.
* name:		F�rem�lets namn.
* texture:	Textur f�r f�rem�let.
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
* modul: std::string
* modul: sfml-grafik
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

Item::Item(int ID, string name, sf::Texture& texture)
	:	ID_{ID}, 
		name_{name}
{
	sprite_.setOrigin(sf::Vector2f(0.0f, 0.0f));
	sprite_.setTexture(texture);
	sprite_.setScale(sf::Vector2f(1.5f, 1.5f));
}

/*
* FUNKTION Item::getName()
*
* BESKRIVNING
*
* H�mtar namn p� f�rem�let.
*
* INDATA
*
* -
*
* UTDATA
*
* string: F�rem�lets namn
*
* SIDOEFFEKTER
*
* -
*
* UTNYTTJAR
*
* modul: std::string
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

const string& Item::getName()
{
	return name_;
}

/*
* FUNKTION Item::getID()
*
* BESKRIVNING
*
* H�mtar ID p� f�rem�let.
*
* INDATA
*
* -
*
* UTDATA
*
* int: F�rem�lets ID.
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

const int Item::getID()
{
	return ID_;
}

/*
* FUNKTION Item::getSprite()
*
* BESKRIVNING
*
* H�mtar textur f�r f�rem�let.
*
* INDATA
*
* 
*
* UTDATA
*
* sf::Sprite&: F�rem�lets textur.
*
* SIDOEFFEKTER
*
* -
*
* UTNYTTJAR
*
* modul: sfml-grafik
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

const sf::Sprite& Item::getSprite() const
{
	return sprite_;
}

/*
* FUNKTION Item::render(GameWindow & window, sf::Vector2f pos)
*
* BESKRIVNING
*
* Renderar f�rem�let.
*
* INDATA
*
* window:	F�nstet som f�rem�let renderas i.
* pos:		Position som f�rem�let renderas p�.
*
* UTDATA
*
* 
*
* SIDOEFFEKTER
*
* -
*
* UTNYTTJAR
*
* modul: sfml-grafik
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

void Item::render(GameWindow & window, sf::Vector2f pos)
{
	sprite_.setPosition(pos);
	window.draw(sprite_);
}

/*
* SLUT P� FILEN Item.cpp
*/