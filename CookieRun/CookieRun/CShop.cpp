#include "CShop.h"
#include "PetObject.h"
#include "CItemManager.h"
#include "BuyButton.h"
#include <map>
CShop::CShop()
{
	SeleteItem = nullptr;
	SeletItemName = "NONE";
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

	///////////////////////////////////////////////////////////////////////////////
	std::map<String,CPetObject*> InitVct = CItemManager::GetInstance()->GetItemList();

	static int xPos = 150;
	for (auto iter : InitVct)
	{
		mItemList[iter.first] = iter.second;

		CBuyButton* PetButton = new CBuyButton(Vector2D{ xPos,550 }, Vector2D{ 50,50 });
		PetButton->SetTexture("BUY");
		PetButton->SetClickTexture("CLICKBUY");
		PetButton->SetItemName(iter.first);
		xPos += 250;

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
	std::map<String, CPetObject*> InitVct = CItemManager::GetInstance()->GetItemList();
	for (auto iter : InitVct)
	{
		if (iter.second->GetPrice() == 0)
		{

		}
	}
}