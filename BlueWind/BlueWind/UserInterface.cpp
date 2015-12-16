/*
* IDENTIFIERING
*
* Filnamn:    UserInterface.cpp
* Enhetsnamn: UserInterface
* Typ:        Definitioner h�rande till klass Inventory
* Revision:   1
* Skriven av: Joakim Bertils, Johannes Grundell
*
*
* BESKRIVNING
*
* Denna implementeringsfil definierar medlemsfunktioner f�r klassen UserInterface.
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

#include "UserInterface.h"
#include "UIPortrait.h"
#include "UIChatBox.h"
#include "UIInventoryFrame.h"

using namespace std;

/*
* KONSTRUKTOR UserInterface::UserInterface(Player * playerPtr)
*
* BESKRIVNING
*
* Denna konstruktor konstruerar ett anv�ndagr�nssnitt.
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
* std::map
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

UserInterface::UserInterface(Player * playerPtr)
{
	if (!uiFont_.loadFromFile("res/calibri.ttf"))
	{
		throw UIException("Kan inte l�sa in typsnitt: res/calibri.ttf");
	}
	loadComponents(playerPtr);
}

/*
* DESTRUKTOR UserInterface::~UserInterface()
*
* BESKRIVNING
*
* Denna destruktor destrukterar ett anv�ndargr�nssnitt.
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
* std::map
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

UserInterface::~UserInterface()
{
	while (!components_.empty())
	{
		auto it = components_.begin();
		delete it->second;
		components_.erase(it);
	}
}

/*
* FUNKTION UserInterface::handleKeyEvent(const sf::Event& ev)
*
* BESKRIVNING
*
* Hanterar knapp-event i anv�ndargr�nssnittet.
*
* INDATA
*
* ev:		Eventet som ska hanteras.
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
* modul: std::map
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

void UserInterface::handleKeyEvent(const sf::Event& ev)
{
	for (auto it : components_)
	{
		it.second->handleKeyEvent(ev);
	}
}

/*
* FUNKTION UserInterface::addStringToChatBox(std::string newString)
*
* BESKRIVNING
*
* L�gger till en str�ng till anv�ndargr�nssnittets chattruta.
*
* INDATA
*
* newString:	Str�ngen som ska l�ggas till.
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
* modul: std::map
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

void UserInterface::addStringToChatBox(std::string newString)
{
	dynamic_cast<UIChatBox*>(components_.at("chatbox"))->setConversation(newString);
}

/*
* FUNKTION UserInterface::update()
*
* BESKRIVNING
*
* Uppdaterar anv�ndargr�nssnittet.
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
* modul: std::map
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

void UserInterface::update()
{
	for (auto it : components_)
	{
		it.second->update();
	}
}

/*
* FUNKTION UserInterface::render(GameWindow & window)
*
* BESKRIVNING
*
* Renderar anv�ndargr�nssnittet p� f�nstret.
*
* INDATA
*
* window:		F�nstret som anv�ndargr�nssnittet renderas i.
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
* modul: std::map
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

void UserInterface::render(GameWindow & window)
{
	sf::View old = window.getView();
	window.setView(uiView_);
	for (auto it : components_)
	{
		if (it.second->isVisible())
		{
			it.second->render(window);
		}
	}
	window.setView(old);
}

/*
* FUNKTION UserInterface::getFont()
*
* BESKRIVNING
*
* Returnerar en referens till anv�ndargr�nssnittets typsnitt.
*
* INDATA
*
* -
*
* UTDATA
*
* sf::Font&:		Anv�ndargr�nssnittets typsnitt.
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

sf::Font & UserInterface::getFont()
{
	return uiFont_;
}

/*
* FUNKTION UserInterface::loadComponents(Player* playerPtr)
*
* BESKRIVNING
*
* L�gger till komponenter p� anv�ndargr�nssnittet.
*
* INDATA
*
* playerPtr:		Pekare till spelaren.
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
* modul: std::map
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

void UserInterface::loadComponents(Player* playerPtr)
{
	components_.emplace("portrait", new UIPortrait(this, playerPtr));
	components_.emplace("chatbox", new UIChatBox(this, playerPtr));
	components_.emplace("inventoryScreen", new UIInventoryFrame(this, playerPtr));
}

/*
* SLUT P� FILEN UserInterface.cpp
*/