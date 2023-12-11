#pragma once

#include "Engine.h"
#include "Branch/Script.h"

#include "Structs/Color.h"

#include "Branch/Branch2D/Text2D.h"
#include "Branch/Branch2D/Button2D.h"

class GameManager;

class HUD : public Perch::Script
{

private:

	Perch::Branch2D* root = nullptr;

	Perch::Branch2D* gameHUD = nullptr;
	Perch::Text2D* scoreText = nullptr;

	Perch::Branch2D* menuHUD = nullptr;
	Perch::Text2D* tutorialText = nullptr;

	Perch::Sprite2D* scoreboard = nullptr;
	Perch::Button2D* restartButton = nullptr;
	Perch::Sprite2D* restartButtonSprite = nullptr;
	Perch::Text2D* restartButtonText = nullptr;
	Perch::Text2D* gameOverText = nullptr;
	Perch::Text2D* gainedScoreText = nullptr;
	Perch::Text2D* highScoreText = nullptr;

private:

	GameManager* gameManager = nullptr;

public:

	inline void SetGameManager(GameManager* gameManager) { this->gameManager = gameManager; }

public:

	HUD(Perch::Engine* engine) : Script(engine) {}
	inline Perch::Branch2D* GetRoot() { return root; }
	void Create();

	void UpdateScore(int score);

	void RestartGame();

	void GameStarted();
	void GameEnded(int score);


};

