#pragma once

#include "Engine.h"
#include "Branch/Script.h"

#include "Branch/Branch2D/Branch2D.h"

#include "Cat.h"

#include <memory>
#include <vector>

class CatCouple : public Perch::Script
{

private:

	Perch::Branch2D* root = nullptr;
	Perch::Collider2D* pointDetector = nullptr;

	Cat* topCat = nullptr;
	Cat* bottomCat = nullptr;

public:

	float minOffset = -300.0f;
	float maxOffset = 300.0f;

	float minGap = 250.0f;
	float maxGap = 300.0f;

public:


	CatCouple(Perch::Engine* engine) : Script(engine) {}
	inline Perch::Branch2D* GetRoot() { return root; }
	void Create();

};

