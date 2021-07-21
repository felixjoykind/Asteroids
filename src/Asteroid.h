#pragma once

#include "Entity.h"
#include "Random.h"

class Asteroid : public Entity
{
private:
	sf::Vector2f _direction;

public:
	Asteroid(sf::Vector2f pos, sf::Vector2f direction, sf::Vector2f scale, GameDataRef data);
	~Asteroid();

	std::pair<Asteroid*, Asteroid*> breakup() const;

	void update(float deltaTime) override;

};

