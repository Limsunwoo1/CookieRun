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
#include <string>

CTitleScene::CTitleScene() 
{
}

CTitleScene::~CTitleScene()
{

}

void CTitleScene::Init()
{
	CHpBar* Hp = new CHpBar();
	Hp->SetTexture("HP_UI");
	Hp->SetDynamic_Width();
	AddObject(OBJ_LAYER::UI, Hp);

	CSpriteObject* BackGround = new CSpriteObject();
	BackGround->SetPosition(Vector2D(400, 400));
	BackGround->SetTexture("BACKGRUOND");
	AddObject(OBJ_LAYER::BACKGROUND, BackGround);

	CPlayer* Player = new CPlayer();
	Player->SetPosition(Vector2D(500, 550));
	Player->SetScale(Vector2D(100, 100));
	Player->SetCollisionScale(Vector2D(100, 100));
	Player->SetTexture("RUN", "PLAYER_RUN", 6, 30.f);
	Player->SetTexture("DEAD", "PLAYER_DEAD", 4, 5.f, false);
	Player->SetTexture("JUMP", "PLAYER_JUMP", 1, 30.f, false);
	Player->SetTexture("DOUJUMP", "PLAYER_DOUJUMP", 1, 30.f, false);
	Player->SetTexture("SLIDING", "PLAYER_SLIDING", 1, 30.f, false);
	AddObject(OBJ_LAYER::PLAYER, Player);

	
	// UI�� �浹üũ�ϸ� ������ ���ϼ��� ���� üũ�ص� UI ������ �ϵ��� ����
	std::vector<OBJ_LAYER> checkLayerList;
	checkLayerList.push_back(OBJ_LAYER::PLAYER);
	CheckCollisionLayer[OBJ_LAYER::BULLET] = checkLayerList;
	checkLayerList.push_back(OBJ_LAYER::BLOCK);
	CheckCollisionLayer[OBJ_LAYER::BULLET] = checkLayerList;

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