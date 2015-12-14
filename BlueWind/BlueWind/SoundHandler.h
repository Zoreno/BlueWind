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

#include <map>
#include <string>
#include <SFML/Audio.hpp>
#include <stdexcept>

using soundTable = std::map<const std::string, sf::SoundBuffer*>;
using musicTable = std::map<const std::string, sf::Music*>;

/*
* KLASS SoundException
*
* BASKLASSER
*
* logic_error
*
* BESKRIVNING
*
* Klassen kastar undantag f�r SoundHandler.
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
* 1            151214  Ursprungsversion
*
*/

class SoundException : public std::logic_error
{
public:
	using std::logic_error::logic_error;
};

/*
* KLASS SoundHandler
*
* BASKLASSER
*
* -
*
* BESKRIVNING
*
* Klassen representerar ljudhanteraren i spelet. Ljudhanteraren spelar upp, byter och st�nger av musik och ljudeffekter.
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

class SoundHandler
{
public:
	SoundHandler();
	SoundHandler(const SoundHandler&) = delete;
	SoundHandler& operator=(const SoundHandler&) = delete;

	~SoundHandler();

	void playSound(const std::string&);
	void playMusic(const std::string&);
	void stopMusic();
	
private:
	soundTable sounds_;
	musicTable music_;
	sf::Sound currentSound_;
	std::string currentMusic_;

	void loadSound(const std::string&, const std::string&);
	void loadMusic(const std::string&, const std::string&);
};//class SoundHandler

   /*
   * SLUT P� FILEN SoundHandler.h
   */
