#pragma once

#include "Engine.h"
#include "Script.h"

#include "Branch/Branch2D/Rectangle2D.h"

#include "PlayerScore.h"
#include "Structs/Color.h"

#include <memory>

class Background : public Perch::Script
{

private:

	std::shared_ptr<Perch::Rectangle2D> Rect = NULL;


public:

	float t = 0;
	bool yes = false;

	inline std::shared_ptr<Perch::Rectangle2D> GetRoot() { return Rect; }

	void Create(Perch::Engine* engine);

	virtual void Update(Perch::Engine* engine) override;

};

