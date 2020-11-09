#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h" 
#include "GameL\HitBoxManager.h"
#include "ObjItem.h"

//イニシャライズ
void CObjItem::Init()
{
	m_x = 0.0f;
	m_y = 0.0f;

	////当たり判定用HitBoxを作成
	//Hits::SetHitBox(this, m_x, m_y, 40, 40, ELEMENT_ENEMY, OBJ_ITEM, 1);
}

//アクション
void CObjItem::Action()
{
	/*CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}*/
}

//ドロー
void CObjItem::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top    = 0.0f;
	src.m_left   = 0.0f;
	src.m_right  = 0.0f;
	src.m_bottom = 0.0f;

	dst.m_top    = 0.0f ;
	dst.m_left   = 0.0f ;
	dst.m_right  = 32.0f;
	dst.m_bottom = 32.0f;

	Draw::Draw(0, &src, &dst,c,0.0f);
}