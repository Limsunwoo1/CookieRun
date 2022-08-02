#pragma once
#include "CScene.h"
#include <map>

class CButton;

class CInventory :
    public CScene
{
private:
    int XPos;
public:
    CInventory();
    virtual ~CInventory();

    virtual void Init() override;
    virtual void Clear() override;

    virtual void Update(float InDeltaTime) override;
    static void Exit();
};

