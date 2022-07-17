#pragma once
#include "AnimationObject.h"

class CPlayer :
    public CAnimationObject
{
public:
    CPlayer();
    CPlayer(Vector2D InVector, Vector2D InScale);
    virtual ~CPlayer();

    virtual void Init();
    virtual void Update(float InDeltaTime) override;
    virtual void Render(HDC InHdc) override;
    virtual void Collision(const CObject* InOtherObject) override;
};

