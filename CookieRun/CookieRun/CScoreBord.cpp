#include "CScoreBord.h"
#include "CTexture.h"

CScoreBord::CScoreBord() : CUI(Vector2D {650,50}, Vector2D {50,50}),
MaxCount(1),
Score(0),
SaveScore(0)
{
	FilePathList.push_back("0");
	FilePathList.push_back("1");
	FilePathList.push_back("2");
	FilePathList.push_back("3");
	FilePathList.push_back("4");
	FilePathList.push_back("5");
	FilePathList.push_back("6");
	FilePathList.push_back("7");
	FilePathList.push_back("8");
	FilePathList.push_back("9");

	bufsize = 20;

	for (int i = 0; i < bufsize; ++i)
	{
		buf[i] = 0;
	}

	IntervalPosX = Position.x;
}

CScoreBord::CScoreBord(Vector2D InPos, Vector2D InScale) : CUI(Vector2D{ InPos.x,InPos.y }, Vector2D{ InScale.x,InScale.y }),
MaxCount(1),
Score(0),
SaveScore(0)
{
	FilePathList.push_back("0");
	FilePathList.push_back("1");
	FilePathList.push_back("2");
	FilePathList.push_back("3");
	FilePathList.push_back("4");
	FilePathList.push_back("5");
	FilePathList.push_back("6");
	FilePathList.push_back("7");
	FilePathList.push_back("8");
	FilePathList.push_back("9");

	bufsize = 20;

	for (int i = 0; i < bufsize; ++i)
	{
		buf[i] = 0;
	}

	IntervalPosX = Position.x;
}

CScoreBord::~CScoreBord()
{
	FilePathList.clear();
}

void CScoreBord::Update(float InDeltaTime)
{
	//static float delt = 0.f;
	//delt += InDeltaTime;
	//if (delt > 0.001f)
	//{
	//	Score++;
	//	delt = -0.001f;
	//}

	buf[0] = Score;

	if (Score >= 10)
	{
		Score -= 10;
		buf[0] = Score;
		buf[1]++;

		for (int i = 1; i < bufsize; ++i)
		{
			if (buf[i] >= 10)
			{
				buf[i] -= 10;
				buf[i + 1]++;
			}
		}

		for (int i = (bufsize - 1); 0 < i; --i)
		{
			if (buf[i] > 0)
			{
				MaxCount = i + 1;
				if (MaxCount >= bufsize)
				{
					MaxCount = bufsize;
				}
				return;
			}
		}
	}
	//점수에 상승에 따라 높아지는 숫자의 비례식 세우기
}

void CScoreBord::Render(HDC InHdc)
{
	IntervalPosX = Position.x;

	{
		SetTexture("JELLY");

		TransparentBlt(InHdc,
			(int)IntervalPosX - (int)(Texture->GetWidth() * 0.5f),
			(int)Position.y - (int)(Texture->GetHeight() * 0.5f),
			Texture->GetWidth(),
			Texture->GetHeight(),
			Texture->GetHdc(),
			0,
			0,
			Texture->GetWidth(),
			Texture->GetHeight(),
			RGB(255, 0, 255));
	}

	IntervalPosX = IntervalPosX - ((Texture->GetWidth() * 0.5f) * 4.f);

	for(int i = 0;i < MaxCount; ++i)
	{
		SetTexture(FilePathList[buf[i]]);

		TransparentBlt(InHdc,
			(int)IntervalPosX - (int)(Texture->GetWidth() * 0.5f),
			(int)Position.y - (int)(Texture->GetHeight() * 0.5f),
			Texture->GetWidth(),
			Texture->GetHeight(),
			Texture->GetHdc(),
			0,
			0,
			Texture->GetWidth(),
			Texture->GetHeight(),
			RGB(255, 0, 255));

		IntervalPosX = IntervalPosX - ((Texture->GetWidth() * 0.5f) * 2.f);
	}
}

void CScoreBord::ReSetScore()
{
	for (int i = 0; i < bufsize; ++i)
	{
		buf[i] = 0;
	}
	Score = 0;
	MaxCount = 1;
	
	for (int i = 0; i < SaveScore; ++i)
	{
		Score++;

		buf[0] = Score;

		if (Score > 9)
		{
			Score = 0;
			buf[0] = Score;
			buf[1]++;

			for (int i = 1; i < bufsize; ++i)
			{
				if (buf[i] >= 10)
				{
					buf[i] -= 10;
					buf[i + 1]++;
				}
			}

			for (int i = (bufsize - 1); 0 < i; --i)
			{
				if (buf[i] > 0)
				{
					MaxCount = i + 1;
					if (MaxCount >= bufsize)
					{
						MaxCount = bufsize;
					}
					break;
				}
			}
		}
	}
}