#include "Player.h"
#include "KeyManager.h"
#include "CSceneManager.h"
#include "ResourceManager.h"
#include "EventManager.h"
#include "CTexture.h"
#include "UtilMath.h"

static bool playerJump = false;
static bool playerdoubleJump = false;
static const Vector2D gravity = Vector2D(0.0f, 9.8f);
const int Upspeed = 450;

CPlayer::CPlayer() : CAnimationObject(Vector2D{ 100, 100 }, Vector2D{ 50, 50 })
{
	mVel = Vector2D(0.0f, -3.5f);
}

CPlayer::CPlayer(Vector2D InVector, Vector2D InScale) : CAnimationObject(Vector2D{ InVector.x , InVector.y }, Vector2D{ InScale.x, InScale.y })
{
	mVel = Vector2D(0.0f, -3.5f);
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
	int SPEED = 1000;

	if (playerJump)
	{
		JumpAction(InDeltaTime);
	}

	/*if (KEY_STATE(KEY::A) == KEY_STATE::HOLD)
	{
		Vector2D position = Position;
		position.x -= SPEED * InDeltaTime;

		if (position.x < 20)
		{
			position.x = 20;
		}

		Position = position;
	}

	if (KEY_STATE(KEY::D) == KEY_STATE::HOLD)
	{
		Vector2D position = Position;
		position.x += SPEED * InDeltaTime;

		if (position.x > 940)
		{
			position.x = 940;
		}

		Position = position;
	}*/

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

			SetAnimState("DOUJUMP");
			SetScale(Vector2D(90, 90));
			SetCollisionScale(Vector2D(90, 90));
		}
	}

	if (KEY_STATE(KEY::W) == KEY_STATE::TAB || KEY_STATE(KEY::W) == KEY_STATE::HOLD)
	{
		if (playerdoubleJump || playerJump)
			return;

		SetAnimState("SLIDING");
		SetScale(Vector2D(150, 50));
		SetCollisionScale(Vector2D(100, 100));
		Position.y = 575;
	}

	if (KEY_STATE(KEY::W) == KEY_STATE::AWAY)
	{
		if (playerdoubleJump || playerJump)
			return;

		SetAnimState("RUN");
		SetScale(Vector2D(100, 100));
		SetCollisionScale(Vector2D(100, 100));

		Position.y = 550;
	}
}

void CPlayer::Collision(const CObject* InOtherObject)
{
	CObject::Collision(InOtherObject);
}

void CPlayer::Render(HDC InHdc)
{
	CAnimationObject::Render(InHdc);
}

void CPlayer::JumpAction(float InDeltaTime)
{
	if (playerdoubleJump)
	{
		if (DoubleJumpAction(InDeltaTime))
			return;
	}

	if (Position.y >= 551)     // 초기값 세팅후 종료
	{
		Position.y = 550;
		playerJump = false;
		mVel.y = -3.5f;

		SetAnimState("RUN");
		SetScale(Vector2D(100, 100));
		SetCollisionScale(Vector2D(100, 100));
		return;
	}

	mVel += gravity * InDeltaTime;
	Position += UtilMath::Normalize(mVel) * InDeltaTime * Upspeed;
}

bool CPlayer::DoubleJumpAction(float InDeltaTime)
{
	static Vector2D mvel = Vector2D(0.0f, -1.0f);
	if (Position.y > 551)     // 초기값 세팅후 종료
	{
		Position.y = 551;
		playerdoubleJump = false;
		mvel.y = -1.0f;
		return false;
	}

	mvel += gravity * InDeltaTime ;
	Position += UtilMath::Normalize(mvel) * InDeltaTime * Upspeed;
	return true;
}