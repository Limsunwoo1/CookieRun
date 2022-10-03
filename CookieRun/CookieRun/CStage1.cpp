#include "CStage1.h"
#include "Func.h"
#include "Button.h"
#include "Player.h"
#include "HpBar.h"
#include "PetObject.h"
#include "CGroundObject.h"
#include "CScoreBord.h"
#include "SpriteObject.h"
#include "COBST.h"
#include "COutPutScore.h"
#include "CSceneManager.h"
#include "ResourceManager.h"
#include "EventManager.h"
#include "CItemManager.h"
#include "UtilLog.h"
#include "UtilString.h"
#include "CPAUSE.h"
#include "Loger.h"
#include "CJellyObject.h"
#include <string>
#include <fstream>

using namespace std;

CStage1::CStage1()
{
	mPlayer = nullptr;
	OutScore = nullptr;
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
	Player->SetPosition(Vector2D(200, 100));
	Player->SetScale(Vector2D(100, 100));
	Player->SetCollisionScale(Vector2D(Player->GetScale().x * 0.8f, Player->GetScale().y * 0.8f));
	Player->SetHP(Hp);
	Player->SetTexture("RUN", "PLAYER_RUN", 6, 30.f);
	Player->SetTexture("DEAD", "PLAYER_DEAD", 4, 5.f, false);
	Player->SetTexture("JUMP", "PLAYER_JUMP", 1, 30.f, false);
	Player->SetTexture("DOUJUMP", "PLAYER_DOUJUMP", 1, 30.f, false);
	Player->SetTexture("SLIDING", "PLAYER_SLIDING", 1, 30.f, false);

	mPlayer = Player;
	AddObject(OBJ_LAYER::PLAYER, Player);

	CScoreBord* score = new CScoreBord();
	OutScore = score;
	AddObject(OBJ_LAYER::UI, score);

	//CButton* Jelly = new CButton(Vector2D{(int)(score->GetPosition().x - 100) ,50},Vector2D{50,50});
	//Jelly->SetTexture("JELLY");
	//AddObject(OBJ_LAYER::UI, Jelly);  //jelly obj 추가 예정

	CButton* pause = new CButton(Vector2D{ 750,50 }, Vector2D{ 50,50 });
	pause->SetTexture("EXIT");
	pause->SetButtonFunc(BUTTON_STATE::LBUTTON_RELEASE, PAUSE);
	AddObject(OBJ_LAYER::UI, pause);

	CPetObject* pet = CItemManager::GetInstance()->GetSelectItem();
	if (pet)
	{
		pet->SetTarget(Player);
		AddObject(OBJ_LAYER::PET, pet);
	}

	static int x = 0;
	String st;
	int cnt = 1;
	ifstream readFile;
	readFile.open("TXT/Stage1.txt");
	if (!readFile.is_open())
	{
		LOG("파일 없음");
		return;
	}		
	while (!readFile.eof())
	{
		if (cnt >= 19)
		{
			cnt -= 18;
			x += 800;
		}

		getline(readFile, st);
		MapDesign(st, cnt, x, score);
		LOG(st)
		cnt++;
	}
	readFile.close();
	x = 0;

	// UI는 충돌체크하면 로직이 꼬일수도 있음 체크해도 UI 끼리만 하도록 주의
	std::vector<OBJ_LAYER> checkLayerList;
	checkLayerList.push_back(OBJ_LAYER::PLAYER);
	CheckCollisionLayer[OBJ_LAYER::OBSTACLE] = checkLayerList;
	checkLayerList.push_back(OBJ_LAYER::PLAYER);
	CheckCollisionLayer[OBJ_LAYER::FOOTHOLD] = checkLayerList;
	checkLayerList.push_back(OBJ_LAYER::PLAYER);
	CheckCollisionLayer[OBJ_LAYER::ITEM] = checkLayerList;
	checkLayerList.push_back(OBJ_LAYER::OBSTACLE);
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
	if (mPlayer->GetPlayerHP())
		CScene::Update(InDeltaTime);
	else
	{
		mPlayer->Update(InDeltaTime);

		static float deta = 0.0f;
		deta += InDeltaTime;
		
		if (deta > 3.0f)
		{
			deta = 0.0f;

			COutPutScore* Out = new COutPutScore();
			Out->Init(OutScore->GetSaveScore());

			int i = OutScore->GetSaveScore();
			LOG(STRING("%d", i));
			EventInfo SetScene;
			SetScene.Type = EVENT_TYPE::CHANGE_SCENE;
			SetScene.Parameter = Out;

			CEventManager::GetInstance()->AddEvent(SetScene);
		}
	}
}

void CStage1::Render(HDC Inhdc)
{
	CScene::Render(Inhdc);
}

void CStage1::MapDesign(String Instr, int cnt, int x, CScoreBord* InSCor)
{
	float height = 800.f / 17.f;
	float width = 800.f / 20.f;
	CGroundObject* Stage1Road;
	for (int i = 0; i < Instr.size(); i++)
	{
		switch (Instr[i])
		{
		case '1':
		{
			Stage1Road = new CGroundObject();
			Stage1Road->SetPosition(Vector2D(((width * (i + 1)) + x), height * cnt));
			Stage1Road->SetTexture("STAGE1_ROAD1");
			AddObject(OBJ_LAYER::FOOTHOLD, Stage1Road);
			break;
		}
		case'2':
		{
			COBST* obs2 = new COBST();
			obs2->SetPosition(Vector2D(((width * (i + 1)) + x), height * cnt));
			obs2->SetTexture("STAGE1_ROAD2");
			AddObject(OBJ_LAYER::OBSTACLE, obs2);
			break;
		}
		case'3':
		{
			COBST* obs3 = new COBST();
			obs3->SetPosition(Vector2D(((width * (i + 1)) + x), height * cnt));
			obs3->SetTexture("STAGE1_ROAD3");
			AddObject(OBJ_LAYER::OBSTACLE, obs3);
			break;
		}
		case'4':
		{
			COBST* obs4 = new COBST();
			obs4->SetPosition(Vector2D(((width * (i + 1)) + x), height * cnt));
			obs4->SetTexture("STAGE1_ROAD4");
			AddObject(OBJ_LAYER::OBSTACLE, obs4);
			break;
		}
		case'5':
		{
			COBST* obs5 = new COBST();
			obs5->SetPosition(Vector2D(((width * (i + 1)) + x), height * cnt));
			obs5->SetTexture("STAGE1_ROAD5");
			AddObject(OBJ_LAYER::OBSTACLE, obs5);
			break;
		}
		case'6':
		{
			COBST* obs6 = new COBST();
			obs6->SetPosition(Vector2D(((width * (i + 1)) + x), height * cnt));
			obs6->SetTexture("STAGE1_ROAD6");
			AddObject(OBJ_LAYER::OBSTACLE, obs6);
			break;
		}
		case'7':
		{
			COBST* obs7 = new COBST();
			obs7->SetPosition(Vector2D(((width * (i + 1)) + x), height * cnt));
			obs7->SetTexture("STAGE1_ROAD7");
			AddObject(OBJ_LAYER::OBSTACLE, obs7);
			break;
		}
		case'9':
		{
			CJellyObject* jelly = new CJellyObject();
			jelly->SetPosition(Vector2D(((width * (i + 1)) + x), height * cnt));
			jelly->SetTexture("JELLY");
			jelly->SetScore(InSCor);
			AddObject(OBJ_LAYER::ITEM, jelly);
			break;
		}
		default:
		{
			break;
		}
		}
	}
}

void CStage1::PAUSE()
{
	CPAUSE* pause = new CPAUSE();
	CSceneManager::GetInstance()->SetReGame(pause);
}