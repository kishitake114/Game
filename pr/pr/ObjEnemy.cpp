#include "ObjEnemy.h"
#include "ObjRoad.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h" 
#include "GameL\HitBoxManager.h"

#include <stdlib.h>
#include <time.h>


//イニシャライズ
void CObjEnemy::Init()
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

	

	Hits::SetHitBox(this, p_x, p_y, 40, 40, ELEMENT_ENEMY, OBJ_ENEMY, 1);
	
}

//アクション
void CObjEnemy::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(p_x, p_y);


	if (se == true)
	{


		//プレイヤーと接触しているかどうかを調べる
		if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr)
		{

			se = false;

			//---------敵のアクション----------------

			//ランダム変数
	/*		plx = rand() % 4;
			ply = rand() % 4;*/

			plx = 2;
			ply = 0;

			//今いる場所と同じ場合、ランダム処理をやり直す
			if (memx == plx && memy == ply)
			{
				plx = rand() % 4;
				ply = rand() % 4;
			}

			//それ以外は、memx,memyにランダム内容を入れる
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
					atr_y =0.0f;
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

				//ply=0　map[2][2]
				if (ply == 0)
				{
					p_x = 0.0f;
					atr_x = -80.0f;
					cs_xe = 45.0f;

					p_y = 80.0f;
					atr_y = 80.0f;
				}

				//ply=1　map[2][5]
				if (ply == 1)
				{
					p_x = 0.0f;
					atr_x = -80.0f;
					cs_xe = 45.0f;

					p_y = 200.0f;
					atr_y = 200.0f;
				}

				//ply=2　map[2][8]
				if (ply == 2)
				{
					p_x = 0.0f;
					atr_x = -80.0f;
					cs_xe = 45.0f;

					p_y = 320.0f;
					atr_y = 320.0f;
				}

				//ply=3　map[2][11]
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

			HP -= 2;


			//HPが０になったら破棄
			if (HP == 0)
			{
				this->SetStatus(false);			
				Hits::DeleteHitBox(this);

				Scene::SetScene(new CSceneStage2());
			}
		}
	}
	else
	{
		se = true;
	}


}

//ドロー
void CObjEnemy::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//表示：マウスカーソルとボタン
	wchar_t str[256];

	swprintf_s(str, L"HP %d/10",HP);
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

	dst.m_top	 =  0.0f + atr_y;
	dst.m_left   = 80.0f +atr_x;
	dst.m_right  = 120.0f+atr_x;
	dst.m_bottom = 40.0f + atr_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);

}
