//�g�p����w�b�_�[
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "ObjPlayer.h"
#include "ObjRoad.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h"
#include "GameL\HitBoxManager.h"
#include "GameL/Audio.h"

using namespace GameL;

//�C�j�V�����C�Y
void CObjPlayer::Init()
{
	atk = 0;

	p_x = 0.0f;
	p_y = 200.0f;

	s_p = false;
	st_p = true;
	atr = true;

	sw = false;
	sei = false;

	cs_x = 50.0f;

	HP = 999;

		Hits::SetHitBox(this, p_x+40, p_y+40, 40, 40, ELEMENT_PLAYER, OBJ_PLAYER, 1);
	

}

//�A�N�V����
void CObjPlayer::Action()
{
	CObjItem* item = (CObjItem*)Objs::GetObj(OBJ_ITEM);
	CObjRoad* Road = (CObjRoad*)Objs::GetObj(OBJ_ROAD);
	CObjTime* Time = (CObjTime*)Objs::GetObj(OBJ_TIME);
	CObjEnemy* Enemy = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);

	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

	if (mou_r == true)
	{

		if (s_p==false)
		{
			if (cs_x == 0.0f)
			{
				p_y += 40.0f;
			}

			if (cs_x == 50.0f)
			{
				p_x += 40.0f;

			}

			if (cs_x == 95.0f)
			{
				p_y -= 40.0f;
			}

			if (cs_x == 140.0f)
			{
				p_x -= 40.0f;
			}
			s_p = true;
		}

	}

	if (s_p == true)
	{
	

			if (Input::GetVKey('W') == true )
			{
				/*	Audio::Start(2);*/
				   
					p_y -= 10.0f;
					cs_x = 95.0f;
					count = '-';

			}

			else if (Input::GetVKey('A') == true)
			{
			/*	    Audio::Start(2);*/

					p_x -= 10.0f;
					cs_x = 140.0f;
					count = '-';


			}
			
			else if (Input::GetVKey('D') == true)
			{
				    /*Audio::Start(2);*/
	
					p_x += 10.0f;
					cs_x = 50.0f;
					count = '-';
	
			}

			else if (Input::GetVKey('S') == true )
			{
			/*	    Audio::Start(2);*/
			
					p_y += 10.0f;
					cs_x = 0.0;
					count = '-';

			}

			
			//�`���[�g���A���X�e�[�W�̈ړ�����
			if (num == 0)
			{
				//�X�e�[�W���[����o�Ȃ��悤�ɂ���
				if (p_x < 0.0f)
				{
					p_x = 0.0f;
				}

				//-----------------map[][0]�̐���-----------------

				//map[0�`1][0]�ɓ������Ƃ��̃v���O����
				if (p_x<=0.0f && p_y >= 0.0f&& p_y < 80.0f)
				{
					p_y = 80.0f;
				}
				
				//map[3�`4][0]�ɓ������Ƃ��̃v���O����
				if (p_x <= 0.0f && p_y > 120.0f && p_y < 200.0f)
				{

					p_y = 200.0f;
				}
				
				//map[6�`7][0]�ɓ������Ƃ��̃v���O����
				if (p_x <= 0.0f && p_y >= 240.0f && p_y < 320.0f)
				{
					p_y = 200.0f;
				}

				//�X�e�[�W�E�[����o�Ȃ��悤�ɂ���
				if (p_x > 280.0f)
				{
					p_x = 280.0f;
				}

				//-----------------map[][13]�̐���-----------------

				//map[0�`1][13]�ɓ������Ƃ��̃v���O����
				if (p_x >= 280.0f && p_y >= 0.0f && p_y <= 80.0f)
				{
					p_y = 80.0f;
				}
				//map[3�`4][13]�ɓ������Ƃ��̃v���O����
				if (p_x >= 280.0f && p_y >= 120.0f && p_y <= 200.0f)
				{
					p_y = 200.0f;
				}
				//map[6�`7][13]�ɓ������Ƃ��̃v���O����
				if (p_x >= 280.0f && p_y >= 240.0f && p_y <= 320.0f)
				{
					p_y = 200.0f;
				}

				//�X�e�[�W��[����o�Ȃ��悤�ɂ���
				if (p_y < 0.0f)
				{
					p_y = 0.0f;
				}

				//�X�e�[�W���[����o�Ȃ��悤�ɂ���
				if (p_y > 280.0f)
				{
					p_y = 280.0f;
				}

			}

			if (num == 1)
			{
				//----------------�X�e�[�W����o�Ȃ��悤�ɂ���v���O����----------------------
				//�X�e�[�W���[����o�Ȃ��悤�ɂ���
				if (p_x < 0.0f)
				{
					p_x = 0.0f;
				}

				//�X�e�[�W��[����o�Ȃ��悤�ɂ���
				if (p_y < 0.0f)
				{
					p_y = 0.0f;
				}

				//�X�e�[�W���[����o�Ȃ��悤�ɂ���
				if (p_y > 520.0f)
				{
					p_y = 520.0f;
				}

				//�X�e�[�W���[����o�Ȃ��悤�ɂ���
				if (p_x > 520.0f)
				{
					p_x = 520.0f;
				}
				//------------------------------------------------------------------------------
			}

	}

	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(p_x, p_y);

	if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
	{
		s_p = true;

		Enemy->HP = Enemy->HP - atk;
		atk = 0;
		HP--;

		s_p = false;
		Road->s_r = true;
		Time->m_flag_time = true;

		if (cs_x == 0.0f)
		{
			p_y = 520.0f;
			cs_x = 95.0f;
		}

		if (cs_x == 50.0f)
		{
			p_x = 0.0f;
			cs_x = 140.0f;
		}

		if (cs_x == 95.0f)
		{
			p_y = 0.0f;
			cs_x = 0.0f;
		}

		if (cs_x == 140)
		{
			p_x = 520.0f;
			cs_x = 50.0f;
		}
	}

	if (HP <= 0)
		Scene::SetScene(new CSceneGameOver());
	

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

	swprintf_s(str, L"�A�^�b�N=%d", atk);
	Font::StrDraw(str, 600, 450, 30, c);

	swprintf_s(str, L"�؂���=%f", cs_x);
	Font::StrDraw(str, 600, 350, 30, c);

	swprintf_s(str, L"playerX=%f", p_x);
	Font::StrDraw(str, 600, 251, 25, c);
	swprintf_s(str, L"playerY=%fw", p_y);
	Font::StrDraw(str, 600, 276, 25, c);

	//�\���F�v���C���[
	RECT_F src;
	RECT_F dst;

	src.m_top     = 0.0f ;
	src.m_left    = 0.0f  + cs_x;
	src.m_right   = 45.0f + cs_x;
	src.m_bottom  = 45.0f;

	if (num <= 1)
	{
		dst.m_top = 0.0f + p_y;
		dst.m_left = 0.0f + p_x;
		dst.m_right = 40.0f + p_x;
		dst.m_bottom = 40.0f + p_y;

	}

	if (num == 2)
	{
		dst.m_top = 240.0f + p_y;
		dst.m_left = 0.0f + p_x;
		dst.m_right = 30.0f + p_x;
		dst.m_bottom = 270.0f + p_y;
	}

	if (num == 3)
	{
		dst.m_top = 200.0f + p_y;
		dst.m_left = 0.0f + p_x;
		dst.m_right = 25.0f + p_x;
		dst.m_bottom = 225.0f + p_y;
	}


	if (num == 4)
	{
		dst.m_top = 242.0f + p_y;
		dst.m_left = 0.0f + p_x;
		dst.m_right = 22.0f + p_x;
		dst.m_bottom = 264.0f + p_y;
	}


	Draw::Draw(0, &src, &dst, c, 0.0f);
}