#include "CShop.h"
#include "PetObject.h"
#include "CItemManager.h"
#include "BuyButton.h"
#include "CScoreBord.h"
#include "CSceneManager.h"
#include "CTitleScene.h"
#include "EventManager.h"
#include "CBankManager.h"
#include "UtilLog.h"
#include "UtilString.h"
#include <map>
CShop::CShop()
{
	SeleteItem = nullptr;
	Money = nullptr;
	SeletItemName = "NONE";
	xPos = 150;
}

CShop::~CShop()
{

}

void CShop::Init()
{
	CSpriteObject* BackGround = new CSpriteObject();
	BackGround->SetPosition(Vector2D(400, 400));
	BackGround->SetTexture("SHOPMAIN");
	AddObject(OBJ_LAYER::BACKGROUND, BackGround);

	CButton* ExitBUtton = new CButton(Vector2D{ 750,200 }, Vector2D{ 50,50 });
	ExitBUtton->SetTexture("EXIT");
	ExitBUtton->SetButtonFunc(BUTTON_STATE::LBUTTON_RELEASE, Exit);
	AddObject(OBJ_LAYER::UI, ExitBUtton);

	if (CBankManager::GetInstance()->GetScore())
	{
		Money = CBankManager::GetInstance()->GetScore();
		Money->SetPosition(Vector2D{ 600,200 });
		Money->SetSaveScore(CBankManager::GetInstance()->GetMoney());
		Money->ReSetScore();

		int i = Money->GetSaveScore();
		LOG(STRING("%d", i));
	}

	///////////////////////////////////////////////////////////////////////////////
	std::map<String,CPetObject*> InitVct = CItemManager::GetInstance()->GetItemList();

	for (auto iter : InitVct)
	{
		mItemList[iter.first] = iter.second;

		CBuyButton* PetButton = new CBuyButton(Vector2D{ xPos,550 }, Vector2D{ 50,50 });
		PetButton->SetTexture("BUY");
		PetButton->SetClickTexture("CLICKBUY");
		PetButton->SetItemName(iter.first);
		xPos += 240;

		if (iter.second->GetPrice() == 0)
		{
			PetButton->SetTexture("CLICKBUY");
			PetButton->SetClickTexture("CLICKBUY");
		}

		AddObject(OBJ_LAYER::UI, PetButton);
	}
	xPos = 150;
}

void CShop::Clear()
{

}

void CShop::Update(float InDeltaTime)
{
	CScene::Update(InDeltaTime);
	Money->Update(InDeltaTime);
	/*std::map<String, CPetObject*> InitVct = CItemManager::GetInstance()->GetItemList();
	for (auto iter : InitVct)
	{
		
	}*/
}

void CShop::Render(HDC InHdc)
{
	CScene::Render(InHdc);
	Money->Render(InHdc);
}

void CShop::Exit()
{
	CTitleScene* Title = new CTitleScene();
	CEventManager::GetInstance()->ChangeSceneEvent(Title);
}