/*
* IDENTIFIERING
*
* Filnamn:    World.cpp
* Enhetsnamn: World
* Typ:        Definitioner h�rande till klassen World
* Revision:   1
* Skriven av: Joakim Bertils, Johannes Grundell
*
*
* BESKRIVNING
*
* Denna implementeringsfil definierar medlemsfunktioner f�r klassen World.
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

#include "World.h"
#include "Universe.h"

using namespace std;

/*
* KONSTRUKTOR World::World(int ID, Universe* universePtr, std::string mapFile, string music)
*
* BESKRIVNING
*
* Denna konstruktor skapar en spelv�rld.
*
* INDATA
*
* ID:			Spelv�rldens ID.
* universePtr:	Pekare till speluniversum.
* mapFile:		Fil som inneh�ller spelv�rldens pixelkarta (hur v�rlden ska se ut).
* music:		Musiken som ska spelas i spelv�rlden.
*
* UTDATA
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

World::World(int ID, Universe* universePtr, std::string mapFile, string music)
	: ID_{ ID },
	universePointer_{ universePtr },
	music_{ music }
{
	loadWorld(mapFile);
}

/*
* DESTRUKTOR World::~World()
*
* BESKRIVNING
*
* Denna destruktor destruerar ett World-objekt
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

World::~World()
{
	universePointer_ = nullptr;

	while (!enemyVector_.empty())
	{
		auto it = enemyVector_.begin();
		delete it->second;
		enemyVector_.erase(it);
	}

	while (!NPCVector_.empty())
	{
		auto it = NPCVector_.begin();
		delete it->second;
		NPCVector_.erase(it);
	}

	while (!sensorVector_.empty())
	{
		auto it = sensorVector_.begin();
		delete it->second;
		sensorVector_.erase(it);
	}
}

/*
* FUNKTION World::update()
*
* BESKRIVNING
*
* Uppdaterar spelv�rldens best�ndsdelar.
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
* 1                    151214          Ursprungsversion
*
*/

void World::update()
{
	for (auto it : enemyVector_)
	{
		it.second->update();
	}
	updateLists();
}

/*
* FUNKTION World::render(GameWindow& window)
*
* BESKRIVNING
*
* Ritar upp tiles runt spelkarakt�ren, samt spelv�rldens samtliga fiender och NPC:er.
*
* INDATA
*
* window: F�nster som spelv�rlden ska ritas upp i.
*
* UTDATA
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

void World::render(GameWindow& window)
{
	sf::View view = window.getView();

	int startX = (static_cast<int>(view.getCenter().x) - (20 * Tile::TILESIZE)) / Tile::TILESIZE;
	int endX = (static_cast<int>(view.getCenter().x) + (20 * Tile::TILESIZE)) / Tile::TILESIZE;
	int startY = (static_cast<int>(view.getCenter().y) - (20 * Tile::TILESIZE)) / Tile::TILESIZE;
	int endY = (static_cast<int>(view.getCenter().y) + (20 * Tile::TILESIZE)) / Tile::TILESIZE;

	if (startX > mapWidth_)
		startX = mapWidth_;
	if (startX < 0)
		startX = 0;

	if (endX > mapWidth_)
		endX = mapWidth_;
	if (endX < 0)
		endX = 0;

	if (startY > mapHeight_)
		startY = mapHeight_;
	if (startY < 0)
		startY = 0;

	if (endY > mapHeight_)
		endY = mapHeight_;
	if (endY < 0)
		endY = 0;

	for (int y = startY; y < endY; ++y)
	{
		for (int x = startX; x < endX; ++x)
		{
			universePointer_->getTile(tileVector_.at(x + mapWidth_*y)).render(window, x, y);
		}
	}

	for (auto it : enemyVector_)
	{
		it.second->render(window);
	}

	for (auto it : NPCVector_)
	{
		it.second->render(window);
	}
}

/*
* FUNKTION World::loadWorld(std::string mapFile)
*
* BESKRIVNING
*
* L�ser in och �vers�tter spelv�rldens pixelkarta till en lista med motsvarande tiles.
*
* INDATA
*
* mapFile: Spelv�rldens pixelkarta.
*
* UTDATA
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

void World::loadWorld(std::string mapFile)
{
	sf::Image image;
	if (!image.loadFromFile(mapFile))
	{
		throw WorldException("Kunde inte l�sa v�rldsfil:" + mapFile);
	}

	mapWidth_ = image.getSize().x;
	mapHeight_ = image.getSize().y;

	for (int y{ 0 }; y < mapHeight_; ++y)
	{
		for (int x{ 0 }; x < mapWidth_; ++x)
		{
			tileVector_.push_back(getIntFromColor(image.getPixel(x, y)));
		}
	}
}

/*
* FUNKTION World::addEnemy(Enemy* enemyPtr)
*
* BESKRIVNING
*
* L�gger till en fiende i spelv�rlden.
*
* INDATA
*
* enemyPtr: Pekare till den fiende som skall l�ggas till.
*
* UTDATA
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

void World::addEnemy(Enemy* enemyPtr)
{
	enemyVector_.emplace(enemyPtr->getID(), enemyPtr);
}

/*
* FUNKTION World::addNPC(NPC* NPCPtr)
*
* BESKRIVNING
*
* L�gger till en NPC i spelv�rlden.
*
* INDATA
*
* NPCPtr: Pekare till den NPC som skall l�ggas till.
*
* UTDATA
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

void World::addNPC(NPC* NPCPtr)
{
	NPCVector_.emplace(NPCPtr->getID(), NPCPtr);
}

/*
* FUNKTION World::addSensor(Sensor* sensorPtr)
*
* BESKRIVNING
*
* L�gger till en sensor i spelv�rlden.
*
* INDATA
*
* sensorPtr: Pekare till den sensor som skall l�ggas till.
*
* UTDATA
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

void World::addSensor(Sensor* sensorPtr)
{
	sensorVector_.emplace(sensorPtr->getID(), sensorPtr);
}

/*
* FUNKTION World::removeEnemy(Enemy* enemyPtr)
*
* BESKRIVNING
*
* L�gger till en fiende i "removeEnemyVector_" (listan �ver de fiender i spelv�rlden som skall tas bort).
*
* INDATA
*
* enemyPtr: Pekare till den fiende som skall tas bort.
*
* UTDATA
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

void World::removeEnemy(Enemy* enemyPtr)
{
	removeEnemyVector_.push_back(enemyPtr->getID());
}

/*
* FUNKTION World::removeNPC(NPC* NPCPtr)
*
* BESKRIVNING
*
* L�gger till en NPC i "removeNPCVector_" (listan �ver de NPC:er i spelv�rlden som skall tas bort).
*
* INDATA
*
* NPCPtr: Pekare till den NPC som skall tas bort.
*
* UTDATA
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

void World::removeNPC(NPC* NPCPtr)
{
	removeNPCVector_.push_back(NPCPtr->getID());
}

/*
* FUNKTION World::removeSensor(Sensor* sensorPtr)
*
* BESKRIVNING
*
* L�gger till en sensor i "removeSensorVector_" (listan �ver de sensorer i spelv�rlden som skall tas bort).
*
* INDATA
*
* sensorPtr: Pekare till den sensor som skall tas bort.
*
* UTDATA
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

void World::removeSensor(Sensor* sensorPtr)
{
	removeSensorVector_.push_back(sensorPtr->getID());
}

/*
* FUNKTION World::changeTile(int pos, int value)
*
* BESKRIVNING
*
* Ers�tter en tile i spelv�rlden med en annan typ av tile.
*
* INDATA
*
* pos: Positionen f�r den tile som skall ers�ttas.
* value: Den typ av tile som den gamla ska ers�ttas med.
*
* UTDATA
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

void World::changeTile(int pos, int value)
{
	if (pos < 0 || (static_cast<unsigned int>(pos) > tileVector_.size()))
	{
		throw WorldException("�tkomst till tile utanf�r kartan, du angav:" + pos);
	}

	tileVector_.at(pos) = value;
}

/*
* FUNKTION World::getUniverse()
*
* BESKRIVNING
*
* H�mtar (en pekare till) det speluniversum som spelv�rlden tillh�r.
*
* INDATA
*
* -
*
* UTDATA
*
* Universe*: Pekare till det speluniversum som spelv�rlden tillh�r.
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151214          Ursprungsversion
*
*/

Universe* World::getUniverse() const
{
	return universePointer_;
}

/*
* FUNKTION World::getID()
*
* BESKRIVNING
*
* H�mtar spelv�rldens ID.
*
* INDATA
*
* -
*
* UTDATA
*
* const int: Spelv�rldens ID.
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151214          Ursprungsversion
*
*/

const int World::getID() const
{
	return ID_;
}

/*
* FUNKTION World::getMusic()
*
* BESKRIVNING
*
* H�mtar musiken som spelas i spelv�rlden.
*
* INDATA
*
* -
*
* UTDATA
*
* std::string: Den musik som spelas i spelv�rlden.
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151214          Ursprungsversion
*
*/

const std::string World::getMusic()
{
	return music_;
}

/*
* FUNKTION World::getMapWidth()
*
* BESKRIVNING
*
* H�mtar spelv�rldens bredd.
*
* INDATA
*
* -
*
* UTDATA
*
* const int: Spelv�rldens bredd.
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151214          Ursprungsversion
*
*/

const int World::getMapWidth() const
{
	return mapWidth_;
}

/*
* FUNKTION World::getMapHeight()
*
* BESKRIVNING
*
* H�mtar spelv�rldens h�jd.
*
* INDATA
*
* -
*
* UTDATA
*
* const int: Spelv�rldens h�jd.
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151214          Ursprungsversion
*
*/

const int World::getMapHeight() const
{
	return mapHeight_;
}

/*
* FUNKTION World::getTileVector()
*
* BESKRIVNING
*
* H�mtar listan �ver spelv�rldens tiles.
*
* INDATA
*
* -
*
* UTDATA
*
* std::vector<int>: Lista �ver spelv�rldens tiles.
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151214          Ursprungsversion
*
*/

const std::vector<int> World::getTileVector() const
{
	return tileVector_;
}

/*
* FUNKTION World::getNPCVector()
*
* BESKRIVNING
*
* H�mtar listan �ver spelv�rldens alla NPC:er.
*
* INDATA
*
* -
*
* UTDATA
*
* std::map<int,NPC*>: Lista �ver spelv�rldens alla NPC:er.
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151214          Ursprungsversion
*
*/

const std::map<int, NPC*> World::getNPCVector() const
{
	return NPCVector_;
}

/*
* FUNKTION World::getSensorVector()
*
* BESKRIVNING
*
* H�mtar listan �ver spelv�rldens alla sensorer.
*
* INDATA
*
* -
*
* UTDATA
*
* std::map<int, Sensor*>: Lista �ver spelv�rldens alla sensorer.
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151214          Ursprungsversion
*
*/

const std::map<int, Sensor*> World::getSensorVector() const
{
	return sensorVector_;
}

/*
* FUNKTION World::getEnemyVector()
*
* BESKRIVNING
*
* H�mtar listan �ver spelv�rldens alla fiender.
*
* INDATA
*
* -
*
* UTDATA
*
* std::map<int, Enemy*>: Lista �ver spelv�rldens alla fiender.
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151214          Ursprungsversion
*
*/

const std::map<int, Enemy*> World::getEnemyVector() const
{
	return enemyVector_;
}

/*
* FUNKTION World::getIntFromColor(sf::Color color)
*
* BESKRIVNING
*
* �vers�tter f�rger till heltal.
*
* INDATA
*
* color: F�rgen som skall �vers�ttas.
*
* UTDATA
*
* int: F�rgens motsvarande heltal.
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151214          Ursprungsversion
*
*/

int World::getIntFromColor(sf::Color color)
{
	switch (color.toInteger())
	{
	case 0x00FF00FF: //Gr�s
		return 0;
	case 0xFF0000FF: //Tr�d p� gr�s
		return 1;
	case 0x7F6A00FF: //Bro
		return 2;
	case 0xFF8800FF: //Hus00
		return 3;
	case 0xFF8801FF: //Hus01
		return 4;
	case 0xFF8802FF: //Hus02
		return 5;
	case 0xFF8803FF: //Hus03
		return 6;
	case 0xFF8810FF: //Hus10
		return 7;
	case 0xFF8811FF: //Hus11
		return 8;
	case 0xFF8812FF: //Hus12
		return 9;
	case 0xFF8813FF: //Hus13
		return 10;
	case 0xFF8820FF: //Hus20
		return 11;
	case 0xFF8821FF: //Hus21
		return 12;
	case 0xFF8822FF: //Hus22
		return 13;
	case 0xFF8823FF: //Hus23
		return 14;
	case 0xFF8830FF: //Hus30
		return 15;
	case 0xFF8831FF: //Hus31
		return 16;
	case 0xFF8832FF: //Hus32
		return 17;
	case 0xFF8833FF: //Hus33
		return 18;
	case 0x7F7F7FFF: //Berg p� gr�s
		return 19;
	case 0x0000FFFF: //Vatten
		return 20;
	case 0xFF7F00FF: //Stubbe p� gr�s
		return 21;
	case 0x00FFFFFF: //Sn�
		return 22;
	case 0xFFFF00FF: //Tr�d p� gr�s
		return 23;
	case 0xFF006EFF: //Kaktus
		return 24;
	case 0xFF6A00FF: //Sand
		return 25;
	case 0x404040FF: //Palm
		return 26;
	case 0xFF0022FF: //Lava
		return 100;
	case 0x808080FF: //Lavasten
		return 101;
	case 0x7F3300FF: //Nedbrunnet tr�d
		return 102;
	case 0x123456FF: //Font�n
		return 200;
	case 0xFF1000FF: //Sand (kan EJ g� p�)
		return 201;
	case 0x7F1C00FF: //Nedbrunnet tr�d p� gr�s
		return 900;
	case 0x77617CFF: //Sten p� gr�s
		return 902;

	default:
		return -1;
	}
}

/*
* FUNKTION World::updateLists()
*
* BESKRIVNING
*
* Tar bort de fiender, NPC:er samt sensorer i spelv�rlden som har blivit m�rkta med att de skall tas bort.
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
* 1                    151214          Ursprungsversion
*
*/

void World::updateLists()
{
	for (auto iter : removeEnemyVector_)
	{
		auto it = enemyVector_.find(iter);

		if (it != enemyVector_.end())
		{
			delete (it->second);
			enemyVector_.erase(it);
		}
	}
	removeEnemyVector_.clear();

	for (auto iter : removeNPCVector_)
	{
		auto it = NPCVector_.find(iter);

		if (it != NPCVector_.end())
		{
			delete (it->second);
			NPCVector_.erase(it);
		}
	}
	removeNPCVector_.clear();

	for (auto iter : removeSensorVector_)
	{
		auto it = sensorVector_.find(iter);

		if (it != sensorVector_.end())
		{
			delete (it->second);
			sensorVector_.erase(it);
		}
	}
	removeSensorVector_.clear();
}

/*
* SLUT P� FILEN World.cpp
*/