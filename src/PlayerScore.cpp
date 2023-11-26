#include "PlayerScore.h"

#include "Log.h"


using namespace Perch;
using namespace std;
using namespace Squawk;


void PlayerScore::AddScore()
{
	Score++;
	Text->SetText(to_string(Score));
}

void PlayerScore::Create(Engine* engine)
{
	shared_ptr<Font> lameFont = Font::Create(engine, "./fonts/LameFont.ttf", 64);
	if (lameFont == NULL)
	{
		return;
	}
	Text = shared_ptr<Text2D>(new Text2D(engine));
	Text->Position = Vector2(20, 20);
	Text->SetFont(lameFont);
	Text->SetText(to_string(Score));
}


