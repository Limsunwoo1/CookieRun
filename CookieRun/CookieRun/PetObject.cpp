#include "PetObject.h"
#include "CTexture.h"

CPetObject::CPetObject() : CSpriteObject(Vector2D{0,0},Vector2D{50,50})
{
	PetName = "None";
	Price = 0;
	SelectItem = false;
	TextureName = "None";
	TargetPlayer = nullptr;
	DirVec = Vector2D{ 0,0 };
}

CPetObject::~CPetObject()
{

}

void CPetObject::Update(float InDeltaTime)
{
	CSpriteObject::Update(InDeltaTime);
	if (!TargetPlayer)
		return;

	// -80 , -20
	if ((Position.x == 0) && (Position.y == 0))
	{
		Position.x = TargetPlayer->GetPosition().x - 80;
		Position.y = TargetPlayer->GetPosition().y - 20;
	}

	if (Position.y - (TargetPlayer->GetPosition().y - 20) < 0)
	{
		DirVec.y = 1;
		Position += UtilMath::Normalize(DirVec) * InDeltaTime * 400;
	}
	else if(Position.y - (TargetPlayer->GetPosition().y - 20) > 0)
	{
		DirVec.y = -1;
		Position += UtilMath::Normalize(DirVec) * InDeltaTime * 400;
	}
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