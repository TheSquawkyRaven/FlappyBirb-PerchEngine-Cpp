#include "PlayerScore.h"

#include "Squawk/Log.h"


using namespace Perch;
using namespace std;
using namespace Squawk;


void PlayerScore::Create()
{
	shared_ptr<Font> lameFont = Font::Create(engine, "./fonts/LameFont.ttf");
	if (lameFont == nullptr)
	{
		return;
	}
	text = new Text2D(engine);
	text->fontSize = 64;
	text->position = Vector2(20, 20);
	text->SetFont(lameFont);
	text->SetText(to_string(score));
}

void PlayerScore::AddScore()
{
	score++;
	text->SetText(to_string(score));
}
