/*
* IDENTIFIERING
*
* Filnamn:    Inventory.h
* Enhetsnamn: Inventory
* Typ:        Moduldeklaration
* Revision:   1
* Skriven av: Joakim Bertils, Johannes Grundell
*
*
* BESKRIVNING
*
* Denna modul representerar f�rr�d i spelet.
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
#include <vector>
#include <stdexcept>
#include "Item.h"

/*
* Fram�tdeklarationer
*/

class Player;
class Game;

/*
* KLASS InvetoryException
*
* BASKLASSER
*
* logic_error
*
* BESKRIVNING
*
* Klassen hanterar undantag i Inventory.
*
* TILLST�ND
*
* -
*
* KONSTRUKTORER
*
* default-konstruktor.
*
* OPERATIONER
*
* -
*
* DATAMEDLEMMAR
*
* -
*
* REVISIONSBER�TTELSE
*
* Revision     Datum   F�r�ndringar
*
* 1            151120  Ursprungsversion
*
*/

class InventoryException : public std::logic_error
{
public:
	using std::logic_error::logic_error;
};

/*
* KLASS Inventory
*
* BASKLASSER
*
* -
*
* BESKRIVNING
*
* Klassen representerar f�rr�d i spelet
*
* TILLST�ND
*
* -
*
* KONSTRUKTORER
*
* Inventory(Player* playerPtr, Game* gamePtr);
*
* OPERATIONER
*
* -
*
* DATAMEDLEMMAR
*
* items_:			Lista �ver f�rr�dets f�rem�l.
* maxSize_:			F�rr�dets maxstorlek.
* playerPointer_:	Pekare till spelaren.
* gamePointer_:		Pekare till spelframe.
* allItems_:		Lista med alla items som finns i spelet.
*
* REVISIONSBER�TTELSE
*
* Revision     Datum   F�r�ndringar
*
* 1            151120  Ursprungsversion
*
*/

class Inventory
{
public:
	Inventory() = delete;
	Inventory(const Inventory&) = delete;
	Inventory& operator=(const Inventory&) = delete;
	Inventory(Player*, Game*);
	~Inventory();

	void addItem(int);
	void removeItem(int);
	bool hasItem(int);
	bool isFull();
	const int getCount(int);
	const int getSize();
	const unsigned int getMaxSize();

	Item* at(int);

	std::string toString();

private:
	std::vector<Item*> items_;
	const unsigned int maxSize_{8};
	Player* playerPointer_;
	Game* gamePointer_;

	void populateItemList();
	std::vector<Item*> allItems_;
};//class Inventory

/*
 * SLUT P� FILEN Inventory.h
 */