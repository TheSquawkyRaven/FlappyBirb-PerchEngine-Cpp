#include "Cat.h"

#include "Squawk/Log.h"


using namespace Perch;
using namespace std;
using namespace Squawk;


void Cat::Create()
{
	static shared_ptr<Texture> birbTexture = Texture::Create(engine, "./images/cat.png");

	sprite = new Sprite2D(engine);
	sprite->SetTexture(birbTexture);
	sprite->scale = Vector2(6, 6);
	sprite->positionPivot = Vector2(0.5f, 0.0f);
	sprite->rotatePivot = Vector2(0.5f, 0.0f);

	collider = new Collider2D(engine);

	sprite->AttachChild(unique_ptr<Branch>(collider));

	sprite->AttachScript(unique_ptr<Cat>(this));
}

void Cat::SetIsTop(bool isTop)
{
	if (isTop)
	{
		sprite->angle = 180.0f;
		collider->rect = Rect2(-8, -68, 16, 64);
	}
	else
	{
		sprite->angle = 0.0f;
		collider->rect = Rect2(-8, 4, 16, 64);
	}
}
