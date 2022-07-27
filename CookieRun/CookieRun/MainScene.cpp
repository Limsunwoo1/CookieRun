#include "MainScene.h"
#include "IntroDysPlay.h"
#include "CSceneManager.h"

CMainScene::CMainScene() : CScene(),
Direction(false)
{
	dev = nullptr;
	kakao = nullptr;
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
	static float delta = 0.f;
	static int setalph = 0;
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
		dev->Setalph(setalph);
	else if (kakao)
		kakao->Setalph(setalph);
		
	if ((Direction) && (setalph <= 0))
		if (dev)
			dev = nullptr;
		else if (kakao)
			kakao = nullptr;

	/*if (!Direction && !kakao)
		CSceneManager::SetCurScene();*/
}

void CMainScene::MainSceneIntro(CIntroDysPlay* Indev, CIntroDysPlay* Inkakao)
{
	dev = Indev;
	kakao = Inkakao;
}