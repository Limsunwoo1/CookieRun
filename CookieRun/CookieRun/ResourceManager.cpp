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
	LoadTexture("IVENTORYMAIN", L"Texture/cookeiResources/BackGround/Inventory.bmp");

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

	LoadTexture("JELLY", L"Texture/cookeiResources/Utill/item_jelly.bmp");

	LoadTexture("STARTBUTTON", L"Texture/cookeiResources/Button/game_start_button.bmp");
	LoadTexture("STARTBTPRESS", L"Texture/cookeiResources/Button/game_start_button_click.bmp");
	LoadTexture("BUY", L"Texture/cookeiResources/Button/buy_button_click.bmp");
	LoadTexture("CLICKBUY", L"Texture/cookeiResources/Button/check_button_click.bmp");
	LoadTexture("INSHOP", L"Texture/cookeiResources/Button/shop.bmp");
	LoadTexture("CLICKSHOP", L"Texture/cookeiResources/Button/clickshop.bmp");
	LoadTexture("INVENTORY", L"Texture/cookeiResources/Button/pet_button.bmp");
	LoadTexture("CLICK_INVENTORY", L"Texture/cookeiResources/Button/pet_button_click.bmp");
	LoadTexture("SELECTBUTTON", L"Texture/cookeiResources/Button/select_button_click.bmp");
	LoadTexture("EXIT", L"Texture/cookeiResources/Button/exit_button.bmp");

	LoadTexture("0", L"Texture/cookeiResources/NumBer/NumBer(0).bmp");
	LoadTexture("1", L"Texture/cookeiResources/NumBer/NumBer(1).bmp");
	LoadTexture("2", L"Texture/cookeiResources/NumBer/NumBer(2).bmp");
	LoadTexture("3", L"Texture/cookeiResources/NumBer/NumBer(3).bmp");
	LoadTexture("4", L"Texture/cookeiResources/NumBer/NumBer(4).bmp");
	LoadTexture("5", L"Texture/cookeiResources/NumBer/NumBer(5).bmp");
	LoadTexture("6", L"Texture/cookeiResources/NumBer/NumBer(6).bmp");
	LoadTexture("7", L"Texture/cookeiResources/NumBer/NumBer(7).bmp");
	LoadTexture("8", L"Texture/cookeiResources/NumBer/NumBer(8).bmp");
	LoadTexture("9", L"Texture/cookeiResources/NumBer/NumBer(9).bmp");

	//STAGE1
	LoadTexture("STAGE1_ROAD1", L"Texture/cookeiResources/Stage1/First_ground.bmp");
	LoadTexture("STAGE1_ROAD2", L"Texture/cookeiResources/Stage1/Stage1_Fork.bmp");
	LoadTexture("STAGE1_ROAD3", L"Texture/cookeiResources/Stage1/Stage1_thorn.bmp");
	LoadTexture("STAGE1_ROAD4", L"Texture/cookeiResources/Stage1/Stage1_thorn2.bmp");
	LoadTexture("STAGE1_ROAD5", L"Texture/cookeiResources/Stage1/Stage1_thorn3.bmp");
	LoadTexture("STAGE1_ROAD6", L"Texture/cookeiResources/Stage1/Stage1_thorn4.bmp");
	LoadTexture("STAGE1_ROAD7", L"Texture/cookeiResources/Stage1/Stage1_thorn5.bmp");
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
