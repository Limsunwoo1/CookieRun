#include "CStage1.h"
#include "Func.h"
#include "Button.h"
#include "Player.h"
#include "HpBar.h"
#include "PetObject.h"
#include "SpriteObject.h"
#include "CSceneManager.h"
#include "ResourceManager.h"
#include "EventManager.h"
#include "CItemManager.h"
#include "UtilLog.h"
#include "UtilString.h"
#include "Loger.h"
#include <string>

CStage1::CStage1()
{
}

CStage1::~CStage1()
{
	ClearObject();
}

void CStage1::Init()
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
	Player->SetPosition(Vector2D(200, 550));
	Player->SetScale(Vector2D(100, 100));
	Player->SetCollisionScale(Vector2D(100, 100));
	Player->SetHP(Hp);
	Player->SetTexture("RUN", "PLAYER_RUN", 6, 30.f);
	Player->SetTexture("DEAD", "PLAYER_DEAD", 4, 5.f, false);
	Player->SetTexture("JUMP", "PLAYER_JUMP", 1, 30.f, false);
	Player->SetTexture("DOUJUMP", "PLAYER_DOUJUMP", 1, 30.f, false);
	Player->SetTexture("SLIDING", "PLAYER_SLIDING", 1, 30.f, false);
	AddObject(OBJ_LAYER::PLAYER, Player);

	CPetObject* pet = CItemManager::GetInstance()->GetSelectItem();
	if (pet)
	{
		pet->SetTarget(Player);
		AddObject(OBJ_LAYER::PET, pet);
	}

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

void CStage1::Clear()
{
	CScene::Clear();
}

void CStage1::Update(float InDeltaTime)
{
	CScene::Update(InDeltaTime);
}