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

	HP = 2;
	p_x = 80.0f;
	p_y = 0.0f;

	atr_x = 0.0f;
	atr_y = 0.0f;

	plx = 0;
	ply = 0;

	

	Hits::SetHitBox(this, p_x, p_y, 40, 40, ELEMENT_ENEMY, OBJ_ENEMY, 1);
	
}

//アクション
void CObjEnemy::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(p_x, p_y);


	//プレイヤーと接触しているかどうかを調べる
	if ( hit->CheckObjNameHit(OBJ_PLAYER) != nullptr)
	{
		ran = 1;
		plx = rand() % 4;
		ply = rand() % 4;

		plx = 1;
		ply = 1;

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

					p_y = 0.0f;
					atr_y = 0.0f;
				}

				if (ply == 1)
				{
					p_x = 80.0f;
					atr_x = 0.0f;

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

					p_y = 0.0f;
					atr_y = 0.0f;
				}

				if (ply == 1)
				{
					p_x = 200.0f;
					atr_x = 120.0f;

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
					p_x =0.0f;

					p_y = 80.0f;
					atr_y = 80.0f;
				}

				if (ply == 3)
				{
					atr_x = -80.0f;
					p_x = 0.0f;

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

					p_y = 80.0f;
					atr_y = 80.0f;
				}

				if (ply == 3)
				{
					atr_x = 200.0f;
					p_x = 280.0f;

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

			Scene::SetScene(new CSceneClear());
		}
	}
	else
	{
		ran = 0;
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

	swprintf_s(str, L"HP %d/2",HP);
	Font::StrDraw(str, 600, 400, 30, c);

	swprintf_s(str, L"%d", ran);
	Font::StrDraw(str, 600, 250, 30, c);

	swprintf_s(str, L"plx %d", plx);
	Font::StrDraw(str, 450, 300, 30, c);	
	swprintf_s(str, L"ply %d", ply);
	Font::StrDraw(str, 450, 400, 30, c);

	src.m_top = 50.0f;
	src.m_left = 0.0f;
	src.m_right = 45.0f;
	src.m_bottom = 80.0f;

	dst.m_top	 =  0.0f + atr_y;
	dst.m_left   = 80.0f +atr_x;
	dst.m_right  = 120.0f+atr_x;
	dst.m_bottom = 40.0f + atr_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);

}
