#pragma once

#include "Engine.h"
#include "Branch/Script.h"

#include "Branch/Branch2D/Rectangle2D.h"
#include "Branch/Branch2D/ScrollingSprite2D.h"

#include "Structs/Color.h"

#include <memory>

class Background : public Perch::Script
{

private:

	Perch::Branch2D* root = nullptr;
	Perch::ScrollingSprite2D* skySprite = nullptr;
	Perch::ScrollingSprite2D* hillsSprite = nullptr;
	Perch::ScrollingSprite2D* cityscapeBackSprite = nullptr;
	Perch::ScrollingSprite2D* cityscapeSprite = nullptr;

public:

	Background(Perch::Engine* engine) : Script(engine) {}
	inline Perch::Branch2D* GetRoot() { return root; }
	void Create();

	virtual void Update() override;

};

