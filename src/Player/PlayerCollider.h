#pragma once

#include "Engine.h"
#include "Branch/Script.h"

#include "Branch/Branch2D/Collider2D.h"

#include <memory>

class Player;

class PlayerCollider : public Perch::Script
{

private:

	Player* player = nullptr;

public:

	inline void SetPlayer(Player* player) { this->player = player; }

public:

	PlayerCollider(Perch::Engine* engine) : Script(engine) {}

	virtual void OnCollision2D(Perch::Collider2D* collider) override;


};

