#pragma once
#include "SpriteObject.h"
class CPlayer;

class CPetObject :
    public CSpriteObject
{
    PROTECT_MEMBER(String, PetName)
    PROTECT_MEMBER(int, Price)
    PROTECT_MEMBER(String, TextureName)
    PROTECT_MEMBER(bool, SelectItem)
private:
    CObject* TargetPlayer;
    Vector2D DirVec;
public:
    CPetObject();
    ~CPetObject();

    virtual void Update(float InDeltaTime) override;
    virtual void Render(HDC Inhdc) override;

    void SetTarget(CObject* InPlayer) {TargetPlayer = InPlayer;};
};

