#include "Cat.h"

#include "Log.h"

#include "PlayerCollider.h"


using namespace Perch;
using namespace std;
using namespace Squawk;

void Cat::Create(Engine* engine)
{
	shared_ptr<Texture> birbTexture = Texture::Create(engine, "./images/cat.png");
	shared_ptr<Sprite2D> sprite(new Sprite2D(engine));
	sprite->SetTexture(birbTexture);
	sprite->Scale = Vector2(6, 6);
	sprite->PositionPivot = Vector2(0.5f, 0.0f);
	sprite->RotatePivot = Vector2(0.5f, 0.0f);
	Sprite = sprite;

	shared_ptr<Collider2D> collider(new Collider2D(engine));
	Collider = collider;
	/*
	float l, t, r, b;
	collider->GetAABB(l, t, r, b);
	Log::Printf("%f, %f, %f, %f", l, t, r, b);*/

	sprite->AttachChild(collider);

	sprite->AttachScript(GetScript());
}

void Cat::SetIsTop(Engine* engine, bool isTop)
{
	if (isTop)
	{
		Sprite->Angle = 180.0f;
		Collider->Rect = Rect2(-96/2, -384+64, 16, 48);
	}
	else
	{
		Sprite->Angle = 0.0f;
		Collider->Rect = Rect2(-96/2, 32, 16, 48);
	}

}

void Cat::Update(Perch::Engine* engine)
{

}

void Cat::Draw(Perch::Engine* engine, SDL_Renderer* renderer)
{
}
