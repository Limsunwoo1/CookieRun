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

	LoadTexture("LOBBYBACKGRUOND", L"Texture/cookeiResources/BackGround/lobby_background2.bmp");
	LoadTexture("BACKGRUOND", L"Texture/cookeiResources/BackGround/First_Background.bmp");
	LoadTexture("HP_UI", L"Texture/cookeiResources/Utill/hpBar.bmp");
	LoadTexture("SHOPMAIN", L"Texture/cookeiResources/BackGround/shop_main.bmp");

	LoadTexture("MAINGAME", L"Texture/cookeiResources/BackGround/title.bmp");
	LoadTexture("DEVSIS", L"Texture/cookeiResources/BackGround/title_CI.bmp");
	LoadTexture("KAKAO", L"Texture/cookeiResources/BackGround/title_kakao.bmp");

	LoadTexture("PLAYER_RUN",L"Texture/cookeiResources/Cookie/cookie_run!!.bmp");
	LoadTexture("PLAYER_DEAD", L"Texture/cookeiResources/Cookie/cookie_run_dead.bmp");
	LoadTexture("PLAYER_JUMP", L"Texture/cookeiResources/Cookie/cookie_run_jump.bmp");
	LoadTexture("PLAYER_DOUJUMP", L"Texture/cookeiResources/Cookie/cookie_run_jump2.bmp");
	LoadTexture("PLAYER_SLIDING", L"Texture/cookeiResources/Cookie/cookie_run_slide.bmp");

	LoadTexture("CHOCOPET", L"Texture/cookeiResources/Utill/chestnut_pet.bmp");
	LoadTexture("DOGPET", L"Texture/cookeiResources/Utill/dog_pet.bmp");
	LoadTexture("WAFERPET", L"Texture/cookeiResources/Utill/wafer_pet.bmp");

	LoadTexture("STARTBUTTON", L"Texture/cookeiResources/Button/game_start_button.bmp");
	LoadTexture("STARTBTPRESS", L"Texture/cookeiResources/Button/game_start_button_click.bmp");
	LoadTexture("BUY", L"Texture/cookeiResources/Button/buy_button_click.bmp");
	LoadTexture("CLICKBUY", L"Texture/cookeiResources/Button/check_button_click.bmp");
	LoadTexture("INSHOP", L"Texture/cookeiResources/Button/pet_button.bmp");
	LoadTexture("CLICKSHOP", L"Texture/cookeiResources/Button/pet_button_click.bmp");
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
