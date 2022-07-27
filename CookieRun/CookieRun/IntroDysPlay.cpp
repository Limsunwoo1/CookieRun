#include "IntroDysPlay.h"
#include "CTexture.h"

CIntroDysPlay::CIntroDysPlay() : CSpriteObject(Vector2D{400,400}, Vector2D{50,50}),
alph(0)
{

}

CIntroDysPlay::~CIntroDysPlay()
{

}

void CIntroDysPlay::Render(HDC InHdc)
{
	if (!Texture)
		CSpriteObject::Render(InHdc);

	BLENDFUNCTION bf = {};
	bf.BlendOp = AC_SRC_OVER;
	bf.BlendFlags = 0;
	bf.AlphaFormat = 0;
	bf.SourceConstantAlpha = alph;

	AlphaBlend(InHdc,
		(int)(Position.x - (Texture->GetWidth() * 0.5f)),
		(int)(Position.y - (Texture->GetHeight() * 0.5f)),
		Texture->GetWidth(),
		Texture->GetHeight(),
		Texture->GetHdc(),
		0,
		0,
		Texture->GetWidth(),
		Texture->GetHeight(),
		bf);
}