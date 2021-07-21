#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "Defenitions.hpp"
#include <SFML/Graphics.hpp>

class Physics
{
public:
	static float DegToRad(float angle);
	static float Clamp(float min, float max, float val);
	static sf::Vector2f WrapCoordinates(sf::Vector2f pos, sf::Vector2f size);
};

