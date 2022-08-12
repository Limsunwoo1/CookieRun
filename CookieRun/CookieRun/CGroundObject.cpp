#include "CGroundObject.h"
#include "CSceneManager.h"
#include <vector>

CGroundObject::CGroundObject() : CSpriteObject()
{

}

CGroundObject::CGroundObject(Vector2D InPosition, Vector2D InScale) : CSpriteObject(Vector2D{ InPosition.x,InPosition .y}, Vector2D{ InScale.x,InScale .y})
{

}

CGroundObject::~CGroundObject()
{

}

void CGroundObject::Update(float InDeltaTime)
{
	if (Position.x < -5000)
		Position.x = 2000;

	CSpriteObject::Update(InDeltaTime);
	Position.x -= InDeltaTime * 300;
}

void CGroundObject::Collision(const CObject* InOtherObject)
{
	CObject::Collision(InOtherObject);
}