#include "Player.h"

Player::Player(sf::Vector2f pos, GameDataRef data)
	:Entity(pos, data)
{
	this->loadSprite(_data->assets.GetTexture("player"));
	this->createMovementComponent({ 150.f, 3.f, 1.f });
}

Player::~Player()
{ }

float Player::getRotation() const
{
	return this->_spr->getRotation();
}

void Player::setRotation(float new_rotation)
{
	this->_spr->setRotation(new_rotation);
}

bool Player::canShoot() const
{
	return this->_canShoot;
}

void Player::setCanShoot(bool value)
{
	this->_canShoot = value;
}

void Player::shoot(std::vector<Bullet*>& _bullets)
{
	_bullets.push_back(new Bullet(
		this->getPosition(),
		{ sin(Physics::DegToRad(this->getRotation())), -cos(Physics::DegToRad(this->getRotation())) },
		_data
	));
	this->_canShoot = false;
}

void Player::startFlashing(unsigned int flashCount)
{
	this->_isFlashing = true;
	this->_flashCount = flashCount;
}

void Player::flash(float deltaTime)
{
	auto new_clr = _spr->getColor();
	int alpha = (int)new_clr.a;
	alpha -= int(FLASH_SPEED * deltaTime);
	if (alpha <= 0)
	{
		this->_flashCount--;
		if (this->_flashCount == 0)
		{
			this->_isFlashing = false;
			alpha = 255;
		}
	}

	new_clr.a = alpha;
	this->_spr->setColor(new_clr);
}

void Player::update(float deltaTime)
{
	// movement
	this->movementComponent->Update(deltaTime);
	this->_spr->move(movementComponent->GetVelocity() * deltaTime);

	this->_spr->setPosition(Physics::WrapCoordinates(_spr->getPosition(), this->getScaledSize()));

	// flash
	if (this->_isFlashing)
	{
		this->flash(deltaTime);
	}
}
