#include "Player.h"

#include "Log.h"


using namespace Perch;
using namespace std;
using namespace Squawk;

void Player::Create(Engine* engine)
{
	shared_ptr<Rigidbody2D> rigidbody = engine->CreateBranch<Rigidbody2D>();
	rigidbody->Gravity = 9.8f;
	rigidbody->AttachScript(GetScript());
	Rigidbody = rigidbody;

	shared_ptr<Texture> birbTexture = Texture::Create(engine, "./images/birb-Sheet.png");
	shared_ptr<Sprite2D> birbSprite = engine->CreateBranch<Sprite2D>();

	birbSprite->SetTexture(birbTexture);
	birbSprite->Scale = Vector2(8, 8);
	birbSprite->SetSpriteColumns(2);

	Rigidbody->AttachChild(birbSprite);

}

void Player::Update(Engine* engine)
{
	if (engine->GetInput()->GetKeyDown(SDL_SCANCODE_SPACE))
	{
		Rigidbody->Velocity = Vector2(0, -10.0f);
		//Rigidbody->AddForce(Vector2(0, -10.0f));
		Log::Print("Space Pressed");
		Log::Printf("DeltaTime: %f", engine->DeltaTime);
	}

}
