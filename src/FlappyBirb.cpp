// This file is to test the game engine

#include "Engine.h"
#include "Squawk/Log.h"
#include "Branch/Branch2D/Sprite2D.h"
#include "Branch/Branch2D/Rigidbody2D.h"
#include "Branch/Branch2D/Text2D.h"
#include "Branch/Branch2D/Rectangle2D.h"
#include "Structs/Texture.h"
#include "Structs/Font.h"

#include "Player.h"
#include "PlayerScore.h"
#include "Background.h"
#include "CatGod.h"

using namespace std;
using namespace Perch;
using namespace Squawk;

const string WINDOW_NAME = "Flappy Birb";
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

void OnRootCreate(Engine* engine, Branch* Root);

int main(int argc, char* args[])
{
	shared_ptr<EngineConfig> engineConfig = shared_ptr<EngineConfig>(new EngineConfig());

	engineConfig->windowName = WINDOW_NAME;
	engineConfig->windowSize = Vector2i(SCREEN_WIDTH, SCREEN_HEIGHT);
	engineConfig->clearColor = Color::White();
	engineConfig->showDebug = true;

	unique_ptr<Engine> engine(new Engine(engineConfig));
	engine->SetOnRootCreate(&OnRootCreate);
	engine->Start();

	return 0;
}

void OnRootCreate(Engine* engine, Branch* root)
{

	Background* background = new Background(engine);
	background->Create();

	root->AttachChild(unique_ptr<Branch>(background->GetRoot()));

	CatGod* catGod = new CatGod(engine);
	catGod->Create();

	root->AttachChild(unique_ptr<Branch>(catGod->GetRoot()));

	Player* player = new Player(engine);
	player->Create();

	root->AttachChild(unique_ptr<Branch>(player->GetRoot()));

	PlayerScore* score = new PlayerScore(engine);
	score->Create();

	root->AttachChild(unique_ptr<Branch>(score->GetRoot()));

	player->SetPlayerScore(score);

}
