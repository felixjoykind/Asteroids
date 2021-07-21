#pragma once

#include "Game.h"
#include "MovementComponent.h"

class Entity
{
protected:
	GameDataRef _data;

	sf::Sprite* _spr = nullptr;
	MovementComponent* movementComponent = nullptr;

public:
	Entity(sf::Vector2f pos, GameDataRef data);
	virtual ~Entity() = 0;
	virtual void loadSprite(const sf::Texture& texture);
	virtual void createMovementComponent(MovementSettings settings);

	// Getters
	virtual sf::Vector2f getPosition() const;
	virtual const sf::Sprite& getSpr() const;
	virtual sf::Vector2f getScaledSize() const;

	virtual bool hits(const Entity& other) const;

	virtual void move(const float dir_x, const float dir_y, float deltaTime);

	virtual void update(float deltaTime);
	virtual void render() const;
	
};

