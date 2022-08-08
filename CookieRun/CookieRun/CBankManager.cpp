#include "CBankManager.h"
#include "UtilLog.h"
#include <iostream>
#include "Define.h"
#include <fstream>

using namespace std;

CBankManager::CBankManager()
{
	Money = 300;
	TextureCount = 0;

	RanderPos = Vector2D(700, 100);
	RanderSca = Vector2D(0, 0);
}
CBankManager::~CBankManager()
{

}

void CBankManager::Init()
{
	FILE_OUTPUT(Buff, "NumBerList.txt");
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
	
}