#include "CBankManager.h"
#include "UtilLog.h"
#include <iostream>
#include "Define.h"
#include <fstream>

using namespace std;

CBankManager::CBankManager()
{
	Money = 0;
	TextureCount = 0;

	RanderPos = Vector2D(700, 100);
	RanderSca = Vector2D(0, 0);
}
CBankManager::~CBankManager()
{

}

void CBankManager::Init()
{
	FILE_OUTPUT(Buff);
	LOG(Buff);
}

void CBankManager::Update(float InDeltaTIme)
{
	if (Money < 0)
	{
		Money = 0;
	}

}

void CBankManager::Render(HDC Inhdc)
{
	for (int i = TextureCount; i < 0; i--)
	{
		/*TransparentBlt(Inhdc,
			(int)100 - (Texture->GetWidth() * 0.5f),
			(int)100 - (Texture->GetHeight() * 0.5f),
			Texture->GetWidth(),
			Texture->GetHeight(),
			Texture->GetHdc(),
			0,
			0,
			Texture->GetWidth(),
			Texture->GetHeight(),
			RGB(255, 0, 255));*/
	};
}