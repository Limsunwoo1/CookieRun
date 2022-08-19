#pragma once
#include "SpriteObject.h"
#include "CScoreBord.h"

class CJellyObject :
    public CSpriteObject
{
private:
    CScoreBord* Score;

    bool FirstCollsion;
public:
    CJellyObject();
    CJellyObject(Vector2D InPos, Vector2D InScale);
    ~CJellyObject();

    virtual void Update(float InDeltaTIme) override;
    virtual void Render(HDC Inhdc) override;
    virtual void Collision(const CObject* InOtherObject) override;
    
    void SetScore(CScoreBord* InScore) { Score = InScore; };
};

