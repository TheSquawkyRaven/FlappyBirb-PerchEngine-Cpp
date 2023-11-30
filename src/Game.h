#pragma once

#include "Engine.h"
#include "Branch/Script.h"

#include "GameManager.h"

#include "Structs/Color.h"
#include "Branch/Branch2D/Rectangle2D.h"
#include "Branch/Branch2D/Text2D.h"

class Game : public Perch::Script
{

private:

	Perch::Branch* root = nullptr;
	Perch::Rectangle2D* overlay = nullptr;
	Perch::Text2D* overlayText = nullptr;

	Perch::Text2D* scoreText = nullptr;

private:

	GameManager* gameManager = nullptr;
	bool waitForInput = true;

	int score = 0;

public:

	inline void SetGameManager(GameManager* gameManager) { this->gameManager = gameManager; }
	inline int GetScore() const { return score; }

public:

	Game(Perch::Engine* engine) : Script(engine) {}
	inline Perch::Branch* GetRoot() { return root; }
	void Create();

	virtual void Update() override;

	void AddScore();

	void StartGame();
	void EndGame();

};

