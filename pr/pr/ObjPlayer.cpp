//使用するヘッダー
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "ObjPlayer.h"
#include "ObjRoad.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h"
#include "GameL\HitBoxManager.h"


using namespace GameL;

//イニシャライズ
void CObjPlayer::Init()
{
	p_x = 0.0f;
	p_y = 0.0f;
	p_vx = 0.0f;
	p_vy = 200.0f;
	s_p = false;
	st_p = true;
	atr = true;

	cs_x = 0.0f;
	cs_y = 0.0f;

	Hits::SetHitBox(this, p_vx+40, p_vy+40, 40, 40, ELEMENT_PLAYER, OBJ_PLAYER, 1);
}

//アクション
void CObjPlayer::Action()
{
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
	
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(p_vx, p_vy);

		if (hit->CheckObjNameHit(OBJ_NO_ROAD) != nullptr)
		{
			atr = true;
		}
		else
		{
			atr = false;
		}



		if (Input::GetVKey('W') == true)
		{
			if (atr==true)
			{
				p_y += 0.0f;
				p_y += 10.0f;
				p_vy +=10.0f;
				atr = false;
			}
			else
			{
				p_y -= 10.0f;
				p_vy -= 10.0f;
				cs_x = 95.0f;
			}

		}

		if (Input::GetVKey('A') == true)
		{
			if (atr == true)
			{
				p_x -= 0.0f;
				p_x += 10.0f;
				p_vx += 10.0f;
				atr = false;
			}
			else
			{
				p_x -= 10.0f;
				p_vx -= 10.0f;	
				cs_x = 140.0f;
			
			}
		}

		if (Input::GetVKey('D') == true)
		{

			if (atr == true)
			{
				p_x += 0.0f;
				p_x -= 10.0f;
				p_vx -= 10.0f;
				atr = false;
			}
			else
			{
				p_x += 10.0f;
				p_vx += 10.0f;
				cs_x = 45.0f;
			}
	
		}

		if (Input::GetVKey('S') == true)
		{

			if (atr == true)
			{
				p_y -= 0.0f;	
				p_y -= 10.0f;
				p_vy -= 10.0f;
				atr = false;
			}
			else
			{
				p_y += 10.0f;
				p_vy += 10.0f;
				cs_x = 0.0f;
			}
		}
		


	}

	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(p_vx, p_vy);

		if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
		{
			if (cs_x == 95.0f)
			{
				p_y = -200.0f;
				p_vy = p_y/200;

				cs_x = 0.0f;
			}

			if (cs_x == 140.0f)
			{
				p_x = 0.0f;
				p_vx = p_x / 40;

				cs_x = 45.0f;
			}

			s_p = false;
		}



}

//ドロー
void CObjPlayer::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//表示：プレイヤー
	wchar_t str[256];

	if (s_p == true)
	{
		Font::StrDraw(L"Player", 660, 40, 20, c);
		Font::StrDraw(L"操作\n W,A,S,D", 550, 300, 20, c);
	}


	//表示：プレイヤー
	RECT_F src;
	RECT_F dst;

	src.m_top     = 0.0f ;
	src.m_left    = 0.0f  + cs_x;
	src.m_right   = 45.0f + cs_x;
	src.m_bottom  = 45.0f;

	dst.m_top    = 200.0f + p_y;
	dst.m_left   =   0.0f + p_x;
	dst.m_right  =  40.0f + p_x;
	dst.m_bottom = 240.0f + p_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}
