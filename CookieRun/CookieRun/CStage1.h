#pragma once
#include "CScene.h"
class CStage1 :
    public CScene
{
protected:


public:
    CStage1();
    virtual ~CStage1();

    virtual void Init() override;	// ������ �ʿ��� ������Ʈ���� ��ü���� �����ؼ� �����Ѵ�
    virtual void Clear() override;   // ���� ���� ������ ���� �Ҹ��Ų��

    virtual void Update(float InDeltaTime) override;
};
