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

CPlayer::CPlayer() : CAnimationObject(Vector2D{ 100, 100 }, Vector2D{ 50, 50 }),
HP(nullptr)
{
	mVel = Vector2D(0.0f, -2.5f);
}

CPlayer::CPlayer(Vector2D InVector, Vector2D InScale) : CAnimationObject(Vector2D{ InVector.x , InVector.y }, Vector2D{ InScale.x, InScale.y }),
HP(nullptr)
{
	mVel = Vector2D(0.0f, -2.5f);
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

	if (playerJump)
	{
		const int Upspeed = 450;
		JumpAction(InDeltaTime, Upspeed);
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

void CPlayer::JumpAction(float InDeltaTime, int Speed)
{
	if (playerdoubleJump)
	{
		if (DoubleJumpAction(InDeltaTime, Speed))
			return;
	}

	if (Position.y >= 551)     // 초기값 세팅후 종료
	{
		Position.y = 550;
		playerJump = false;
		mVel.y = -2.5f;

		SetAnimState("RUN");
		SetScale(Vector2D(100, 100));
		SetCollisionScale(Vector2D(100, 100));
		return;
	}

	mVel += gravity * InDeltaTime;
	Position += mVel * InDeltaTime * Speed;
}

bool CPlayer::DoubleJumpAction(float InDeltaTime, int Speed)
{
	static Vector2D mvel = Vector2D(0.0f, -2.0f);
	if (Position.y > 551)     // 초기값 세팅후 종료
	{
		Position.y = 551;
		playerdoubleJump = false;
		mvel.y = -2.0f;
		return false;
	}

	/*static float mprev;
	mprev = Position.y;*/
	mvel += gravity * InDeltaTime ;
	Position += mvel * InDeltaTime * Speed;
	return true;
}