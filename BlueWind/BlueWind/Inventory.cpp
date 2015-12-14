/*
* IDENTIFIERING
*
* Filnamn:    Inventory.cpp
* Enhetsnamn: Inventory
* Typ:        Definitioner h�rande till klass Inventory
* Revision:   1
* Skriven av: Joakim Bertils, Johannes Grundell
*
*
* BESKRIVNING
*
* Denna implementeringsfil definierar medlemsfunktioner f�r klassen Inventory.
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

#include "Inventory.h"
#include "Player.h"
#include "Game.h"
#include "Application.h"

using namespace std;

/*
* KONSTRUKTOR Inventory::Inventory(Player * playerPtr, Game* gamePtr)
*
* BESKRIVNING
*
* Denna konstruktor konstruerar ett f�rem�l.
*
* INDATA
*
* playerPtr:	Pekare till spelaren.
* gamePtr:		Pekare till spelframe.
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
* std::vector
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

Inventory::Inventory(Player * playerPtr, Game* gamePtr)
	: playerPointer_{ playerPtr },
	gamePointer_{ gamePtr }
{
	items_.reserve(maxSize_);
	populateItemList();
}

/*
* DESTRUKTOR Inventory::~Inventory()
*
* BESKRIVNING
*
* Denna destruktor destrukterar ett f�rem�l.
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
* std::vector
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

Inventory::~Inventory()
{
	while (!allItems_.empty())
	{
		delete allItems_.back();
		allItems_.pop_back();
	}
	items_.clear();
}

/*
* FUNKTION Inventory::addItem(int ID)
*
* BESKRIVNING
*
* L�gger till ett f�rem�l (Item) i Inventory.
*
* INDATA
*
* ID: ID p� f�rem�let som ska l�ggas till.
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
* modul: std::vector
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

void Inventory::addItem(int ID)
{
	if (isFull())
	{
		gamePointer_->getUserInterface()->addStringToChatBox("Inventory is full");
		return;
	}
	for (auto it : allItems_)
	{
		if (it->getID() == ID)
		{
			items_.push_back(it);
		}
	}
}

/*
* FUNKTION Inventory::removeItem(int ID)
*
* BESKRIVNING
*
* Tar Bort ett f�rem�l (Item) i Inventory.
*
* INDATA
*
* ID: ID p� f�rem�let som ska tas bort.
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
* modul: std::vector
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

void Inventory::removeItem(int ID)
{
	cout << "Removing item :" + ID << endl;
	auto it = items_.begin();

	while (it != items_.end())
	{
		cout << "Iterating :" + ID << endl;
		if ((*it)->getID() == ID)
		{
			items_.erase(it);
			break;
		}
		++it;
	}
}

/*
* FUNKTION Inventory::hasItem(int ID)
*
* BESKRIVNING
*
* Unders�ker om f�rem�let finns i inventory.
*
* INDATA
*
* ID: ID p� f�rem�let som unders�ks.
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
* modul: std::vector
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

bool Inventory::hasItem(int ID)
{
	for (auto it : items_)
	{
		if (it->getID() == ID)
		{
			return true;
		}
	}
	return false;
}

/*
* FUNKTION Inventory::isFull()
*
* BESKRIVNING
*
* -
*
* INDATA
*
* ID: ID p� f�rem�let som ska tas bort.
*
* UTDATA
*
* bool: Return inventorys status vad g�ller om det �r fullt.
*
* SIDOEFFEKTER
*
* -
*
* UTNYTTJAR
*
* modul: std::vector
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

bool Inventory::isFull()
{
	return (items_.size() >= maxSize_);
}

/*
* FUNKTION Inventory::getCount(int ID)
*
* BESKRIVNING
*
* Returnerar antalet av ett f�rem�l i inventory.
*
* INDATA
*
* ID: ID p� f�rem�let som ska r�knas.
*
* UTDATA
*
* int: Antalet f�rem�l som finns i inventory.
*
* SIDOEFFEKTER
*
* -
*
* UTNYTTJAR
*
* modul: std::vector
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

const int Inventory::getCount(int ID)
{
	int count{ 0 };

	for (auto it : items_)
	{
		if (it->getID() == ID)
		{
			count++;
		}
	}

	return count;
}

/*
* FUNKTION Inventory::at(int pos)
*
* BESKRIVNING
*
* Returnerar f�rem�let p� en plats i inventory.
*
* INDATA
*
* pos: Position i inventory som ska returneras.
*
* UTDATA
*
* Item*: En pekare till f�rem�let p� platsen i inventory.
*
* SIDOEFFEKTER
*
* -
*
* UTNYTTJAR
*
* modul: std::vector
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

Item * Inventory::at(int pos)
{
	if (pos >= 0 && pos <= items_.size())
		return items_.at(pos);
	else
		throw InventoryException("Kan ej h�mta element p� angiven position:" + pos);
}

/*
* FUNKTION Inventory::getSize()
*
* BESKRIVNING
*
* Returnerar storleken p� inventory (antalet f�rem�l i inventory).
*
* INDATA
*
* -
*
* UTDATA
*
* int: Storleken p� inventory.
*
* SIDOEFFEKTER
*
* -
*
* UTNYTTJAR
*
* modul: std::vector
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

const int Inventory::getSize()
{
	return items_.size();
}

/*
* FUNKTION Inventory::getMaxSize()
*
* BESKRIVNING
*
* Returnerar inventorys maxstorlek.
*
* INDATA
*
* -
*
* UTDATA
*
* int: Maxstorleken p� inventory.
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

const unsigned int Inventory::getMaxSize()
{
	return maxSize_;
}

/*
* FUNKTION Inventory::toString()
*
* BESKRIVNING
*
* Omvandlar vektorn f�r inventory till en str�ng med f�rem�lens ID.
*
* INDATA
*
* -
*
* UTDATA
*
* int: Storleken p� inventory.
*
* SIDOEFFEKTER
*
* -
*
* UTNYTTJAR
*
* modul: std::vector
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

std::string Inventory::toString()
{
	string s;
	for (auto it : items_)
	{
		s = s + to_string(it->getID()) + " ";
	}
	return s;
}

/*
* FUNKTION Inventory::populateItemList()
*
* BESKRIVNING
*
* L�gger till de f�rem�l som ska finnas i listan �ver alla f�rem�l.
*
* INDATA
*
* -
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
* modul: std::vector
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

void Inventory::populateItemList()
{
	//							ID	Namn		Textur
	allItems_.push_back(new Item{ 0,"Tree",gamePointer_->getTexture("grassTreeChoppable") });
	allItems_.push_back(new Item{ 1,"Axe",gamePointer_->getTexture("pickAxe") });
	allItems_.push_back(new Item{ 2,"Energy Ring",gamePointer_->getTexture("energyRing") });
	allItems_.push_back(new Item{ 3,"Armour",gamePointer_->getTexture("armour") });
	allItems_.push_back(new Item{ 4,"Amulet of Power",gamePointer_->getTexture("amulet") });
	allItems_.push_back(new Item{ 5,"Magic Orb of Fire",gamePointer_->getTexture("magicFireOrb") });
	allItems_.push_back(new Item{ 6,"Magic Wet Chalice",gamePointer_->getTexture("magicWaterCalice") });

}

/*
* SLUT P� FILEN Inventory.cpp
*/