#include "BuyButton.h"
#include "CItemManager.h"
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
	CButton::MouseLButtonPress();
	this->SetTexture(ClickTexture);
	BuyButton();
}

void CBuyButton::BuyButton()
{
	CItemManager::GetInstance()->SetBuyItem(ITemName);
}