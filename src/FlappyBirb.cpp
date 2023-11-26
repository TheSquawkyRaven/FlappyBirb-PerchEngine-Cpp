// This file is to test the game engine

#include "Engine.h"
#include "Log.h"
#include "Branch/Branch2D/Sprite2D.h"
#include "Branch/Branch2D/Rigidbody2D.h"
#include "Branch/Branch2D/Text2D.h"
#include "Branch/Branch2D/Rectangle2D.h"
#include "Branch/Branch2D/BorderedRectangle2D.h"
#include "Branch/Branch2D/Line2D.h"
#include "Branch/Branch2D/Point2D.h"
#include "Branch/Branch2D/Viewport2D.h"
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

void OnRootCreate(Engine* Engine, Branch* Root);

int main(int argc, char* args[])
{
	shared_ptr<EngineConfig> engineConfig = shared_ptr<EngineConfig>(new EngineConfig());

	engineConfig->WindowName = WINDOW_NAME;
	engineConfig->WindowSize = Vector2i(SCREEN_WIDTH, SCREEN_HEIGHT);
	engineConfig->ClearColor = Color::White();

	Engine* engine = new Engine(engineConfig);

	engine->SetOnRootCreate(&OnRootCreate);
	engine->Start();

	delete engine;

	return 0;
}

void OnRootCreate(Engine* Engine, Branch* Root)
{

	Background* background = new Background();
	background->Create(Engine);

	Root->AttachChild(background->GetRoot());

	CatGod* catGod = new CatGod();
	catGod->Create(Engine);

	Root->AttachChild(catGod->GetRoot());

	Player* player = new Player();
	player->Create(Engine);

	Root->AttachChild(player->GetRoot());

	PlayerScore* score = new PlayerScore();
	score->Create(Engine);

	Root->AttachChild(score->GetRoot());

	player->SetPlayerScore(score);

}
