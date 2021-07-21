#include "Game.h"
#include "GameState.h"

Game::Game(unsigned int w, unsigned int h, std::string title)
{
	this->_data->window.create(sf::VideoMode(w, h), title, sf::Style::Titlebar | sf::Style::Close);

	this->_data->assets.LoadTexture("player", PLAYER_TEXTURE_FILEPATH);
	this->_data->assets.LoadTexture("bullet", BULLET_TEXTURE_FILEPATH);
	this->_data->assets.LoadTexture("asteroid", ASTEROID_TEXTURE_FILEPATH);

	this->_data->assets.LoadFont("basic font", BASIC_FONT_FILEPATH);

	this->_data->machine.AddState(StateRef(new GameState(this->_data)), false);

	this->_data->window.setFramerateLimit(60);
}

Game::~Game()
{ }

void Game::Run()
{
	this->_deltaClock.restart();
	while (this->_data->window.isOpen())
	{
		this->_data->machine.ProcessStateChanges();
		this->_data->machine.GetActiveState()->PollEvents();
		this->_data->machine.GetActiveState()->update(this->_deltaClock.restart().asSeconds());
		this->_data->machine.GetActiveState()->render();
	}
}
