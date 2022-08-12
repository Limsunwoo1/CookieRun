#include "COBST.h"
#include "CTexture.h"
#include "CSceneManager.h"
#include <vector>
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
	/*if (Position.x < -50)
	{
		std::vector<CObject*> Vct;
		Vct = CSceneManager::GetInstance()->Get_Object(OBJ_LAYER::OBSTACLE);
		Position.x = Vct.end()[-1]->GetPosition().x + 800;
		return;
	}*/
	CSpriteObject::Update(InDeltaTIme);
	Position.x -= InDeltaTIme * 300;
}

void COBST::Render(HDC Inhdc)
{
	TransparentBlt(Inhdc,
		(int)Position.x - (Texture->GetWidth() * 0.5f),
		(int)Position.y - (Texture->GetHeight() * 0.5f),
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