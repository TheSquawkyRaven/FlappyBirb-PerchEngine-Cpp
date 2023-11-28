#include "Player.h"

#include "Squawk/Log.h"


using namespace Perch;
using namespace std;
using namespace Squawk;


void Player::Create()
{
	rigidbody = new Rigidbody2D(engine);
	rigidbody->gravity = 15.0f;
	rigidbody->AttachScript(unique_ptr<Player>(this));

	shared_ptr<Texture> birbTexture = Texture::Create(engine, "./images/birb-Sheet.png");
	sprite = new Sprite2D(engine);
	sprite->SetTexture(birbTexture);
	sprite->scale = Vector2(6, 6);
	sprite->SetSpriteColumns(2);
	sprite->positionPivot = Vector2(0.5f, 0.5f);

	Vector2 playerStartPosition = engine->GetMainWindowSize();
	playerStartPosition.x /= 3;
	playerStartPosition.y /= 2;
	rigidbody->position = playerStartPosition;

	collider = new Collider2D(engine);
	collider->rect = Rect2(-28, -28, 10, 10);

	playerCollider = new PlayerCollider(engine);
	collider->AttachScript(unique_ptr<PlayerCollider>(playerCollider));

	sprite->AttachChild(unique_ptr<Branch>(collider));
	rigidbody->AttachChild(unique_ptr<Branch>(sprite));
}

void Player::Update()
{
	if (rigidbody->velocity.y > 0.0f)
	{
		sprite->SetSpriteIndex(0);
	}
	if (engine->GetInput()->GetKeyDown(SDL_SCANCODE_SPACE))
	{
		sprite->SetSpriteIndex(1);
		rigidbody->velocity = Vector2(0, -5.0f);
	}

	time += engine->deltaTime;
	if (time > 1.0f)
	{
		playerScore->AddScore();
		time = 0.0f;
	}


	if (rigidbody->position.y < 0.0f || rigidbody->position.y > 720.0f)
	{
		engine->Quit();
	}

}

void Player::SetPlayerScore(PlayerScore* playerScore)
{
	this->playerScore = playerScore;
	playerCollider->SetPlayerScore(playerScore);
}
