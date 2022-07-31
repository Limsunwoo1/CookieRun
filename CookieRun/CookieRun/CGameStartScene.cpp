#include "CGameStartScene.h"
#include "Button.h"
#include "CTitleScene.h"
#include "EventManager.h"
#include "CShop.h"

CGameStartScene::CGameStartScene()
{

}

CGameStartScene::~CGameStartScene()
{

}

void CGameStartScene::Init()
{
	CSpriteObject* titelscene = new CSpriteObject(Vector2D{400,400},Vector2D{400,400});
	titelscene->SetTexture("MAINGAME");
	AddObject(OBJ_LAYER::BACKGROUND, titelscene);

	CButton* startbutton = new CButton(Vector2D{400, 730}, Vector2D{50, 50});
	startbutton->SetTexture("STARTBUTTON");
	startbutton->SetClickTexture("STARTBTPRESS");
	startbutton->SetButtonFunc(BUTTON_STATE::LBUTTON_RELEASE, GameStart);
	AddObject(OBJ_LAYER::UI, startbutton);
}

void CGameStartScene::Clear()
{
	CScene::Clear();
}

void CGameStartScene::Update(float InDeltaTime)
{
	CScene::Update(InDeltaTime);
}

void CGameStartScene::GameStart()
{
	CTitleScene* Title = new CTitleScene();
	CEventManager::GetInstance()->ChangeSceneEvent(Title);
}