#pragma once

#include "Engine.h"
#include "Branch/Script.h"

#include "Branch/Branch.h"
#include "Structs/Vector2.h"

#include "../Cat/CatGod.h"
#include "../Cat/CatCouple.h"
#include "Bread.h"

#include <vector>
#include <memory>

class BreadGod : public Perch::Script
{

private:

	Perch::Branch* root = nullptr;

	CatGod* catGod = nullptr;

public:

	float spawnOffset = 200.0f;
	float minY = -300.0f;
	float maxY = 300.0f;

public:

	BreadGod(Perch::Engine* engine) : Script(engine) {}
	inline Perch::Branch* GetRoot() { return root; }
	void Create(CatGod* catGod);

	void OnCatCoupleCreated(CatCouple* catCouple);


};

