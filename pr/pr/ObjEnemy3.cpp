#include "ObjEnemy3.h"
#include "ObjStage3.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h" 
#include "GameL\HitBoxManager.h"
#include "GameL/Audio.h"

#include <stdlib.h>
#include <time.h>


//イニシャライズ
void CObjEnemy3::Init()
{
	srand(time(NULL));

	HP = 25;
	p_x = 200.0f;
	p_y = 0.0f;

	atr_x = 200.0f;
	atr_y = 0.0f;

	cs_xe = 0.0f;

	plx = 0;
	ply = 3;

	memx = 0;
	memy = 0;

	ran = 0;

	se = false;



	Hits::SetHitBox(this, p_x, p_y, 25, 25, ELEMENT_ENEMY, OBJ_ENEMY3, 1);

}

//アクション
void CObjEnemy3::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(p_x, p_y);


	if (se == true)
	{


		//プレイヤーと接触しているかどうかを調べる
		if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr)
		{
			ran = 1;

			CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
			CObjTime* time = (CObjTime*)Objs::GetObj(OBJ_TIME);
			CObjStage3* Road3 = (CObjStage3*)Objs::GetObj(OBJ_STAGE3);


			HP = HP - player->atk;
			player->atk = 0;
			if (HP <= 0)
			{
				this->SetStatus(false);
				Hits::DeleteHitBox(this);

				Audio::Start(2);

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
					Road3->memmap[i][j] = Road3->map[i][j];
				}
			}

			time->m_time = 7200;


			se = false;

			plx = rand() % 4;
			ply = rand() % 6;


			if (memx == plx && memy == ply)
			{
				plx = rand() % 4;
				ply = rand() % 6;
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
					p_x = 50.0f;
					atr_x = 50.0f;
					cs_xe = 0.0f;

					p_y = 0.0f;
					atr_y = 0.0f;

				}

				//ply=1　map[0][5]
				if (ply == 1)
				{
					p_x = 125.0f;
					atr_x = 125.0f;
					cs_xe = 0.0f;

					p_y = 0.0f;
					atr_y = 0.0f;
				}

				//ply=2　map[0][8]
				if (ply == 2)
				{
					p_x = 200.0f;
					atr_x = 200.0f;
					cs_xe = 0.0f;

					p_y = 0.0f;
					atr_y = 0.0f;
				}

				//ply=3　map[0][11]
				if (ply == 3)
				{
					p_x = 275.0f;
					atr_x = 275.0f;
					cs_xe = 0.0f;

					p_y = 0.0f;
					atr_y = 0.0f;
				}

				if (ply == 4)
				{
					p_x = 350.0f;
					atr_x = 350.0f;
					cs_xe = 0.0f;

					p_y = 0.0f;
					atr_y = 0.0f;
				}

				if (ply == 5)
				{
					p_x = 425.0f;
					atr_x = 425.0f;
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
					atr_x = 0.0f;
					cs_xe = 100.0f;

					p_y = 50.0f;
					atr_y = 50.0f;
				}

				//ply=1　map[0][5]
				if (ply == 1)
				{
					p_x = 0.0f;
					atr_x = 0.0f;
					cs_xe = 100.0f;

					p_y = 125.0f;
					atr_y = 125.0f;
				}

				//ply=2　map[0][8]
				if (ply == 2)
				{
					p_x = 0.0f;
					atr_x = 0.0f;
					cs_xe = 100.0f;

					p_y = 200.0f;
					atr_y = 200.0f;
				}

				//ply=3　map[0][11]
				if (ply == 3)
				{
					p_x = 0.0f;
					atr_x = 0.0f;
					cs_xe = 100.0f;

					p_y = 275.0f;
					atr_y = 275.0f;
				}

				//ply=3　map[0][11]
				if (ply == 4)
				{
					p_x = 0.0f;
					atr_x = 0.0f;
					cs_xe = 100.0f;

					p_y = 350.0f;
					atr_y = 350.0f;
				}

				if (ply == 5)
				{
					p_x = 0.0f;
					atr_x = 0.0f;
					cs_xe = 100.0f;

					p_y = 425.0f;
					atr_y = 425.0f;
				}
				break;

				//plxが２の場合＝map[][13](右)に移動
			case 2:

				if (ply == 0)
				{
					p_x = 0.0f;
					atr_x = 0.0f;
					cs_xe = 100.0f;

					p_y = 50.0f;
					atr_y = 50.0f;
				}

				//ply=1　map[0][5]
				if (ply == 1)
				{
					p_x = 0.0f;
					atr_x = 0.0f;
					cs_xe = 100.0f;

					p_y = 125.0f;
					atr_y = 150.0f;
				}

				//ply=2　map[0][8]
				if (ply == 2)
				{
					p_x = 0.0f;
					atr_x = 0.0f;
					cs_xe = 100.0f;

					p_y = 200.0f;
					atr_y = 200.0f;
				}

				//ply=3　map[0][11]
				if (ply == 3)
				{
					p_x = 0.0f;
					atr_x = 0.0f;
					cs_xe = 100.0f;

					p_y = 275.0f;
					atr_y = 275.0f;
				}

				//ply=3　map[0][11]
				if (ply == 4)
				{
					p_x = 0.0f;
					atr_x = 0.0f;
					cs_xe = 100.0f;

					p_y = 350.0f;
					atr_y = 350.0f;
				}

				if (ply == 5)
				{
					p_x = 0.0f;
					atr_x = 0.0f;
					cs_xe = 100.0f;

					p_y = 425.0f;
					atr_y = 425.0f;
				}
				

				break;

				//plxが１の場合＝map[13][](下)に移動
			case 3:

				//ply=0　map[0][2]
				if (ply == 0)
				{
					p_x = 475.0f;
					atr_x = 475.0f;
					cs_xe = 55.0f;

					p_y = 50.0f;
					atr_y = 50.0f;
				}

				//ply=1　map[0][5]
				if (ply == 1)
				{
					p_x = 475.0f;
					atr_x = 475.0f;
					cs_xe = 55.0f;

					p_y = 125.0f;
					atr_y = 125.0f;
				}

				//ply=2　map[0][8]
				if (ply == 2)
				{
					p_x = 475.0f;
					atr_x = 475.0f;
					cs_xe = 55.0f;

					p_y = 200.0f;
					atr_y = 200.0f;
				}

				//ply=3　map[0][11]
				if (ply == 3)
				{
					p_x = 475.0f;
					atr_x = 475.0f;
					cs_xe = 55.0f;

					p_y = 275.0f;
					atr_y = 275.0f;
				}

				//ply=3　map[0][11]
				if (ply == 4)
				{
					p_x = 475.0f;
					atr_x = 475.0f;
					cs_xe = 55.0f;

					p_y = 350.0f;
					atr_y = 350.0f;
				}

				if (ply == 5)
				{
					p_x = 475.0f;
					atr_x = 475.0f;
					cs_xe = 55.0f;

					p_y = 425.0f;
					atr_y = 425.0f;
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

//ドロー
void CObjEnemy3::Draw()
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

	src.m_top = 64.0f;
	src.m_left =10.0f + cs_xe;
	src.m_right = 40.0f + cs_xe;
	src.m_bottom = 84.0f;

	dst.m_top = 0.0f + atr_y;
	dst.m_left = 0.0f + atr_x;
	dst.m_right = 25.0f + atr_x;
	dst.m_bottom = 25.0f + atr_y;

	Draw::Draw(1, &src, &dst, c, 0.0f);

	src.m_top = 64.0f;
	src.m_left = 10.0f ;
	src.m_right = 40.0f;
	src.m_bottom = 84.0f;

	dst.m_top = 250.0f;
	dst.m_left = 600.0f;
	dst.m_right = 640.0f;
	dst.m_bottom = 290.0f;

	Draw::Draw(1, &src, &dst, c, 0.0f);

}
