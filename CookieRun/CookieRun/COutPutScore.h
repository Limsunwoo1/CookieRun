#pragma once
#include "CScene.h"

class CScoreBord;

class COutPutScore :
    public CScene
{
private:
    int Int_Score;
    float deltatime;
    CScoreBord* Scorebord;

public:
    COutPutScore();
    ~COutPutScore();

    virtual void Update(float DeltaTIme) override;
    virtual void Render(HDC Inhdc) override;

    virtual void Clear() override;

    void Init(int InScore);

    static void Exit();
};


