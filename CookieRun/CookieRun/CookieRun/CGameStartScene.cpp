#include "CGameStartScene.h"
#include "Button.h"
#include "EventManager.h"

CGameStartScene::CGameStartScene()
{

}

CGameStartScene::~CGameStartScene()
{

}

void CGameStartScene::Init()
{
	CSpriteObject* titelscene = new CSpriteObject();
	titelscene->SetTexture("MAINGAME");
	AddObject(OBJ_LAYER::BACKGROUND, titelscene);

	CButton* startbutton = new CButton(Vector2D{700, 700}, Vector2D{50, 50});
	startbutton->SetButtonFunc(BUTTON_STATE::LBUTTON_PRESS,GameStart);
	startbutton->SetTexture("MAINGAME");
	AddObject(OBJ_LAYER::UI, startbutton);
}

void CGameStartScene::Clear()
{
	CScene::Clear();
}

void CGameStartScene::Update(float InDeltaTime)
{

}

static void GameStart()
{
	EventInfo DeletCurScene;
	DeletCurScene.Type = EVENT_TYPE::DELETE_OBJECT;
	DeletCurScene.Parameter = new OBJ_LAYER(OBJ_LAYER::)
}