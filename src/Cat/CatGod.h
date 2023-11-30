#pragma once

#include "Engine.h"
#include "Branch/Script.h"

#include "Branch/Branch.h"

#include "Cat.h"
#include "CatCouple.h"

#include <memory>
#include <vector>

class CatGod : public Perch::Script
{

private:

	Perch::Branch* root = nullptr;

	// Dont' use shared_ptr because a shared pointer is already created with the internal
	// GetScript() call
	std::vector<CatCouple*> catCouples;

	float spawnRateC = 1000.0f;
	float spawnX = 0.0f;

public:

	float minGap = 20.0f;
	float maxGap = 200.0f;
	float speed = 100.0f;
	float spawnRate = 4.0f;

public:

	CatGod(Perch::Engine* engine) : Script(engine) {}
	inline Perch::Branch* GetRoot() { return root; }
	void Create();

	virtual void Update() override;

	void Spawn();


};

