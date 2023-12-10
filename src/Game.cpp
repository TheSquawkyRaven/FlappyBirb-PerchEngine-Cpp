#include "Game.h"

#include "Squawk/Log.h"

#include "Player/Player.h"
#include "Background.h"
#include "Cat/CatGod.h"

#include <memory>

using namespace Perch;
using namespace std;
using namespace Squawk;


void Game::Create()
{
	root = new Branch(engine);
	root->AttachScriptu(this);

	overlay = new Rectangle2D(engine);
	overlay->rect = engine->GetMainWindowRect();
	overlay->color = Color(255, 255, 255, 69);
	root->AttachChildu(overlay);

	shared_ptr<Font> lameFont = Font::Create(engine, "./fonts/LameFont.ttf");
	if (lameFont == nullptr)
	{
		return;
	}

	overlayText = new Text2D(engine);
	overlayText->SetFont(lameFont);
	overlayText->color = Color::Black();
	overlayText->position = engine->GetMainWindowSize() / 2;
	overlayText->positionPivot = Vector2(0.5f, 0.5f);
	overlayText->SetText("Hit 'Space' to flap!");
	overlay->AttachChildu(overlayText);

	scoreText = new Text2D(engine);
	scoreText->fontSize = 64;
	scoreText->position = Vector2(20, 20);
	scoreText->color = Color::Black();
	scoreText->SetDrawLayer(10);
	scoreText->SetFont(lameFont);
	scoreText->SetText(to_string(score));
	root->AttachChildu(scoreText);

	engine->timeScale = 0.0f;
}

void Game::Update()
{
	if (!waitForInput)
	{
		return;
	}

	if (engine->GetInput()->GetKeyDown(SDL_SCANCODE_SPACE))
	{
		StartGame();
	}
}

void Game::AddScore()
{
	score++;
	scoreText->SetText(to_string(score));
}

void Game::StartGame()
{
	waitForInput = false;
	engine->timeScale = 1.0f;
	overlay->SetActive(false);

	Background* background = new Background(engine);
	background->Create();
	root->AttachChildu(background->GetRoot());

	CatGod* catGod = new CatGod(engine);
	catGod->Create();
	root->AttachChildu(catGod->GetRoot());

	Player* player = new Player(engine);
	player->SetGame(this);
	player->Create();
	root->AttachChildu(player->GetRoot());

}

void Game::EndGame()
{
	engine->timeScale = 0.0f;

	Log::Printf("\n-----\nGame Ended\n-----\n Score: %d\n-----", score);

	// TODO pop in score board, then only end game
	//gameManager->EndGame(score);
}
