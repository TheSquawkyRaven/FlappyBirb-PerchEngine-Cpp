#pragma once

#include "SDL.h"

#include "Engine.h"
#include "Script.h"

#include "Branch/Branch2D/Rigidbody2D.h"
#include "Branch/Branch2D/Sprite2D.h"
#include "Branch/Branch2D/Collider2D.h"

#include <memory>

class Cat : public Perch::Script
{

private:

	std::shared_ptr<Perch::Sprite2D> Sprite = NULL;
	std::shared_ptr<Perch::Collider2D> Collider = NULL;

public:

	inline std::shared_ptr<Perch::Sprite2D> GetRoot() { return Sprite; }

	void Create(Perch::Engine* engine);

	void SetIsTop(Perch::Engine* engine, bool isTop);


	virtual void Update(Perch::Engine* engine) override;
	virtual void Draw(Perch::Engine* engine, SDL_Renderer* renderer);

};

