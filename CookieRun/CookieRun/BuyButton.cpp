#include "BuyButton.h"
#include "CItemManager.h"
#include "CBankManager.h"
#include "PetObject.h"
CBuyButton::CBuyButton(Vector2D InPos, Vector2D InSca) : CButton(Vector2D{ InPos.x, InPos.y}, Vector2D{ InSca.x, InSca.y })
{
	ITemName = "None";
}

CBuyButton::~CBuyButton()
{

}

void CBuyButton::MouseLButtonPress()
{
	CPetObject* Pet = CItemManager::GetInstance()->FindItem(ITemName);
	int change = CBankManager::GetInstance()->GetMoney();
	if (change - Pet->GetPrice() < 0)
		return;
	else if (change - Pet->GetPrice() >= 0)
	{
		CBankManager::GetInstance()->SetMoney(change - Pet->GetPrice());

		if (CBankManager::GetInstance()->GetScore())
		{
			CBankManager::GetInstance()->GetScore()->ReSetScore();
		}
	}

	CButton::MouseLButtonPress();
	this->SetTexture(ClickTexture);
	BuyButton();
}

void CBuyButton::BuyButton()
{
	CItemManager::GetInstance()->SetBuyItem(ITemName);
}