#pragma once
#include "Entity.h"

class Bullet : public Entity
{
private:
	sf::Vector2f _direction;

public:
	Bullet(sf::Vector2f pos, sf::Vector2f direction, GameDataRef data);
	~Bullet();

	void update(float deltaTime) override;
};

