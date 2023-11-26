#pragma once

#include "Engine.h"
#include "Script.h"

#include "Branch/Branch2D/Branch2D.h"

#include "Cat.h"

#include <memory>
#include <vector>

class CatCouple : public Perch::Script
{

private:

	std::shared_ptr<Perch::Branch2D> Root = NULL;

	// Dont' use shared_ptr because a shared pointer is already created with the internal
	// GetScript() call
	Cat* TopCat = NULL;
	Cat* BottomCat = NULL;

public:

	float MinOffset = -300.0f;
	float MaxOffset = 300.0f;

	float MinGap = 250.0f;
	float MaxGap = 300.0f;

	inline std::shared_ptr<Perch::Branch2D> GetRoot() { return Root; }

	void Create(Perch::Engine* engine);

	void Spawn(Perch::Engine* engine);

	virtual void Update(Perch::Engine* engine) override;


};

