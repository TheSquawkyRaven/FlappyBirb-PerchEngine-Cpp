#include "CatGod.h"

#include "Squawk/Log.h"


using namespace Perch;
using namespace std;
using namespace Squawk;

void CatGod::Create()
{
	spawnX = engine->GetMainWindowSize().x + 128.0f;

	root = new Branch(engine);
	root->AttachScript(unique_ptr<CatGod>(this));
	
}

void CatGod::Update()
{
	// Move cats
	for (int i = 0; i < catCouples.size(); i++)
	{
		Branch2D* catRoot = catCouples[i]->GetRoot();
		catRoot->position = catRoot->position + Vector2(-speed * engine->GetDeltaTime(), 0);

		if (catRoot->position.x < -100.0f)
		{
			catCouples.erase(catCouples.begin() + i);
			catRoot->Destroy();
			i--;
		}
	}

	spawnRateC += engine->GetDeltaTime();
	if (spawnRateC > spawnRate)
	{
		Spawn();
		spawnRateC = 0.0f;
	}
}

void CatGod::Spawn()
{
	float gap = engine->GetRandom()->RandomFloat(minGap, maxGap);

	CatCouple* catCouple = new CatCouple(engine);
	catCouple->Create();
	catCouple->GetRoot()->position.x = spawnX;

	catCouples.push_back(catCouple);

	root->AttachChild(unique_ptr<Branch>(catCouple->GetRoot()));
}
