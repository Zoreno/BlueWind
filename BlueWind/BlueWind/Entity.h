/*
* IDENTIFIERING
*
* Filnamn:    Entity.h
* Enhetsnamn: Entity
* Typ:        Moduldeklaration
* Revision:   1
* Skriven av: Olle Andersson, Jonas Ehn
*
*
* BESKRIVNING
*
* Denna modul representerar objekt i spelv�rlden
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

#include <string>
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "GameWindow.h"

/*
* FRAM�TDEKLARATIONER
*/

class World;

/*
* KLASS Entity
*
* BASKLASSER
*
* -
*
* BESKRIVNING
*
* Klassen representerar objekt i spelv�rlden
*
* KONSTRUKTORER
*
* Entity(int level, int health, int damage, int ID, std::string name,
*        sf::Vector2f position, World * worldPtr, sf::Texture& tex)
*
* DATAMEDLEMMAR
*
* level_ :			Vilken niv� som entity-objektet har
* health_ :			Antalet h�lsopo�ng hos entity-objektet
* maxHealth_ :		Maxantalet h�lsopo�ng hos entity-objektet
* damage_ :			Ett tal p� storleken p� skadeverkan av objektet
* ID_ :				Objektets ID
* walking_ :		En mark�r f�r om objektet r�r p� sig eller inte
* animState_ :		Markerar vilken bild som ska ritas (g�, attackera, magiattack)
* dir_ :			Markerar i vilken riktning som entity-objektet �r v�nt
* name_ :			Namn p� objektet
* position_ :		Positionen till objektet
* worldPointer_ :	En pekare till v�rlden som entity-objektet befinner sig i
* anim_ :			Ett animationsobjekt som sk�ter uppritningen av entityn
*
*
* REVISIONSBER�TTELSE
*
* Revision     Datum   F�r�ndringar
*
* 1            151120  Ursprungsversion
*
*/

class Entity
{
	friend class Animation;
public:
	enum STATES { walking1 = 0x0, walking2 = 0x1, attacking = 0x2, spell = 0x3 };
	enum DIRECTION { north = 0x0, west = 0x2, east = 0x3, south = 0x1 };

	Entity(int, int, int, int, std::string, sf::Vector2f, World*, sf::Texture&);

	Entity(const Entity&) = delete;
	Entity() = delete;
	Entity& operator= (const Entity&) = delete;

	virtual void update() = 0;
	virtual void render(GameWindow&) = 0;

	void move(float, float);
	void teleport(float, float);

	int getLevel() const;
	int getHealth() const;
	int getMaxHealth() const;
	int getDamage() const;
	int getID() const;
	std::string getName() const;
	const sf::Vector2f getPosition() const;
	World* getWorld() const;

	void setCurrentWorld(World*);

	void addHealth(int);
	void removeHealth(int);

	virtual void die();

protected:
	int level_;
	int health_;
	int maxHealth_;
	int damage_;
	int ID_;

	bool walking_;

	STATES animState_{ walking1 };
	DIRECTION dir_{ south };

	std::string name_;
	sf::Vector2f position_;
	World* worldPointer_;
	Animation anim_;
}; //class Entity

   /*
   * SLUT P� FILEN UIBar.h
   */