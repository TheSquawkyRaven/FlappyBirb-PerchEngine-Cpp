#pragma once

#include "SDL.h"

#include "Engine.h"
#include "Branch/Script.h"

#include "Branch/Branch2D/Rigidbody2D.h"
#include "Branch/Branch2D/Sprite2D.h"
#include "Branch/Branch2D/Collider2D.h"

#include <memory>

class Cat : public Perch::Script
{

private:

	Perch::Sprite2D* sprite = nullptr;
	Perch::Collider2D* collider = nullptr;

public:

	Cat(Perch::Engine* engine) : Script(engine) {}
	inline Perch::Sprite2D* GetRoot() { return sprite; }
	void Create();

	void SetIsTop(bool isTop);


};

