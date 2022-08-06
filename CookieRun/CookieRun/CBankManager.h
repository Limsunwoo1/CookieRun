#pragma once
#include "Define.h"

class CBankManager
{
	SINGLE(CBankManager)

private:
	MEMBER(int, Money)

public:
	void Init();
	void Update(float InDeltaTIme);
};

