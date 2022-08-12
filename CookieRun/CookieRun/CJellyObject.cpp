#include "CJellyObject.h"
#include "EventManager.h"
#include "CTexture.h"

CJellyObject::CJellyObject() : CSpriteObject(Vector2D{ 100,100 }, Vector2D{ 50,50 }),
Score(nullptr)
{

}

CJellyObject::CJellyObject(Vector2D InPos, Vector2D InScale) : CSpriteObject(Vector2D{InPos.x, InPos.y}, Vector2D{InScale.x, InScale.y}),
Score(nullptr)
{

}
CJellyObject::~CJellyObject()
{

}

void CJellyObject::Update(float InDeltaTIme)
{
	CObject::Update(InDeltaTIme);

	Position.x -= InDeltaTIme * 300;
}

void CJellyObject::Render(HDC Inhdc)
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

void CJellyObject::Collision(const CObject* InOtherObject)
{
	if (!Score)
		return;

	int jelly = Score->GetScore();
	Score->SetScore(++jelly);

	EventInfo evnt;
	evnt.Type = EVENT_TYPE::DELETE_OBJECT;
	evnt.Parameter = new OBJ_LAYER(OBJ_LAYER::ITEM);
	evnt.Parameter2 = this;

	CEventManager::GetInstance()->AddEvent(evnt);
}