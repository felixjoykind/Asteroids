#pragma once
class State
{
public:
	// Init
	virtual void Init() = 0;

	// Polling events
	virtual void PollEvents() = 0;

	// Functions
	virtual void update(float deltaTine) = 0;
	virtual void render() const = 0;

	virtual void Pause() { }
	virtual void Resume() { }
};

