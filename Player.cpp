#include "Player.h"

#include "Log.h"


using namespace Perch;
using namespace std;
using namespace Squawk;

void Player::Create(Engine* engine)
{
	shared_ptr<Rigidbody2D> rigidbody = engine->CreateBranch<Rigidbody2D>();
	rigidbody->AttachScript(GetScript());
	Root = rigidbody;

	shared_ptr<Texture> birbTexture = Texture::Create(engine, "./images/birb-Sheet.png");
	shared_ptr<Sprite2D> birbSprite = engine->CreateBranch<Sprite2D>();

	birbSprite->SetTexture(birbTexture);
	birbSprite->Scale = Vector2(8, 8);
	birbSprite->SetSpriteColumns(2);

	Root->AttachChild(birbSprite);

}

void Player::Update(Engine* engine)
{
	if (engine->GetInput()->GetKey(SDL_SCANCODE_SPACE))
	{
		Log::Print("Space Pressed");
	}

}
