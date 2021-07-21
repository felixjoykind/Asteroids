#pragma once

#include <SFML\Graphics.hpp>
#include "Bullet.h"
#include "Random.h"

constexpr float FLASH_SPEED = 800.f;

class Player : public Entity
{
private:
	bool _canShoot = true;
	bool _isFlashing = false;
	unsigned int _flashCount = 0;
	void flash(float deltaTime);

public:
	Player(sf::Vector2f pos, GameDataRef data);
	~Player();

	// Getters and setters
	float getRotation() const;
	void setRotation(float new_rotation);

	bool canShoot() const;
	void setCanShoot(bool value);
	void shoot(std::vector<Bullet*>& _bullets);
	void startFlashing(unsigned int flashCount);

	void update(float deltaTime) override;

};

