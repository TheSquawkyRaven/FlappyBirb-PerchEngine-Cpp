#pragma once

#include "Engine.h"
#include "Branch/Script.h"

#include "GameManager.h"

#include "Structs/Color.h"
#include "Branch/Branch2D/Rectangle2D.h"
#include "Branch/Branch2D/Text2D.h"

#include "Player/Player.h"
#include "Background.h"
#include "Cat/CatGod.h"

class Game : public Perch::Script
{

private:

	Perch::Branch* root = nullptr;

	Background* background = nullptr;
	CatGod* catGod = nullptr;
	Player* player = nullptr;

private:

	GameManager* gameManager = nullptr;

	int score = 0;

public:

	inline void SetGameManager(GameManager* gameManager) { this->gameManager = gameManager; }
	inline int GetScore() const { return score; }

public:

	Game(Perch::Engine* engine) : Script(engine) {}
	inline Perch::Branch* GetRoot() { return root; }
	void Create();

	void AddScore();

	void CreateProps();

	void ResetGame();
	void StartGame();
	void EndGame();

};

