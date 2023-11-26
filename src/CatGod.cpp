#include "CatGod.h"

#include "Log.h"


using namespace Perch;
using namespace std;
using namespace Squawk;

void CatGod::Create(Engine* engine)
{
	shared_ptr<Branch> root(new Branch(engine));
	Root = root;

	SpawnX = engine->GetMainWindowSize().X + 128.0f;

	Root->AttachScript(GetScript());
	

}

void CatGod::Spawn(Engine* engine)
{
	float gap = engine->GetRandom()->RandomFloat(MinGap, MaxGap);

	CatCouple* catCouple = new CatCouple();
	catCouple->Create(engine);
	catCouple->GetRoot()->Position.X = SpawnX;

	CatCouples.push_back(catCouple);

	Root->AttachChild(catCouple->GetRoot());
}

void CatGod::Update(Engine* engine)
{
	// Move cats
	for (int i = 0; i < CatCouples.size(); i++)
	{
		shared_ptr<Branch2D> catRoot = CatCouples[i]->GetRoot();
		catRoot->Position = catRoot->Position + Vector2(-Speed * engine->DeltaTime, 0);

		if (catRoot->Position.X < -100.0f)
		{
			CatCouples.erase(CatCouples.begin() + i);
			catRoot->Destroy();
			i--;
		}
	}

	SpawnRateC += engine->DeltaTime;
	if (SpawnRateC > SpawnRate)
	{
		Spawn(engine);
		SpawnRateC = 0.0f;
	}
}
