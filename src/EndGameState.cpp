#include "EndGameState.h"

EndGameState::EndGameState(GameDataRef data, Statistic stats)
	:_data(data), _stats(stats)
{

}

EndGameState::~EndGameState()
{
	delete _title;
	delete	_score;
	delete _subtitle;

}

void EndGameState::Init()
{
	this->_title = new sf::Text("Game Over", _data->assets.GetFont("basic font"), 64);
	this->_title->setPosition(150.f, 100.f);

	this->_score = new sf::Text("Your score: " + std::to_string(_stats.score), _data->assets.GetFont("basic font"), 32);
	this->_score->setPosition(180.f, 180.f);

	this->_subtitle =new sf::Text("Press SPACE to restart", _data->assets.GetFont("basic font"), 46);
	this->_subtitle->setPosition(80.f, 350.f);
}

void EndGameState::PollEvents()
{
	sf::Event ev;
	while (_data->window.pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed)
		{
			_data->window.close();
		}

		if (ev.key.code == sf::Keyboard::Space)
		{
			_data->machine.AddState(StateRef(new GameState(_data)), true);
		}
	}
}

void EndGameState::update(float deltaTime)
{

}

void EndGameState::render() const
{
	_data->window.clear();

	_data->window.draw(*_title);
	_data->window.draw(*_subtitle);
	_data->window.draw(*_score);

	_data->window.display();
}
