/*
* IDENTIFIERING
*
* Filnamn:    UIComponent.cpp
* Enhetsnamn: UIComponent
* Typ:        Definitioner h�rande till klass UIComponent
* Revision:   1
* Skriven av: Joakim Bertils, Johannes Grundell
*
*
* BESKRIVNING
*
* Denna implementeringsfil definierar medlemsfunktioner f�r klassen UIComponent
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

#include "UIComponent.h"

/*
* KONSTRUKTOR UIComponent(sf::Vector2f position, sf::Vector2f size, UserInterface * uiPtr, Player * playerPtr, bool visible)
*
* BESKRIVNING
*
* Denna konstruktor konstruerar en komponent p� anv�ndargr�nssnittet.
*
* INDATA
*
* position:		Plats p� sk�rm d�r m�taren ska ritas.
* size:			Storlek p� m�taren.
* uiPtr:		Pekare till anv�ndargr�nssnittet som m�taren �r en del av.
* playerPtr:	Pekare till spelaren.
* visible:		Anger om komponenten ska ritas.
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

UIComponent::UIComponent(sf::Vector2f position, sf::Vector2f size, UserInterface * uiPtr, Player * playerPtr, bool visible)
	:position_{position}, 
	size_{size}, 
	ui_{uiPtr}, 
	player_{playerPtr}, 
	visible_{visible}
{}

/*
* FUNKTION UIComponent::isVisible() const
*
* BESKRIVNING
*
* Returnerar sant om komponenten �r synlig f�r anv�ndaren.
*
* INDATA
*
* -
*
* UTDATA
*
* bool:	Komponentens synlighetsstatus.
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

bool UIComponent::isVisible() const
{
	return visible_;
}

/*
* FUNKTION UIComponent::getPosition() const
*
* BESKRIVNING
*
* Returnerar komponentens position (�vre v�nstra h�rn).
*
* INDATA
*
* -
*
* UTDATA
*
* sf::Vector2f:	Vektor med komponentens position.
*
* REVISIONSBER�TTELSE
*
* Revision             Datum           F�r�ndringar
*
* 1                    151120          Ursprungsversion
*
*/

sf::Vector2f UIComponent::getPosition() const
{
	return position_;
}

/*
* FUNKTION UIComponent::toggleVisible()
*
* BESKRIVNING
*
* V�xlar komponentens synlighetsstatus.
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

void UIComponent::toggleVisible()
{
	visible_ = !visible_;
}

/*
* FUNKTION UIComponent::setVisible(bool value)
*
* BESKRIVNING
*
* S�tter komponentens synlighetsstatus till value.
*
* INDATA
*
* value:	Statusen som synligheten s�tts till.
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

void UIComponent::setVisible(bool value)
{
	visible_ = value;
}

/*
* SLUT P� FILEN UIComponent.cpp
*/