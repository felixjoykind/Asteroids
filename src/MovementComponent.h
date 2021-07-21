#pragma once

#include "Physics.h"

struct MovementSettings
{
	float maxVelocity;
	float acceleration;
	float deceleration;
};

class MovementComponent
{
private:
	sf::Vector2f _velocity;

	MovementSettings _settings;

public:
	MovementComponent(float maxVel, float acc, float dec);
	MovementComponent(MovementSettings settings);
	virtual ~MovementComponent();

	const sf::Vector2f& GetVelocity() const;
	void Move(const float dir_x, const float dir_y);
	void Update(const float deltaTime);

};

