#pragma once
#include "CScene.h"

class CScoreBord;
class CPlayer;

class CStage1 :
    public CScene
{
private:
    CPlayer* mPlayer;
    CScoreBord* OutScore;
public:
    CStage1();
    virtual ~CStage1();

    virtual void Init() override;	// ������ �ʿ��� ������Ʈ���� ��ü���� �����ؼ� �����Ѵ�
    virtual void Clear() override;   // ���� ���� ������ ���� �Ҹ��Ų��

    virtual void Update(float InDeltaTime) override;
    virtual void Render(HDC Inhdc) override;
    void MapDesign(String Instr, int cnt, int x, CScoreBord* InSCor);

    static void PAUSE();
};

