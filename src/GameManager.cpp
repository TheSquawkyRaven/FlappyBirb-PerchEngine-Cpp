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
	hud->SetGameManager(this);
	hud->Create();
	root->AttachChildu(hud->GetRoot());

	currentGame = new Game(engine);
	currentGame->SetGameManager(this);
	currentGame->Create();
	root->AttachChildu(currentGame->GetRoot());
}

void GameManager::Update()
{
	if (gameState != GameState::Starting)
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
	gameState = GameState::Game;
	currentGame->StartGame();
	hud->GameStarted();
}

void GameManager::EndGame(int score)
{
	gameState = GameState::GameOver;
	hud->GameEnded(score);

	//currentGame->GetRoot()->Destroy();
	//currentGame = nullptr;
}

void GameManager::RestartGame()
{
	gameState = GameState::Starting;
	currentGame->ResetGame();
}
