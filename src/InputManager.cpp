#include "InputManager.h"

bool InputManager::isButtonPressed(sf::Keyboard::Key key) const
{
    return sf::Keyboard::isKeyPressed(key);
}

bool InputManager::isMouseButtonPressed(sf::Mouse::Button button) const
{
    return sf::Mouse::isButtonPressed(button);
}
