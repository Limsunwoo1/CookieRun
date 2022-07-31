#pragma once
#include "SpriteObject.h"
class CPetObject :
    public CSpriteObject
{
    PROTECT_MEMBER(String, PetName)
    PROTECT_MEMBER(int, Price)
    PROTECT_MEMBER(bool, GameRunning)
    PROTECT_MEMBER(String, TextureName)
private:
    CObject* TargetPlayer;
public:
    CPetObject();
    ~CPetObject();

    virtual void Update(float InDeltaTime) override;
    virtual void Render(HDC Inhdc) override;

    void SetTarget(CObject* InPlayer) {TargetPlayer = InPlayer;};
};

