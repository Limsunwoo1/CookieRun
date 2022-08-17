#include "CPAUSE.h"
#include "Button.h"
#include "ResourceManager.h"
#include "CTitleScene.h"
#include "CStage1.h"
#include "CSceneManager.h"
#include "EventManager.h"

CPAUSE::CPAUSE()
{

}

CPAUSE::~CPAUSE()
{
	CPAUSE::Clear();
}

void CPAUSE::Init()
{
	//BACKGROUND
	CSpriteObject* BackGround = new CSpriteObject(Vector2D{ 400,350 }, Vector2D{ 50,50 });
	BackGround->SetObjectLayer(OBJ_LAYER::BACKGROUND);
	BackGround->SetTexture(CResourceManager::GetInstance()->FindTexture("PAUSEBACKGROUN"));
	AddObject(OBJ_LAYER::BACKGROUND, BackGround);

	//UI
	CButton* RePlay = new CButton(Vector2D{ 280, 420 }, Vector2D{ 50, 50 });
	RePlay->SetObjectLayer(OBJ_LAYER::UI);
	RePlay->SetTexture(CResourceManager::GetInstance()->FindTexture("REPLAY"));
	RePlay->SetButtonFunc(BUTTON_STATE::LBUTTON_PRESS, CPAUSE::RePlay);
	AddObject(OBJ_LAYER::UI, RePlay);

	CButton* Return = new CButton(Vector2D{ 480, 420 }, Vector2D{ 50, 50 });
	Return->SetObjectLayer(OBJ_LAYER::UI);
	Return->SetTexture(CResourceManager::GetInstance()->FindTexture("RETURN"));
	Return->SetButtonFunc(BUTTON_STATE::LBUTTON_PRESS, CPAUSE::ReTurn);
	AddObject(OBJ_LAYER::UI, Return);

	CButton* Exit = new CButton(Vector2D{ 700, 300 }, Vector2D{ 50, 50 });
	Exit->SetObjectLayer(OBJ_LAYER::UI);
	Exit->SetTexture(CResourceManager::GetInstance()->FindTexture("XBUTTON"));
	Exit->SetButtonFunc(BUTTON_STATE::LBUTTON_PRESS, CPAUSE::Exit);
	AddObject(OBJ_LAYER::UI, Exit);
}

void CPAUSE::Update(float InDeltaTime)
{
	CScene::Update(InDeltaTime);
}

void CPAUSE::Clear()
{
	CPAUSE::ClearObject();
}

void CPAUSE::RePlay()
{
	CStage1* Stage1 = new CStage1();

	EventInfo SetScene;
	SetScene.Type = EVENT_TYPE::CHANGE_SCENE;
	SetScene.Parameter = Stage1;

	CEventManager::GetInstance()->AddEvent(SetScene);
	CSceneManager::GetInstance()->ClearReGame();
}

void CPAUSE::ReTurn()
{
	CTitleScene* Title = new CTitleScene();

	EventInfo SetScene;
	SetScene.Type = EVENT_TYPE::CHANGE_SCENE;
	SetScene.Parameter = Title;

	CEventManager::GetInstance()->AddEvent(SetScene);
	CSceneManager::GetInstance()->ClearReGame();
}

void CPAUSE::Exit()
{
	CSceneManager::GetInstance()->ClearReGame();
}