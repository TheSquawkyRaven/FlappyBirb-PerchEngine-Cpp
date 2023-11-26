#pragma once

#include "Engine.h"
#include "Script.h"

#include "Branch/Branch.h"

#include "Cat.h"
#include "CatCouple.h"

#include <memory>
#include <vector>

class CatGod : public Perch::Script
{

private:

	std::shared_ptr<Perch::Branch> Root = NULL;

	// Dont' use shared_ptr because a shared pointer is already created with the internal
	// GetScript() call
	std::vector<CatCouple*> CatCouples;

	float SpawnRateC = 1000.0f;
	float SpawnX = 0.0f;

public:

	float MinGap = 20.0f;
	float MaxGap = 200.0f;
	float Speed = 100.0f;
	float SpawnRate = 4.0f;

	inline std::shared_ptr<Perch::Branch> GetRoot() { return Root; }

	void Create(Perch::Engine* engine);

	void Spawn(Perch::Engine* engine);

	virtual void Update(Perch::Engine* engine) override;


};

