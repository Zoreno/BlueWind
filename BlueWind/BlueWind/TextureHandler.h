/* IDENTIFIERING
*
* Filnamn:    TextureHandler.h
* Enhetsnamn: TextureHandler
* Typ:        Moduldeklaration
* Revision:   1
* Skriven av: Simon Arkeholt, Fredrik Gustafsson
*
*
* BESKRIVNING
*
* Denna modul representerar texturhanteraren i spelet.
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
#include <SFML\Graphics.hpp>
#include <stdexcept>

using textureTable = std::map<const std::string, sf::Texture*>;

/*
* KLASS TextureException
*
* BASKLASSER
*
* logic_error
*
* BESKRIVNING
*
* Klassen kastar undantag f�r TextureHandler.
*
* KONSTRUKTORER
*
* default-konstruktor.
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

class TextureException : public std::logic_error
{
public:
	using std::logic_error::logic_error;
};

/*
* KLASS TextureHandler
*
* BASKLASSER
*
* -
*
* BESKRIVNING
*
* Klassen representerar texturhateraren i spelet. TextureHandler l�ser in, sparar och ger �tkomst till alla texturer som anv�nds i spelet. 
*
* KONSTRUKTORER
*
* TextureHandler()
*
* DATAMEDLEMMAR
*
* textures_:		TextureTable med alla texturer lagrade.
*
* REVISIONSBER�TTELSE
*
* Revision     Datum   F�r�ndringar
*
* 1            151214  Ursprungsversion
*
*/

class TextureHandler
{
public:
	TextureHandler();
	TextureHandler(const TextureHandler&) = delete;
	TextureHandler& operator=(const TextureHandler&) = delete;

	~TextureHandler();

	sf::Texture& getTextureRef(const std::string&);
private:
	textureTable textures_;

	void loadTexture(const std::string&, const std::string&);
};// class TextureHandler

/*
* SLUT P� FILEN TextureHandler.h
*/