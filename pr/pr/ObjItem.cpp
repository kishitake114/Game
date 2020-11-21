#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h" 
#include "GameL\HitBoxManager.h"
#include "ObjItem.h"
#include "ObjRoad.h"

CObjItem::CObjItem(float x, float y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjItem::Init()
{
	/*CObjRoad* Road = (CObjRoad*)Objs::GetObj(OBJ_ROAD);*/

	//当たり判定用HitBoxを作成

	//Hits::SetHitBox(this, m_x, m_y, 40, 40, ELEMENT_ITEM, OBJ_ITEM, 0);

	mou_x = 0.0f;
	mou_y = 0.0f;
	mou_r = false;
	mou_l = false;

}

//アクション
void CObjItem::Action()
{
	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

	//CHitBox* hit = Hits::GetHitBox(this);
	//hit->SetPos(m_x, m_y);

	//	//主人公と接触で削除
	//	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr)
	//	{
	//		this->SetStatus(false);
	//		Hits::DeleteHitBox(this);
	//	}
	
}

//ドロー
void CObjItem::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	

	//src.m_top    = 130.0f;
	//src.m_left   = 1.0f;
	//src.m_right  = 51.0f;
	//src.m_bottom = 180.0f;

	Draw::Draw(0, &src, &dst,c,0.0f);
}