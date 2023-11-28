#pragma once

#include "Engine.h"
#include "Branch/Script.h"

#include "Branch/Branch2D/Collider2D.h"

#include "PlayerScore.h"

#include <memory>

class PlayerCollider : public Perch::Script
{

private:

	PlayerScore* playerScore = nullptr;

public:

	inline void SetPlayerScore(PlayerScore* playerScore) { this->playerScore = playerScore; }

public:

	PlayerCollider(Perch::Engine* engine) : Script(engine) {}

	virtual void OnCollision2D(Perch::Collider2D* collider) override;


};

