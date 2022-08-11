#pragma once
#include "SpriteObject.h"
class CGroundObject :
    public CSpriteObject
{
public:
    CGroundObject();
    CGroundObject(Vector2D InPosition, Vector2D InScale);
    ~CGroundObject();

    virtual void Update(float InDeltaTime) override;
    virtual void Collision(const CObject* InOtherObject) override;
};

