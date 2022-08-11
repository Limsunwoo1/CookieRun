#include "CGroundObject.h"

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
	Position.x -= InDeltaTime * 200;
}

void CGroundObject::Collision(const CObject* InOtherObject)
{
	CObject::Collision(InOtherObject);
}