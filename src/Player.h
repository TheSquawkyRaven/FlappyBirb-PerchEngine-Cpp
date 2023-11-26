#pragma once

#include "Engine.h"
#include "Script.h"

#include "Branch/Branch2D/Rigidbody2D.h"
#include "Branch/Branch2D/Sprite2D.h"
#include "Branch/Branch2D/Collider2D.h"

#include "PlayerScore.h"
#include "PlayerCollider.h"

#include <memory>

class Player : public Perch::Script
{

private:

	std::shared_ptr<Perch::Rigidbody2D> Rigidbody = NULL;
	std::shared_ptr<Perch::Sprite2D> Sprite = NULL;
	std::shared_ptr<Perch::Collider2D> Collider = NULL;
	PlayerCollider* PCollider = NULL;
	PlayerScore* Score = NULL;

public:

	float t = 0;

	inline std::shared_ptr<Perch::Rigidbody2D> GetRoot() { return Rigidbody; }

	void Create(Perch::Engine* engine);
	void SetPlayerScore(PlayerScore* playerScore);

	virtual void Update(Perch::Engine* engine) override;

};

