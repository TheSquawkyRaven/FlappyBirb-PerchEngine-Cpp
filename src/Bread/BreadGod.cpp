#include "BreadGod.h"

#include "Squawk/Log.h"


using namespace Perch;
using namespace std;
using namespace Squawk;

void BreadGod::Create(CatGod* catGod)
{
	root = new Branch(engine);
	root->AttachScript(unique_ptr<BreadGod>(this));

	this->catGod = catGod;
	// Bind this using lambda
	catGod->SetCatCoupleCreated([this](CatCouple* catCouple)
	{
		OnCatCoupleCreated(catCouple);
	});
}

void BreadGod::OnCatCoupleCreated(CatCouple* catCouple)
{
	Bread* bread = new Bread(engine);
	bread->Create();
	float x = spawnOffset;
	float y = engine->GetRandom()->RandomFloat(minY, maxY);
	Vector2 pos = Vector2(x, y);
	bread->GetRoot()->position = pos;

	catCouple->GetRoot()->AttachChildu(bread->GetRoot());
}
