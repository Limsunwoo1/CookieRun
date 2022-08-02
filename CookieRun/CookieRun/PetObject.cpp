#include "PetObject.h"
#include "CTexture.h"

CPetObject::CPetObject() : CSpriteObject(Vector2D{100,100},Vector2D{50,50})
{
	PetName = "None";
	Price = 0;
	SelectItem = false;
	TextureName = "None";
}

CPetObject::~CPetObject()
{

}

void CPetObject::Update(float InDeltaTime)
{
	CSpriteObject::Update(InDeltaTime);

	if (!TargetPlayer)
		return;

	Position.x = TargetPlayer->GetPosition().x - 80;
	Position.y = TargetPlayer->GetPosition().y - 20;
}

void CPetObject::Render(HDC Inhdc)
{
	TransparentBlt(Inhdc,
		(int)Position.x - (Texture->GetWidth() * 0.5f),
		(int)Position.y - (Texture->GetHeight() * 0.5f),
		Texture->GetWidth(),
		Texture->GetHeight(),
		Texture->GetHdc(),
		0,
		0,
		Texture->GetWidth(),
		Texture->GetHeight(),
		RGB(255, 0, 255));
}