#pragma once
#include "Define.h"
#include "CScoreBord.h"
#include "Typedef.h"
#include "framework.h"
#include <vector>
class CBankManager
{
	SINGLE(CBankManager)

private:
	MEMBER(int, Money)

	std::vector<String> FilePathList;
	int					TextureCount;
	CScoreBord*			Score;

	char				Buff[200];
	Vector2D			RanderPos;
	Vector2D			RanderSca;
public:
	void Init();
	void Update(float InDeltaTIme);
	void Render(HDC Inhdc);

	CScoreBord* GetScore() { return Score; };
};

