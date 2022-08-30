#include "COBST.h"
#include "CTexture.h"
#include "CSceneManager.h"
#include <vector>

void Test(CObject* InObject)
{

}

COBST::COBST() : CSpriteObject()
{

}

COBST::COBST(Vector2D InPos, Vector2D InScale) : CSpriteObject(Vector2D{InPos.x,InPos.y }, Vector2D{InScale.x,InScale.y})
{

}

COBST::~COBST()
{

}

void COBST::Update(float InDeltaTIme)
{
	if (Position.x < -5000)
		Position.x = 2000;

	CSpriteObject::Update(InDeltaTIme);
	Position.x -= InDeltaTIme * 300;

	//const auto& objectList = CSceneManager::GetInstance()->Get_Object(OBJ_LAYER::ITEM);
	//for (const CObject* object : objectList)
	//{
	//	//~~~
	//}

	//int count = 0;
	//CSceneManager::GetInstance()->ForEachObject( [] ( CObject* InObject ) 
	//{
	//	if (!InObject)
	//		return;

	//	count++;
	//} );

	//if (count > 3)
	//{
	//	LOG("!!!!");
	//}
}

void COBST::Render(HDC Inhdc)
{
	TransparentBlt(Inhdc,
		Position.x - (Texture->GetWidth() * 0.5f),
		Position.y - (Texture->GetHeight() * 0.5f),
		Texture->GetWidth(),
		Texture->GetHeight(),
		Texture->GetHdc(),
		0,
		0,
		Texture->GetWidth(),
		Texture->GetHeight(),
		RGB(255, 0, 255));
}

void COBST::Collision(const CObject* InOtherObject)
{
	CObject::Collision(InOtherObject);

	if ((InOtherObject->GetObjectLayer() == OBJ_LAYER::FOOTHOLD) && (Position.y <= InOtherObject->GetPosition().y))
		Position.y = InOtherObject->GetPosition().y - (InOtherObject->GetScale().y * 0.6f);
}