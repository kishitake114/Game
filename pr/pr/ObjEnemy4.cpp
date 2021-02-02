#include "ObjEnemy4.h"
#include "ObjRoad4.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h" 
#include "GameL\HitBoxManager.h"
#include "GameL/Audio.h"

#include <stdlib.h>
#include <time.h>


//イニシャライズ
void CObjEnemy4::Init()
{
	srand(time(NULL));

	HP = 32;
	p_x = 176.0f;
	p_y = 0.0f;

	atr_x = 176.0f;
	atr_y = 0.0f;

	cs_xe = 150.0f;

	plx = 0;
	ply = 2;

	memx = 0;
	memy = 0;

	ran = 0;

	se = false;
	e_s = false;
	atk = false;



	Hits::SetHitBox(this, p_x, p_y, 22, 22, ELEMENT_ENEMY, OBJ_ENEMY4, 1);

}

//アクション
void CObjEnemy4::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(p_x, p_y);

	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	CObjTime* time = (CObjTime*)Objs::GetObj(OBJ_TIME);
	CObjRoad4* Road4 = (CObjRoad4*)Objs::GetObj(OBJ_ROAD4);

	if (e_s == true)
	{
		plx = rand() % 4;
		ply = rand() % 4;

		//---------敵のアクション----------------


		plx = rand() % 4;
		ply = rand() % 4;


		//今いる場所と同じ場合、ランダム処理をやり直す
		if (memx == plx && memy == ply)
		{
			plx = rand() % 4;
			ply = rand() % 4;
		}


		//ランダム変数

		plx = rand() % 4;
		ply = rand() % 8;


		if (memx == plx && memy == ply)
		{
			plx = rand() % 4;
			ply = rand() % 8;
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


			if (ply == 0)
			{
				p_x = 0.0f;
				atr_x = 0.0f;
				cs_xe = 0.0f;

				p_y = 44.0f;
				atr_y = 44.0f;

			}

			//ply=1　map[0][5]
			if (ply == 1)
			{
				p_x = 0.0f;
				atr_x = 0.0f;
				cs_xe = 0.0f;

				p_y = 110.0f;
				atr_y = 110.0f;
			}

			//ply=2　map[0][8]
			if (ply == 2)
			{
				p_x = 0.0f;
				atr_x = 0.0f;
				cs_xe = 0.0f;

				p_y = 176.0f;
				atr_y = 176.0f;
			}

			//ply=3　map[0][11]
			if (ply == 3)
			{
				p_x = 0.0f;
				atr_x = 0.0f;
				cs_xe = 0.0f;

				p_y = 506.0f;
				atr_y = 506.0f;
			}

			if (ply == 4)
			{
				p_x = 0.0f;
				atr_x = 0.0f;
				cs_xe = 0.0f;

				p_y = 242.0f;
				atr_y = 242.0f;
			}

			if (ply == 5)
			{
				p_x = 0.0f;
				atr_x = 0.0f;
				cs_xe = 0.0f;

				p_y = 308.0f;
				atr_y = 308.0f;
			}

			if (ply == 6)
			{
				p_x = 0.0f;
				atr_x = 0.0f;
				cs_xe = 0.0f;

				p_y = 374.0f;
				atr_y = 374.0f;
			}

			if (ply == 7)
			{
				p_x = 0.0f;
				atr_x = 0.0f;
				cs_xe = 0.0f;

				p_y = 440.0f;
				atr_y = 440.0f;
			}

			break;

			//plxが１の場合＝map[][0](左)に移動
		case 1:

			//ply=0　map[0][2]
			if (ply == 0)
			{
				p_x = 44.0f;
				atr_x = 44.0f;
				cs_xe = 150.0f;

				p_y = 0.0f;
				atr_y = 0.0f;

			}

			//ply=1　map[0][5]
			if (ply == 1)
			{
				p_x = 110.0f;
				atr_x = 110.0f;
				cs_xe = 150.0f;

				p_y = 0.0f;
				atr_y = 0.0f;
			}

			//ply=2　map[0][8]
			if (ply == 2)
			{
				p_x = 176.0f;
				atr_x = 176.0f;
				cs_xe = 150.0f;

				p_y = 0.0f;
				atr_y = 0.0f;
			}

			//ply=3　map[0][11]
			if (ply == 3)
			{
				p_x = 506.0f;
				atr_x = 506.0f;
				cs_xe = 150.0f;

				p_y = 0.0f;
				atr_y = 0.0f;
			}

			if (ply == 4)
			{
				p_x = 242.0f;
				atr_x = 242.0f;
				cs_xe = 150.0f;

				p_y = 0.0f;
				atr_y = 0.0f;
			}

			if (ply == 5)
			{
				p_x = 308.0f;
				atr_x = 308.0f;
				cs_xe = 150.0f;

				p_y = 0.0f;
				atr_y = 0.0f;
			}

			if (ply == 6)
			{
				p_x = 374.0f;
				atr_x = 374.0f;
				cs_xe = 150.0f;

				p_y = 0.0f;
				atr_y = 0.0f;
			}

			if (ply == 7)
			{
				p_x = 440.0f;
				atr_x = 440.0f;
				cs_xe = 150.0f;

				p_y = 0.0f;
				atr_y = 0.0f;
			}

			break;

			//plxが２の場合＝map[][13](右)に移動
		case 2:


			if (ply == 0)
			{
				p_x = 550.0f;
				atr_x = 550.0f;
				cs_xe = 100.0f;

				p_y = 44.0f;
				atr_y = 44.0f;

			}

			//ply=1　map[0][5]
			if (ply == 1)
			{
				p_x = 550.0f;
				atr_x = 550.0f;
				cs_xe = 100.0f;

				p_y = 110.0f;
				atr_y = 110.0f;
			}

			//ply=2　map[0][8]
			if (ply == 2)
			{
				p_x = 550.0f;
				atr_x = 550.0f;
				cs_xe = 100.0f;

				p_y = 176.0f;
				atr_y = 176.0f;
			}

			//ply=3　map[0][11]
			if (ply == 3)
			{
				p_x = 550.0f;
				atr_x = 550.0f;
				cs_xe = 100.0f;

				p_y = 506.0f;
				atr_y = 506.0f;
			}

			if (ply == 4)
			{
				p_x = 550.0f;
				atr_x = 550.0f;
				cs_xe = 100.0f;

				p_y = 242.0f;
				atr_y = 242.0f;
			}

			if (ply == 5)
			{
				p_x = 550.0f;
				atr_x = 550.0f;
				cs_xe = 100.0f;

				p_y = 308.0f;
				atr_y = 308.0f;
			}

			if (ply == 6)
			{
				p_x = 550.0f;
				atr_x = 550.0f;
				cs_xe = 100.0f;

				p_y = 374.0f;
				atr_y = 374.0f;
			}

			if (ply == 7)
			{
				p_x = 550.0f;
				atr_x = 550.0f;
				cs_xe = 100.0f;

				p_y = 440.0f;
				atr_y = 440.0f;
			}



			break;

			//plxが１の場合＝map[13][](下)に移動
		case 3:

			//ply=0　map[0][2]
			if (ply == 0)
			{
				p_x = 44.0f;
				atr_x = 44.0f;
				cs_xe = 50.0f;

				p_y = 550.0f;
				atr_y = 550.0f;

			}

			//ply=1　map[0][5]
			if (ply == 1)
			{
				p_x = 110.0f;
				atr_x = 110.0f;
				cs_xe = 150.0f;

				p_y = 550.0f;
				atr_y = 550.0f;
			}

			//ply=2　map[0][8]
			if (ply == 2)
			{
				p_x = 176.0f;
				atr_x = 176.0f;
				cs_xe = 150.0f;

				p_y = 550.0f;
				atr_y = 550.0f;
			}

			//ply=3　map[0][11]
			if (ply == 3)
			{
				p_x = 506.0f;
				atr_x = 506.0f;
				cs_xe = 150.0f;

				p_y = 550.0f;
				atr_y = 550.0f;
			}

			if (ply == 4)
			{
				p_x = 242.0f;
				atr_x = 242.0f;
				cs_xe = 150.0f;

				p_y = 550.0f;
				atr_y = 550.0f;
			}

			if (ply == 5)
			{
				p_x = 308.0f;
				atr_x = 308.0f;
				cs_xe = 150.0f;

				p_y = 550.0f;
				atr_y = 550.0f;
			}

			if (ply == 6)
			{
				p_x = 374.0f;
				atr_x = 374.0f;
				cs_xe = 150.0f;

				p_y = 550.0f;
				atr_y = 550.0f;
			}

			if (ply == 7)
			{
				p_x = 440.0f;
				atr_x = 440.0f;
				cs_xe = 150.0f;

				p_y = 550.0f;
				atr_y = 550.0f;
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
			se = true;

			HP = HP - player->atk;
			player->atk = 0;

			Road4->s_r = true;
			if (HP <= 0)
			{
				this->SetStatus(false);
				Hits::DeleteHitBox(this);
				Audio::Start(2);

				player->battle = true;
			}
			else if (HP > 0)
			{
				if (atk == false)
				{
					player->HP--;
					atk = true;
					Audio::Start(6);
				}
			}


			for (int i = 0; i < 26; i++)
			{
				for (int j = 0; j < 26; j++)
				{
					Road4->memmap[i][j] = Road4->map[i][j];
				}
			}

			time->m_time = 3600;


		}
	}

	else
	{
		se = false;
	}


}

//ドロー
void CObjEnemy4::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//表示：マウスカーソルとボタン
	wchar_t str[256];

	swprintf_s(str, L"Enemy HP");
	Font::StrDraw(str, 642, 290, 20, c);

	swprintf_s(str, L"%2d", HP);
	Font::StrDraw(str, 730, 295, 30, c);

	src.m_top = 10.0f;
	src.m_left = 10.0f + cs_xe;
	src.m_right = 40.0f + cs_xe;
	src.m_bottom = 35.0f;

	dst.m_top = 0.0f + atr_y;
	dst.m_left = 0.0f + atr_x;
	dst.m_right = 22.0f + atr_x;
	dst.m_bottom = 22.0f + atr_y;

	Draw::Draw(1, &src, &dst, c, 0.0f);

	src.m_top = 10.0f;
	src.m_left = 160.0f ;
	src.m_right = 190.0f;
	src.m_bottom = 35.0f;

	dst.m_top = 290.0f;
	dst.m_left = 600.0f;
	dst.m_right = 640.0f;
	dst.m_bottom = 330.0f;

	Draw::Draw(1, &src, &dst, c, 0.0f);

}
