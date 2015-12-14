/*
* IDENTIFIERING
*
* Filnamn:    Enemy.h
* Enhetsnamn: Enemy
* Typ:        Moduldeklaration
* Revision:   1
* Skriven av: Jonas Ehn, Olle Andersson
*
*
* BESKRIVNING
*
* Denna modul representerar entities av fiendetyp
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

#include "Entity.h"
#include "GameWindow.h"
#include <functional>

/*
* LOKALA FUNKTIONER (DEKLARATIONER)
*/

float getDistance(sf::Vector2f, sf::Vector2f);
sf::Vector2f normalize(sf::Vector2f);

/*
* KLASS Enemy
*
* BASKLASSER
*
* Entity
*
* BESKRIVNING
*
* Klassen representerar entity-objekt av fiendekarakt�r
*
* TILLST�ND
*
* -
*
* KONSTRUKTORER
*
* Enemy(int level, int health, int damage, int ID, std::string name, sf::Vector2f position, World * worldPtr,
		sf::Texture& texture, std::function<void(Enemy*)> callbackFunc)
*
* OPERATIONER
*
* -
*
* DATAMEDLEMMAR
*
* startPosition_ :	Den position som fienden utg�r ifr�n
* state_ :			Fiendens tillst�nd
* attackCooldown_ :	En timer som f�rhindrar att fienderna skadar spelaren f�r ofta
* resetTimer_ :		En timer som uppm�rksammar om fienden fastnat vid n�got hinder
* deathFkn_ :		En funktion som k�rs n�r fienden d�r	
*
* REVISIONSBER�TTELSE
*
* Revision     Datum   F�r�ndringar
*
* 1            151120  Ursprungsversion
*
*/

class Enemy : public Entity
{
public:
	enum STATES { ATTACK, MOVETOPLAYER, IDLE, RESET };

	Enemy(int, int, int, int, std::string, sf::Vector2f, World*, sf::Texture&, std::function<void(Enemy*)>);
	Enemy() = delete;
	Enemy(const Enemy&) = delete;
	Enemy& operator=(const Enemy&) = delete;

	void update() override;
	void render(GameWindow&) override;

	void die() override;

private:
	const sf::Vector2f startPosition_;
	STATES state_{ IDLE };

	int attackCooldown_{ 0 };
	int resetTimer_{ 0 };

	void updateState();
	void executeState();
	std::function<void(Enemy*)> deathFkn_;
	void attackPlayer();
};// class Enemy

  /*
  * SLUT P� FILEN Enemy.h
  */