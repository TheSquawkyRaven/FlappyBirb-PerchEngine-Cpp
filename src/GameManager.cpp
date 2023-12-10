#include "GameManager.h"

#include "Squawk/Log.h"

#include "Game.h"

using namespace Perch;
using namespace std;
using namespace Squawk;


void GameManager::Create()
{
	root = new Branch(engine);
	root->AttachScriptu(this);

	hud = new HUD(engine);
	hud->Create();
	root->AttachChildu(hud->GetRoot());
}

void GameManager::Update()
{
	if (gameState != MainMenu)
	{
		return;
	}

	if (engine->GetInput()->GetKeyDown(SDL_SCANCODE_SPACE))
	{
		StartGame();
	}
}

void GameManager::StartGame()
{
	gameState = GameState::InGame;

	currentGame = new Game(engine);
	currentGame->SetGameManager(this);
	currentGame->Create();
	root->AttachChildu(currentGame->GetRoot());
}

void GameManager::EndGame(int score)
{
	gameState = GameState::MainMenu;

	currentGame->GetRoot()->Destroy();
	currentGame = nullptr;
}
