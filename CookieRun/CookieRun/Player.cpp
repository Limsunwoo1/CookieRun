#include "Player.h"
#include "KeyManager.h"
#include "CSceneManager.h"
#include "HpBar.h"
#include "ResourceManager.h"
#include "EventManager.h"
#include "CTexture.h"
#include "UtilMath.h"
#include "UtilLog.h"
#include "UtilString.h"
#include "UtilMath.h"

static bool playerJump = false;
static bool playerdoubleJump = false;
static const Vector2D gravity = Vector2D(0.0f, 9.8f);
static Vector2D Jmvel = Vector2D(0.0f, -2.5f);
static Vector2D Dmvel = Vector2D(0.0f, -2.5f);

CPlayer::CPlayer() : CAnimationObject(Vector2D{ 100, 100 }, Vector2D{ 50, 50 }),
HP(nullptr),
delta(2.f),
diving(false),
CurCollsion(false)
{
	mVel = Vector2D(0.0f, 2.5f);
}

CPlayer::CPlayer(Vector2D InVector, Vector2D InScale) : CAnimationObject(Vector2D{ InVector.x , InVector.y }, Vector2D{ InScale.x, InScale.y }),
HP(nullptr),
delta(2.f),
diving(false),
CurCollsion(false)
{
	mVel = Vector2D(0.0f, 2.5f);
}

CPlayer::~CPlayer()
{

}

void CPlayer::Init()
{
	CAnimationObject::Init();

	SetAnimState("RUN");
}

void CPlayer::Update(float InDeltaTime)
{
	CAnimationObject::Update(InDeltaTime);
	delta += InDeltaTime;

	if (CheckDiving(InDeltaTime))
		return;

	const int Upspeed = 400;
	if (HP != nullptr && HP->GetGameStop())
	{
		SetAnimState("DEAD");
		SetScale(Vector2D(100, 100));
		SetCollisionScale(Vector2D(Scale.x * 0.8f, Scale.y * 0.8f));

		HP = nullptr;
		return;
	}
	else if (!HP)
	{
		/*mVel += gravity * InDeltaTime;
		Position += mVel * InDeltaTime * Upspeed;*/

		return;
	}

	if (KEY_STATE(KEY::SPACE) == KEY_STATE::TAB)
	{
		if (!playerJump)
		{
			playerJump = true;

			SetAnimState("JUMP");
			SetScale(Vector2D(90, 90));
			SetCollisionScale(Vector2D(Scale.x * 0.8f, Scale.y * 0.8f));
		}
		else if (playerJump)
		{
			playerdoubleJump = true;
		}
	}

	if (KEY_STATE(KEY::W) == KEY_STATE::TAB || KEY_STATE(KEY::W) == KEY_STATE::HOLD)
	{
		if (playerdoubleJump || playerJump)
		{

		}
		else
		{
			SetAnimState("SLIDING");
			SetScale(Vector2D(150, 50));
			SetCollisionScale(Vector2D(Scale.x * 0.8f, Scale.y * 0.8f));
		}
	}

	if (KEY_STATE(KEY::W) == KEY_STATE::AWAY)
	{
		if (playerdoubleJump || playerJump)
		{ 

		}
		else
		{
			SetAnimState("RUN");
			SetScale(Vector2D(100, 100));
			SetCollisionScale(Vector2D(Scale.x * 0.8f, Scale.y * 0.8f));
		}
	}

	if (playerJump || playerdoubleJump)
	{
		if (playerdoubleJump)
			DoubleJumpAction(InDeltaTime, Upspeed);
		else if (playerJump)
			JumpAction(InDeltaTime, Upspeed);

		return;
	}

	mVel += gravity * InDeltaTime;
	Position += mVel * InDeltaTime * Upspeed;
}

void CPlayer::Collision(const CObject* InOtherObject)
{
	CObject::Collision(InOtherObject);

	if (diving)
		return;

	if ((InOtherObject->GetObjectLayer() == OBJ_LAYER::FOOTHOLD) && (Position.y < InOtherObject->GetPosition().y))
	{
		if (playerJump)
		{
			playerJump = false;
			Jmvel.y = -2.5f;
		}
		if (playerdoubleJump)
		{
			playerdoubleJump = false;
			Dmvel.y = -2.5f;
		}

		if (CurAnimName == "SLIDING")
		{
			Position.y = InOtherObject->GetPosition().y - (InOtherObject->GetScale().y * 0.63f);
			mVel = Vector2D(0.0f, 2.5f);
			return;
		}

		if (CurAnimName == "RUN")
		{

		}
		else if(CurAnimName == "DEAD")
		{
		/*	Position.y = InOtherObject->GetPosition().y - (InOtherObject->GetScale().y * 0.75f);
			mVel = Vector2D(0.0f, 0.0f);*/
			return;
		}
		else
		{
			SetAnimState("RUN");
			SetScale(Vector2D(100, 100));
			SetCollisionScale(Vector2D(Scale.x * 0.9f, Scale.y * 0.9f));
		}

		Position.y = InOtherObject->GetPosition().y - (InOtherObject->GetScale().y * 0.75f);
		mVel = Vector2D(0.0f, 2.5f);
		return;
	}
	else if (delta > 2.0f)
	{
		if (!HP)
			return;

		if (InOtherObject->GetObjectLayer() == OBJ_LAYER::OBSTACLE)
		{
			Vector2D DeleteHP = HP->GetScale();
			DeleteHP.x -= (HP->GetDynamic_Width() * 30);
			HP->SetScale(DeleteHP);

			delta -= 2.0f;

			return;
		}
	}

	if (InOtherObject->GetObjectLayer() == OBJ_LAYER::OBSTACLE)
	{
		if (delta < 2.0f)
		{
			CurCollsion = true;
		}
	}
}

void CPlayer::Render(HDC InHdc)
{
	if (CurCollsion)
	{
		static int cnt = 0;
		if (cnt % 2 == 0)
		{
			CAnimationObject::Render(InHdc);
		}

		if (cnt >= 500)
		{
			CurCollsion = false;
			cnt = 0;
			return;
		}
		cnt++;
		return;
	}
	CAnimationObject::Render(InHdc);
}

void CPlayer::JumpAction(float InDeltaTime, int Speed)
{
	Jmvel += gravity * InDeltaTime;
 	Position += Jmvel * InDeltaTime * (float)Speed;
}

void CPlayer::DoubleJumpAction(float InDeltaTime, int Speed)
{
	Dmvel += gravity * InDeltaTime ;
	Position += Dmvel * InDeltaTime * (float)Speed;
}

bool CPlayer::CheckDiving(float InDeltaTime)
{
	if (Position.y > 1000)
	{
		diving = true;

		mVel = Vector2D(0.0f, -10.0f);
	}

	if (diving)
	{
		if (Position.y < 400)
		{
			mVel = Vector2D(0.0f, 0.1f);
			diving = false;
			return diving;
		}

		Position += UtilMath::Normalize(mVel) * InDeltaTime * 500;
	}

	return diving;
}