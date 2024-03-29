#include "HpBar.h"
#include "CTexture.h"

CHpBar::CHpBar() : CUI(Vector2D(100, 100), Vector2D(600, 50)),
mDynamic_Width(0.f),
GameStop(false)
{

}

CHpBar::~CHpBar()
{

}

void CHpBar::Update(float InDeltaTime)
{
    static float Delta = 0.f;
    Delta += InDeltaTime;
	if (GameStop)
		return;
	if (Scale.x <= 30) // 최소 UI는 표시
	{
		Scale.x = 30;
		GameStop = true;
		return;
	}

    if (Delta > 0.1f)
    {
        Scale.x -= mDynamic_Width;
        Delta -= 0.1f;
    }

}

void CHpBar::Render(HDC Inhdc)
{
	BLENDFUNCTION bf = {};
	bf.BlendOp = AC_SRC_OVER;
	bf.BlendFlags = 0;
	bf.AlphaFormat = 0;
	bf.SourceConstantAlpha = 255;

	AlphaBlend(Inhdc,
		(int)Position.x,
		(int)Position.y,
		(int)Scale.x,
		(int)Scale.y,
		Texture->GetHdc(),
		0,
		0,
		(int)Scale.x,
		(int)Scale.y,
		bf);

	//HBRUSH White = CreateSolidBrush(RGB(255, 255, 255));
	//SelectObject(Inhdc, White);
	//Rectangle(Inhdc,
	//	(int)Position.x,
	//	(int)Position.y,
	//	(int)Scale.x,
	//	(int)Scale.y
	//);

	//DeleteObject(White);

}

void CHpBar::SetDynamic_Width()
{
    mDynamic_Width = Scale.x / 1000;
}