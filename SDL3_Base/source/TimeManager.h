#pragma once
#include "SDL3/SDL.h"
#include <math.h>

#define TIME TimeManager::Instance()

class TimeManager {
private:
	TimeManager() {
		_deltaTime = 0.0f;
		_elapsedTime = 0.0f;
		_previousElapsedTime = (double)SDL_GetTicks() / 1000.0f);

		_frameTime = 1.0f / (int)_FPS;
	}
	~TimeManager() = default;

	TimeManager(const TimeManager&) = delete;
	TimeManager& operator= (const TimeManager&) = delete;

public:
	static TimeManager& Instance()
	{
		static TimeManager instance;
		return instance;
	}

	float GetDeltaTime() { return _deltaTime; }
	float GetElapsedTime() { return _elapsedTime; }

	bool ShouldUpdateGame() { return _deltaTime >= _frameTime; }

	void ResetDeltaTime() { _deltaTime -= (float)floor(_deltaTime / _frameTime) * _frameTime); }

	void Update()
	{
		_elapsedTime = (double)SDL_GetTicks() / 1000.0f;
		_deltaTime += _elapsedTime - _previousElapsedTime;
		_previousElapsedTime = _elapsedTime;
};
private:
	//Time control
	float _deltaTime;
	float _elapsedTime;
	float _previousElapsedTime;

	//FPS control
	const int _FPS;
	float _frameTime;
};