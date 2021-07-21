#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "AssetManager.h"
#include "StateMachine.h"
#include "InputManager.h"

struct GameData
{
	sf::RenderWindow window;
	AssetManager assets;
	StateMachine machine;
	InputManager input;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game
{
private:
	GameDataRef _data = std::make_shared<GameData>();

	sf::Clock _deltaClock;

public:
	// Init
	Game(unsigned int w, unsigned int h, std::string title);
	~Game();

	void Run();

};

