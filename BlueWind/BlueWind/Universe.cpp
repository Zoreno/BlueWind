#include "Universe.h"
#include "Game.h"

#include <iostream>

using namespace std;

Universe::Universe(Game * gamePtr)
	: gamePointer_{gamePtr}
{
	loadTiles();
	loadWorlds();
	populateWorlds();
}

void Universe::update()
{
	currentWorld_->update();
}

void Universe::render(GameWindow & window)
{
	//cout << "Universe renderar" << endl;
	currentWorld_->render(window);
}

World * Universe::getCurrentWorld()
{
	return currentWorld_;
}

World * Universe::getWorld(int ID)
{
	for (auto it : worlds_)
	{
		if (ID == it->getID())
		{
			return it;
		}
	}
	//TODO kasta ex
	return nullptr;
}

void Universe::setCurrentWorld(int ID)
{
	for (auto it : worlds_)
	{
		if (ID == it->getID())
		{
			currentWorld_ = it;
		}
	}
}

Tile Universe::getTile(int i)
{
	return (*tileAtlas_.find(i)->second);
}

Game * Universe::getGame() const
{
	return gamePointer_;
}

void Universe::loadTiles()
{
	cout << "Laddar in Tiles" << endl;
	tileAtlas_.emplace(0,new Tile(gamePointer_->getTexture("grass"), true));
	tileAtlas_.emplace(1,new Tile(gamePointer_->getTexture("tree"), false));
	cout << "Laddning av tiles klart" << endl;
}

void Universe::loadWorlds()
{
	cout << "Laddar in v�rldar" << endl;
	worlds_.push_back(new World(0, this, "res/worlds/level.bmp"));

	cout << "Laddning av v�rldar klart" << endl;

	setCurrentWorld(0);
}

void Universe::populateWorlds() 
{

	//OBS!!!!!!
	//UNIKA ID KR�VS
	addNPC(0, new NPC(1, 100, 10, 0, "Paul", sf::Vector2f(3 * 16, 10 * 16), getWorld(0), gamePointer_->getTexture("NPC"), "Hej, jag heter Paul!"));
	addNPC(0, new NPC(1, 100, 10, 1, "Erwin", sf::Vector2f(7 * 16, 7 * 16), getWorld(0), gamePointer_->getTexture("NPC"), "Hej, jag heter Erwin!"));
	addNPC(0, new NPC(1, 100, 10, 2, "James Clerk", sf::Vector2f(10 * 16, 3 * 16), getWorld(0), gamePointer_->getTexture("NPC"), "Hej, jag heter James Clerk!"));
	//--------------------------
	addEnemy(0, new Enemy(1, 100, 10, 0, "Pelle", sf::Vector2f(12 * 16, 14 * 16), getWorld(0), gamePointer_->getTexture("enemy")));
	addEnemy(0, new Enemy(1, 100, 10, 1, "Pelle", sf::Vector2f(13 * 16, 14 * 16), getWorld(0), gamePointer_->getTexture("enemy")));
	addEnemy(0, new Enemy(1, 100, 10, 2, "Pelle", sf::Vector2f(14 * 16, 14 * 16), getWorld(0), gamePointer_->getTexture("enemy")));
}

void Universe::addEnemy(int worldID, Enemy * enemyPtr)
{
	for (auto it : worlds_)
	{
		if (it->getID() == worldID)
		{
			it->addEnemy(enemyPtr);
			break;
		}
	}
}

void Universe::addNPC(int worldID, NPC * NPCPtr)
{
	for (auto it : worlds_)
	{
		if (it->getID() == worldID)
		{
			it->addNPC(NPCPtr);
			break;
		}
	}
}
