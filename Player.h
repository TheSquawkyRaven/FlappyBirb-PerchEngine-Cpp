#pragma once

#include "Engine.h"
#include "Script.h"

#include "Branch/Branch2D/Rigidbody2D.h"
#include "Branch/Branch2D/Sprite2D.h"

#include <memory>

class Player : public Perch::Script
{

private:

	std::shared_ptr<Perch::Rigidbody2D> Rigidbody = NULL;

public:

	inline std::shared_ptr<Perch::Rigidbody2D> GetRoot() { return Rigidbody; }

	void Create(Perch::Engine* engine);

	virtual void Update(Perch::Engine* engine) override;

};

