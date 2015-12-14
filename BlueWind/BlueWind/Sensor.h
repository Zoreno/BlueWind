/* IDENTIFIERING
*
* Filnamn:    SoundHandler.h
* Enhetsnamn: SoundHandler
* Typ:        Moduldeklaration
* Revision:   1
* Skriven av: Simon Arkeholt, Fredrik Gustafsson
*
*
* BESKRIVNING
*
* Denna modul representerar en ljudhanterare i spelet.
*
* REVISIONSBER�TTELSE
*
* Revision     Datum   F�r�ndringar
*
* 1            151214  Ursprungsversion
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
* KLASS SoundHandler
*
* BASKLASSER
*
* Entity
*
* BESKRIVNING
*
* Klassen representerar sensorer i spelet. Sensorer triggar h�ndelser n�r spelaren n�rmar sig.
*
* TILLST�ND
*
* -
*
* KONSTRUKTORER
*
* SoundHandler()
*
* OPERATIONER
*
* -
*
* DATAMEDLEMMAR
*
* sounds_:			map inneh�llande namn p� ljud och motavarande SoundBuffer.
* music_:			map inneh�llande namn p� musik och motsvarande Music.
* currentSound_:	Nuvarande ljud som ska spalas upp.
* currentMusic_:	Nuvarnde musikslinga som ska spelas upp.
*
* REVISIONSBER�TTELSE
*
* Revision     Datum   F�r�ndringar
*
* 1            151214  Ursprungsversion
*
*/

class Game;

class Sensor : public Entity
{
public:
	Sensor(int, std::string, sf::Vector2f, World*, std::function<void(World*)>, sf::Texture&);
	Sensor() = delete;
	Sensor(const Sensor&) = delete;
	Sensor& operator=(const Sensor&) = delete;

	void update() override;
	void render(GameWindow&) override;
	void trigger();

	void die() override;
private:
	std::function<void(World*)> callback_;
};
