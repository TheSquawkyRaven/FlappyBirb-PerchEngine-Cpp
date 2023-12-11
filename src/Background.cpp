#include "Background.h"

#include "Squawk/Log.h"


using namespace Perch;
using namespace std;
using namespace Squawk;


void Background::Create()
{
	root = new Branch2D(engine);

	Vector2 scale(6, 6);

	shared_ptr<Texture> hills = Texture::Create(engine, "./images/hills.png");
	hillsSprite = new ScrollingSprite2D(engine);
	hillsSprite->SetTexture(hills);
	hillsSprite->scale = scale;

	shared_ptr<Texture> sky = Texture::Create(engine, "./images/sky.png");
	skySprite = new ScrollingSprite2D(engine);
	skySprite->SetTexture(sky);
	skySprite->scale = scale;

	shared_ptr<Texture> cityscape = Texture::Create(engine, "./images/cityscape.png");
	cityscapeSprite = new ScrollingSprite2D(engine);
	cityscapeSprite->SetTexture(cityscape);
	cityscapeSprite->scale = scale;

	shared_ptr<Texture> cityscapeBack = Texture::Create(engine, "./images/cityscapeBack.png");
	cityscapeBackSprite = new ScrollingSprite2D(engine);
	cityscapeBackSprite->SetTexture(cityscapeBack);
	cityscapeBackSprite->scale = scale;

	shared_ptr<Texture> sun = Texture::Create(engine, "./images/sun.png");
	sunSprite = new Sprite2D(engine);
	sunSprite->SetTexture(sun);
	sunSprite->scale = scale;
	sunSprite->position = Vector2(1075, -175);

	root->AttachScriptu(this);

	root->AttachChildu(skySprite);
	root->AttachChildu(hillsSprite);
	root->AttachChildu(cityscapeBackSprite);
	root->AttachChildu(cityscapeSprite);

	root->AttachChildu(sunSprite);
	
}

void Background::Update()
{
	float speed = -10.0f;
	skySprite->scroll += engine->GetDeltaTime() * speed * 0.2f;
	hillsSprite->scroll += engine->GetDeltaTime() * speed * 0.8f;
	cityscapeBackSprite->scroll += engine->GetDeltaTime() * speed * 2.25f;
	cityscapeSprite->scroll += engine->GetDeltaTime() * speed * 5.0f;

}
