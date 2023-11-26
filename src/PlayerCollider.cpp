#include "PlayerCollider.h"

#include "Log.h"


using namespace Perch;
using namespace std;
using namespace Squawk;

void PlayerCollider::OnCollision2D(Engine* engine, Collider2D* collider)
{
	Log::Printf("Collided");
	Log::Printf("Score: %d", Score->Score);
	delete engine;
}
