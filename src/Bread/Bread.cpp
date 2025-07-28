#include "Bread.h"

#include "Squawk/Log.h"


using namespace Perch;
using namespace std;
using namespace Squawk;


void Bread::Create()
{
	static shared_ptr<Texture> breadTexture = Texture::Create(engine, "./images/bread.png");

	sprite = new Sprite2D(engine);
	sprite->SetTexture(breadTexture);
	sprite->scale = Vector2(6, 6);
	sprite->positionPivot = Vector2(0.5f, 0.0f);
	sprite->rotatePivot = Vector2(0.5f, 0.0f);

	collider = new Collider2D(engine);
	collider->SetName("Bread");
	collider->rect = Rect2(-4, -4, 8, 8);

	sprite->AttachChild(unique_ptr<Branch>(collider));

	sprite->AttachScript(unique_ptr<Bread>(this));
}
