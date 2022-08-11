#include "CStage1.h"
#include "Func.h"
#include "Button.h"
#include "Player.h"
#include "HpBar.h"
#include "PetObject.h"
#include "CGroundObject.h"
#include "CScoreBord.h"
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

	CGroundObject* Stage1Road = new CGroundObject();
	Stage1Road->SetPosition(Vector2D(400, 700));
	Stage1Road->SetTexture("STAGE1_ROAD");
	AddObject(OBJ_LAYER::FOOTHOLD, Stage1Road);

	Stage1Road = new CGroundObject();
	Stage1Road->SetPosition(Vector2D(600, 700));
	Stage1Road->SetTexture("STAGE1_ROAD");
	AddObject(OBJ_LAYER::FOOTHOLD, Stage1Road);

	Stage1Road = new CGroundObject();
	Stage1Road->SetPosition(Vector2D(800, 700));
	Stage1Road->SetTexture("STAGE1_ROAD");
	AddObject(OBJ_LAYER::FOOTHOLD, Stage1Road);

	Stage1Road = new CGroundObject();
	Stage1Road->SetPosition(Vector2D(1100, 700));
	Stage1Road->SetTexture("STAGE1_ROAD");
	AddObject(OBJ_LAYER::FOOTHOLD, Stage1Road);

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

	CScoreBord* score = new CScoreBord();
	AddObject(OBJ_LAYER::UI, score);

	CButton* Jelly = new CButton(Vector2D{(int)(score->GetPosition().x - 100) ,50},Vector2D{50,50});
	Jelly->SetTexture("JELLY");
	AddObject(OBJ_LAYER::UI, Jelly);  //jelly obj 추가 예정

	CPetObject* pet = CItemManager::GetInstance()->GetSelectItem();
	if (pet)
	{
		pet->SetTarget(Player);
		AddObject(OBJ_LAYER::PET, pet);
	}

	// UI는 충돌체크하면 로직이 꼬일수도 있음 체크해도 UI 끼리만 하도록 주의
	std::vector<OBJ_LAYER> checkLayerList;
	checkLayerList.push_back(OBJ_LAYER::PLAYER);
	CheckCollisionLayer[OBJ_LAYER::OBSTACLE] = checkLayerList;
	checkLayerList.push_back(OBJ_LAYER::PLAYER);
	CheckCollisionLayer[OBJ_LAYER::FOOTHOLD] = checkLayerList;

	LOG_TODO("로그 예시 코드 확인했으면 지워도 무방");
	LOG("일반 로그 테스트");
	WARN_LOG("경고 로그 테스트");
	ERROR_LOG("에러 로그 테스트");
	ETC1_LOG("커스텀 로그 테스트");
	LOG(STRING("문자열 포매팅 테스트 : %d !!!", 30));
}

void CStage1::Clear()
{
	CScene::Clear();
}

void CStage1::Update(float InDeltaTime)
{
	CScene::Update(InDeltaTime);
}