#include "SelectButton.h"
#include "CItemManager.h"
#include "PetObject.h"
CSelectButton::CSelectButton(Vector2D InPos, Vector2D InSca) : CButton(Vector2D{ InPos.x, InPos.y }, Vector2D{ InSca.x, InSca.y })
{
	ITemName = "None";
	trackingItem = nullptr;
}

CSelectButton::~CSelectButton()
{

}

void CSelectButton::Update(float InDeltaTime)
{
	CButton::Update(InDeltaTime);
	
	if (!trackingItem)
		return;

	if (!trackingItem->GetSelectItem())
		this->SetTexture("SELECTBUTTON");
}

void CSelectButton::MouseLButtonPress()
{
	CButton::MouseLButtonPress();
	this->SetTexture("CLICKBUY");

	CItemManager::GetInstance()->SetSelectItem(ITemName);
	trackingItem = CItemManager::GetInstance()->FindItem(ITemName);
	CItemManager::GetInstance()->SettingSelectItem(ITemName);
}