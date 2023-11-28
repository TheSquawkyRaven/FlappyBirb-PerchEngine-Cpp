#pragma once

#include "Engine.h"
#include "Branch/Script.h"

#include "Branch/Branch2D/Rigidbody2D.h"
#include "Branch/Branch2D/Sprite2D.h"
#include "Branch/Branch2D/Collider2D.h"

#include "PlayerScore.h"
#include "PlayerCollider.h"

#include <memory>

class Player : public Perch::Script
{

private:

	Perch::Rigidbody2D* rigidbody = nullptr;
	Perch::Sprite2D* sprite = nullptr;
	Perch::Collider2D* collider = nullptr;

	PlayerCollider* playerCollider = nullptr;
	PlayerScore* playerScore = nullptr;

private:

	float time = 0;

public:

	Player(Perch::Engine* engine) : Script(engine) {}
	inline Perch::Rigidbody2D* GetRoot() { return rigidbody; }
	void Create();

	virtual void Update() override;

	void SetPlayerScore(PlayerScore* playerScore);


};

