#include "CatCouple.h"

#include "Squawk/Log.h"


using namespace Perch;
using namespace std;
using namespace Squawk;


void CatCouple::Create()
{
	root = new Branch2D(engine);
	root->position.y = engine->GetMainWindowSize().y / 2;
	root->AttachScript(unique_ptr<CatCouple>(this));

	float offset = engine->GetRandom()->RandomFloat(minOffset, maxOffset);
	float gap = engine->GetRandom()->RandomFloat(minGap, maxGap);

	topCat = new Cat(engine);
	topCat->Create();
	topCat->SetIsTop(true);
	topCat->GetRoot()->position.y -= -offset / 2 + gap / 2;

	bottomCat = new Cat(engine);
	bottomCat->Create();
	bottomCat->SetIsTop(false);
	bottomCat->GetRoot()->position.y += offset / 2 + gap / 2;

	pointDetector = new Collider2D(engine);
	pointDetector->rect = Rect2(2, -(-offset / 2 + gap / 2), 4, gap);
	pointDetector->SetName("Point");
	root->AttachChildu(pointDetector);

	root->AttachChildu(topCat->GetRoot());
	root->AttachChildu(bottomCat->GetRoot());
}
