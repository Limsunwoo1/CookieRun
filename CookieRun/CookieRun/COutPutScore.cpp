#include "COutPutScore.h"
#include "CScoreBord.h"
#include "SpriteObject.h"
#include "Button.h"
#include "CTitleScene.h"
#include "EventManager.h"
#include "CBankManager.h"

COutPutScore::COutPutScore() : CScene()
{
	Int_Score = 0;
	deltatime = 0.0f;
	Scorebord = nullptr;
}

COutPutScore::~COutPutScore()
{

}

void COutPutScore::Init(int InScore)
{
	Int_Score = InScore;

	CSpriteObject* BackGround = new CSpriteObject(Vector2D{400,400}, Vector2D{50,50});
	BackGround->SetTexture("OUTPUT");
	AddObject(OBJ_LAYER::BACKGROUND, BackGround);

	Scorebord = new CScoreBord(Vector2D{630,370}, Vector2D{50,50});
	AddObject(OBJ_LAYER::UI, Scorebord);

	CButton* OkButton = new CButton(Vector2D{ 400,700 }, Vector2D{ 50,50 });
	OkButton->SetTexture("OKBUTTON");
	OkButton->SetClickTexture("CLICK_OK");
	OkButton->SetButtonFunc(BUTTON_STATE::LBUTTON_RELEASE, Exit);
	AddObject(OBJ_LAYER::UI, OkButton);

	deltatime = -1.0f;

	int push = CBankManager::GetInstance()->GetMoney();
	CBankManager::GetInstance()->SetMoney(Int_Score + push);
}

void COutPutScore::Update(float DeltaTIme)
{
	CScene::Update(DeltaTIme);

	if (Int_Score <= 0)
		return;

	deltatime += DeltaTIme;

	if (deltatime > 0.01f)
	{
		int jelly = Scorebord->GetScore();
		Scorebord->SetScore(++jelly);
		--Int_Score;

		deltatime -= 0.01f;
	}
}

void COutPutScore::Render(HDC Inhdc)
{
	CScene::Render(Inhdc);
}

void COutPutScore::Clear()
{
	CScene::Clear();
}

void COutPutScore::Exit()
{
	CTitleScene* GoTitle = new CTitleScene();

	EventInfo SetScene;
	SetScene.Type = EVENT_TYPE::CHANGE_SCENE;
	SetScene.Parameter = GoTitle;

	CEventManager::GetInstance()->AddEvent(SetScene);
}