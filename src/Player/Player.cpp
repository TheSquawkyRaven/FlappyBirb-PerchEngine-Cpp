#include "Player.h"

#include "Squawk/Log.h"

#include "../Game.h"

using namespace Perch;
using namespace std;
using namespace Squawk;


void Player::Create()
{
	rigidbody = new Rigidbody2D(engine);
	rigidbody->gravity = 980.f;
	rigidbody->AttachScript(unique_ptr<Player>(this));

	shared_ptr<Texture> birbTexture = Texture::Create(engine, "./images/birb-Sheet.png");
	sprite = new Sprite2D(engine);
	sprite->SetTexture(birbTexture);
	sprite->scale = Vector2(6, 6);
	sprite->SetSpriteColumns(2);
	sprite->positionPivot = Vector2(0.5f, 0.5f);

	Vector2 playerStartPosition = engine->GetMainWindowSize();
	playerStartPosition.x /= 3.5;
	playerStartPosition.y /= 3.5f;
	rigidbody->position = playerStartPosition;

	collider = new Collider2D(engine);
	collider->rect = Rect2(-5, -5, 10, 10);

	playerCollider = new PlayerCollider(engine);
	playerCollider->SetPlayer(this);
	collider->AttachScriptu(playerCollider);

	sprite->AttachChildu(collider);
	rigidbody->AttachChildu(sprite);

	shared_ptr<Clip> jumpClip = Clip::Create(engine, "./audio/Jump.wav");
	jumpAudio = new Audio(engine);
	jumpAudio->SetClip(jumpClip);
	rigidbody->AttachChildu(jumpAudio);

	shared_ptr<Clip> deathClip = Clip::Create(engine, "./audio/Death.wav");
	deathAudio = new Audio(engine);
	deathAudio->SetClip(deathClip);
	rigidbody->AttachChildu(deathAudio);

	shared_ptr<Clip> scoreClip = Clip::Create(engine, "./audio/Score.wav");
	scoreAudio = new Audio(engine);
	scoreAudio->SetClip(scoreClip);
	rigidbody->AttachChildu(scoreAudio);


}

void Player::Update()
{
	if (isDead)
	{
		return;
	}

	if (rigidbody->velocity.y > 0.0f)
	{
		sprite->SetSpriteIndex(0);
		sprite->angle += 200.f * engine->GetDeltaTime();
	}
	else
	{
		sprite->angle -= 100.f * engine->GetDeltaTime();
	}
	if (engine->GetInput()->GetKeyDown(SDL_SCANCODE_SPACE))
	{
		sprite->SetSpriteIndex(1);
		rigidbody->velocity = Vector2(0, -600.0f);
		jumpAudio->Play();
		sprite->angle = -10.f;
	}

	if (rigidbody->position.y < 0.0f || rigidbody->position.y > engine->GetMainWindowSize().y)
	{
		Die();
	}

}

void Player::AddScore(int score)
{
	scoreAudio->Play();
	game->AddScore(score);
}

void Player::Die()
{
	if (isDead)
	{
		return;
	}

	deathAudio->Play();
	game->EndGame();
	isDead = true;
}
