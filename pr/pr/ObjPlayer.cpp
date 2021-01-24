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

	memp_x = p_x;
	memp_y = p_y;

	s_p = false;
	st_p = true;
	atr = true;

	sw = false;
	sei = false;

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
	CObjRoad* road = (CObjRoad*)Objs::GetObj(OBJ_ROAD1);
	CObjRoad2* Road2 = (CObjRoad2*)Objs::GetObj(OBJ_ROAD2);
	CObjRoad3* road3 = (CObjRoad3*)Objs::GetObj(OBJ_ROAD3);
	CObjStage4* road4 = (CObjStage4*)Objs::GetObj(OBJ_ROAD4);
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

			if (Input::GetVKey('W') == true || Input::GetVKey(VK_UP) == true)
			{
					//Audio::Start(1);
				   
					p_y -= 5.0f;
					cs_x = 95.0f;
					count = '-';

			}

			else if (Input::GetVKey('A') == true || Input::GetVKey(VK_LEFT) == true)
			{
				  // Audio::Start(1);

					p_x -=5.0f;
					cs_x = 140.0f;
					count = '-';


			}
			
			else if (Input::GetVKey('D') == true || Input::GetVKey(VK_RIGHT) == true)
			{
				   //Audio::Start(1);
	
					p_x += 5.0f;
					cs_x = 50.0f;
					count = '-';
	
			}

			else if (Input::GetVKey('S') == true || Input::GetVKey(VK_DOWN) == true)
			{
				   //Audio::Start(1);
			
					p_y += 5.0f;
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

	if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr|| hit->CheckObjNameHit(OBJ_HARD_ENEMY) != nullptr)
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

	if (hit->CheckObjNameHit(OBJ_ENEMY2) != nullptr|| hit->CheckObjNameHit(OBJ_HARD_ENEMY2) != nullptr)
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



	if (battle == false)
	{

		swprintf_s(str, L"ATK");
		Font::StrDraw(str, 642, 150, 20, c);

		swprintf_s(str, L"%2d", atk);
		Font::StrDraw(str, 730, 155, 30, c);

		swprintf_s(str, L"Player HP");
		Font::StrDraw(str, 642,200, 20, c);

		swprintf_s(str, L"%2d", HP);
		Font::StrDraw(str, 730, 205, 30, c);

	}


	swprintf_s(str, L"%d",((UserData*)Save::GetData())->Hperfect);
	Font::StrDraw(str, 0, 550, 30, c);

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

		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 45.0f;
		src.m_bottom = 45.0f;

		dst.m_top = 200.0f;
		dst.m_left = 600.0f;
		dst.m_right = 640.0f;
		dst.m_bottom = 240.0f;

		Draw::Draw(0, &src, &dst, c, 0.0f);

		src.m_top = 130.0f;
		src.m_left = 1.0f;
		src.m_right = 51.0f;
		src.m_bottom = 180.0f;

		dst.m_top = 150.0f;
		dst.m_left = 598.0f;
		dst.m_right = 642.0f;
		dst.m_bottom = 190.0f;

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