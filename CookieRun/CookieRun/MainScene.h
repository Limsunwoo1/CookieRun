#pragma once
#include "CScene.h"
#include "IntroDysPlay.h"
class CMainScene :
    public CScene
{
private:
    CIntroDysPlay* dev;
    CIntroDysPlay* kakao;

    float delta;
    int setalph;
    bool Direction;
public:
    CMainScene();
    virtual ~CMainScene();

    virtual void Init() override;	// 씬에서 필요한 오브젝트같은 객체들을 생성해서 세팅한다
    virtual void Clear() override;   // 현재 씬의 정보를 전부 소멸시킨다

    virtual void Update(float InDeltaTime) override;

    void MainSceneIntro(CIntroDysPlay* Indev, CIntroDysPlay* Inkakao);
};

