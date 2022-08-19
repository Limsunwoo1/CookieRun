#pragma once
#include "AnimationObject.h"

class CHpBar;

class CPlayer :
    public CAnimationObject
{
private:
    Vector2D mVel;
    CHpBar* HP;
    
    float delta;
    bool diving;
    bool CurCollsion;
public:
    CPlayer();
    CPlayer(Vector2D InVector, Vector2D InScale);
    virtual ~CPlayer();

    virtual void Init();
    virtual void Update(float InDeltaTime) override;
    virtual void Render(HDC InHdc) override;
    virtual void Collision(const CObject* InOtherObject) override;

    void JumpAction(float InDeltaTime, int Speed);
    void DoubleJumpAction(float InDeltaTime, int Speed);
    void SetHP(CHpBar* InHP) { HP = InHP; };
    CHpBar* GetPlayerHP() {return HP;};
    bool CheckDiving(float InDeltaTime);
};

