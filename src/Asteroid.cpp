#include "Asteroid.h"

Asteroid::Asteroid(sf::Vector2f pos, sf::Vector2f direction, sf::Vector2f scale, GameDataRef data)
	:Entity(pos, data), _direction(direction)
{
	this->loadSprite(_data->assets.GetTexture("asteroid"));
	this->createMovementComponent({ 30.0f, 30.0f, 0.0f });
	this->_spr->setRotation(Random::Float(360.0f));
	this->_spr->setScale(scale);
}

Asteroid::~Asteroid()
{ }

std::pair<Asteroid*, Asteroid*> Asteroid::breakup() const
{
	return std::make_pair(
		new Asteroid(
			this->getPosition(), // first
			sf::Vector2f(Random::Float() - 0.5f, Random::Float() - 0.5f),
			this->getSpr().getScale() / 2.0f, _data
		),

		new Asteroid(
			this->getPosition(), // second
			sf::Vector2f(Random::Float() - 0.5f, Random::Float() - 0.5f),
			this->getSpr().getScale() / 2.0f, _data
		)
	);
}

void Asteroid::update(float deltaTime)
{
	this->move(_direction.x, _direction.y, deltaTime);
	this->movementComponent->Update(deltaTime);

	this->_spr->setPosition(Physics::WrapCoordinates(_spr->getPosition(), this->getScaledSize()));
}
