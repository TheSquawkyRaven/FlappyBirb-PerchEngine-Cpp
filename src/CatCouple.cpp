#include "CatCouple.h"

#include "Log.h"


using namespace Perch;
using namespace std;
using namespace Squawk;

void CatCouple::Create(Engine* engine)
{
	shared_ptr<Branch2D> root(new Branch2D(engine));
	Root = root;

	root->Position.Y = engine->GetMainWindowSize().Y / 2;

	Root->AttachScript(GetScript());
	Spawn(engine);
}

void CatCouple::Spawn(Engine* engine)
{
	float offset = engine->GetRandom()->RandomFloat(MinOffset, MaxOffset);
	float gap = engine->GetRandom()->RandomFloat(MinGap, MaxGap);

	Cat* topCat = new Cat();
	topCat->Create(engine);
	topCat->SetIsTop(engine, true);
	topCat->GetRoot()->Position.Y -= -offset / 2 + gap / 2;

	Cat* bottomCat = new Cat();
	bottomCat->Create(engine);
	bottomCat->SetIsTop(engine, false);
	bottomCat->GetRoot()->Position.Y += offset / 2 + gap / 2;

	TopCat = topCat;
	BottomCat = bottomCat;

	Root->AttachChild(topCat->GetRoot());
	Root->AttachChild(bottomCat->GetRoot());
}

void CatCouple::Update(Engine* engine)
{
}
