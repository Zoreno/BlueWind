/*
* IDENTIFIERING
*
* Filnamn:    Tile.cpp
* Enhetsnamn: Tile
* Typ:        Definitioner h�rande till klassen Tile
* Revision:   1
* Skriven av: Joakim Bertils, Johannes Grundell
*
*
* BESKRIVNING
*
* Denna implementeringsfil definierar medlemsfunktioner f�r klassen Tile.
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

#include "Tile.h"

/*
* KONSTRUKTOR Tile::Tile(sf::Texture& texture, bool walkable)
*
* BESKRIVNING
*
* Denna konstruktor skapar en ruta (tile).
*
* INDATA
*
* texture: Rutans textur.
* walkable: Anger om man ska kunna g� p� rutan (true) eller ej.
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

Tile::Tile(sf::Texture& texture, bool walkable)
	: walkable_{ walkable }
{
	sprite_.setOrigin(sf::Vector2f(0.0f, 0.0f));
	sprite_.setTexture(texture);
}

/*
* FUNKTION Tile::render(GameWindow& window, int x, int y)
*
* BESKRIVNING
*
* Ritar upp rutan.
*
* INDATA
*
* window:	F�nster som rutan ska ritas upp i.
* x:		x-positionen d�r rutan ska ritas.
* y:		y-positionen d�r rutan ska ritas.
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

void Tile::render(GameWindow& window, int x, int y)
{
	sprite_.setPosition(static_cast<float>(TILESIZE * x), static_cast<float>(TILESIZE * y));
	window.draw(sprite_);
}

/*
* FUNKTION Tile::isWalkable()
*
* BESKRIVNING
*
* H�mtar om man kan g� p� rutan eller ej.
*
* INDATA
*
* -
*
* UTDATA
*
* bool: Anger om man kan g� p� rutan (true) eller ej.
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

bool Tile::isWalkable()
{
	return walkable_;
}

/*
* SLUT P� FILEN Tile.cpp
*/