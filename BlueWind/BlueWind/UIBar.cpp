/*
* IDENTIFIERING
*
* Filnamn:    UIBar.cpp
* Enhetsnamn: UIBar
* Typ:        Definitioner h�rande till klass UIBar
* Revision:   1
* Skriven av: Joakim Bertils, Johannes Grundell
*
*
* BESKRIVNING
*
* Denna implementeringsfil definierar medlemsfunktioner f�r klassen UIBar.
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

#include <string>
#include "UIBar.h"

using namespace std;

/*
* KONSTRUKTOR UIBar(sf::Vector2f position, sf::Vector2f size, sf::Color color, const std::string& postfix, UserInterface* uiPtr)
*
* BESKRIVNING
*
* Denna konstruktor konstruerar en m�tare.
*
* INDATA
*
* position:		Plats p� sk�rm d�r m�taren ska ritas.
* size:			Storlek p� m�taren.
* color:		F�rg p� m�taren.
* postfix:		Text som ska skrivas sist p� m�taren.
* uiPtr:		Pekare till anv�ndargr�nssnittet som m�taren �r en del av.
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

UIBar::UIBar(sf::Vector2f position, sf::Vector2f size, sf::Color color, const std::string& postfix, UserInterface* uiPtr)
	:fillLevel_{ 1 }, 
	position_ {position}, 
	size_ {size}, 
	color_{color}, 
	postfix_ {postfix}, 
	ui_{uiPtr}
{}

/*
* FUNKTION UIBar::update(int current, int max)
*
* BESKRIVNING
*
* Uppdaterar m�taren.
*
* INDATA
*
* current:		Nuvarande v�rdet p� representerad storhet.
* max:			Maximala v�rdet p� representerad storhet.
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
* modul: std::string
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

void UIBar::update(int current, int max)
{
	text_ = to_string(current) + '/' + to_string(max);
	if (max != 0 && current > 0)
	{
		fillLevel_ = static_cast<float>(current) / static_cast<float>(max);
		return;
	}
	fillLevel_ = 0;
}

/*
* FUNKTION UIBar::render(GameWindow& window)
*
* BESKRIVNING
*
* Ritar m�taren.
*
* INDATA
*
* window:		F�nster som m�taren ska ritas p�.
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

void UIBar::render(GameWindow & window)
{
	sf::RectangleShape border{ size_ };
	border.setOutlineColor(sf::Color::Black);
	border.setFillColor(sf::Color::White);
	border.setOutlineThickness(2.0f);

	sf::RectangleShape fill{ sf::Vector2f(size_.x * fillLevel_, size_.y) };
	fill.setOutlineColor(sf::Color::Transparent);
	fill.setFillColor(color_);

	border.setPosition(position_);
	fill.setPosition(position_);

	window.draw(border);
	window.draw(fill);

	sf::Text text{ text_ + postfix_, ui_->getFont(), 16 };
	text.setPosition(position_ + sf::Vector2f(2, 0));
	text.setColor(sf::Color::Black);
	text.setStyle(sf::Text::Bold);
	window.draw(text);
}

/*
* SLUT P� FILEN UIBar.cpp
*/