#include "ObjEnemy4.h"
#include "ObjStage4.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h" 
#include "GameL\HitBoxManager.h"

#include <stdlib.h>
#include <time.h>


//イニシャライズ
void CObjEnemy4::Init()
{
	srand(time(NULL));

	HP = 3;
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



	Hits::SetHitBox(this, p_x, p_y, 22, 22, ELEMENT_ENEMY, OBJ_ENEMY4, 1);

}

//アクション
void CObjEnemy4::Action()
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
			CObjStage4* Road4 = (CObjStage4*)Objs::GetObj(OBJ_STAGE4);


			HP = HP - player->atk;
			player->atk = 0;
			player->HP--;

			for (int i = 0; i < 17; i++)
			{
				for (int j = 0; j < 17; j++)
				{
					Road4->memmap[i][j] = Road4->map[i][j];
				}
			}

			time->m_time = 7200;


			se = false;

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

			//HPが０になったら破棄
			if (HP <= 0)
			{
				this->SetStatus(false);
				Hits::DeleteHitBox(this);

				Scene::SetScene(new CSceneClear());
			}
		}
	}
	else
	{
		se = true;
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

	swprintf_s(str, L"HP %d", HP);
	Font::StrDraw(str, 600, 400, 30, c);

	swprintf_s(str, L"%d", ran);
	Font::StrDraw(str, 600, 250, 30, c);

	swprintf_s(str, L"plx %d", plx);
	Font::StrDraw(str, 450, 300, 30, c);
	swprintf_s(str, L"ply %d", ply);
	Font::StrDraw(str, 450, 400, 30, c);

	src.m_top = 10.0f;
	src.m_left = 10.0f + cs_xe;
	src.m_right = 40.0f + cs_xe;
	src.m_bottom = 35.0f;

	dst.m_top = 0.0f + atr_y;
	dst.m_left = 0.0f + atr_x;
	dst.m_right = 22.0f + atr_x;
	dst.m_bottom = 22.0f + atr_y;

	Draw::Draw(1, &src, &dst, c, 0.0f);

}
