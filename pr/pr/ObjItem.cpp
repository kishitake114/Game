#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h" 
#include "GameL\HitBoxManager.h"
#include "ObjItem.h"
#include "ObjRoad.h"

//�C�j�V�����C�Y
void CObjItem::Init()
{
	m_x = 80.0f;
	m_y = 80.0f;

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x ,m_y, 40,40, ELEMENT_ENEMY, OBJ_ITEM, 2);
}

//�A�N�V����
void CObjItem::Action()
{
	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//��l���ƐڐG�ō폜
	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//�h���[
void CObjItem::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top    = 130.0f;
	src.m_left   = 1.0f;
	src.m_right  = 51.0f;
	src.m_bottom = 180.0f;

	dst.m_top    = 80.0f ;
	dst.m_left   = 80.0f ;
	dst.m_right  = 120.0f;
	dst.m_bottom = 120.0f;

	Draw::Draw(0, &src, &dst,c,0.0f);
}