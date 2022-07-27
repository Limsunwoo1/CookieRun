#pragma once
#include "CScene.h"
class CGameStartScene :
    public CScene
{
public:
    CGameStartScene();
    ~CGameStartScene();

    virtual void Init() override;
    virtual void Clear() override;

    virtual void Update(float InDeltaTime) override;
    static void GameStart();
};

