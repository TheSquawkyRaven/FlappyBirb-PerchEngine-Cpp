#pragma once

#include "Engine.h"
#include "Branch/Script.h"

#include "Structs/Color.h"

#include "Branch/Branch2D/Button2D.h"

class HUD : public Perch::Script
{

private:

	Perch::Branch2D* root = nullptr;
	Perch::Button2D* button = nullptr;
	Perch::Sprite2D* buttonSprite = nullptr;

private:

public:

	HUD(Perch::Engine* engine) : Script(engine) {}
	inline Perch::Branch2D* GetRoot() { return root; }
	void Create();

};

