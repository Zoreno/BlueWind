#pragma once

#include <map>
#include "UIComponent.h"
#include "GameWindow.h"

class UserInterface
{
public:
	UserInterface(Player*);
	UserInterface() = delete;
	UserInterface(const UserInterface&) = delete;
	UserInterface& operator=(const UserInterface&) = delete;

	void handleKeyEvent(sf::Event);

	void addStringToChatBox(std::string);

	void update();
	void render(GameWindow&);

	sf::Font& getFont();
private:
	std::map<std::string,UIComponent*> components_;
	void loadComponents(Player*);
	sf::Font uiFont_;
	sf::View uiView_{ sf::FloatRect(0,0,800,600) };
};