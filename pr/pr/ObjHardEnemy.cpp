#include "ObjHardEnemy.h"
#include "hardstage1.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h" 
#include "GameL\HitBoxManager.h"
#include "GameL/Audio.h"

#include <stdlib.h>
#include <time.h>


void CObjHardEnemy::Init()
{
	srand(time(NULL));

	HP = 10;
	p_x = 80.0f;
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

	e_time;

	Hits::SetHitBox(this, p_x, p_y, 40, 40, ELEMENT_ENEMY, OBJ_ENEMY, 1);

}

void CObjHardEnemy::Action()
{
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	CObjTime* time = (CObjTime*)Objs::GetObj(OBJ_TIME);
	CObjHardStage1* Road = (CObjHardStage1*)Objs::GetObj(OBJ_HARD_STAGE1);

	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(p_x, p_y);


	if (se == true)
	{

		//プレイヤーと接触しているかどうかを調べる
		if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr)
		{

			HP = HP - player->atk;
			player->atk = 0;

			Road->s_r = true;
			if (HP <= 0)
			{
				this->SetStatus(false);
				Hits::DeleteHitBox(this);

				Audio::Start(2);

				player->battle = true;
			}
			else if (HP > 0)
			{
				player->HP-=2;
			}

			for (int i = 0; i < 14; i++)
			{
				for (int j = 0; j < 14; j++)
				{
					if (Road->map[i][j] == 8)
					{
						Road->map[i][j] = 2;
					}

					if (Road->Hmap[i][j] == 1)
					{
						Road->map[i][j] = 8;
					}
				}
			}

			for (int i = 0; i < 14; i++)
			{
				for (int j = 0; j < 14; j++)
				{

					if (Road->Hmap[i][j] == 1)
					{
						Road->Hmap[i][j] = 0;
					}
				}
			}

			for (int i = 0; i < 14; i++)
			{
				for (int j = 0; j < 14; j++)
				{
					Road->Hmemmap[i][j] = Road->Hmap[i][j];
				}
			}

			for (int i = 0; i < 14; i++)
			{
				for (int j = 0; j < 14; j++)
				{
					Road->memmap[i][j] = Road->map[i][j];
				}
			}

			time->m_time = 3600;



			//---------敵のアクション----------------

			//ランダム変数

			plx = rand() % 4;
			ply = rand() % 4;


			//今いる場所と同じ場合、ランダム処理をやり直す
			if (memx == plx && memy == ply)
			{
				plx = rand() % 4;
				ply = rand() % 4;
			}


			switch (plx)
			{

				//plxが０の場合＝map[0][](上)に移動
			case 0:

				//ply=0　map[0][2]
				if (ply == 0)
				{
					p_x = 80.0f;
					atr_x = 0.0f;
					cs_xe = 0.0f;

					p_y = 0.0f;
					atr_y = 0.0f;

				}

				//ply=1　map[0][5]
				if (ply == 1)
				{
					p_x = 200.0f;
					atr_x = 120.0f;
					cs_xe = 0.0f;

					p_y = 0.0f;
					atr_y = 0.0f;
				}

				//ply=2　map[0][8]
				if (ply == 2)
				{
					p_x = 320.0f;
					atr_x = 240.0f;
					cs_xe = 0.0f;

					p_y = 0.0f;
					atr_y = 0.0f;
				}

				//ply=3　map[0][11]
				if (ply == 3)
				{
					p_x = 440.0f;
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
					atr_x = -80.0f;
					cs_xe = 45.0f;

					p_y = 80.0f;
					atr_y = 80.0f;
				}

				//ply=1　map[0][5]
				if (ply == 1)
				{
					p_x = 0.0f;
					atr_x = -80.0f;
					cs_xe = 45.0f;

					p_y = 200.0f;
					atr_y = 200.0f;
				}

				//ply=2　map[0][8]
				if (ply == 2)
				{
					p_x = 0.0f;
					atr_x = -80.0f;
					cs_xe = 45.0f;

					p_y = 320.0f;
					atr_y = 320.0f;
				}

				//ply=3　map[0][11]
				if (ply == 3)
				{
					p_x = 0.0f;
					atr_x = -80.0f;
					cs_xe = 45.0f;

					p_y = 440.0f;
					atr_y = 440.0f;
				}
				break;

				//plxが２の場合＝map[][13](右)に移動
			case 2:

				//ply=0　map[2][13]
				if (ply == 0)
				{
					atr_x = 440.0f;
					p_x = 520.0f;
					cs_xe = 140.0f;

					p_y = 80.0f;
					atr_y = 80.0f;
				}

				//ply=0　map[5][13]
				if (ply == 1)
				{
					atr_x = 440.0f;
					p_x = 520.0f;
					cs_xe = 140.0f;

					p_y = 200.0f;
					atr_y = 200.0f;
				}

				//ply=0　map[8][13]
				if (ply == 2)
				{
					atr_x = 440.0f;
					p_x = 520.0f;
					cs_xe = 140.0f;

					p_y = 320.0f;
					atr_y = 320.0f;
				}

				//ply=0　map[11][13]
				if (ply == 3)
				{
					atr_x = 440.0f;
					p_x = 520.0f;
					cs_xe = 140.0f;

					p_y = 440.0f;
					atr_y = 440.0f;
				}

				break;

				//plxが１の場合＝map[13][](下)に移動
			case 3:

				//ply=0　map[13][2]
				if (ply == 0)
				{
					p_x = 80.0f;
					atr_x = 0.0f;
					cs_xe = 0.0f;

					p_y = 520.0f;
					atr_y = 520.0f;

				}

				//ply=0　map[13][5]
				if (ply == 1)
				{
					p_x = 200.0f;
					atr_x = 120.0f;
					cs_xe = 0.0f;

					p_y = 520.0f;
					atr_y = 520.0f;

				}

				//ply=0　map[13][8]
				if (ply == 2)
				{
					p_x = 320.0f;
					atr_x = 240.0f;
					cs_xe = 0.0f;

					p_y = 520.0f;
					atr_y = 520.0f;

				}

				//ply=0　map[13][11]
				if (ply == 3)
				{
					p_x = 440.0f;
					atr_x = 360.0f;
					cs_xe = 0.0f;

					p_y = 520.0f;
					atr_y = 520.0f;

				}

			default:
				break;

			}

			//HPが０になったら破棄

			se = false;
		}
	}
	else
	{
		se = true;
	}

}

void CObjHardEnemy::Draw()
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

	src.m_top = 50.0f;
	src.m_left = 0.0f + cs_xe;
	src.m_right = 45.0f + cs_xe;
	src.m_bottom = 80.0f;

	dst.m_top = 0.0f + atr_y;
	dst.m_left = 80.0f + atr_x;
	dst.m_right = 120.0f + atr_x;
	dst.m_bottom = 40.0f + atr_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);

	src.m_top = 50.0f;
	src.m_left = 0.0f;
	src.m_right = 45.0f;
	src.m_bottom = 80.0f;

	dst.m_top = 250.0f;
	dst.m_left = 600.0f;
	dst.m_right = 640.0f;
	dst.m_bottom = 290.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}
