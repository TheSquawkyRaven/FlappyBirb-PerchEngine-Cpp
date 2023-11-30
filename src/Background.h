#pragma once

#include "Engine.h"
#include "Branch/Script.h"

#include "Branch/Branch2D/Rectangle2D.h"

#include "Structs/Color.h"

#include <memory>

class Background : public Perch::Script
{

private:

	Perch::Rectangle2D* rectangle = nullptr;

public:

	float time = 0;
	bool colorFlip = false;

public:

	Background(Perch::Engine* engine) : Script(engine) {}
	inline Perch::Rectangle2D* GetRoot() { return rectangle; }
	void Create();

	virtual void Update() override;

};

