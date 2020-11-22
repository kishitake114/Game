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

CObjPlayer::CObjPlayer(float x, float y)
{
	p_x = x;
	p_y = y;
}

//イニシャライズ
void CObjPlayer::Init()
{
	atk = 0;

	memp_x = p_x;
	memp_y = p_y;

	s_p = false;
	st_p = true;
	atr = true;

	sw = false;
	sei = false;

	cs_x = 50.0f;

	HP = 999;

	p_x = 0.0f;
	p_y = 0.0f;

	kt = 0;

	Hits::SetHitBox(this, p_x, p_y, 20, 20, ELEMENT_PLAYER, OBJ_PLAYER, 1);
	
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(p_x, p_y);

}

//アクション
void CObjPlayer::Action()
{
	CObjItem* item = (CObjItem*)Objs::GetObj(OBJ_ITEM);
	CObjRoad* road = (CObjRoad*)Objs::GetObj(OBJ_ROAD);
	CObjStage2* road2 = (CObjStage2*)Objs::GetObj(OBJ_STAGE2);
	CObjStage3* road3 = (CObjStage3*)Objs::GetObj(OBJ_STAGE3);
	CObjStage4* road4 = (CObjStage4*)Objs::GetObj(OBJ_STAGE4);
	CObjTime* Time = (CObjTime*)Objs::GetObj(OBJ_TIME);
	CObjEnemy* Enemy = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);

	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

	if (mou_r == true)
	{
			s_p = true;

			memp_x = p_x;
			memp_y = p_y;

	}

	if (s_p == true)
	{
	

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
				if (p_x < 0.0f)
				{
					p_x = 0.0f;
				}

				//ステージ上端から出ないようにする
				if (p_y < 0.0f)
				{
					Scene::SetScene(new CSceneMain);
				}

				//ステージ下端から出ないようにする
				if (p_y > 280.0f)
				{
					p_y = 280.0f;
				}

				//ステージ下端から出ないようにする
				if (p_x > 280.0f)
				{
					p_x = 280.0f;
				}

			}

			if (num == 1)
			{
				//----------------ステージから出ないようにするプログラム----------------------
				//ステージ左端から出ないようにする
				if (p_x < 0.0f)
				{
					p_x = 0.0f;
				}

				//ステージ上端から出ないようにする
				if (p_y < 0.0f)
				{
					p_y = 0.0f;
				}

				//ステージ下端から出ないようにする
				if (p_y > 520.0f)
				{
					p_y = 520.0f;
				}

				//ステージ下端から出ないようにする
				if (p_x > 520.0f)
				{
					p_x = 520.0f;
				}
				//------------------------------------------------------------------------------
			}

			if (num == 2)
			{
				//----------------ステージから出ないようにするプログラム----------------------
				//ステージ左端から出ないようにする
				if (p_x < 0.0f)
				{
					p_x = 0.0f;
				}

				//ステージ上端から出ないようにする
				if (p_y < 0.0f)
				{
					p_y = 0.0f;
				}

				//ステージ下端から出ないようにする
				if (p_y > 480.0f)
				{
					p_y = 480.0f;
				}

				//ステージ下端から出ないようにする
				if (p_x > 480.0f)
				{
					p_x = 480.0f;
				}
				//------------------------------------------------------------------------------
			}

			if (num == 3)
			{
				//----------------ステージから出ないようにするプログラム----------------------
				//ステージ左端から出ないようにする
				if (p_x < 0.0f)
				{
					p_x = 0.0f;
				}

				//ステージ上端から出ないようにする
				if (p_y < 0.0f)
				{
					p_y = 0.0f;
				}

				//ステージ下端から出ないようにする
				if (p_y > 475.0f)
				{
					p_y = 475.0f;
				}

				//ステージ下端から出ないようにする
				if (p_x > 475.0f)
				{
					p_x = 475.0f;
				}
				//------------------------------------------------------------------------------
			}

			if (num == 4)
			{
				//----------------ステージから出ないようにするプログラム----------------------
				//ステージ左端から出ないようにする
				if (p_x < 0.0f)
				{
					p_x = 0.0f;
				}

				//ステージ上端から出ないようにする
				if (p_y < 0.0f)
				{
					p_y = 0.0f;
				}

				//ステージ下端から出ないようにする
				if (p_y > 550.0f)
				{
					p_y = 550.0f;
				}

				//ステージ下端から出ないようにする
				if (p_x > 550.0f)
				{
					p_x = 550.0f;
				}
				//------------------------------------------------------------------------------
			}

	}

	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(p_x, p_y);

	if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
	{
		s_p = true;


		memp_x = p_x;
		memp_y = p_y;

		s_p = false;
		road->s_r = true;
		Time->m_flag_time = true;

		if (cs_x == 0.0f)
		{
			p_y = 520.0f;
			cs_x = 95.0f;
		}

		if (cs_x == 50.0f)
		{
			p_x = 0.0f;
			cs_x = 140.0f;
		}

		if (cs_x == 95.0f)
		{
			p_y = 0.0f;
			cs_x = 0.0f;
		}

		if (cs_x == 140)
		{
			p_x = 520.0f;
			cs_x = 50.0f;
		}
	}

	if (hit->CheckObjNameHit(OBJ_ENEMY2) != nullptr)
	{
		s_p = true;


		memp_x = p_x;
		memp_y = p_y;

		s_p = false;
		road2->s_r = true;
		Time->m_flag_time = true;

		if (cs_x == 0.0f)
		{
			p_y = 480.0f;
			cs_x = 95.0f;
		}

		if (cs_x == 50.0f)
		{
			p_x = 0.0f;
			cs_x = 140.0f;
		}

		if (cs_x == 95.0f)
		{
			p_y = 0.0f;
			cs_x = 0.0f;
		}

		if (cs_x == 140)
		{
			p_x = 480.0f;
			cs_x = 50.0f;
		}
	}

	if (hit->CheckObjNameHit(OBJ_ENEMY3) != nullptr)
	{
		s_p = true;


		memp_x = p_x;
		memp_y = p_y;

		s_p = false;
		road3->s_r = true;
		Time->m_flag_time = true;

		if (cs_x == 0.0f)
		{
			p_y = 475.0f;
			cs_x = 95.0f;
		}

		if (cs_x == 50.0f)
		{
			p_x = 0.0f;
			cs_x = 140.0f;
		}

		if (cs_x == 95.0f)
		{
			p_y = 0.0f;
			cs_x = 0.0f;
		}

		if (cs_x == 140)
		{
			p_x = 0.0f;
			cs_x = 50.0f;
		}
	}

	if (hit->CheckObjNameHit(OBJ_ENEMY4) != nullptr)
	{
		s_p = true;


		memp_x = p_x;
		memp_y = p_y;

		s_p = false;
		road4->s_r = true;
		Time->m_flag_time = true;

		if (cs_x == 0.0f)
		{
			p_y = 550.0f;
			cs_x = 95.0f;
		}

		if (cs_x == 50.0f)
		{
			p_x = 550.0f;
			cs_x = 140.0f;
		}

		if (cs_x == 95.0f)
		{
			p_y = 0.0f;
			cs_x = 0.0f;
		}

		if (cs_x == 140)
		{
			p_x = 0.0f;
			cs_x = 50.0f;
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

	swprintf_s(str, L"アタック=%d", atk);
	Font::StrDraw(str, 600, 450, 30, c);

	swprintf_s(str, L"num=%d", num);
	Font::StrDraw(str, 600, 200, 30, c);

	swprintf_s(str, L"切り取り=%f", cs_x);
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
		dst.m_top = 0.0f + p_y;
		dst.m_left = 0.0f + p_x;
		dst.m_right = 30.0f + p_x;
		dst.m_bottom = 30.0f + p_y;
	}

	if (num == 3)
	{
		dst.m_top = 0.0f + p_y;
		dst.m_left = 0.0f + p_x;
		dst.m_right = 25.0f + p_x;
		dst.m_bottom = 25.0f + p_y;
	}


	if (num == 4)
	{
		dst.m_top = 0.0f + p_y;
		dst.m_left = 0.0f + p_x;
		dst.m_right = 22.0f + p_x;
		dst.m_bottom = 22.0f + p_y;
	}


	Draw::Draw(0, &src, &dst, c, 0.0f);
}