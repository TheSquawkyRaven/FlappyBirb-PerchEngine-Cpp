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

	float spawnX = 0.0f;

public:

	float speed = 100.0f;
	float spawnXGap = 250.0f;

public:

	CatGod(Perch::Engine* engine) : Script(engine) {}
	inline Perch::Branch* GetRoot() { return root; }
	void Create();

	virtual void Update() override;

	void Spawn();


};

