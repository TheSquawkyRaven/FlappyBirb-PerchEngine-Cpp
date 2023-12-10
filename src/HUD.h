#pragma once

#include "Engine.h"
#include "Branch/Script.h"

#include "Structs/Color.h"

#include "Branch/BranchUI/ButtonUI.h"

class HUD : public Perch::Script
{

private:

	Perch::BranchUI* root = nullptr;

private:

public:

	HUD(Perch::Engine* engine) : Script(engine) {}
	inline Perch::BranchUI* GetRoot() { return root; }
	void Create();

};

