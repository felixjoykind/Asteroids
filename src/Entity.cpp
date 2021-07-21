#include "Entity.h"

Entity::Entity(sf::Vector2f pos, GameDataRef data)
	:_data(data), _spr(new sf::Sprite())
{
	this->_spr->setPosition(pos);
}

Entity::~Entity()
{
	if (this->_spr)
		delete this->_spr;

	if(this->movementComponent)
		delete this->movementComponent;
	std::cout << "entity destructor" << std::endl;
}

void Entity::loadSprite(const sf::Texture& texture)
{
	this->_spr->setTexture(texture);
	this->_spr->setOrigin(
		float(this->_spr->getTexture()->getSize().x / 2),
		float(this->_spr->getTexture()->getSize().y / 2));
	this->_spr->setScale(0.2f, 0.2f);
}

void Entity::createMovementComponent(MovementSettings settings)
{
	this->movementComponent = new MovementComponent(settings);
}

sf::Vector2f Entity::getPosition() const
{
	return this->_spr->getPosition();
}

const sf::Sprite& Entity::getSpr() const
{
	return *this->_spr;
}

sf::Vector2f Entity::getScaledSize() const
{
	return sf::Vector2f(
		_spr->getTexture()->getSize().x * _spr->getScale().x,
		_spr->getTexture()->getSize().y * _spr->getScale().y);
}

bool Entity::hits(const Entity& other) const
{
	float xDist = abs(this->getPosition().x - other.getPosition().x);
	float yDist = abs(this->getPosition().y - other.getPosition().y);
	float distance = sqrt(xDist * xDist + yDist * yDist);

	return distance < this->getScaledSize().x / 2.0f
		&& distance < this->getScaledSize().y / 2.0f;
}

void Entity::move(const float dir_x, const float dir_y, float deltaTime)
{
	if (this->movementComponent)
	{
		this->movementComponent->Move(dir_x, dir_y);
		this->_spr->move(movementComponent->GetVelocity() * deltaTime);
	}
}

void Entity::update(float deltaTime)
{
	if (this->_spr && this->movementComponent)
	{
		this->movementComponent->Update(deltaTime);
	}
}

void Entity::render() const
{
	if (this->_spr)
		_data->window.draw(*this->_spr);
}
