/* IDENTIFIERING
*
* Filnamn:    Universe.h
* Enhetsnamn: Universe
* Typ:        Moduldeklaration
* Revision:   1
* Skriven av: Simon Arkeholt, Fredrik Gustafsson, Jonas Ehn, Olle Andersson, Joakim Bertils, Johannes Grundell
*
*
* BESKRIVNING
*
* Denna modul representerar speluniversumet och dess best�ndsdelar.
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

#include <map>
#include <stdexcept>
#include "GameWindow.h"
#include "World.h"
#include "Tile.h"
#include "Enemy.h"
#include "NPC.h"
#include "Sensor.h"

/*
* Fram�tdeklarationer
*/

class Game;

/*
* KLASS UniverseException
*
* BASKLASSER
*
* logic_error
*
* BESKRIVNING
*
* Klassen kastar undantag f�r Universe.
*
* KONSTRUKTORER
*
* �rver fr�n std::logic_error.
*
* DATAMEDLEMMAR
*
* -
*
* REVISIONSBER�TTELSE
*
* Revision     Datum   F�r�ndringar
*
* 1            151214  Ursprungsversion
*
*/
class UniverseException : public std::logic_error
{
public:
	using std::logic_error::logic_error;
};

/*
* KLASS Universe
*
* BASKLASSER
*
* -
*
* BESKRIVNING
*
* Klassen representerar speluniversumet. Universe skapar och h�ller reda p� alla v�rldar i spelet.
*
* KONSTRUKTORER
*
* Universe(Game*)
*
* DATAMEDLEMMAR
*
* gamePointer_:		Pekare till aktuellt Game.
* currentWorld_:	Pekare till v�rlden spelaren befinner sig i.
* worlds_:			Vektor inneh�llande spelets alla v�rldar.
* tileAtlas_:		Map inneh�llande pekare till alla Tiles och respektive nyckel.
*
* REVISIONSBER�TTELSE
*
* Revision     Datum   F�r�ndringar
*
* 1            151214  Ursprungsversion
*
*/

class Universe
{
public:
	Universe(Game*);
	Universe(const Universe&) = delete;
	Universe& operator=(const Universe&) = delete;

	~Universe();

	void update();
	void render(GameWindow&);
	World* getCurrentWorld();
	World* getWorld(int);
	void setCurrentWorld(int);

	void switchWorld(int, int, int);

	Tile& getTile(int);

	Game* getGame() const;

	void addEnemy(int, Enemy*);
	void addNPC(int, NPC*);
	void addSensor(int, Sensor*);

	void populateCity();
private:
	Game* gamePointer_;
	World* currentWorld_;
	std::vector<World*> worlds_;
	std::map<int, Tile*> tileAtlas_;

	void loadTiles();
	void loadWorlds();
	void populateWorlds();
}; //class Universe

/*
* SLUT P� FILEN Universe.h
*/