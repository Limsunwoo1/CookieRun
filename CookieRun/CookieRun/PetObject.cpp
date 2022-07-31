#include "PetObject.h"

CPetObject::CPetObject() : CSpriteObject(Vector2D{100,100},Vector2D{50,50})
{
	PetName = "None";
	Price = 0;
	GameRunning = false;
	TextureName = "None";
}

CPetObject::~CPetObject()
{

}

void CPetObject::Update(float InDeltaTime)
{
	if (!GameRunning)
		return;

	CSpriteObject::Update(InDeltaTime);

	
}

void CPetObject::Render(HDC Inhdc)
{
	CSpriteObject::Render(Inhdc);
}