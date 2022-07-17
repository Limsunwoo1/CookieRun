#include "SpriteObject.h"
#include "ResourceManager.h"
#include "CTexture.h"

CSpriteObject::CSpriteObject()
: CObject(Vector2D{ 100, 100 }, Vector2D{ 50, 50 })
, Texture(nullptr)
{

}

CSpriteObject::CSpriteObject(Vector2D InPosition, Vector2D InScale)
: CObject(Vector2D{ InPosition.x , InPosition.y }, Vector2D{ InScale.x, InScale.y })
, Texture(nullptr)
{

}

CSpriteObject::~CSpriteObject()
{

}

void CSpriteObject::Init()
{
	CObject::Init();
}

void CSpriteObject::Update(float InDeltaTime)
{
	CObject::Update(InDeltaTime);
}

void CSpriteObject::LateUpdate(float InDeltaTime)
{
	CObject::LateUpdate(InDeltaTime);
}

void CSpriteObject::Render(HDC InHdc)
{
	if (!Texture)
		CObject::Render(InHdc);

	// ���İ� == ����
	// �����ϰ� ���°�, �������ϰ� ���°Ÿ� ���ĺ��� �̶�� �Ѵ�
	// ������ ���´ٴ� ������ �ǹ�

	// bmp ������ ���� ������ 24��Ʈ¥��
	// R : 8��Ʈ
	// G : 8��Ʈ
	// B : 8��Ʈ 0 ~ 255 ��
	// 32 ��Ʈ�� ���⿡ A : 8 ��Ʈ�� �߰��� �� ( ���İ� )

	// 32��Ʈ bmp �� bf.AlphaFormat = AC_SRC_ALPHA
		// 24��Ʈ bmp �� bf.AlphaFormat = 0

	BLENDFUNCTION bf = {};
	bf.BlendOp = AC_SRC_OVER;
	bf.BlendFlags = 0;
	bf.AlphaFormat = AC_SRC_ALPHA;
	bf.SourceConstantAlpha = 255;

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

	// Ư�� ������ ������ �ƿ� �׸��� �ʴ´�
/*	TransparentBlt(InHdc,
		Position.x - (Texture->GetWidth() * 0.5f),
		Position.y - (Texture->GetHeight() * 0.5f),
		Texture->GetWidth(),
		Texture->GetHeight(),
		Texture->GetHdc(),
		0,
		0,
		Texture->GetWidth(),
		Texture->GetHeight(),
		RGB(0, 0, 0));*/

		//BitBlt(InHdc,
		//	Position.x - (Texture->GetWidth() * 0.5f),
		//	Position.y - (Texture->GetHeight() * 0.5f),
		//	//Scale.x,
		//	//Scale.y,
		//	Texture->GetWidth(),
		//	Texture->GetHeight(),
		//	Texture->GetHdc(),
		//	0,
		//	0,
		//	SRCCOPY);
}

void CSpriteObject::SetTexture(CTexture* InTexture)
{
	Texture = InTexture;

	SetScale(Vector2D((int)Texture->GetWidth(), (int)Texture->GetHeight()));
	SetCollisionScale(Vector2D((int)Texture->GetWidth(), (int)Texture->GetHeight()));
}

void CSpriteObject::SetTexture(const std::string& InFilePath)
{
	SetTexture(CResourceManager::GetInstance()->FindTexture(InFilePath));
}