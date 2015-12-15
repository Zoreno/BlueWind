/*
* IDENTIFIERING
*
* Filnamn:    Enemy.cpp
* Enhetsnamn: Enemy
* Typ:        Definitioner h�rande till klass Enemy
* Revision:   1
* Skriven av: Jonas Ehn, Olle Andersson
*
*
* BESKRIVNING
*
* Denna implementeringsfil definierar medlemsfunktioner f�r klassen Enemy.
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

#include "Enemy.h"
#include "World.h"
#include "Universe.h"
#include "Game.h"
#include <iostream>

using namespace std;

/*
* KONSTRUKTOR Enemy(int level, int health, int damage, int ID, std::string name, sf::Vector2f position, World * worldPtr,
					sf::Texture& texture, std::function<void(Enemy*)> deathFkn)
*
* BESKRIVNING
*
* Denna konstruktor konstruerar en fiende.
*
* INDATA
*
* level :		Fiendens niv�
* health :		Fiendens h�lsopo�ng
* damage :		M�ngden skada som fienden orsakar p� spelaren
* ID :			Fiendens ID i v�rlden
* name :		Fiendens namn
* position :	Fiendens utg�ngsposition
* worldPtr :	En pekare till den v�rld som fienden ska finnas i
* texture :		En textur till fiendens animation
* deathFkn :	Den funktion som ska k�ras n�r fienden d�r
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
* 1                    151120          Ursprungsversion
*
*/

Enemy::Enemy(int level, int health, int damage, int ID, std::string name, sf::Vector2f position, World * worldPtr, sf::Texture& texture, std::function<void(Enemy*)> deathFkn)
	: Entity(level,health,damage,ID,name,position,worldPtr, texture), startPosition_{position}, deathFkn_{ deathFkn }
{}

/*
* FUNKTION update()
*
* BESKRIVNING
*
* Denna funktion uppdaterar fienden
*
* INDATA
*
* -
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
* 1                    151120          Ursprungsversion
*
*/

void Enemy::update()
{
	updateState();
	executeState();
	anim_.update(animState_, dir_, walking_);
}

/*
* FUNKTION render(GameWindow & window)
*
* BESKRIVNING
*
* Denna funktion ritar upp fiender i f�nstret
*
* INDATA
*
* window :		F�nstret som vi ritar upp fienden i 
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
* modul: sfml-grafik
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

void Enemy::render(GameWindow & window)
{
	anim_.render(window);
	sf::RectangleShape hpBar{ sf::Vector2f(32 * ((float)health_ / (float)maxHealth_), 8) };
	hpBar.setPosition(position_ + sf::Vector2f(0, -8));
	hpBar.setFillColor(sf::Color::Red);
	window.draw(hpBar);
}

/*
* FUNKTION die()
*
* BESKRIVNING
*
* Denna funktion utf�r d�dandet av fienden
*
* INDATA
*
* -
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
* 1                    151120          Ursprungsversion
*
*/

void Enemy::die()
{
	deathFkn_(this);
}

/*
* FUNKTION updateState()
*
* BESKRIVNING
*
* Denna funktion uppdaterar fiendens tillst�nd
*
* INDATA
*
* -
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
* modul: sfml-grafik
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

void Enemy::updateState()
{
	sf::Vector2f playerPos = worldPointer_->getUniverse()->getGame()->getPlayer()->getPosition();
	float playerDistance = getDistance(position_, playerPos);
	float startDistance = getDistance(position_, startPosition_);

	switch (state_)
	{
	case IDLE:
		if (playerDistance <= 160)
		{
			state_ = MOVETOPLAYER;
		}
		break;

	case RESET:
		if (startDistance < 2)
		{
			state_ = IDLE;
			walking_ = false;
		}
		break;

	case ATTACK:
		if (startDistance > 160 || playerDistance > 160)
		{
			state_ = RESET;
		}
		else if (playerDistance > 32)
		{
			state_ = MOVETOPLAYER;
		}
		break;

	case MOVETOPLAYER:
		if (startDistance > 160 || playerDistance > 160)
		{
			state_ = RESET;
		}
		else if (playerDistance <= 32)
		{
			state_ = ATTACK;
		}
		break;

	}
}

/*
* FUNKTION executeState()
*
* BESKRIVNING
*
* Denna funktion g�r de saker med fienden som dikteras av dess tillst�nd
*
* INDATA
*
* -
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
* modul: sfml-grafik
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

void Enemy::executeState()
{
	const sf::Vector2f playerPos = worldPointer_->getUniverse()->getGame()->getPlayer()->getPosition();
	sf::Vector2f returnVector;
	sf::Vector2f toPlayerVector;
	sf::Vector2f toStartVector;
	switch (state_)
	{
	case IDLE:
		resetTimer_ = 0;
		break;
	case RESET:
		health_ = maxHealth_;
		if (resetTimer_ >= 300)
		{
			teleport((startPosition_.x), (startPosition_.y));
		}
		else
		{
			resetTimer_++;
			toStartVector = normalize(startPosition_ - position_);
			move(2.0f*toStartVector.x, 2.0f*toStartVector.y);
		}
			break;
	case ATTACK:
		attackPlayer();
		break;
	case MOVETOPLAYER:
		toPlayerVector = normalize(playerPos - position_);
		move(toPlayerVector.x, toPlayerVector.y);
		break;
	}
}

/*
* FUNKTION attackState()
*
* BESKRIVNING
*
* Denna funktion g�r s� att fienden skadar spelaren
*
* INDATA
*
* -
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
* 1                    151120          Ursprungsversion
*
*/

void Enemy::attackPlayer()
{
	
	if (attackCooldown_ >= 60)
	{
		animState_ = Entity::STATES::attacking;
		worldPointer_->getUniverse()->getGame()->getPlayer()->removeHealth(damage_);
		attackCooldown_ = 0;
		return;
	}
	attackCooldown_++;
}

/*
* FUNKTION getDistance(sf::Vector2f vec1, sf::Vector2f vec2)
*
* BESKRIVNING
*
* Denna funktion r�knar ut avst�ndet mellan spelaren och fienden
*
* INDATA
*
* vec1 : en positionsvektor
* vec2 : en positionsvektor
*
* UTDATA
*
* float : ett tal som anger avst�ndet mellan spelaren och fienden
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

float getDistance(sf::Vector2f vec1, sf::Vector2f vec2)
{
	sf::Vector2f vec = vec2 - vec1;
	return sqrt(vec.x*vec.x + vec.y*vec.y);
}

/*
* FUNKTION normalize(sf::Vector2f vec)
*
* BESKRIVNING
*
* Denna funktion normaliserar l�ngden p� elementen i en vektor
*
* INDATA
*
* vec : en vektor med 2 element
*
* UTDATA
*
* sf::Vector2f : En vektor med element som har l�ngden ett.
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

sf::Vector2f normalize(sf::Vector2f vec)
{
	int x = static_cast<int>(vec.x);
	int y = static_cast<int>(vec.y);

	if (x != 0)
	{
		x /= abs(x);
	}

	if (y != 0)
	{
		y /= abs(y);
	}

	return sf::Vector2f(static_cast<float>(x),static_cast<float>(y));
}

/*
* SLUT P� FILEN Enemy.cpp
*/
