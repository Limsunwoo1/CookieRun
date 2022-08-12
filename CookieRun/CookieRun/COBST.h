#pragma once
#include "SpriteObject.h"
class COBST :
    public CSpriteObject

{
public:
    COBST();
    COBST(Vector2D InPos, Vector2D InScale);
    ~COBST();

    virtual void Update(float InDeltaTIme) override;
    virtual void Render(HDC Inhdc) override;

    virtual void Collision(const CObject* InOtherObject) override;
};

