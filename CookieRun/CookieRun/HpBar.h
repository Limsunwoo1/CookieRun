#pragma once
#include "UI.h"
class CHpBar :
    public CUI
{
private:
    float mDynamic_Width;
    MEMBER(bool, GameStop)
public:
    CHpBar();
    ~CHpBar();

    virtual void Update(float InDeltaTime) override;
    virtual void Render(HDC InHdc);

    void SetDynamic_Width();
    float GetDynamic_Width() { return mDynamic_Width; };
};