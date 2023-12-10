#include "HUD.h"

#include "Squawk/Log.h"

using namespace Perch;
using namespace std;
using namespace Squawk;


void HUD::Create()
{
	root = new BranchUI(engine);
	root->AttachScriptu(this);
}
