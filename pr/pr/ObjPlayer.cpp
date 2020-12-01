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

CObjPlayer::CObjPlayer(float x, float y)
{
	p_x = x;
	p_y = y;
}

//�C�j�V�����C�Y
void CObjPlayer::Init()
{
	atk = 0;

	battle = false;

	memp_x = p_x;
	memp_y = p_y;

	s_p = false;
	st_p = true;
	atr = true;

	sw = false;
	sei = false;

	cs_x = 50.0f;

	HP = 10;

	p_x = 0.0f;
	p_y = 0.0f;


	tarn = 1;

	kt = 0;

	Hits::SetHitBox(this, p_x, p_y, 20, 20, ELEMENT_PLAYER, OBJ_PLAYER, 1);
	
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(p_x, p_y);

}

//�A�N�V����
void CObjPlayer::Action()
{
	CObjItem* item = (CObjItem*)Objs::GetObj(OBJ_ITEM);
	CObjRoad* road = (CObjRoad*)Objs::GetObj(OBJ_ROAD);
	CObjStage2* road2 = (CObjStage2*)Objs::GetObj(OBJ_STAGE2);
	CObjStage3* road3 = (CObjStage3*)Objs::GetObj(OBJ_STAGE3);
	CObjStage4* road4 = (CObjStage4*)Objs::GetObj(OBJ_STAGE4);
	CObjTime* Time = (CObjTime*)Objs::GetObj(OBJ_TIME);
	CObjEnemy* Enemy = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
	CObjEnemy2* Enemy2 = (CObjEnemy2*)Objs::GetObj(OBJ_ENEMY2);
	CObjEnemy3* Enemy3 = (CObjEnemy3*)Objs::GetObj(OBJ_ENEMY3);
	CObjEnemy4* Enemy4 = (CObjEnemy4*)Objs::GetObj(OBJ_ENEMY4);



	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

	if (mou_r == true)
	{
			s_p = true;

			memp_x = p_x;
			memp_y = p_y;

	}

	if (s_p == true)
	{
	

			if (Input::GetVKey('W') == true || Input::GetVKey(VK_UP) == true)
			{
					Audio::Start(1);
				   
					p_y -= 5.0f;
					cs_x = 95.0f;
					count = '-';

			}

			else if (Input::GetVKey('A') == true || Input::GetVKey(VK_LEFT) == true)
			{
				    Audio::Start(1);

					p_x -= 5.0f;
					cs_x = 140.0f;
					count = '-';


			}
			
			else if (Input::GetVKey('D') == true || Input::GetVKey(VK_RIGHT) == true)
			{
				    Audio::Start(1);
	
					p_x += 5.0f;
					cs_x = 50.0f;
					count = '-';
	
			}

			else if (Input::GetVKey('S') == true || Input::GetVKey(VK_DOWN) == true)
			{
				    Audio::Start(1);
			
					p_y += 5.0f;
					cs_x = 0.0;
					count = '-';

			}

			
			//�`���[�g���A���X�e�[�W�̈ړ�����
			if (num == 0)
			{
				if (p_x < 0.0f)
				{
					p_x = 0.0f;
				}

				//�X�e�[�W��[����o�Ȃ��悤�ɂ���
				if (p_y < 0.0f)
				{
					battle = true;
					p_y = 0.0f;
					
				}

				//�X�e�[�W���[����o�Ȃ��悤�ɂ���
				if (p_y > 280.0f)
				{
					battle = true;
					p_y = 280.0f;
				}

				//�X�e�[�W���[����o�Ȃ��悤�ɂ���
				if (p_x > 280.0f)
				{
					battle = true;
					p_x = 280.0f;
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

			if (num == 2)
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
				if (p_y > 480.0f)
				{
					p_y = 480.0f;
				}

				//�X�e�[�W���[����o�Ȃ��悤�ɂ���
				if (p_x > 480.0f)
				{
					p_x = 480.0f;
				}
				//------------------------------------------------------------------------------
			}

			if (num == 3)
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
				if (p_y > 475.0f)
				{
					p_y = 475.0f;
				}

				//�X�e�[�W���[����o�Ȃ��悤�ɂ���
				if (p_x > 475.0f)
				{
					p_x = 475.0f;
				}
				//------------------------------------------------------------------------------
			}

			if (num == 4)
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
				if (p_y > 550.0f)
				{
					p_y = 550.0f;
				}

				//�X�e�[�W���[����o�Ȃ��悤�ɂ���
				if (p_x > 550.0f)
				{
					p_x = 550.0f;
				}
				//------------------------------------------------------------------------------
			}

	}

	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(p_x, p_y);

	if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
	{
		s_p = true;

		memp_x = p_x;
		memp_y = p_y;

		s_p = false;

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

	if (hit->CheckObjNameHit(OBJ_ENEMY2) != nullptr)
	{
		s_p = true;

		memp_x = p_x;
		memp_y = p_y;

		s_p = false;
		road2->s_r = true;
		Time->m_flag_time = true;

		if (cs_x == 0.0f)
		{
			p_y = 480.0f;
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
			p_x = 480.0f;
			cs_x = 50.0f;
		}
	}

	if (hit->CheckObjNameHit(OBJ_ENEMY3) != nullptr)
	{
		s_p = true;

		memp_x = p_x;
		memp_y = p_y;

		s_p = false;
		road3->s_r = true;
		Time->m_flag_time = true;

		if (cs_x == 0.0f)
		{
			p_y = 475.0f;
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
			p_x = 0.0f;
			cs_x = 50.0f;
		}
	}

	if (hit->CheckObjNameHit(OBJ_ENEMY4) != nullptr)
	{
		s_p = true;

		memp_x = p_x;
		memp_y = p_y;

		s_p = false;
		road4->s_r = true;
		Time->m_flag_time = true;

		if (cs_x == 0.0f)
		{
			p_y = 550.0f;
			cs_x = 95.0f;
		}

		if (cs_x == 50.0f)
		{
			p_x = 550.0f;
			cs_x = 140.0f;
		}

		if (cs_x == 95.0f)
		{
			p_y = 0.0f;
			cs_x = 0.0f;
		}

		if (cs_x == 140)
		{
			p_x = 0.0f;
			cs_x = 50.0f;
		}
	}

	if (HP <= 0)
		Scene::SetScene(new CSceneGameOver());
	
	if (battle == true)
	{
		if (num >= 1)
		{
			Time->m_flag_time = false;
		}	

		s_p = false;
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



	if (battle == false)
	{

		if (s_p == true)
		{
			Font::StrDraw(L"Player", 600, 80, 40, b);
		}

		swprintf_s(str, L"ATK");
		Font::StrDraw(str, 642, 150, 20, c);

		swprintf_s(str, L"%2d", atk);
		Font::StrDraw(str, 730, 155, 30, c);

		swprintf_s(str, L"Player HP");
		Font::StrDraw(str, 642,200, 20, c);

		swprintf_s(str, L"%2d", HP);
		Font::StrDraw(str, 730, 205, 30, c);

	}

	swprintf_s(str, L"x %f", p_x);
	Font::StrDraw(str, 600, 440, 30, c);

	swprintf_s(str, L"y %f", p_y);
	Font::StrDraw(str, 600, 400, 30, c);


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
		dst.m_top = 0.0f + p_y;
		dst.m_left = 0.0f + p_x;
		dst.m_right = 30.0f + p_x;
		dst.m_bottom = 30.0f + p_y;
	}

	if (num == 3)
	{
		dst.m_top = 0.0f + p_y;
		dst.m_left = 0.0f + p_x;
		dst.m_right = 25.0f + p_x;
		dst.m_bottom = 25.0f + p_y;
	}


	if (num == 4)
	{
		dst.m_top = 0.0f + p_y;
		dst.m_left = 0.0f + p_x;
		dst.m_right = 22.0f + p_x;
		dst.m_bottom = 22.0f + p_y;
	}


	Draw::Draw(0, &src, &dst, c, 0.0f);

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 45.0f;
	src.m_bottom = 45.0f;

	dst.m_top = 200.0f;
	dst.m_left = 600.0f;
	dst.m_right = 640.0f;
	dst.m_bottom = 240.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);

	src.m_top = 130.0f;
	src.m_left = 1.0f;
	src.m_right = 51.0f;
	src.m_bottom = 180.0f;

	dst.m_top = 150.0f;
	dst.m_left = 598.0f;
	dst.m_right = 642.0f;
	dst.m_bottom = 190.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}