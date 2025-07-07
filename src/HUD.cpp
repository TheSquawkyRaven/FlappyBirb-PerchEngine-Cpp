#include "HUD.h"

#include "Squawk/Log.h"

#include "GameManager.h"

using namespace Perch;
using namespace std;
using namespace Squawk;


void HUD::Create()
{
	root = new Branch2D(engine);
	root->AttachScriptu(this);

	root->SetDrawLayer(100);

	// Game HUD
	gameHUD = new Branch2D(engine);
	gameHUD->SetDrawLayer(101);
	root->AttachChildu(gameHUD);

	shared_ptr<Font> lameFont = Font::Create(engine, "./fonts/LameFont.ttf");
	scoreText = new Text2D(engine);
	scoreText->fontSize = 64;
	scoreText->position = Vector2(20, 20);
	scoreText->color = Color::Black();
	scoreText->SetDrawLayer(10);
	scoreText->SetFont(lameFont);
	gameHUD->AttachChildu(scoreText);

	// Menu HUD
	menuHUD = new Branch2D(engine);
	menuHUD->SetDrawLayer(102);
	root->AttachChildu(menuHUD);

	tutorialText = new Text2D(engine);
	tutorialText->SetFont(lameFont);
	tutorialText->fontSize = 48;
	tutorialText->color = Color::Black();
	tutorialText->position = engine->GetMainWindowSize() / 2;
	tutorialText->positionPivot = Vector2::Half();
	tutorialText->SetText("Press 'Space' to Flap");
	menuHUD->AttachChildu(tutorialText);

	// Scoreboard
	shared_ptr<Texture> menuBoard = Texture::Create(engine, "./images/menu.png");
	scoreboard = new Sprite2D(engine);
	scoreboard->SetTexture(menuBoard);
	scoreboard->position = Vector2(400, 200);
	scoreboard->scale = Vector2(3, 3);
	menuHUD->AttachChildu(scoreboard);

	shared_ptr<Texture> buttonTexture = Texture::Create(engine, "./images/button-Sheet.png");
	restartButton = new Button2D(engine);
	restartButton->position = Vector2(32, 80) * scoreboard->scale;
	scoreboard->AttachChildu(restartButton);

	restartButtonSprite = new Sprite2D(engine);
	restartButtonSprite->SetTexture(buttonTexture);
	restartButtonSprite->SetSpriteColumns(3);
	restartButton->AttachChildu(restartButtonSprite);
	restartButton->LinkSprite(restartButtonSprite);

	restartButtonText = new Text2D(engine);
	restartButtonText->position = restartButtonSprite->GetGlobalSize() / 2;
	restartButtonText->positionPivot = Vector2::Half();
	restartButtonText->fontSize = 32;
	restartButtonText->color = Color::Black();
	restartButtonText->SetFont(lameFont);
	restartButtonText->SetText("CONTINUE");
	restartButton->AttachChildu(restartButtonText);

	gameOverText = new Text2D(engine);
	gameOverText->position = Vector2(64, 28) * scoreboard->scale;
	gameOverText->positionPivot = Vector2::Half();
	gameOverText->fontSize = 48;
	gameOverText->color = Color::White();
	gameOverText->SetFont(lameFont);
	gameOverText->SetText("GAME OVER");
	scoreboard->AttachChildu(gameOverText);

	gainedScoreText = new Text2D(engine);
	gainedScoreText->position = Vector2(64, 44) * scoreboard->scale;
	gainedScoreText->positionPivot = Vector2::Half();
	gainedScoreText->fontSize = 32;
	gainedScoreText->color = Color::Lime();
	gainedScoreText->SetFont(lameFont);
	gainedScoreText->SetText("Score: ");
	scoreboard->AttachChildu(gainedScoreText);

	highScoreText = new Text2D(engine);
	highScoreText->position = Vector2(64, 58) * scoreboard->scale;
	highScoreText->positionPivot = Vector2::Half();
	highScoreText->fontSize = 24;
	highScoreText->color = Color::White();
	highScoreText->SetFont(lameFont);
	highScoreText->SetText("High Score: TODO");
	scoreboard->AttachChildu(highScoreText);

	restartButton->SetOnClick([this]() { this->RestartGame(); });

	scoreboard->SetActive(false);

}

void HUD::UpdateScore(int score)
{
	if (score == 0)
	{
		scoreText->SetText("");
		return;
	}
	scoreText->SetText(to_string(score));
}

void HUD::RestartGame()
{
	gameManager->RestartGame();
	menuHUD->SetActive(true);
	tutorialText->SetActive(true);
	scoreboard->SetActive(false);
}

void HUD::GameStarted()
{
	menuHUD->SetActive(false);
	tutorialText->SetActive(false);
	scoreboard->SetActive(false);
}

void HUD::GameEnded(int score)
{
	menuHUD->SetActive(true);
	scoreboard->SetActive(true);
	gainedScoreText->SetText("Score: " + to_string(score));
}
