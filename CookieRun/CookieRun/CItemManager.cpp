#include "CItemManager.h"
#include "PetObject.h"
#include "Typedef.h"
#include <map>

CItemManager::CItemManager()
{
	SelectItem = nullptr;
}
CItemManager::~CItemManager()
{
	for (auto iter = mItemList.begin(); iter != mItemList.end(); iter++)
	{
		delete iter->second;
	}
}

void CItemManager::Init()
{
	CPetObject* Chocopet = new CPetObject();
	Chocopet->SetPetName("Chocopet");
	Chocopet->SetPrice(100);
	Chocopet->SetTexture("CHOCOPET");
	Chocopet->SetTextureName("CHOCOPET");

	CPetObject* Dogpet = new CPetObject();
	Dogpet->SetPetName("Dogpet");
	Dogpet->SetPrice(200);
	Dogpet->SetTexture("DOGPET");
	Dogpet->SetTextureName("DOGPET");

	CPetObject* WaferPet = new CPetObject();
	WaferPet->SetPetName("WaferPet");
	WaferPet->SetPrice(300);
	WaferPet->SetTexture("WAFERPET");
	WaferPet->SetTextureName("WAFERPET");

	mItemList[Chocopet->GetPetName()] = Chocopet;
	mItemList[Dogpet->GetPetName()] = Dogpet;
	mItemList[WaferPet->GetPetName()] = WaferPet;
}

void CItemManager::Update(float InDeltaTime)
{

}

CPetObject* CItemManager::FindItem(String& InName)
{
	auto iter = mItemList.find(InName);
	if (iter == mItemList.end())
		return nullptr;

	return iter->second;
}

void CItemManager::SetSelectItem(String& InName)
{
	SelectItem = CItemManager::FindItem(InName);
}

void CItemManager::SetBuyItem(String& InName)
{
	BuyItem = CItemManager::FindItem(InName);
	BuyItem->SetPrice(0);
}

void CItemManager::SettingSelectItem(const String& InName)
{
	for (auto iter = mItemList.begin(); iter != mItemList.end(); iter++)
	{
		if (iter->second->GetPetName() == InName)
			iter->second->SetSelectItem(true);
		else
			iter->second->SetSelectItem(false);
	}
}