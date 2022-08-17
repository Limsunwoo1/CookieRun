#include "CSceneManager.h"
#include "CScene.h"
#include "CTitleScene.h"
#include "MainScene.h"
#include "Func.h"
#include "EventManager.h"
#include <random>

//random_device rd;
//mt19937 gen(rd());
//uniform_int_distribution<int> dis(0, 980);
//uniform_int_distribution<int> Dis(50, 150);


CSceneManager::CSceneManager()
: CurScene(nullptr),
ReGame(nullptr)
{

}

CSceneManager::~CSceneManager()
{
	CurScene->Clear();
	delete CurScene;
	CurScene = nullptr;

	if (ReGame)
	{
		ReGame->Clear();
		delete ReGame;
		ReGame = nullptr;
	}
}

void CSceneManager::Init()
{
	CurScene = new CMainScene();
	CurScene->Init();
}

void CSceneManager::Update(float InDeltaTime)
{
	if (ReGame)
	{
		ReGame->Update(InDeltaTime);
		return;
	}

	CurScene->Update(InDeltaTime);
}

void CSceneManager::LateUpdate(float InDeltaTime)
{
	CurScene->LateUpdate(InDeltaTime);
}

void CSceneManager::Render(HDC InHdc)
{
	CurScene->Render(InHdc);

	if (ReGame)
		ReGame->Render(InHdc);

#ifdef SHOW_COLLISION
	CurScene->CollisionRender(InHdc);
#endif

}

void CSceneManager::SetCurScene(CScene* InNewScene)
{
	if (CurScene)
	{
		CurScene->Clear();
		delete CurScene;
	}

	CEventManager::GetInstance()->Clear();

	CurScene = InNewScene;
	CurScene->Init();
}

void CSceneManager::AddObject(OBJ_LAYER InLayer, CObject* InObject)
{
	CurScene->AddObject(InLayer, InObject);
}

void CSceneManager::DeleteObject(OBJ_LAYER InLayer, CObject* InObject)
{
	CurScene->DeleteObject(InLayer, InObject);
}

const std::vector<CObject*>& CSceneManager::Get_Object(OBJ_LAYER InLayer)
{
	return CurScene->Get_Object(InLayer);
}

void CSceneManager::SetReGame(CScene* InScene)
{
	ReGame = InScene;
	ReGame->Init();
}

void CSceneManager::ClearReGame()
{
	if (ReGame)
	{
		ReGame->Clear();
		delete ReGame;
		ReGame = nullptr;
	}
}