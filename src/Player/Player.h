#pragma once

#include "Engine.h"
#include "Branch/Script.h"

#include "Branch/Branch2D/Rigidbody2D.h"
#include "Branch/Branch2D/Sprite2D.h"
#include "Branch/Branch2D/Collider2D.h"
#include "Branch/Audio.h"

#include "PlayerCollider.h"

class Game;

class Player : public Perch::Script
{

private:

	Perch::Rigidbody2D* rigidbody = nullptr;
	Perch::Sprite2D* sprite = nullptr;
	Perch::Collider2D* collider = nullptr;
	Perch::Audio* jumpAudio = nullptr;
	Perch::Audio* deathAudio = nullptr;
	Perch::Audio* scoreAudio = nullptr;

private:

	PlayerCollider* playerCollider = nullptr;
	Game* game = nullptr;

	bool isDead = false;

public:

	inline void SetGame(Game* game) { this->game = game; }

public:

	Player(Perch::Engine* engine) : Script(engine) {}
	inline Perch::Rigidbody2D* GetRoot() { return rigidbody; }
	void Create();

	virtual void Update() override;

	void AddScore();
	void Die();


};

