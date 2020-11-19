#include "ObjEnemy2.h"
#include "ObjRoad.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h" 
#include "GameL\HitBoxManager.h"

#include <stdlib.h>
#include <time.h>


//イニシャライズ
void CObjEnemy2::Init()
{
	srand(time(NULL));

	HP = 999;
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



	Hits::SetHitBox(this, p_x, p_y, 40, 40, ELEMENT_ENEMY, OBJ_ENEMY2, 1);

}

//アクション
void CObjEnemy2::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(p_x, p_y);


	if (se == true)
	{


		//プレイヤーと接触しているかどうかを調べる
		if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr)
		{
			ran = 1;

			se = false;

			plx = rand() % 4;
			ply = rand() % 4;

			if (memx == plx && memy == ply)
			{
				plx = rand() % 4;
				ply = rand() % 4;
			}

			else
			{
				memx = plx;
				memy = ply;
			}


			switch (plx)
			{
			case 0:

				if (ply > 2)
				{
					ply -= 2;
				}

				if (ply == 0)
				{
					p_x = 80.0f;
					atr_x = 0.0f;
					cs_xe = 0.0f;

					p_y = 0.0f;
					atr_y = 0.0f;

				}

				if (ply == 1)
				{
					p_x = 80.0f;
					atr_x = 0.0f;
					cs_xe = 93.0f;

					p_y = 280.0f;
					atr_y = 280.0f;
				}

				break;

			case 1:

				if (ply > 2)
				{
					ply -= 2;
				}

				if (ply == 0)
				{
					p_x = 200.0f;
					atr_x = 120.0f;
					cs_xe = 0.0f;

					p_y = 0.0f;
					atr_y = 0.0f;
				}

				if (ply == 1)
				{
					p_x = 200.0f;
					atr_x = 120.0f;
					cs_xe = 93.0f;

					p_y = 280.0f;
					atr_y = 280.0f;
				}
				break;

			case 2:


				if (ply < 2)
				{
					ply += 2;
				}

				if (ply == 2)
				{
					atr_x = -80.0f;
					p_x = 0.0f;
					cs_xe = 45.0f;

					p_y = 80.0f;
					atr_y = 80.0f;
				}

				if (ply == 3)
				{
					atr_x = -80.0f;
					p_x = 0.0f;
					cs_xe = 45.0f;

					p_y = 200.0f;
					atr_y = 200.0f;
				}
				break;

			case 3:

				if (ply < 2)
				{
					ply += 2;
				}

				if (ply == 2)
				{
					atr_x = 200.0f;
					p_x = 280.0f;
					cs_xe = 140.0f;

					p_y = 80.0f;
					atr_y = 80.0f;
				}

				if (ply == 3)
				{
					atr_x = 200.0f;
					p_x = 280.0f;
					cs_xe = 140.0f;

					p_y = 200.0f;
					atr_y = 200.0f;
				}

			default:
				break;

			}

			HP -= 1;


			//HPが０になったら破棄
			if (HP == 0)
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
void CObjEnemy2::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//表示：マウスカーソルとボタン
	wchar_t str[256];

	swprintf_s(str, L"HP %d/999", HP);
	Font::StrDraw(str, 600, 400, 30, c);

	swprintf_s(str, L"%d", ran);
	Font::StrDraw(str, 600, 250, 30, c);

	swprintf_s(str, L"plx %d", plx);
	Font::StrDraw(str, 450, 300, 30, c);
	swprintf_s(str, L"ply %d", ply);
	Font::StrDraw(str, 450, 400, 30, c);

	src.m_top = 50.0f;
	src.m_left = 0.0f + cs_xe;
	src.m_right = 45.0f + cs_xe;
	src.m_bottom = 80.0f;

	dst.m_top = 0.0f + atr_y;
	dst.m_left = 60.0f + atr_x;
	dst.m_right = 120.0f + atr_x;
	dst.m_bottom = 40.0f + atr_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);

}