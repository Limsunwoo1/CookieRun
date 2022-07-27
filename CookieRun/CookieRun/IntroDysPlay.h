#pragma once
#include "SpriteObject.h"

class CIntroDysPlay :
    public CSpriteObject
{
    MEMBER(int, alph)
public:
    CIntroDysPlay();
    ~CIntroDysPlay();
    virtual void Render(HDC InHdc) override;
};

