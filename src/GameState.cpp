#include "GameState.h"

GameState::GameState(GameDataRef data)
	:_data(data),
	player(new Player(sf::Vector2f(
		float(_data->window.getSize().x / 2),
		float(_data->window.getSize().y / 2)), this->_data))
{ }

GameState::~GameState()
{
	delete this->player;
}

void GameState::Init()
{
	// init ui
	this->_livesText = sf::Text("Lives: " + std::to_string(_lives), _data->assets.GetFont("basic font"), 32);
	this->_livesText.setPosition(10.f, 10.f);

	// spawning asteroids
	for (unsigned short int i = 0; i < 6; i++)
	{
		this->_asteroids.push_back(new Asteroid(
			{ Random::Float(SCREEN_WIDTH), Random::Float(SCREEN_HEIGHT) },
			{ Random::Float(2.0f) - 1.0f, Random::Float(2.0f) - 1.0f }, 
			{ 0.4f, 0.4f }, _data));
	}
}

void GameState::PollEvents()
{
	sf::Event ev;
	while (_data->window.pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed)
		{
			_data->window.close();
		}

		// cheking if space is unpressed to be ready to shoot again
		if (ev.type == sf::Event::KeyReleased)
		{
			if (ev.key.code == sf::Keyboard::Space)
			{
				this->player->setCanShoot(true);
			}
		}
	}
}

void GameState::update(float deltaTime)
{
	// input
	if (_data->input.isButtonPressed(sf::Keyboard::A))
	{
		player->setRotation(player->getRotation() - 150.0f * deltaTime);
	}
	else if (_data->input.isButtonPressed(sf::Keyboard::D))
	{
		player->setRotation(player->getRotation() + 150.0f * deltaTime);
	}

	// shoting if space is pressed
	if (_data->input.isButtonPressed(sf::Keyboard::Space))
	{
		if (this->player->canShoot())
			this->player->shoot(_bullets);
	}

	if (_data->input.isButtonPressed(sf::Keyboard::W))
	{
		// movement logic
		player->move( // passing direction based on angle
			sin(Physics::DegToRad(player->getRotation())),
			-cos(Physics::DegToRad(player->getRotation())),
			deltaTime);
	}

	// checking bullets for collision
	for (int i = _bullets.size() - 1; i >= 0; --i)
	{
		const auto& b = _bullets[i];
		if (b->getPosition().x > SCREEN_WIDTH || b->getPosition().x < 0.0f
			|| b->getPosition().y > SCREEN_HEIGHT || b->getPosition().y < 0.0f)
		{
			_bullets.erase(_bullets.begin() + i);
			continue;
		}

		for (int j = _asteroids.size() - 1; j >= 0; --j)
		{
			const auto& a = _asteroids[j];
			if (a->hits(*b))
			{
				// spawning new asteroids
				if (a->getSpr().getScale().x / 2.0f > 0.05f)
				{
					auto new_asteroids = a->breakup();
					this->_asteroids.push_back(new_asteroids.first);
					this->_asteroids.push_back(new_asteroids.second);
				}

				// deleting asteroid and bullet
				delete _bullets[i];
				delete _asteroids[j];
				_bullets.erase(_bullets.begin() + i);
				_asteroids.erase(_asteroids.begin() + j);

				this->_score += 100;
				break;
			}
		}
	}

	// checking for collision beetwen player and asteroids
	for (unsigned int i = 0; i < _asteroids.size(); i++)
	{
		if (_asteroids[i]->hits(*this->player))
		{
			// delete asteroid
			delete _asteroids[i];
			this->_asteroids.erase(_asteroids.begin() + i);

			this->_lives--;
			this->_livesText.setString("Lives: " + std::to_string(_lives));
			this->player->startFlashing(3);
			break;
		}
	}

	// checking for player to die
	if (this->_lives == 0)
	{
		// TODO: add timer logic
		_data->machine.AddState(StateRef(new EndGameState(_data, { _score })), true);
	}

	// updating bullets
	for (auto& b : _bullets)
		b->update(deltaTime);

	// updating asteroids
	for (auto& a : _asteroids)
		a->update(deltaTime);

	// updating player
	this->player->update(deltaTime);
}

void GameState::render() const
{
	_data->window.clear();

	// render player
	this->player->render();
	
	// render bullets
	for (const auto& b : _bullets)
		b->render();

	// render asteroids
	for (const auto& a : _asteroids)
		a->render();

	// ui
	this->_data->window.draw(_livesText);

	_data->window.display();
}
