#include "Bullet.h"

Bullet::Bullet(sf::Vector2f pos, sf::Vector2f direction, GameDataRef data)
	:Entity(pos, data), _direction(direction)
{
	this->loadSprite(_data->assets.GetTexture("bullet"));
	this->_spr->setScale(0.05f, 0.05f);
}

Bullet::~Bullet()
{ }

void Bullet::update(float deltaTime)
{
	this->_spr->move(_direction.x * 300.0f * deltaTime, _direction.y * 300.0f * deltaTime);
}
