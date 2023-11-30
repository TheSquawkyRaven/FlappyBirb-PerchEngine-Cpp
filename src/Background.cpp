#include "Background.h"

#include "Squawk/Log.h"


using namespace Perch;
using namespace std;
using namespace Squawk;


void Background::Create()
{
	rectangle = new Rectangle2D(engine);
	rectangle->rect = Rect2(0, 0, 1280, 720);
	rectangle->AttachScript(unique_ptr<Background>(this));
}

void Background::Update()
{
	time += engine->GetDeltaTime();

	if (time > 1.0f)
	{
		Color color = rectangle->color;
		color.r = colorFlip ? 255 : 230;
		color.g = colorFlip ? 230 : 255;
		color.b = colorFlip ? 230 : 230;
		colorFlip = !colorFlip;
		time = 0.0f;
		rectangle->color = color;
	}

}
