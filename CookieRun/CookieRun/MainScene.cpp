#include "MainScene.h"
#include "IntroDysPlay.h"
#include "CGameStartScene.h"
#include "EventManager.h"
#include "CSceneManager.h"
#include "KeyManager.h"

CMainScene::CMainScene() : CScene(),
Direction(false)
{
	dev = nullptr;
	kakao = nullptr;

	delta = 0.f;
	setalph = 0;
}

CMainScene::~CMainScene()
{
	Clear();
}

void CMainScene::Init()
{
	/*CIntroDysPlay* titelscene = new CIntroDysPlay();
	titelscene->SetTexture("MAINGAME");
	AddObject(OBJ_LAYER::BACKGROUND, titelscene);*/

	CIntroDysPlay* devesis = new CIntroDysPlay();
	devesis->SetTexture("DEVSIS");
	AddObject(OBJ_LAYER::BACKGROUND, devesis);

	CIntroDysPlay* kakao = new CIntroDysPlay();
	kakao->SetTexture("KAKAO");
	AddObject(OBJ_LAYER::BACKGROUND, kakao);

	MainSceneIntro(devesis, kakao);
}

void CMainScene::Clear()
{
	ClearObject();
}

void CMainScene::Update(float InDeltaTime)
{
	delta += InDeltaTime;

	if (delta > 0.001f)
	{
		if (!Direction)
		{
			if (setalph >= 255)
				Direction = true;
			setalph++;
		}
		else if (Direction)
		{
			if (setalph <= 0)
				Direction = false;
			setalph--;
		}
		delta -= 0.001f;
	}
	
	if (dev)
		dev->Setalpha(setalph);
	else if (kakao)
		kakao->Setalpha(setalph);
		
	if ((Direction) && (setalph <= 0))
		if (dev)
			dev = nullptr;
		else if (kakao)
			kakao = nullptr;

	if ((!Direction && !kakao) || (KEY_STATE(KEY::ESC) == KEY_STATE::AWAY))
	{
		CGameStartScene* start = new CGameStartScene();
		CEventManager::GetInstance()->ChangeSceneEvent(start);  // 게임 시작페이지 생성
	}
}

void CMainScene::MainSceneIntro(CIntroDysPlay* Indev, CIntroDysPlay* Inkakao)
{
	dev = Indev;
	kakao = Inkakao;
}