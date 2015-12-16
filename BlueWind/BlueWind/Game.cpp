
/*
* IDENTIFIERING
*
* Filnamn:    Game.cpp
* Enhetsnamn: Game
* Typ:        Definitioner h�rande till klass Game och GameState
* Revision:   1
* Skriven av: Joakim Bertils, Johannes Grundell
*
*
* BESKRIVNING
*
* Denna implementeringsfil definierar medlemsfunktioner f�r klasserna Game och GameState.
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


#include <fstream>
#include <sstream>
#include "Game.h"
#include "Application.h"
#include "Universe.h"

using namespace std;

/*
* FUNKTION toString()
*
* BESKRIVNING
*
* Konstruerar en str�ng av de tre datamedlemmarna i klassen
*
* INDATA
*
*
* UTDATA
*
* std::string :	en str�ng som inneh�ller de tre datamedlemmarna i klassen
*
* SIDOEFFEKTER
*
* -
*
* UTNYTTJAR
*
* std::string
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/
string GameState::toString()
{
	string s;
	s.append(to_string(bridge1Built) + " ");
	s.append(to_string(minotaurDead) + " ");
	s.append(to_string(bridge2Built));
	return s;
}

/*
* KONSTRUKTOR Game(Application * appPtr, bool loadSave)
*
* BESKRIVNING
*
* Konstruktor f�r Game-klassen
*
* INDATA
*
* appPtr :		En pekare till applikationen	
* loadSave :	Boolsk uttryck f�r om vi vill k�ra load eller save 
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
Game::Game(Application * appPtr, bool loadSave)
	:Frame{appPtr}, 
	universe_{this}, 
	player_{universe_.getCurrentWorld(), textureHandler_.getTextureRef("player"), this }, 
	ui_{&player_}
{
	if (loadSave)
	{
		loadGame();
	}
	else
		appPtr->getSoundHandler().playMusic("world0Music");
}

/*
* FUNKTION update()
*
* BESKRIVNING
*
* Uppdaterar viktiga delar i spelet
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
void Game::update()
{
	universe_.update();
	player_.update();
	ui_.update();
}

/*
* FUNKTION render(GameWindow & window)
*
* BESKRIVNING
*
* Renderar viktiga delar i spelet
*
* INDATA
*
* window:	Spelf�nstret
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
void Game::render(GameWindow & window)
{
	sf::View camera = window.getView();
	camera.setCenter(player_.getPosition());
	window.setView(camera);
	universe_.render(window);
	player_.render(window);
	ui_.render(window);
}

/*
* FUNKTION handleKeyEvent(sf::Event event)
*
* BESKRIVNING
*
* K�nner av vilka knappar som trycks in
*
* INDATA
*
* event:	H�r lagras vilken knapp som tryckts in
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
void Game::handleKeyEvent(sf::Event event)
{
	switch (event.key.code)
	{
	case sf::Keyboard::Space:
		player_.swordAttack(universe_.getCurrentWorld()->getEnemyVector());
		break;
	case sf::Keyboard::J:
		player_.fireballAttack(universe_.getCurrentWorld()->getEnemyVector());
		break;
	case sf::Keyboard::K:
		player_.interact(universe_.getCurrentWorld()->getNPCVector());
		break;
	case sf::Keyboard::L:
		ui_.handleKeyEvent(event);
		break;
	default:
		break;
	}
}

/*
* FUNKTION handleMouseEvent(sf::Event)
*
* BESKRIVNING
*
* K�nner av vilka musr�relser i spelet (dvs inga)
*
* INDATA
*
* event:	H�r lagras musr�relser
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
void Game::handleMouseEvent(sf::Event)
{
}

/*
* FUNKTION splitString(string s)
*
* BESKRIVNING
*
* Genererar en lista, delar upp str�ngar vid mellanslag
*
* INDATA
*
* s:	En str�ng
*
* UTDATA
*
* Vector<int>: 
*
* SIDOEFFEKTER
*
* 
*
* UTNYTTJAR
*
* modul: sfml-grafik
* std::string
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/
vector<int> splitString(string s)
{
	stringstream ss(s);
	vector<int> IDs;
	string sub;

	while (ss >> sub)
		IDs.push_back(stoi(sub));
	return IDs;
}

/*
* FUNKTION saveGame()
*
* BESKRIVNING
*
* Sparar aktuellt spel
*
* INDATA
*
* -
*
* UTDATA
*
* savefile.txt:		Sparar aktuellt speltillst�nd till en txt-fil.
*
* SIDOEFFEKTER
*
*
*
* UTNYTTJAR
*
* modul: sfml-grafik
* std::string
* modul: iostream
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/
void Game::saveGame()
{
	ofstream saveStream;
	saveStream.open("savefile.txt", std::ofstream::out | std::ofstream::trunc);
	if (saveStream.is_open())
	{
		saveStream << player_.getName() << endl;
		saveStream << player_.getMaxHealth() << endl;
		saveStream << player_.getMaxMana() << endl;
		saveStream << player_.getDamage() << endl;
		saveStream << player_.getLevel() << endl;
		saveStream << player_.getExperience() << endl;
		saveStream << universe_.getCurrentWorld()->getID() << endl;
		saveStream << player_.getPosition().x << endl;
		saveStream << player_.getPosition().y << endl;
		saveStream << player_.getInventory()->toString() << endl;
		saveStream << gameState_.toString() << endl;
		saveStream.close();
	}
	else
		throw FrameException("Kunde inte spara data till savefile.txt");
}

/*
* FUNKTION loadGame()
*
* BESKRIVNING
*
* Laddar senast sparade spel fr�n savefile.txt
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
* std::string
* modul: iostream
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/
void Game::loadGame()
{
	string line;
	ifstream saveStream("savefile.txt");
	if (saveStream.is_open())
	{
		getline(saveStream, line); //name
		player_.setName(line);
		getline(saveStream, line); //maxHealth
		player_.setMaxHealth(stoi(line));
		getline(saveStream, line); //maxMana
		player_.setMaxMana(stoi(line));
		getline(saveStream, line); //damage
		player_.setDamage(stoi(line));
		getline(saveStream, line); //level
		player_.setLevel(stoi(line));
		getline(saveStream, line); //experience
		player_.setExperience(stoi(line));
		getline(saveStream, line); //currWorld
		int worldID = stoi(line);
		getline(saveStream, line); //pos x
		int posX = stoi(line);
		getline(saveStream, line); //pos y
		int posY = stoi(line);
		universe_.switchWorld(worldID, posX, posY);
		getline(saveStream, line); //inv
		vector<int> items = splitString(line);
		for (auto it : items)
		{
			player_.getInventory()->addItem(it);
		}
		getline(saveStream, line); //Gamestate
		if (line.at(0) == '1') //Bridge1
		{
			int startposition{ 13 * universe_.getWorld(0)->getMapWidth() + 40 };
			for (int i{ 0 }; i < 10; ++i)
			{
				universe_.getWorld(0)->changeTile(startposition + i, 2);
			}
			gameState_.bridge1Built = true;
		}

		if (line.at(2) == '1') //Minotaur
		{
			universe_.populateCity();
			gameState_.minotaurDead = true;
		}

		if (line.at(4) == '1') // Bridge2
		{
			int startposition{ 17 * universe_.getWorld(2)->getMapWidth() + 63 };

			for (int i{ 0 }; i < 2; ++i)
			{
				universe_.getWorld(2)->changeTile(startposition + i, 2);
			}
			gameState_.bridge2Built = true;
		}
		saveStream.close();
	}
	else
		throw FrameException("Kunde inte ladda data fr�n savefile.txt");
}

/*
* FUNKTION Game::getPlayer()
*
* BESKRIVNING
*
* Returnerar spelaren
*
* INDATA
*
* -
*
* UTDATA
*
* Player*:	En pekare till spelaren
*
* SIDOEFFEKTER
*
* -
*
* UTNYTTJAR
*
*�-
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/
Player * Game::getPlayer()
{
	return &player_;
}

/*
* FUNKTION Game::getApp()
*
* BESKRIVNING
*
* Returnerar en pekare till applikationen
*
* INDATA
*
* -
*
* UTDATA
*
* Application*:	En pekare till applikationen
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
Application * Game::getApp()
{
	return appPointer_;
}

/*
* FUNKTION Game::getUserInterface()
*
* BESKRIVNING
*
* Returnerar en pekare till user interface
*
* INDATA
*
* -
*
* UTDATA
*
* UserInterface*:	En pekare till user interfacet
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
UserInterface * Game::getUserInterface()
{
	return &ui_;
}

/*
* FUNKTION Game::getGameState()
*
* BESKRIVNING
*
* Returnerar en pekare till Game State
*
* INDATA
*
* -
*
* UTDATA
*
* GameState*:	En pekare till user GameState
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
GameState * Game::getGameState()
{
	return &gameState_;
}

/*
* FUNKTION Game::getTexture(const std::string& ref)
*
* BESKRIVNING
*
* Returnerar referensen till en textur
*
* INDATA
*
* -
*
* UTDATA
*
* Texture &:	En referens till en textur
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
sf::Texture & Game::getTexture(const std::string& ref)
{
	return textureHandler_.getTextureRef(ref);
}

