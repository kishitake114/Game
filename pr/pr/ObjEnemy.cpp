#include "ObjEnemy.h"
#include "ObjRoad.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h" 
#include "GameL\HitBoxManager.h"

//�C�j�V�����C�Y
void CObjEnemy::Init()
{
	HP = 2;

	Hits::SetHitBox(this, p_x, p_y, 40, 40, ELEMENT_PLAYER, OBJ_ENEMY, 1);
	
}

//�A�N�V����
void CObjEnemy::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(p_x, p_y);


	//�v���C���[�ƐڐG���Ă��邩�ǂ����𒲂ׂ�
	if ( hit->CheckObjNameHit(OBJ_PLAYER) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

}

//�h���[
void CObjEnemy::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//�\���F�}�E�X�J�[�\���ƃ{�^��
	wchar_t str[256];

	swprintf_s(str, L"HP %d/2",HP);
	Font::StrDraw(str, 600, 400, 30, c);

	src.m_top = 50.0f;
	src.m_left = 0.0f;
	src.m_right = 45.0f;
	src.m_bottom = 80.0f;

	dst.m_top	 =   0.0f;
	dst.m_left   =  80.0f;
	dst.m_right  = 120.0f;
	dst.m_bottom =  40.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);

}
