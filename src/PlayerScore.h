#pragma once

#include "Engine.h"
#include "Branch/Script.h"

#include "Branch/Branch2D/Text2D.h"

#include <memory>

class PlayerScore : public Perch::Script
{

private:

	Perch::Text2D* text = nullptr;

private:

	int score = 0;

public:

	inline int GetScore() const { return score; }

public:

	PlayerScore(Perch::Engine* engine) : Script(engine) {}
	inline Perch::Text2D* GetRoot() { return text; }
	void Create();

	void AddScore();

};

