#pragma once
#include "CScene.h"
class CPAUSE :
    public CScene
{
public:
    CPAUSE();
    virtual ~CPAUSE();

public:
    virtual void Init() override;
    virtual void Update(float InDeltaTime) override;
    virtual void Clear() override;

    static void RePlay();
    static void ReTurn();
    static void Exit();
};

