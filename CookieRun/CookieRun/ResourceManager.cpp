#include "ResourceManager.h"
#include "CTexture.h"

CResourceManager::CResourceManager()
: HInstance(0)
, Hdc(0)
{

}

CResourceManager::~CResourceManager()
{
	for (std::pair<string, CTexture*> textureInfo : TextureList)
		delete textureInfo.second;

	TextureList.clear();
}

void CResourceManager::Init(HINSTANCE InHInst, HDC InHdc)
{
	HInstance = InHInst;
	Hdc = InHdc;


	LoadTexture("BACKGRUOND", L"Texture/cookeiResources/BackGround/First_Background.bmp");
	LoadTexture("HP_UI", L"Texture/cookeiResources/Utill/hpBar.bmp");

	LoadTexture("PLAYER_RUN",L"Texture/cookeiResources/Cookie/cookie_run!!.bmp");
	LoadTexture("PLAYER_DEAD", L"Texture/cookeiResources/Cookie/cookie_run_dead.bmp");
	LoadTexture("PLAYER_JUMP", L"Texture/cookeiResources/Cookie/cookie_run_jump.bmp");
	LoadTexture("PLAYER_DOUJUMP", L"Texture/cookeiResources/Cookie/cookie_run_jump2.bmp");
	LoadTexture("PLAYER_SLIDING", L"Texture/cookeiResources/Cookie/cookie_run_slide.bmp");
}

CTexture* CResourceManager::LoadTexture(const string& InName, const wstring& InFilePath)
{
	CTexture* texture = FindTexture(InName);
	if (texture)
		return texture;

	texture = new CTexture;
	if (!texture)
		return nullptr;

	if (texture->LoadTexture(InName, HInstance, Hdc, InFilePath))
	{
		TextureList.emplace(make_pair(InName, texture));
	}
	else
	{
		delete texture;
		texture = nullptr;
	}

	return texture;
}

CTexture* CResourceManager::FindTexture(const string& InName)
{
	//find 에 실패하면 iter에는 end() 값이 담긴다
	auto iter = TextureList.find(InName);
	if (iter == TextureList.end())
		return nullptr;

	return iter->second;
}
