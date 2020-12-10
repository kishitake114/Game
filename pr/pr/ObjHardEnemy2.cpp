#include "ObjHardEnemy2.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h" 
#include "GameL\HitBoxManager.h"
#include "GameL/Audio.h"

#include <stdlib.h>
#include <time.h>

void CObjHardEnemy2::Init()
{
	srand(time(NULL));

	HP = 15;
	p_x = 60.0f;
	p_y = 0.0f;

	atr_x = 0.0f;
	atr_y = 0.0f;

	cs_xe = 0.0f;

	plx = 0;
	ply = 3;

	memx = 0;
	memy = 0;

	ran = 0;

	se = false;

	atk = false;
	e_s = false;

	Hits::SetHitBox(this, p_x, p_y, 30, 30, ELEMENT_ENEMY, OBJ_ENEMY2, 1);
}

void CObjHardEnemy2::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(p_x, p_y);

	CObjTime* time = (CObjTime*)Objs::GetObj(OBJ_TIME);
	CObjHardStage2* Road2 = (CObjHardStage2*)Objs::GetObj(OBJ_HARD_STAGE2);
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);

	if (e_s == true)
	{

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

			//plxが０の場合＝map[0][](上)に移動
		case 0:

			//ply=0　map[0][2]
			if (ply == 0)
			{
				p_x = 60.0f;
				atr_x = 0.0f;
				cs_xe = 0.0f;

				p_y = 0.0f;
				atr_y = 0.0f;

			}

			//ply=1　map[0][5]
			if (ply == 1)
			{
				p_x = 150.0f;
				atr_x = 90.0f;
				cs_xe = 0.0f;

				p_y = 0.0f;
				atr_y = 0.0f;
			}

			//ply=2　map[0][8]
			if (ply == 2)
			{
				p_x = 240.0f;
				atr_x = 180.0f;
				cs_xe = 0.0f;

				p_y = 0.0f;
				atr_y = 0.0f;
			}

			//ply=3　map[0][11]
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

			//plxが１の場合＝map[][0](左)に移動
		case 1:

			//ply=0　map[0][2]
			if (ply == 0)
			{
				p_x = 0.0f;
				atr_x = -60.0f;
				cs_xe = 152.0f;

				p_y = 60.0f;
				atr_y = 60.0f;
			}

			//ply=1　map[0][5]
			if (ply == 1)
			{
				p_x = 0.0f;
				atr_x = -60.0f;
				cs_xe = 152.0f;

				p_y = 150.0f;
				atr_y = 150.0f;
			}

			//ply=2　map[0][8]
			if (ply == 2)
			{
				p_x = 0.0f;
				atr_x = -60.0f;
				cs_xe = 152.0f;

				p_y = 240.0f;
				atr_y = 240.0f;
			}

			//ply=3　map[0][11]
			if (ply == 3)
			{
				p_x = 0.0f;
				atr_x = -60.0f;
				cs_xe = 152.0f;

				p_y = 330.0f;
				atr_y = 330.0f;
			}

			//ply=3　map[0][11]
			if (ply == 4)
			{
				p_x = 0.0f;
				atr_x = -60.0f;
				cs_xe = 152.0f;

				p_y = 420.0f;
				atr_y = 420.0f;
			}
			break;

			//plxが２の場合＝map[][13](右)に移動
		case 2:

			//ply=0　map[0][2]
			if (ply == 0)
			{
				p_x = 60.0f;
				atr_x = 0.0f;
				cs_xe = 52.0f;

				p_y = 480.0f;
				atr_y = 480.0f;

			}

			//ply=1　map[0][5]
			if (ply == 1)
			{
				p_x = 150.0f;
				atr_x = 90.0f;
				cs_xe = 52.0f;

				p_y = 480.0f;
				atr_y = 480.0f;
			}

			//ply=2　map[0][8]
			if (ply == 2)
			{
				p_x = 240.0f;
				atr_x = 180.0f;
				cs_xe = 52.0f;

				p_y = 480.0f;
				atr_y = 480.0f;
			}

			//ply=3　map[0][11]
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

			//plxが１の場合＝map[13][](下)に移動
		case 3:

			//ply=0　map[0][2]
			if (ply == 0)
			{
				p_x = 480.0f;
				atr_x = 420.0f;
				cs_xe = 102.0f;

				p_y = 60.0f;
				atr_y = 60.0f;
			}

			//ply=1　map[0][5]
			if (ply == 1)
			{
				p_x = 480.0f;
				atr_x = 420.0f;
				cs_xe = 102.0f;

				p_y = 150.0f;
				atr_y = 150.0f;
			}

			//ply=2　map[0][8]
			if (ply == 2)
			{
				p_x = 480.0f;
				atr_x = 420.0f;
				cs_xe = 102.0f;

				p_y = 240.0f;
				atr_y = 240.0f;
			}

			//ply=3　map[0][11]
			if (ply == 3)
			{
				p_x = 480.0f;
				atr_x = 420.0f;
				cs_xe = 102.0f;

				p_y = 330.0f;
				atr_y = 330.0f;
			}

			//ply=3　map[0][11]
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
		e_s = false;
	}

	if (se == false)
	{


		//プレイヤーと接触しているかどうかを調べる
		if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr)
		{

			e_s = true;

			HP = HP - player->atk;
			player->atk = 0;

			Road2->s_r = true;
			if (HP <= 0)
			{
				this->SetStatus(false);
				Hits::DeleteHitBox(this);

				player->battle = true;
			}
			else if (HP > 0)
			{
				if (atk == false)
				{
					player->HP-=2;
					atk = true;
				}
			}

			Audio::Start(2);


			for (int i = 0; i < 17; i++)
			{
				for (int j = 0; j < 17; j++)
				{
					if (Road2->map[i][j] == 8)
					{
						Road2->map[i][j] = 2;
					}

					if (Road2->Hmap[i][j] == 1)
					{
						Road2->map[i][j] = 8;
						
					}
				}
			}

			for (int i = 0; i < 17; i++)
			{
				for (int j = 0; j < 17; j++)
				{

					if (Road2->Hmap[i][j] == 1)
					{
						Road2->Hmap[i][j] = 8;
					}
				}
			}

			for (int i = 0; i < 17; i++)
			{
				for (int j = 0; j < 17; j++)
				{
					Road2->Hmemmap[i][j] = Road2->Hmap[i][j];
				}
			}

			for (int i = 0; i < 17; i++)
			{
				for (int j = 0; j < 17; j++)
				{
					Road2->memmap[i][j] = Road2->map[i][j];
				}
			}

			time->m_time = 3600;

			se = true;

		}
	}

	else
	{
		se = false;
	}

}

void CObjHardEnemy2::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//表示：マウスカーソルとボタン
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
	src.m_left = 0.0f;
	src.m_right = 45.0f;
	src.m_bottom = 50.0f;

	dst.m_top = 250.0f;
	dst.m_left = 600.0f;
	dst.m_right = 640.0f;
	dst.m_bottom = 290.0f;

	Draw::Draw(1, &src, &dst, c, 0.0f);

}
