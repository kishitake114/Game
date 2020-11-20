//使用するヘッダー
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "ObjPlayer.h"
#include "ObjRoad.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h"
#include "GameL\HitBoxManager.h"
#include "GameL/Audio.h"

using namespace GameL;

//イニシャライズ
void CObjPlayer::Init()
{
	p_x = 0.0f;
	p_y = 200.0f;
	p_vx = 0.0f;
	p_vy = 200.0f;
	s_p = false;
	st_p = true;
	atr = true;

	sw = false;
	sei = false;

	cs_x = 0.0f;
	cs_y = 0.0f;

	HP = 10;

	count = '-';

	Hits::SetHitBox(this, p_x+40, p_y+40, 40, 40, ELEMENT_PLAYER, OBJ_PLAYER, 1);
}

//アクション
void CObjPlayer::Action()
{

	CObjRoad* obj = (CObjRoad*)Objs::GetObj(OBJ_ROAD);

	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

	if (mou_r == true)
	{
		s_p = true;
	}

	if (s_p == true)
	{
		if (atr == true)
		{
			CHitBox* hit = Hits::GetHitBox(this);
			hit->SetPos(p_x, p_y);

			if (Input::GetVKey('W') == true )
			{
				/*	Audio::Start(2);*/
				   
					p_y -= 10.0f;
					cs_x = 95.0f;
					count = '-';

			}

			else if (Input::GetVKey('A') == true)
			{
			/*	    Audio::Start(2);*/

					p_x -= 10.0f;
					cs_x = 140.0f;
					count = '-';


			}
			
			else if (Input::GetVKey('D') == true)
			{
				    /*Audio::Start(2);*/
	
					p_x += 10.0f;
					cs_x = 50.0f;
					count = '-';
	
			}

			else if (Input::GetVKey('S') == true )
			{
			/*	    Audio::Start(2);*/
			
					p_y += 10.0f;
					cs_x = 0.0;
					count = '-';

			}

			
			//チュートリアルステージの移動制御
			if (num == 0)
			{
				//ステージ左端から出ないようにする
				if (p_x < 0.0f)
				{
					p_x = 0.0f;
				}

				//-----------------map[][0]の制御-----------------

				//map[0～1][0]に入ったときのプログラム
				if (p_x<=0.0f && p_y >= 0.0f&& p_y < 80.0f)
				{
					p_y = 80.0f;
				}
				
				//map[3～4][0]に入ったときのプログラム
				if (p_x <= 0.0f && p_y > 120.0f && p_y < 200.0f)
				{

					p_y = 200.0f;
				}
				
				//map[6～7][0]に入ったときのプログラム
				if (p_x <= 0.0f && p_y >= 240.0f && p_y < 320.0f)
				{
					p_y = 200.0f;
				}

				//ステージ右端から出ないようにする
				if (p_x > 280.0f)
				{
					p_x = 280.0f;
				}

				//-----------------map[][13]の制御-----------------

				//map[0～1][13]に入ったときのプログラム
				if (p_x >= 280.0f && p_y >= 0.0f && p_y <= 80.0f)
				{
					p_y = 80.0f;
				}
				//map[3～4][13]に入ったときのプログラム
				if (p_x >= 280.0f && p_y >= 120.0f && p_y <= 200.0f)
				{
					p_y = 200.0f;
				}
				//map[6～7][13]に入ったときのプログラム
				if (p_x >= 280.0f && p_y >= 240.0f && p_y <= 320.0f)
				{
					p_y = 200.0f;
				}

				//ステージ上端から出ないようにする
				if (p_y < 0.0f)
				{
					p_y = 0.0f;
				}

				//ステージ下端から出ないようにする
				if (p_y > 280.0f)
				{
					p_y = 280.0f;
				}

			}
	
		}

		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(p_x, p_y);

			if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
			{
				s_p = false;
		

				if (cs_x == 95.0f)
				{
					p_y = -200.0f;
					p_vy = p_y+200.0f;

					cs_x = 0.0f;
				}

				if (cs_x == 140.0f)
				{
					p_x = 0.0f;
					p_vx = p_x / 40;

					cs_x = 45.0f;
				}

				if (cs_x == 50.0f)
				{
					p_x = 280.0f;
					p_vx = p_x;

					cs_x = 140.0f;
				}


				sw = true;

				sei = false;
				
		
				obj->s_r=true;

				HP--;

			}
	}

	if (HP <= 0)
		Scene::SetScene(new CSceneGameOver());
	

}


//ドロー
void CObjPlayer::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float r[4] = { 1.0f,0.0f,0.0f,1.0f };
	float g[4] = { 0.0f,1.0f,0.0f,1.0f };
	float b[4] = { 0.0f,0.0f,1.0f,1.0f };

	//表示：プレイヤー
	wchar_t str[256];

	if (sw == true)
	Font::StrDraw(L"左クリックでマウス操作", 500, 80, 20, b);
	else
	Font::StrDraw(L"OFF", 500, 80, 20, c);

	if (s_p == true)
	{
		Font::StrDraw(L"Player", 660, 40, 20, b);
		Font::StrDraw(L"操作\n W,A,S,D", 550, 300, 20, b);
	}

	swprintf_s(str, L"playerHP=%d", HP);
	Font::StrDraw(str, 600, 450, 30, c);

	swprintf_s(str, L"count=%c", count);
	Font::StrDraw(str, 600, 350, 30, c);

	swprintf_s(str, L"playerX=%f", p_x);
	Font::StrDraw(str, 600, 251, 25, c);
	swprintf_s(str, L"playerY=%fw", p_y);
	Font::StrDraw(str, 600, 276, 25, c);

	//表示：プレイヤー
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
		dst.m_top = 240.0f + p_y;
		dst.m_left = 0.0f + p_x;
		dst.m_right = 30.0f + p_x;
		dst.m_bottom = 270.0f + p_y;
	}

	if (num == 3)
	{
		dst.m_top = 200.0f + p_y;
		dst.m_left = 0.0f + p_x;
		dst.m_right = 25.0f + p_x;
		dst.m_bottom = 225.0f + p_y;
	}


	if (num == 4)
	{
		dst.m_top = 242.0f + p_y;
		dst.m_left = 0.0f + p_x;
		dst.m_right = 22.0f + p_x;
		dst.m_bottom = 264.0f + p_y;
	}


	Draw::Draw(0, &src, &dst, c, 0.0f);
}