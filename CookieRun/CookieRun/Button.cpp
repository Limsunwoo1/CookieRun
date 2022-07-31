#include "Button.h"
#include "CTexture.h"
CButton::CButton(Vector2D InPosition, Vector2D InScale)
	: CUI(InPosition, InScale)
{
	for (int i = 0; i < (int)BUTTON_STATE::MAX; ++i)
	{
		ButtonFuncPtr[i] = nullptr;
	}
	ClickTexture = "NONE";
}

CButton::~CButton()
{
	for (int i = 0; i < (int)BUTTON_STATE::MAX; ++i)
	{
		ButtonFuncPtr[i] = nullptr;
	}
}

void CButton::Render(HDC InHdc)
{
	//CSpriteObject::Render(InHdc);
	TransparentBlt(InHdc,
		(int)Position.x - (Texture->GetWidth() * 0.5f),
		(int)Position.y - (Texture->GetHeight() * 0.5f),
		Texture->GetWidth(),
		Texture->GetHeight(),
		Texture->GetHdc(),
		0,
		0,
		Texture->GetWidth(),
		Texture->GetHeight(),
		RGB(255, 0, 255));
	// c_str() : vector<char> ������ string ������ char const* ���·� ��ȯ����
	TextOutA(InHdc, (int)(Position.x - (ButtonText.size() * 5.f)), (int)(Position.y), ButtonText.c_str(), (int)ButtonText.size());
	// ��Ʈ���� Ư¡�� �ٸ��� ���� ����� ���ĺ����� �۾��� ���̰� �ٸ�
}

void CButton::MouseFirstOn()
{

}

void CButton::MouseOn()
{

}

void CButton::MouseFirstOff()
{

}

void CButton::MouseLButtonPress()
{
	if (ClickTexture != "NONE")
		SetTexture(ClickTexture);

	if (ButtonFuncPtr[(int)BUTTON_STATE::LBUTTON_PRESS])
		ButtonFuncPtr[(int)BUTTON_STATE::LBUTTON_PRESS]();
}

void CButton::MouseLButtonRelease()
{
	if (ButtonFuncPtr[(int)BUTTON_STATE::LBUTTON_RELEASE])
		ButtonFuncPtr[(int)BUTTON_STATE::LBUTTON_RELEASE]();

	//LOG_FIXME("ũ���� �ڵ鷯 Ȯ�� �ڵ� Ȯ�������� ���� �ʼ�");
	/*CButton* a = nullptr;
	a->SetPosition(Vector2D());*/

	//LOG_FIXME("�ݽ��� ���� �ڵ� Ȯ�������� ���� �ʼ�");
	//LOGER->AddCallStackLog();
}

void CButton::MouseRButtonPress()
{
	if (ButtonFuncPtr[(int)BUTTON_STATE::RBUTTON_PRESS])
		ButtonFuncPtr[(int)BUTTON_STATE::RBUTTON_PRESS]();
}

void CButton::MouseRButtonRelease()
{
	if (ButtonFuncPtr[(int)BUTTON_STATE::RBUTTON_RELEASE])
		ButtonFuncPtr[(int)BUTTON_STATE::RBUTTON_RELEASE]();
}