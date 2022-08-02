#pragma once
#include "SpriteObject.h"

class CIntroDysPlay :
    public CSpriteObject
{
    MEMBER(int, alpha)
public:
    CIntroDysPlay();
    ~CIntroDysPlay();
    virtual void Render(HDC InHdc) override;
};

