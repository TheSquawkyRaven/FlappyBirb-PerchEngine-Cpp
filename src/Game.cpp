#include "Game.h"

#include "Squawk/Log.h"

#include <memory>

using namespace Perch;
using namespace std;
using namespace Squawk;


void Game::Create()
{
	root = new Branch(engine);
	root->AttachScriptu(this);

	engine->timeScale = 0.0f;

	ResetGame();
}

void Game::AddScore()
{
	score++;
	gameManager->hud->UpdateScore(score);
}

void Game::CreateProps()
{
	if (background != nullptr)
	{
		background->GetRoot()->Destroy();
		catGod->GetRoot()->Destroy();
		player->GetRoot()->Destroy();
	}

	background = new Background(engine);
	background->Create();
	root->AttachChildu(background->GetRoot());

	catGod = new CatGod(engine);
	catGod->Create();
	root->AttachChildu(catGod->GetRoot());

	player = new Player(engine);
	player->SetGame(this);
	player->Create();
	root->AttachChildu(player->GetRoot());
}

void Game::ResetGame()
{
	CreateProps();
	score = 0;
	engine->timeScale = 0.0f;
}

void Game::StartGame()
{
	engine->timeScale = 1.0f;
}

void Game::EndGame()
{
	engine->timeScale = 0.0f;

	// TODO pop in score board, then only end game
	gameManager->EndGame(score);
}
