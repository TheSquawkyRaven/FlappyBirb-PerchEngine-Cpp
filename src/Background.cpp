#include "Background.h"

#include "Log.h"


using namespace Perch;
using namespace std;
using namespace Squawk;

void Background::Create(Engine* engine)
{
	Rect = shared_ptr<Rectangle2D>(new Rectangle2D(engine));
	Rect->SetRect2(Rect2(0, 0, 1280, 720));
	Rect->AttachScript(GetScript());
}

void Background::Update(Engine* engine)
{

	t += engine->DeltaTime;


	if (t > 1.0f)
	{
		Color color = Rect->GetColor();
		color.R = yes ? 255 : 230;
		color.G = yes ? 230 : 255;
		color.B = yes ? 230 : 230;
		yes = !yes;
		t = 0.0f;
		Rect->SetColor(color);
	}

}
