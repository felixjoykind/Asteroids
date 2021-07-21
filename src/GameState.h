#pragma once

#include "Defenitions.hpp"

#include "Player.h"
#include "Asteroid.h"
#include "EndGameState.h"

class GameState : public State
{
private:
	GameDataRef _data;

	// player data
	Player* player;
	unsigned int _score = 0;
	unsigned short int _lives = 3;

	// ui
	sf::Text _livesText;
	
	// game objects
	std::vector<Bullet*> _bullets;
	std::vector<Asteroid*> _asteroids;

public:
	// Init
	GameState(GameDataRef data);
	~GameState();

	void Init() override;

	void PollEvents() override;

	// Functions
	void update(float deltaTime) override;
	void render() const override;

};

