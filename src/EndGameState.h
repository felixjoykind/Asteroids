#pragma once

#include "GameState.h"

struct Statistic
{
	unsigned int score;
};

class EndGameState : public State
{
private:
	GameDataRef _data;
	Statistic _stats;

	sf::Text* _title;
	sf::Text* _score;
	sf::Text* _subtitle;

public:
	EndGameState(GameDataRef data, Statistic stats);
	~EndGameState();

	void Init() override;

	void PollEvents();

	void update(float deltaTime) override;
	void render() const override;

};

