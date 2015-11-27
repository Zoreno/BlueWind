#include "Player.h"
#include "World.h"
#include "Universe.h"
#include "Game.h"
#include "Frame.h"
#include "Application.h"
#include "Input.h"
#include <map>
#include <math.h>

using namespace std;


Player::Player(World * worldPtr, sf::Texture& texture, Game* game, const string& fileName)
	: Entity(1, 100, 10, 0, "Kalle", sf::Vector2f(2 * 16, 2 * 16), worldPtr, fileName),
	mana_{ 20 }, maxMana_{ 20 }, gamePointer_{ game }, inventory_{ this,game }//, anim_{ this }
{
	inventory_.addItem(0);
}

int Player::getExperience() const
{
	return experience_;
}

void Player::addExperience(int value)
{
	experience_ += value;
	while(checkForLevelup())
	{ }
}

int Player::getMana() const
{
	return mana_;
}

void Player::setMana(int value)
{
	mana_ = value;
}

int Player::getMaxMana() const
{
	return maxMana_;
}

void Player::setMaxMana(int value)
{
	maxMana_ = value;
}

int Player::getMaxExperience()
{
	return getXpToLevel();
}

Inventory* Player::getInventory()
{
	return &inventory_;
}

int Player::getXpToLevel()
{
	return std::floor( 100 * std::pow(1.15f, level_));
}

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

void Player::update()
{
	//anim_.state_ = anim_.idle;
	if (worldPointer_->getUniverse()->getGame()->getApp()->getInput().pressedButtons_.at('a'))
	{
		move(-1, 0);
	//anim_.state_ = anim_.walking;
//anim_.dir_ = anim_.west;
	}
	if (worldPointer_->getUniverse()->getGame()->getApp()->getInput().pressedButtons_.at('d'))
	{
		move(1, 0);
		//anim_.state_ = anim_.walking;
		//anim_.dir_ = anim_.east;
	}
	if (worldPointer_->getUniverse()->getGame()->getApp()->getInput().pressedButtons_.at('s'))
	{
		move(0, 1);
		//anim_.state_ = anim_.walking;
		//anim_.dir_ = anim_.south;
	}
	if (worldPointer_->getUniverse()->getGame()->getApp()->getInput().pressedButtons_.at('w'))
	{
		move(0, -1);
		//anim_.state_ = anim_.walking;
		//anim_.dir_ = anim_.north;
	}
	//anim_.update();
			}

void Player::render(GameWindow & window)
{
	anim_.render(window);
}

const int Player::getAttackCooldown() const
		{
	return attackCooldown_;
}

void Player::die()
{
	gamePointer_->getApp()->setNextFrame(new Menu(gamePointer_->getApp()));
	gamePointer_->getApp()->setZoomLevel(2.5f);
	//gamePointer_->getApp()->changeCurrentFrame(new Menu(gamePointer_->getApp()), 2.5f); // TODO Byt Menu mot "GameOver"
}

