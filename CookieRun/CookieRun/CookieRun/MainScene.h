#pragma once
#include "CScene.h"
#include "IntroDysPlay.h"
class CMainScene :
    public CScene
{
private:
    CIntroDysPlay* dev;
    CIntroDysPlay* kakao;

    bool Direction;
public:
    CMainScene();
    virtual ~CMainScene();

    virtual void Init() override;	// ������ �ʿ��� ������Ʈ���� ��ü���� �����ؼ� �����Ѵ�
    virtual void Clear() override;   // ���� ���� ������ ���� �Ҹ��Ų��

    virtual void Update(float InDeltaTime) override;

    void MainSceneIntro(CIntroDysPlay* Indev, CIntroDysPlay* Inkakao);
};

