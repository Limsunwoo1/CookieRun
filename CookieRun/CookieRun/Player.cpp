#include "Player.h"
#include "KeyManager.h"
#include "CSceneManager.h"
#include "HpBar.h"
#include "ResourceManager.h"
#include "EventManager.h"
#include "CTexture.h"
#include "UtilMath.h"

static bool playerJump = false;
static bool playerdoubleJump = false;
static const Vector2D gravity = Vector2D(0.0f, 9.8f);
static Vector2D Jmvel = Vector2D(0.0f, -2.5f);
static Vector2D Dmvel = Vector2D(0.0f, -2.5f);

CPlayer::CPlayer() : CAnimationObject(Vector2D{ 100, 100 }, Vector2D{ 50, 50 }),
HP(nullptr)
{
	mVel = Vector2D(0.0f, 2.5f);
}

CPlayer::CPlayer(Vector2D InVector, Vector2D InScale) : CAnimationObject(Vector2D{ InVector.x , InVector.y }, Vector2D{ InScale.x, InScale.y }),
HP(nullptr)
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

	if (HP != nullptr && HP->GetGameStop())
	{
		SetAnimState("DEAD");
		SetScale(Vector2D(100, 100));
		SetCollisionScale(Vector2D(100, 100));

		HP = nullptr;
		return;
	}

	if (KEY_STATE(KEY::SPACE) == KEY_STATE::TAB)
	{
		if (!playerJump)
		{
			playerJump = true;

			SetAnimState("JUMP");
			SetScale(Vector2D(90, 90));
			SetCollisionScale(Vector2D(90, 90));
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
			SetCollisionScale(Vector2D(100, 100));
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
			SetCollisionScale(Vector2D(100, 100));
		}
	}
	const int Upspeed = 400;
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
		else
		{
			SetAnimState("RUN");
			SetScale(Vector2D(100, 100));
			SetCollisionScale(Vector2D(100, 100));
		}

		Position.y = InOtherObject->GetPosition().y - (InOtherObject->GetScale().y * 0.75f);
		mVel = Vector2D(0.0f, 2.5f);
		return;
	}

	Vector2D DeleteHP = HP->GetPosition();
	DeleteHP.x -= (HP->GetDynamic_Width() * 3);
	HP->SetPosition(DeleteHP);
}

void CPlayer::Render(HDC InHdc)
{
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