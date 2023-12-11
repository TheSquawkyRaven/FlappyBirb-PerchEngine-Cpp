#include "HUD.h"

#include "Squawk/Log.h"

using namespace Perch;
using namespace std;
using namespace Squawk;


void HUD::Create()
{
	root = new Branch2D(engine);
	root->AttachScriptu(this);

	root->SetDrawLayer(100);

	button = new Button2D(engine);
	root->AttachChildu(button);
	button->position = Vector2(100, 100);
	button->scale = Vector2(3, 3);

	shared_ptr<Texture> buttonTexture = Texture::Create(engine, "./images/button-Sheet.png");

	buttonSprite = new Sprite2D(engine);
	buttonSprite->SetTexture(buttonTexture);
	buttonSprite->SetSpriteColumns(3);
	button->AttachChildu(buttonSprite);
	button->LinkSprite(buttonSprite);

}
