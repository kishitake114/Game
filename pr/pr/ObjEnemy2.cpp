#include "ObjEnemy2.h"
#include "ObjRoad.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h" 
#include "GameL\HitBoxManager.h"

#include <stdlib.h>
#include <time.h>


//�C�j�V�����C�Y
void CObjEnemy2::Init()
{
	srand(time(NULL));

	HP = 3;
	p_x = 60.0f;
	p_y = 0.0f;

	atr_x = 0.0f;
	atr_y = 0.0f;

	cs_xe = 0.0f;

	plx = 0;
	ply = 0;

	memx = 0;
	memy = 0;

	ran = 0;

	se = false;



	Hits::SetHitBox(this, p_x, p_y, 30, 30, ELEMENT_ENEMY, OBJ_ENEMY2, 1);

}

//�A�N�V����
void CObjEnemy2::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(p_x, p_y);

	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	if (se == true)
	{
		

		//�v���C���[�ƐڐG���Ă��邩�ǂ����𒲂ׂ�
		if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr)
		{
			ran = 1;

			
			CObjTime* time = (CObjTime*)Objs::GetObj(OBJ_TIME);
			CObjStage2* Road2 = (CObjStage2*)Objs::GetObj(OBJ_STAGE2);
			

			HP = HP - player->atk;
			player->atk = 0;
			if (HP <= 0)
			{
				this->SetStatus(false);
				Hits::DeleteHitBox(this);

				player->battle = true;
			}
			else
			{
				player->HP--;
			}


	


			for (int i = 0; i < 17; i++)
			{
				for (int j = 0; j < 17; j++)
				{
					Road2->memmap[i][j] = Road2->map[i][j];
				}
			}

			time->m_time = 5400;


			se = false;

			plx = rand() % 4;
			ply = rand() % 5;


			if (memx == plx && memy == ply)
			{
				plx = rand() % 4;
				ply = rand() % 5;
			}

			else
			{
				memx = plx;
				memy = ply;
			}

			switch (plx)
			{

				//plx���O�̏ꍇ��map[0][](��)�Ɉړ�
			case 0:

				//ply=0�@map[0][2]
				if (ply == 0)
				{
					p_x = 60.0f;
					atr_x = 0.0f;
					cs_xe = 0.0f;

					p_y = 0.0f;
					atr_y = 0.0f;

				}

				//ply=1�@map[0][5]
				if (ply == 1)
				{
					p_x =150.0f;
					atr_x = 90.0f;
					cs_xe = 0.0f;

					p_y = 0.0f;
					atr_y = 0.0f;
				}

				//ply=2�@map[0][8]
				if (ply == 2)
				{
					p_x = 240.0f;
					atr_x = 180.0f;
					cs_xe = 0.0f;

					p_y = 0.0f;
					atr_y = 0.0f;
				}

				//ply=3�@map[0][11]
				if (ply == 3)
				{
					p_x = 330.0f;
					atr_x = 270.0f;
					cs_xe = 0.0f;

					p_y = 0.0f;
					atr_y = 0.0f;
				}

				if (ply == 4)
				{
					p_x = 420.0f;
					atr_x = 360.0f;
					cs_xe = 0.0f;

					p_y = 0.0f;
					atr_y = 0.0f;
				}

				break;

				//plx���P�̏ꍇ��map[][0](��)�Ɉړ�
			case 1:

				//ply=0�@map[0][2]
				if (ply == 0)
				{
					p_x = 0.0f;
					atr_x = -60.0f;
					cs_xe = 152.0f;

					p_y = 60.0f;
					atr_y = 60.0f;
				}

				//ply=1�@map[0][5]
				if (ply == 1)
				{
					p_x = 0.0f;
					atr_x = -60.0f;
					cs_xe = 152.0f;

					p_y = 150.0f;
					atr_y = 150.0f;
				}

				//ply=2�@map[0][8]
				if (ply == 2)
				{
					p_x = 0.0f;
					atr_x = -60.0f;
					cs_xe = 152.0f;

					p_y = 240.0f;
					atr_y = 240.0f;
				}

				//ply=3�@map[0][11]
				if (ply == 3)
				{
					p_x = 0.0f;
					atr_x = -60.0f;
					cs_xe = 152.0f;

					p_y = 330.0f;
					atr_y =330.0f;
				}

				//ply=3�@map[0][11]
				if (ply == 4)
				{
					p_x = 0.0f;
					atr_x = -60.0f;
					cs_xe = 152.0f;

					p_y = 420.0f;
					atr_y = 420.0f;
				}
				break;

				//plx���Q�̏ꍇ��map[][13](�E)�Ɉړ�
			case 2:

				//ply=0�@map[0][2]
				if (ply == 0)
				{
					p_x = 60.0f;
					atr_x = 0.0f;
					cs_xe = 52.0f;

					p_y = 480.0f;
					atr_y = 480.0f;

				}

				//ply=1�@map[0][5]
				if (ply == 1)
				{
					p_x = 150.0f;
					atr_x = 90.0f;
					cs_xe = 52.0f;

					p_y = 480.0f;
					atr_y = 480.0f;
				}

				//ply=2�@map[0][8]
				if (ply == 2)
				{
					p_x = 240.0f;
					atr_x = 180.0f;
					cs_xe = 52.0f;

					p_y = 480.0f;
					atr_y = 480.0f;
				}

				//ply=3�@map[0][11]
				if (ply == 3)
				{
					p_x = 330.0f;
					atr_x = 270.0f;
					cs_xe = 52.0f;

					p_y = 480.0f;
					atr_y = 480.0f;
				}

				if (ply == 4)
				{
					p_x = 420.0f;
					atr_x = 360.0f;
					cs_xe = 52.0f;

					p_y = 480.0f;
					atr_y = 480.0f;
				}

				break;

				//plx���P�̏ꍇ��map[13][](��)�Ɉړ�
			case 3:

				//ply=0�@map[0][2]
				if (ply == 0)
				{
					p_x = 480.0f;
					atr_x = 420.0f;
					cs_xe = 102.0f;

					p_y = 60.0f;
					atr_y = 60.0f;
				}

				//ply=1�@map[0][5]
				if (ply == 1)
				{
					p_x = 480.0f;
					atr_x = 420.0f;
					cs_xe = 102.0f;

					p_y = 150.0f;
					atr_y = 150.0f;
				}

				//ply=2�@map[0][8]
				if (ply == 2)
				{
					p_x = 480.0f;
					atr_x = 420.0f;
					cs_xe = 102.0f;

					p_y = 240.0f;
					atr_y = 240.0f;
				}

				//ply=3�@map[0][11]
				if (ply == 3)
				{
					p_x = 480.0f;
					atr_x = 420.0f;
					cs_xe = 102.0f;

					p_y = 330.0f;
					atr_y = 330.0f;
				}

				//ply=3�@map[0][11]
				if (ply == 4)
				{
					p_x = 480.0f;
					atr_x = 420.0f;
					cs_xe = 102.0f;

					p_y = 420.0f;
					atr_y = 420.0f;
				}

			default:
				break;

			}

		}
	}
	else
	{
		se = true;
	}


}

//�h���[
void CObjEnemy2::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//�\���F�}�E�X�J�[�\���ƃ{�^��
	wchar_t str[256];

	swprintf_s(str, L"Enemy HP");
	Font::StrDraw(str, 642, 250, 20, c);

	swprintf_s(str, L"%2d", HP);
	Font::StrDraw(str, 730, 255, 30, c);

	src.m_top = 0.0f;
	src.m_left = 0.0f + cs_xe;
	src.m_right = 45.0f + cs_xe;
	src.m_bottom = 50.0f;

	dst.m_top = 0.0f + atr_y;
	dst.m_left = 60.0f + atr_x;
	dst.m_right = 90.0f + atr_x;
	dst.m_bottom = 30.0f + atr_y;

	Draw::Draw(1, &src, &dst, c, 0.0f);


	src.m_top = 0.0f;
	src.m_left = 0.0f ;
	src.m_right = 45.0f;
	src.m_bottom = 50.0f;

	dst.m_top = 250.0f;
	dst.m_left = 600.0f;
	dst.m_right = 640.0f;
	dst.m_bottom = 290.0f;

	Draw::Draw(1, &src, &dst, c, 0.0f);

}