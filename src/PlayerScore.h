#pragma once

#include "Engine.h"
#include "Script.h"

#include "Branch/Branch2D/Text2D.h"

#include <memory>

class PlayerScore : public Perch::Script
{

private:

	std::shared_ptr<Perch::Text2D> Text = NULL;

public:

	int Score = 0;

	inline std::shared_ptr<Perch::Text2D> GetRoot() { return Text; }

	void AddScore();
	
	void Create(Perch::Engine* engine);

};

