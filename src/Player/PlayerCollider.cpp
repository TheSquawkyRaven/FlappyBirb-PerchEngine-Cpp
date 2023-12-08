#include "PlayerCollider.h"

#include "Squawk/Log.h"

#include "Player.h"


using namespace Perch;
using namespace std;
using namespace Squawk;


void PlayerCollider::OnCollision2D(Collider2D* collider, CollisionState collisionState)
{
	if (collisionState == CollisionState::Enter)
	{
		if (collider->GetName() == "Point")
		{
			player->AddScore();
			return;
		}
		player->Die();
	}
}
