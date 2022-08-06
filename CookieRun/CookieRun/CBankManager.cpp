#include "CBankManager.h"

CBankManager::CBankManager()
{

}
CBankManager::~CBankManager()
{

}

void CBankManager::Init()
{
	Money = 300;
}

void CBankManager::Update(float InDeltaTIme)
{
	if (Money < 0)
	{
		Money = 0;
	}
}