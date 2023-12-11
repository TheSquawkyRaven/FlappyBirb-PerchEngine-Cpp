#pragma once

#include "Engine.h"
#include "Branch/Script.h"

#include "Structs/Color.h"

#include "Branch/Branch2D/Rectangle2D.h"
#include "HUD.h"

class Game;

class GameManager : public Perch::Script
{

public:
	enum class GameState
	{
		Starting,
		Game,
		GameOver,
	};

private:

	Perch::Branch* root = nullptr;

private:

	GameState gameState = GameState::Starting;
	Game* currentGame = nullptr;

public:

	HUD* hud = nullptr;

public:

	GameManager(Perch::Engine* engine) : Script(engine) {}
	inline Perch::Branch* GetRoot() { return root; }
	void Create();

	virtual void Update() override;

	void StartGame();
	void EndGame(int score);
	void RestartGame();

};

