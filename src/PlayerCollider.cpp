#include "PlayerCollider.h"

#include "Squawk/Log.h"


using namespace Perch;
using namespace std;
using namespace Squawk;


void PlayerCollider::OnCollision2D(Collider2D* collider)
{
	Log::Printf("Collided");
	Log::Printf("playerScore: %d", playerScore->GetScore());
	delete engine;
}
