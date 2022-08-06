#include "CInventory.h"
#include "SpriteObject.h"
#include "SelectButton.h"
#include "BuyButton.h"
#include "PetObject.h"
#include "CTitleScene.h"
#include "EventManager.h"
#include "CItemManager.h"
#include <map>

CInventory::CInventory() : CScene()
{
	XPos = 150;
}

CInventory::~CInventory()
{
	CScene::Clear();
}

void CInventory::Init()
{
	CSpriteObject* BackGround = new CSpriteObject();
	BackGround->SetPosition(Vector2D(400, 400));
	BackGround->SetTexture("IVENTORYMAIN");
	AddObject(OBJ_LAYER::BACKGROUND, BackGround);

	CButton* ExitBUtton = new CButton(Vector2D{ 700,200 }, Vector2D{ 50,50 });
	ExitBUtton->SetTexture("EXIT");
	ExitBUtton->SetButtonFunc(BUTTON_STATE::LBUTTON_RELEASE, Exit);
	AddObject(OBJ_LAYER::UI, ExitBUtton);
	///////////////////////////////////////////////////////////////////////////
	std::map<String, CPetObject*> InitVct = CItemManager::GetInstance()->GetItemList();

	for (auto iter : InitVct)
	{
		if (iter.second->GetPrice() == 0)
		{
			CSelectButton* SeletecButton = new CSelectButton(Vector2D{ XPos,550 }, Vector2D{ 50,50 });
			if (iter.second->GetSelectItem())
			{
				SeletecButton->SetTexture("CLICKBUY");
				SeletecButton->SetClickTexture("CLICKBUY");
			}
			else
			{
				SeletecButton->SetTexture("SELECTBUTTON");
				SeletecButton->SetClickTexture("CLICKBUY");
			}
			SeletecButton->SetITemName(iter.first);
			SeletecButton->SetTrackingItem(iter.second);

			AddObject(OBJ_LAYER::UI, SeletecButton);
		}
		XPos += 240;
	}
	XPos = 150;
}

void CInventory::Clear()
{
	CScene::Clear();
}

void CInventory::Update(float InDeltaTime)
{
	CScene::Update(InDeltaTime);
}

void CInventory::Exit()
{
	CTitleScene* Title = new CTitleScene();
	CEventManager::GetInstance()->ChangeSceneEvent(Title);
}