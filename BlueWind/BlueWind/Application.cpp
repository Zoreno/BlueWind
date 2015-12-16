/*
* IDENTIFIERING
*
* Filnamn:    Application.cpp
* Enhetsnamn: Application
* Typ:        Definitioner h�rande till klass Application
* Revision:   1
* Skriven av: Joakim Bertils
*
*
* BESKRIVNING
*
* Denna implementeringsfil definierar medlemsfunktioner f�r klassen Application.
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

#include "Application.h"

using namespace std;

/*
* KONSTRUKTOR Application()
*
* BESKRIVNING
*
* Denna konstruktor konstruerar en applikation.
*
* INDATA
*
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

Application::Application()
	: input_{ this }
{
	window_.setFramerateLimit(60);
	sf::Image icon;
	if (icon.loadFromFile("res/textures/icon.png"))
	{
		window_.setIcon(32,32,icon.getPixelsPtr());
	}
	currentFrame_ = new Menu(this);
	nextFrame_ = currentFrame_; 
}

/*
* DESTRUKTOR ~Application()
*
* BESKRIVNING
*
* Denna destruktor destruerar en applikation.
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

Application::~Application()
{
	delete currentFrame_;
}

/*
* FUNKTION run()
*
* BESKRIVNING
*
* Denna funktion k�r en applikation.
*
* INDATA
*
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

void Application::run()
{
	while (window_.isOpen())
	{
		sf::Event event;
		while (window_.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window_.close();

			if (event.type == sf::Event::KeyReleased)
			{
				input_.keyPressed(event);
			}
			if (event.type == sf::Event::MouseButtonReleased)
			{
 				input_.mousePressed(event);
			}
		}

		update();

		window_.clear();
		render(window_);
		window_.display();

		if (currentFrame_ != nextFrame_) // Fick skumma fel om frame-bytet gjordes mitt i loopen
			changeCurrentFrame(); 
	}
}

/*
* FUNKTION render(GameWindow & window)
*
* BESKRIVNING
*
* Denna funktion ritar upp hela spelet.
*
* INDATA
*
* window : Det f�nster i vilket vi vill rita upp applikationen
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

void Application::render(GameWindow & window)
{
	currentFrame_->render(window);
}

/*
* FUNKTION update()
*
* BESKRIVNING
*
* Denna funktion uppdaterar applikationen
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

void Application::update()
{
	currentFrame_->update();
	input_.update();
}

/*
* FUNKTION getInput()
*
* BESKRIVNING
*
* Denna funktion returnerar applikationens Input-objekt
*
* INDATA
*
* -
*
* UTDATA
*
* const Input& : Applikationens Input-objekt
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

const Input& Application::getInput()
{
	return input_;
}

/*
* FUNKTION getCurrentFrame()
*
* BESKRIVNING
*
* Denna funktion returnerar den nuvarande framen
*
* INDATA
*
* -
*
* UTDATA
*
* Frame* : En pekare till den nuvarande framen
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

Frame * Application::getCurrentFrame()
{
	return currentFrame_;
}

/*
* FUNKTION changeCurrentFrame()
*
* BESKRIVNING
*
* Denna funktion �ndrar den nuvarande framen
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

void Application::changeCurrentFrame()
{
	delete currentFrame_;
	currentFrame_ = nextFrame_;
	
	sf::View view = window_.getView();
	view.setCenter(sf::Vector2f(400, 300)); // Beh�ver �terst�llas vid byte fr�n game till meny
	window_.setView(view);
}

/*
* FUNKTION getGameWindow()
*
* BESKRIVNING
*
* Denna funktion �ndrar det nuvarande f�nstret
*
* INDATA
*
* -
*
* UTDATA
*
* GameWindow& : En GameWindow-referens som inneh�ller det nuvarande f�nstret
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

GameWindow& Application::getGameWindow()
{
	return window_;
}

/*
* FUNKTION getSoundHandler()
*
* BESKRIVNING
*
* Denna funktion returnerar ett soundhandler-objekt
*
* INDATA
*
* -
*
* UTDATA
*
* SoundHandler : Applikationens SoundHandler-objekt
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

SoundHandler & Application::getSoundHandler()
{
	return soundHandler_;
}

/*
* FUNKTION getSoundHandler()
*
* BESKRIVNING
*
* Denna funktion returnerar ett soundhandler-objekt
*
* INDATA
*
* framePtr : En frame-pekare till n�sta frame
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

void Application::setNextFrame(Frame* framePtr)
{
	nextFrame_ = framePtr;
}

/*
* SLUT P� FILEN Application.cpp
*/