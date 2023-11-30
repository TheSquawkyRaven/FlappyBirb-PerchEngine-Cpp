#include "PlayerCollider.h"

#include "Squawk/Log.h"

#include "Player.h"


using namespace Perch;
using namespace std;
using namespace Squawk;


void PlayerCollider::OnCollision2D(Collider2D* collider)
{
	player->Die();
}
