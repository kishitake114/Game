//�g�p����w�b�_�[
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "ObjPlayer.h"
#include "ObjRoad.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h"
#include "GameL\HitBoxManager.h"


using namespace GameL;

//�C�j�V�����C�Y
void CObjPlayer::Init()
{
	p_x = 0.0f;
	p_y = 0.0f;
	p_vx = 0.0f;
	p_vy = 200.0f;
	s_p = false;
	st_p = true;
	atr = true;

	sw = false;
	sei = false;

	cs_x = 0.0f;
	cs_y = 0.0f;

	Hits::SetHitBox(this, p_vx+40, p_vy+40, 40, 40, ELEMENT_PLAYER, OBJ_PLAYER, 1);
}

//�A�N�V����
void CObjPlayer::Action()
{
	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

	if (mou_r == true)
	{
		s_p = true;
	}

	if (s_p == true)
	{


			//CHitBox* hit = Hits::GetHitBox(this);
			//hit->SetPos(p_vx, p_vy);

			if (Input::GetVKey('W') == true)
			{
					p_y -= 20.0f;
					p_vy -= 20.0f;
					cs_x = 95.0f;
					atr = false;
			}

			if (Input::GetVKey('A') == true)
			{
					p_x -= 20.0f;
					p_vx -= 20.0f;
					cs_x = 140.0f;

			}

			if (Input::GetVKey('D') == true)
			{
					p_x += 20.0f;
					p_vx += 20.0f;
					cs_x = 50.0f;
			}

			if (Input::GetVKey('S') == true)
			{
					p_y += 20.0f;
					p_vy += 20.0f;
					cs_x = 0.0;
			}

		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(p_vx, p_vy);
		if (sei == true)
		{


			if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
			{

				if (cs_x == 95.0f)
				{
					p_y = -200.0f;
					p_vy = p_y / 40;

					cs_x = 0.0f;
				}

				if (cs_x == 140.0f)
				{
					p_x = 0.0f;
					p_vx = p_x / 40;

					cs_x = 45.0f;
				}

				if (cs_x == 50.0f)
				{
					p_x = 280.0f;
					p_vx = p_x / 40;

					cs_x = 140.0f;
				}

				/*if (cs_x == 0.0f)
				{
					p_x = 0.0f;
					p_vx = p_x / 40;

					cs_x = 95.0f;
				}*/

				sw = true;

				sei = false;
				s_p = false;

			}
		}

		else
		{
			sei = true;
		}

	}

	if (sw==true&&mou_l == true)
	{
		s_p = false;
		sw = false;
	}

}

//�h���[
void CObjPlayer::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float r[4] = { 1.0f,0.0f,0.0f,1.0f };
	float g[4] = { 0.0f,1.0f,0.0f,1.0f };
	float b[4] = { 0.0f,0.0f,1.0f,1.0f };

	//�\���F�v���C���[
	wchar_t str[256];

	if (sw == true)
	Font::StrDraw(L"���N���b�N�Ń}�E�X����", 500, 80, 20, b);
	else
	Font::StrDraw(L"OFF", 500, 80, 20, c);

	if (s_p == true)
	{
		Font::StrDraw(L"Player", 660, 40, 20, b);
		Font::StrDraw(L"����\n W,A,S,D", 550, 300, 20, b);
	}


	//�\���F�v���C���[
	RECT_F src;
	RECT_F dst;

	src.m_top     = 0.0f ;
	src.m_left    = 0.0f  + cs_x;
	src.m_right   = 45.0f + cs_x;
	src.m_bottom  = 45.0f;

	dst.m_top    = 200.0f + p_y;
	dst.m_left   =   0.0f + p_x;
	dst.m_right  =  40.0f + p_x;
	dst.m_bottom = 240.0f + p_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}
