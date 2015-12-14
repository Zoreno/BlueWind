/* IDENTIFIERING
*
* Filnamn:    Sensor.h
* Enhetsnamn: Sensor
* Typ:        Moduldeklaration
* Revision:   1
* Skriven av: Simon Arkeholt, Fredrik Gustafsson
*
*
* BESKRIVNING
*
* Denna modul representerar en sensor i spelet.
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
* Klassen representerar sensorer i spelet. Sensorer triggar callbackfunktioner n�r spelaren n�rmar sig.
*
* TILLST�ND
*
* -
*
* KONSTRUKTORER
*
* Sensor(int, std::string, sf::Vector2f, World*, std::function<void(World*)>, sf::Texture&)
*
* OPERATIONER
*
* -
*
* DATAMEDLEMMAR
*
* callback_:		Callbackfunktion som triggas av sensorn.
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
};//class Sensor

   /*
   * SLUT P� FILEN Sensor.h
   */