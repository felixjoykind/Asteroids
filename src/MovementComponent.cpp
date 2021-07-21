#include "MovementComponent.h"
#include <iostream>

MovementComponent::MovementComponent(float maxVel, float acc, float dec)
	:_settings({ maxVel, acc, dec })
{
}

MovementComponent::MovementComponent(MovementSettings settings)
	:_settings(settings)
{
}

MovementComponent::~MovementComponent()
{ }

const sf::Vector2f& MovementComponent::GetVelocity() const
{
	return this->_velocity;
}

void MovementComponent::Move(const float dir_x, const float dir_y)
{
	this->_velocity.x += _settings.acceleration * dir_x;
	this->_velocity.x = Physics::Clamp(-_settings.maxVelocity, _settings.maxVelocity, _velocity.x);

	this->_velocity.y += _settings.acceleration * dir_y;
	this->_velocity.y = Physics::Clamp(-_settings.maxVelocity, _settings.maxVelocity, _velocity.y);
}

void MovementComponent::Update(const float deltaTime)
{
	if (_velocity.x > 0.0f)
	{
		_velocity.x -= _settings.deceleration;
		if (_velocity.x < 0.0f) _velocity.x = 0.0f;
	}
	else if (_velocity.x < 0.0f)
	{
		_velocity.x += _settings.deceleration;
		if (_velocity.x > 0.0f) _velocity.x = 0.0f;
	}

	if (_velocity.y > 0.0f)
	{
		_velocity.y -= _settings.deceleration;
		if (_velocity.y < 0.0f) _velocity.y = 0.0f;
	}
	else if (_velocity.y < 0.0f)
	{
		_velocity.y += _settings.deceleration;
		if (_velocity.y > 0.0f) _velocity.y = 0.0f;
	}
}
