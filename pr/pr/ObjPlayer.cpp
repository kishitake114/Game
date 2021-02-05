//使用するヘッダー
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "ObjPlayer.h"
#include "ObjRoad.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h"
#include "GameL\HitBoxManager.h"
#include "GameL/Audio.h"
#include "GameL/UserData.h"

using namespace GameL;


//イニシャライズ
void CObjPlayer::Init()
{
	atk = 0;

	battle = false;

	updo = false;	//上　true 下　false
	side = false;	//左　true 右　false

	memp_x = p_x;
	memp_y = p_y;

	s_p = false;
	st_p = true;
	atr = true;

	sw = false;
	sei = false;

	w_time = 1;

	cs_x = 50.0f;

	HP = 5;

	p_x = 0.0f;
	p_y = 0.0f;

	tarn = 1;

	kt = 0;

	Hits::SetHitBox(this, p_x, p_y, 20, 20, ELEMENT_PLAYER, OBJ_PLAYER, 1);
	
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(p_x, p_y);

}

//アクション
void CObjPlayer::Action()
{
	adp_x = (int)p_x;
	adp_y = (int)p_y;

	CObjRoad* road = (CObjRoad*)Objs::GetObj(OBJ_ROAD1);
	CObjRoad2* Road2 = (CObjRoad2*)Objs::GetObj(OBJ_ROAD2);
	CObjRoad3* road3 = (CObjRoad3*)Objs::GetObj(OBJ_ROAD3);
	CObjRoad4* road4 = (CObjRoad4*)Objs::GetObj(OBJ_ROAD4);
	CObjTime* Time = (CObjTime*)Objs::GetObj(OBJ_TIME);
	CObjEnemy* Enemy = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
	CObjEnemy2* Enemy2 = (CObjEnemy2*)Objs::GetObj(OBJ_ENEMY2);
	CObjEnemy3* Enemy3 = (CObjEnemy3*)Objs::GetObj(OBJ_ENEMY3);
	CObjEnemy4* Enemy4 = (CObjEnemy4*)Objs::GetObj(OBJ_ENEMY4);

	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

	if (mou_r == true)
	{

			memp_x = p_x;
			memp_y = p_y;

	}

	if (s_p == true)
	{
		if (w_time % 10 == 0)
		{
			Audio::Start(1);
		}

			if (Input::GetVKey('W') == true || Input::GetVKey(VK_UP) == true)
			{
					w_time++;

					cs_x = 95.0f;
					if (num <= 1)
					{
						if (adp_x % 10 == 6)	p_x += 4.0;
						if (adp_x % 10 == 2)	p_x += 8.0;

						if (adp_x % 10 == 4)	p_x -= 4.0;
						if (adp_x % 10 == 8)	p_x -= 8.0;

						p_y -= 4.0f;
					}

					else if (num == 2)
					{
						if (adp_x % 10 == 3)		p_x -= 3.0;
						if (adp_x % 10 == 6)		p_x -= 6.0;
						if (adp_x % 10 == 9)		p_x -= 9.0;
						if (adp_x % 10 == 2)		p_x -= 12.0;

						if (adp_x % 10 == 8)		p_x += 12.0;
						if (adp_x % 10 == 1)		p_x += 9.0;
						if (adp_x % 10 == 4)		p_x += 6.0;
						if (adp_x % 10 == 7)		p_x += 3.0;

						p_y -= 3.0f;
					}

					else if (num == 3)
					{
						p_y -= 2.5f;
					}

					updo = true;


			}

			else if (Input::GetVKey('A') == true || Input::GetVKey(VK_LEFT) == true)
			{
					w_time++;

					cs_x = 140.0f;
					if (num <= 1)
					{
						if (adp_y % 10 == 6)	p_y += 4.0;
						if (adp_y % 10 == 2)	p_y += 8.0;

						if (adp_y % 10 == 4)	p_y -= 4.0;
						if (adp_y % 10 == 8)	p_y -= 8.0;

						p_x -= 4.0f;
					}

					else if (num == 2)
					{
						p_x -= 3.0f;
					}

					else if (num == 3)
					{
						p_x -= 2.5f;
					}

					side = true;
			}

			else if (Input::GetVKey('D') == true || Input::GetVKey(VK_RIGHT) == true)
			{
					w_time++;
				
					cs_x = 50.0f;
					if (num <= 1)
					{
						if (adp_y % 10 == 6)	p_y += 4.0;

						if (adp_y % 10 == 2)	p_y += 8.0;

						if (adp_y % 10 == 4)	p_y -= 4.0;
						if (adp_y % 10 == 8)	p_y -= 8.0;

						p_x += 4.0f;
					}

					else if (num == 2)
					{
						p_x += 3.0f;
					}

					else if (num == 3)
					{
						p_x += 2.5f;
					}

				

						side = false;
					
			}

			else if (Input::GetVKey('S') == true || Input::GetVKey(VK_DOWN) == true)
			{
					w_time++;
				
					cs_x = 0.0;
					if (num <= 1)
					{
						if (adp_x % 10 == 6)	p_x += 4.0;
						if (adp_x % 10 == 2)	p_x += 8.0;

						if (adp_x % 10 == 4)	p_x -= 4.0;
						if (adp_x % 10 == 8)	p_x -= 8.0;

						p_y += 4.0f;
					}

					else if (num == 2)
					{
						if (adp_x % 10 == 3)		p_x -= 3.0;
						if (adp_x % 10 == 6)		p_x -= 6.0;
						if (adp_x % 10 == 9)		p_x -= 9.0;
						if (adp_x % 10 == 2)		p_x -= 12.0;

						if (adp_x % 10 == 8)		p_x += 12.0;
						if (adp_x % 10 == 1)		p_x += 9.0;
						if (adp_x % 10 == 4)		p_x += 6.0;
						if (adp_x % 10 == 7)		p_x += 3.0;

						p_y += 3.0f;
					}

					else if (num == 3)
					{
						p_y += 2.5f;
					}

					updo = false;
			}
			else
			{
				w_time = 1;
				if (num <= 1)
				{

					if (adp_x % 10 == 6)		p_x += 4.0;
					if (adp_x % 10 == 2)		p_x += 8.0;

					if (adp_x % 10 == 4)		p_x -= 4.0;
					if (adp_x % 10 == 8)		p_x -= 8.0;

					if (adp_y % 10 == 6)		p_y += 4.0;
					if (adp_y % 10 == 2)		p_y += 8.0;

					if (adp_y % 10 == 4)		p_y -= 4.0;
					if (adp_y % 10 == 8)		p_y -= 8.0;
				}

				if (num == 2)
				{

					if (adp_x % 10 == 3)		p_x -= 3.0;
					if (adp_x % 10 == 6)		p_x -= 6.0;
					if (adp_x % 10 == 9)		p_x -= 9.0;
					if (adp_x % 10 == 2)		p_x -=12.0;

					if (adp_x % 10 == 8)		p_x += 12.0;
					if (adp_x % 10 == 1)		p_x +=  9.0;
					if (adp_x % 10 == 4)		p_x +=  6.0;
					if (adp_x % 10 == 7)		p_x +=  3.0;

					if (adp_y % 10 == 3)		p_y -= 3.0;
					if (adp_y % 10 == 6)		p_y -= 6.0;
					if (adp_y % 10 == 9)		p_y -= 9.0;
					if (adp_y % 10 == 2)		p_y -= 12.0;

					if (adp_y % 10 == 8)		p_y += 12.0;
					if (adp_y % 10 == 1)		p_y += 9.0;
					if (adp_y % 10 == 4)		p_y += 6.0;
					if (adp_y % 10 == 7)		p_y += 3.0;
				}

				if (num == 3)
				{
					if (adp_x % 20 == 0)
					{
						if (adp_x % 10 == 2)		p_x -= 2.5;
						if (adp_x % 10 == 5)		p_x -= 5.0;
						if (adp_x % 10 == 7)		p_x -= 7.5;
						if (adp_x % 10 == 0)		p_x -= 10.0;
					}

					else
					{
					/*	if (adp_x % 10 == 2)		p_x += 2.5;
						if (adp_x % 10 == 5)		p_x += 5.0;
						if (adp_x % 10 == 7)		p_x += 7.5;
						if (adp_x % 10 == 0)		p_x += 10.0;*/
					}

				

					/*if (adp_x % 10 == 8)		p_x += 12.0;
					if (adp_x % 10 == 1)		p_x += 9.0;
					if (adp_x % 10 == 4)		p_x += 6.0;
					if (adp_x % 10 == 7)		p_x += 3.0;

					if (adp_y % 10 == 3)		p_y -= 3.0;
					if (adp_y % 10 == 6)		p_y -= 6.0;
					if (adp_y % 10 == 9)		p_y -= 9.0;
					if (adp_y % 10 == 2)		p_y -= 12.0;

					if (adp_y % 10 == 8)		p_y += 12.0;
					if (adp_y % 10 == 1)		p_y += 9.0;
					if (adp_y % 10 == 4)		p_y += 6.0;
					if (adp_y % 10 == 7)		p_y += 3.0;*/
				}




			//	if(adp_y%10==6)
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
					battle = true;
					p_y = 0.0f;
					
				}

				//ステージ下端から出ないようにする
				if (p_y > 280.0f)
				{
					battle = true;
					p_y = 280.0f;
				}

				//ステージ下端から出ないようにする
				if (p_x > 280.0f)
				{
					battle = true;
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

		memp_x = p_x;
		memp_y = p_y;

		s_p = false;

		Time->m_flag_time = true;

		if (p_x-40.0f <= 0.0f)
		{
			p_x = 0.0f;
			cs_x = 95.0f;
		}

		if (p_x+40.0f >= 520.0f)
		{
			p_x = 520.0f;
			cs_x = 140.0f;
		}

		if (p_y-40.0f <= 0.0f)
		{
			p_y = 0.0f;
			cs_x = 0.0f;
		}

		if (p_y + 40.0f >= 520.0f)
		{
			p_y = 520.0f;

		}
	}

	if (hit->CheckObjNameHit(OBJ_ENEMY2) != nullptr)
	{

		memp_x = p_x;
		memp_y = p_y;

		s_p = false;
	
		Time->m_flag_time = true;

		if (p_x - 40.0f <= 0.0f)
		{
			p_x = 0.0f;
			cs_x = 95.0f;
		}

		if (p_x + 40.0f >= 480.0f)
		{
			p_x = 480.0f;
			cs_x = 140.0f;
		}

		if (p_y - 40.0f <= 0.0f)
		{
			p_y = 0.0f;
			cs_x = 0.0f;
		}

		if (p_y + 40.0f >= 480.0f)
		{
			p_y = 480.0f;

		}
	}

	if (hit->CheckObjNameHit(OBJ_ENEMY3) != nullptr)
	{
		memp_x = p_x;
		memp_y = p_y;

		s_p = false;

		Time->m_flag_time = true;

		if (p_x - 40.0f <= 0.0f)
		{
			p_x = 0.0f;
			cs_x = 95.0f;
		}

		if (p_x + 40.0f >= 475.0f)
		{
			p_x = 475.0f;
			cs_x = 140.0f;
		}

		if (p_y - 40.0f <= 0.0f)
		{
			p_y = 0.0f;
			cs_x = 0.0f;
		}

		if (p_y + 40.0f >= 475.0f)
		{
			p_y = 475.0f;

		}
	}

	if (hit->CheckObjNameHit(OBJ_ENEMY4) != nullptr)
	{
		s_p = true;

		memp_x = p_x;

		//550
		memp_y = p_y;

		s_p = false;
		road4->s_r = true;
		Time->m_flag_time = true;

		if (p_x - 40.0f <= 0.0f)
		{
			p_x = 0.0f;
			cs_x = 95.0f;
		}

		if (p_x + 40.0f >= 550.0f)
		{
			p_x = 550.0f;
			cs_x = 140.0f;
		}

		if (p_y - 40.0f <= 0.0f)
		{
			p_y = 0.0f;
			cs_x = 0.0f;
		}

		if (p_y + 40.0f >= 550.0f)
		{
			p_y = 550.0f;

		}
	}
	if (HP <= 0)
		Scene::SetScene(new CSceneGameOver());
	
	if (battle == true)
	{
		if (num >= 1)
		{
			Time->m_flag_time = false;
		}	

		s_p = false;
	}

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

	swprintf_s(str, L"p_x=%f", p_x);
	Font::StrDraw(str, 0, 0, 15, c);

	swprintf_s(str, L"p_y=%f", p_y);
	Font::StrDraw(str, 0, 20, 15, c);

	swprintf_s(str, L"p_x=%d", adp_x);
	Font::StrDraw(str, 0, 40, 15, c);

	swprintf_s(str, L"p_y=%d", adp_y);
	Font::StrDraw(str, 0, 60, 15, c);

	if(updo==true)
		Font::StrDraw(L"上", 600, 300, 25, c);
	else
		Font::StrDraw(L"下", 600, 300, 25, c);

	if (side == true)
		Font::StrDraw(L"左", 600, 330, 25, c);
	else
		Font::StrDraw(L"右", 600, 330, 25, c);

	if (battle == false)
	{

		swprintf_s(str, L"ATK");
		Font::StrDraw(str, 642, 200, 20, c);

		swprintf_s(str, L"%2d", atk);
		Font::StrDraw(str, 730, 205, 30, c);

		swprintf_s(str, L"Player HP");
		Font::StrDraw(str, 642,240, 20, c);

		swprintf_s(str, L"%2d", HP);
		Font::StrDraw(str, 730, 245, 30, c);

	}

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

	if (battle == false)
	{
		//主人公状況
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 45.0f;
		src.m_bottom = 45.0f;

		dst.m_top = 240.0f;
		dst.m_left = 600.0f;
		dst.m_right = 640.0f;
		dst.m_bottom = 280.0f;

		Draw::Draw(0, &src, &dst, c, 0.0f);

		//攻撃状況
		src.m_top = 130.0f;
		src.m_left = 1.0f;
		src.m_right = 51.0f;
		src.m_bottom = 180.0f;

		dst.m_top = 200.0f;
		dst.m_left = 600.0f;
		dst.m_right = 640.0f;
		dst.m_bottom = 240.0f;

		Draw::Draw(0, &src, &dst, c, 0.0f);
	}

	if (s_p == false)
	{

		src.m_top = 450.0f;
		src.m_left = 0.0f;
		src.m_right = 512.0f;
		src.m_bottom = 480.0f;
	}	

	else
	{
		src.m_top = 482.0f;
		src.m_left = 0.0f;
		src.m_right = 512.0f;
		src.m_bottom = 512.0f;
	}

	dst.m_top = 565.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 595.0f;

	Draw::Draw(2, &src, &dst, c, 0.0f);

}