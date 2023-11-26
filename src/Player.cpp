#include "Player.h"

#include "Log.h"


using namespace Perch;
using namespace std;
using namespace Squawk;

void Player::Create(Engine* engine)
{
	shared_ptr<Rigidbody2D> rigidbody(new Rigidbody2D(engine));
	rigidbody->Gravity = 15.0f;
	rigidbody->AttachScript(GetScript());
	Rigidbody = rigidbody;

	shared_ptr<Texture> birbTexture = Texture::Create(engine, "./images/birb-Sheet.png");
	shared_ptr<Sprite2D> sprite(new Sprite2D(engine));
	sprite->SetTexture(birbTexture);
	sprite->Scale = Vector2(6, 6);
	sprite->SetSpriteColumns(2);
	sprite->PositionPivot = Vector2(0.5f, 0.5f);
	Sprite = sprite;

	Vector2 playerStartPosition = engine->GetMainWindowSize();
	playerStartPosition.X /= 3;
	playerStartPosition.Y /= 2;
	Rigidbody->Position = playerStartPosition;

	shared_ptr<Collider2D> collider(new Collider2D(engine));
	collider->Rect = Rect2(-28, -28, 10, 10);
	Collider = collider;

	PlayerCollider* playerCollider = new PlayerCollider();
	Collider->AttachScript(playerCollider->GetScript());
	PCollider = playerCollider;

	sprite->AttachChild(collider);
	Rigidbody->AttachChild(sprite);
}

void Player::SetPlayerScore(PlayerScore* playerScore)
{
	Score = playerScore;
	PCollider->SetPlayerScore(playerScore);
}

void Player::Update(Engine* engine)
{
	if (Rigidbody->Velocity.Y > 0.0f)
	{
		Sprite->SetSpriteIndex(0);
	}
	if (engine->GetInput()->GetKeyDown(SDL_SCANCODE_SPACE))
	{
		Sprite->SetSpriteIndex(1);
		Rigidbody->Velocity = Vector2(0, -5.0f);
	}

	t += engine->DeltaTime;
	if (t > 1.0f)
	{
		Score->AddScore();
		t = 0.0f;
	}


	if (Rigidbody->Position.Y < 0.0f || Rigidbody->Position.Y > 720.0f)
	{
		delete engine;
	}

}
