#pragma once

#include "Engine.h"
#include "Script.h"

#include "Branch/Branch2D/Collider2D.h"

#include "PlayerScore.h"

#include <memory>

class PlayerCollider : public Perch::Script
{

private:

	PlayerScore* Score = NULL;

public:

	inline void SetPlayerScore(PlayerScore* playerScore) { Score = playerScore; }
	virtual void OnCollision2D(Perch::Engine* engine, Perch::Collider2D* collider) override;


};

