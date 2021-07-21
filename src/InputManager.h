#pragma once
#include <SFML/Graphics.hpp>

class InputManager
{
public:
	InputManager() { }
	~InputManager() { }

	bool isButtonPressed(sf::Keyboard::Key key) const;
	bool isMouseButtonPressed(sf::Mouse::Button button) const;

};

