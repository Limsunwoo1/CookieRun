#include "CTitleScene.h"
#include "Func.h"
#include "Button.h"
#include "Player.h"
#include "HpBar.h"
#include "SpriteObject.h"
#include "CSceneManager.h"
#include "ResourceManager.h"
#include "EventManager.h"
#include "UtilLog.h"
#include "UtilString.h"
#include "Loger.h"
#include "CShop.h"
#include "CStage1.h"
#include <string>

CTitleScene::CTitleScene() 
{
}

CTitleScene::~CTitleScene()
{
	ClearObject();
}

void CTitleScene::Init()
{
	CSpriteObject* BackGround = new CSpriteObject();
	BackGround->SetPosition(Vector2D(400, 400));
	BackGround->SetTexture("LOBBYBACKGRUOND");
	AddObject(OBJ_LAYER::BACKGROUND, BackGround);

	CButton* Goinshop = new CButton(Vector2D{ 500, 500 }, Vector2D{ 50, 50 });
	Goinshop->SetTexture("INSHOP");
	Goinshop->SetClickTexture("CLICKSHOP");
	Goinshop->SetButtonFunc(BUTTON_STATE::LBUTTON_PRESS, InShop);
	AddObject(OBJ_LAYER::UI, Goinshop);

	CButton* gameStart = new CButton(Vector2D{ 600, 650 }, Vector2D{ 50, 50 });
	gameStart->SetTexture("STARTBUTTON");
	gameStart->SetClickTexture("STARTBTPRESS");
	gameStart->SetButtonFunc(BUTTON_STATE::LBUTTON_PRESS, GameStart);
	AddObject(OBJ_LAYER::UI, gameStart);
	
	// UI�� �浹üũ�ϸ� ������ ���ϼ��� ���� üũ�ص� UI ������ �ϵ��� ����

	LOG_TODO("�α� ���� �ڵ� Ȯ�������� ������ ����");
	LOG("�Ϲ� �α� �׽�Ʈ");
	WARN_LOG("��� �α� �׽�Ʈ");
	ERROR_LOG("���� �α� �׽�Ʈ");
	ETC1_LOG("Ŀ���� �α� �׽�Ʈ");
	LOG(STRING("���ڿ� ������ �׽�Ʈ : %d !!!", 30));
}

void CTitleScene::Clear()
{	
	CScene::Clear();
}

void CTitleScene::Update(float InDeltaTime)
{
	CScene::Update(InDeltaTime);
}

void CTitleScene::InShop()
{
	CShop* shop = new CShop();
	CEventManager::GetInstance()->ChangeSceneEvent(shop);
}

void CTitleScene::GameStart()
{
	CStage1* start = new CStage1();
	CEventManager::GetInstance()->ChangeSceneEvent(start);
}