/*
* IDENTIFIERING
*
* Filnamn:    Player.cpp
* Enhetsnamn: Player
* Typ:        Definitioner h�rande till klass Player
* Revision:   1
* Skriven av: Jonas Ehn, Olle Andersson
*
*
* BESKRIVNING
*
* Denna implementeringsfil definierar medlemsfunktioner f�r klassen Player.
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

#include <map>
#include <math.h>
#include <algorithm>

#include "Player.h"
#include "World.h"
#include "Universe.h"
#include "Game.h"
#include "Frame.h"
#include "Application.h"
#include "Input.h"
#include "GameOver.h"

using namespace std;
/*
* KONSTRUKTOR Player(World * worldPtr, sf::Texture& texture, Game* game)
*
* BESKRIVNING
*
* Denna konstruktor konstruerar spelaren
*
* INDATA
*
* worldPtr:		Pekare till den aktuella v�rlden
* texture:		En referens till en texture
* game:			En pekare till Game
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

Player::Player(World * worldPtr, sf::Texture& texture, Game* game)
	: Entity(1, 300, 50, 0, "Faranos", sf::Vector2f(20 * 32, 20 * 32), worldPtr, game->getTexture("player")),
	mana_{ 60 },
	maxMana_{ mana_ },
	gamePointer_{ game },
	inventory_{ this,game }
{}

/*
* FUNKTION Player::getExperience() const
*
* BESKRIVNING
*
* Denna funktion returnerar erfarenhetspo�ngen som spelaren har
*
* INDATA
*
* -
*
* UTDATA
*
* int:		Erfarenhetspo�ng
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/
int Player::getExperience() const
{
	return experience_;
}

/*
* FUNKTION Player::addExperience(int value)
*
* BESKRIVNING
*
* Denna funktion �kar spelarens erfarenhetspo�ng
*
* INDATA
*
* value:	Ett heltal med erfarenhetspo�ng att l�gga till
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
void Player::addExperience(int value)
{
	experience_ += value;
	while (checkForLevelup())
	{
		maxHealth_ += 50;
		health_ = maxHealth_;
		maxMana_ += 20;
		mana_ = maxMana_;
		damage_ += 30;
	}
}

/*
* FUNKTION Player::getMana() const
*
* BESKRIVNING
*
* Denna funktion returnerar spelarens magipo�ng
*
* INDATA
*
* -
*
* UTDATA
*
* mana_:	Ett heltal med spelarens magipo�ng
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/
int Player::getMana() const
{
	return mana_;
}

/*
* FUNKTION Player::setMana(int value)
*
* BESKRIVNING
*
* Denna funktion s�tter spelarens magipo�ng till ett visst v�rde
*
* INDATA
*
* value:	Ett heltal som spelarens magipo�ng s�tts till
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
void Player::setMana(int value)
{
	mana_ = value;
}

/*
* FUNKTION Player::addMana(int value)
*
* BESKRIVNING
*
* Denna funktion l�gger till magipo�ng till spelaren
*
* INDATA
*
* value:	Ett heltal som spelarens magipo�ng �kas med
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
void Player::addMana(int value)
{
	mana_ = min(mana_ + value, maxMana_);
}

/*
* FUNKTION getMaxMana() const
*
* BESKRIVNING
*
* Denna funktion returnerar maxantalet magipo�ng som spelaren har
*
* INDATA
*
* -
*
* UTDATA
*
* int:		Ett heltalsv�rde som �r spelarens maximala magipo�ng
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/
int Player::getMaxMana() const
{
	return maxMana_;
}

/*
* FUNKTION setMaxMana(int value)
*
* BESKRIVNING
*
* Denna funktion s�tter spelarens maximala antal magipo�ng
*
* INDATA
*
* value:	Heltal som s�tts till maximala antal magipo�ng
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
void Player::setMaxMana(int value)
{
	maxMana_ = value;
	mana_ = value;
}

/*
* FUNKTION getMaxExperience()
*
* BESKRIVNING
*
* Denna funktion returnerar spelarens maximala erfarenhetspo�ng
*
* INDATA
*
* -
*
* UTDATA
*
* int:	Maximala antalet erfarenhetspo�ng
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/
int Player::getMaxExperience()
{
	return getXpToLevel();
}

/*
* FUNKTION setName(std::string name)
*
* BESKRIVNING
*
* Denna funktion s�tter spelarens namn
*
* INDATA
*
* -
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
void Player::setName(std::string name)
{
	name_ = name;
}

/*
* FUNKTION setMaxHealth(int value)
*
* BESKRIVNING
*
* Denna funktion s�tter spelarens maximala h�lsopo�ng
*
* INDATA
*
* value:	Heltalsv�rde som blir spelarens maximala h�lsopo�ng
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
void Player::setMaxHealth(int value)
{
	maxHealth_ = value;
	health_ = value;
}

/*
* FUNKTION setDamage(int value)
*
* BESKRIVNING
*
* Denna funktion s�tter spelarens skadeverkan
*
* INDATA
*
* value:	Heltalsv�rde som blir spelarens skadeverkan
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
void Player::setDamage(int value)
{
	damage_ = value;
}

/*
* FUNKTION setLevel(int value)
*
* BESKRIVNING
*
* Denna funktion s�tter spelarens niv�
*
* INDATA
*
* value:	Heltalsv�rde som blir spelarens niv�
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
void Player::setLevel(int value)
{
	level_ = value;
}

/*
* FUNKTION setExperience(int value)
*
* BESKRIVNING
*
* Denna funktion s�tter spelarens erfarenhetspo�ng
*
* INDATA
*
* value:	Heltalsv�rde som blir spelarens erfarenhetspo�ng
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
void Player::setExperience(int value)
{
	experience_ = value;
}

/*
* FUNKTION getInventory()
*
* BESKRIVNING
*
* En funktion som returnerar en pekare till spelarens inventory
*
* INDATA
*
* -
*
* UTDATA
*
* Inventory* :		En pekare till spelarens inventory
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

Inventory* Player::getInventory()
{
	return &inventory_;
}

/*
* FUNKTION swordAttack(const map<int, Enemy*>& enemies)
*
* BESKRIVNING
*
* En funktion som representerar en sv�rdsattack
*
* INDATA
*
* enemies : en map med alla fiender i v�rlden
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

void Player::swordAttack(const map<int, Enemy*>& enemies)
{
	if (mana_ < 4) return;
	mana_ -= 4;
	animState_ = attacking;
	for (auto it : enemies)
	{
		if (getDistance(position_, it.second->getPosition()) <= 32)
		{
			if (dir_ == north && it.second->getPosition().y <= position_.y)
			{
				it.second->removeHealth(damage_);
				break;
			}
			else if (dir_ == west && it.second->getPosition().x <= position_.x)
			{
				it.second->removeHealth(damage_);
				break;
			}
			else if (dir_ == east && it.second->getPosition().x >= position_.x)
			{
				it.second->removeHealth(damage_);
				break;
			}
			else if (dir_ == south && it.second->getPosition().y >= position_.y)
			{
				it.second->removeHealth(damage_);
				break;
			}
		}
	}
}

/*
* FUNKTION fireballAttack(const std::map<int, Enemy*>& enemies)
*
* BESKRIVNING
*
* En funktion som representerar en magiattack
*
* INDATA
*
* enemies : en map med alla fiender i v�rlden
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

void Player::fireballAttack(const std::map<int, Enemy*>& enemies)
{
	if (mana_ < 12 || !getInventory()->hasItem(5)) return;
	mana_ -= 12;
	animState_ = spell;
	for (auto it : enemies)
	{
		if (getDistance(position_, it.second->getPosition()) <= 64)
		{
			it.second->removeHealth(2 * damage_);
		}
	}
}

/*
* FUNKTION interact(const std::map<int, NPC*>& NPCs)
*
* BESKRIVNING
*
* En funktion som representerar interaktion med NPC:er
*
* INDATA
*
* NPCs : en map med alla NPCer i v�rlden
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

void Player::interact(const std::map<int, NPC*>& NPCs)
{
	for (auto it : NPCs)
	{
		if (getDistance(position_, it.second->getPosition()) <= 48)
		{
			if (dir_ == north && it.second->getPosition().y <= position_.y)
			{
				it.second->interact();
				break;
			}
			else if (dir_ == west && it.second->getPosition().x <= position_.x)
			{
				it.second->interact();
				break;
			}
			else if (dir_ == east && it.second->getPosition().x >= position_.x)
			{
				it.second->interact();
				break;
			}
			else if (dir_ == south && it.second->getPosition().y >= position_.y)
			{
				it.second->interact();
				break;
			}
		}
	}
}

/*
* FUNKTION getXpToLevel()
*
* BESKRIVNING
*
* En funktion som r�knar ut hur m�nga erfarenhetspo�ng
* som kr�vs f�r att n� n�sta niv�.
*
* INDATA
*
* -
*
* UTDATA
*
* int : antalet erfarenhetspo�ng till n�sta niv�
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

int Player::getXpToLevel()
{
	return static_cast<int>(std::floor(100 * std::pow(1.15f, level_)));
}

/*
* FUNKTION checkForLevelup()
*
* BESKRIVNING
*
* En funktion som r�knar ut om spelaren g�r upp en niv�
*
* INDATA
*
* -
*
* UTDATA
*
* bool : ska spelaren g� upp en niv�?
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

bool Player::checkForLevelup()
{
	if (experience_ >= getXpToLevel())
	{
		experience_ -= getXpToLevel();
		level_++;
		return true;
	}
	return false;
}

/*
* FUNKTION update()
*
* BESKRIVNING
*
* En funktion som uppdaterar spelaren
*
* INDATA
*
* -
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

void Player::update()
{
	healthCounter_++;
	manaCounter_++;

	if (healthCounter_ % 15 == 0)
	{
		addHealth(level_);
		healthCounter_ = 0;
	}
	if (manaCounter_ % 5 == 0)
	{
		addMana(1);
		manaCounter_ = 0;
	}
	walking_ = false;
	if (gamePointer_->getApp()->getInput().isPressed('a'))
	{
		move(-2.0f, 0.0f);
	}
	if (gamePointer_->getApp()->getInput().isPressed('d'))
	{
		move(2.0f, 0.0f);
	}
	if (gamePointer_->getApp()->getInput().isPressed('s'))
	{
		move(0.0f, 2.0f);
	}
	if (gamePointer_->getApp()->getInput().isPressed('w'))
	{
		move(0.0f, -2.0f);
	}
	anim_.update(animState_, dir_, walking_);
	checkSensors();
}

/*
* FUNKTION render(GameWindow & window)
*
* BESKRIVNING
*
* En funktion som renderar spelaren
*
* INDATA
*
* window : spelf�nstret som allt ritas upp i
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

void Player::render(GameWindow & window)
{
	anim_.render(window);
}

/*
* FUNKTION die()
*
* BESKRIVNING
*
* En funktion som d�dar spelaren
*
* INDATA
*
* -
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

void Player::die()
{
	gamePointer_->getApp()->setNextFrame(new GameOver(gamePointer_->getApp()));
}

/*
* FUNKTION checkSensors()
*
* BESKRIVNING
*
* En funktion som kontrollerar om spelaren �r n�ra nog f�r att trigga n�gon sensor
*
* INDATA
*
* -
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

void Player::checkSensors()
{
	for (auto it : worldPointer_->getSensorVector())
	{
		if (getDistance(position_, it.second->getPosition()) <= 32)
		{
			it.second->trigger();
			break;
		}
	}
}

/*
* Slut p� filen Player.cpp
*/