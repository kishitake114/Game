#include "ObjRP.h"
#include "ObjRoad.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "ObjPlayer.h"
#include "GameHead.h"

void CObjRP::Init()
{
	sw = false;
	sc = true;//true 全部灰色　false　それぞれで表示する
}

void CObjRP::Action()
{
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	sw=player->s_p;

	if (player->battle == true)
	{
		sc = true;
	}

}

void CObjRP::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float r[4] = { 1.0f,0.0f,0.0f,1.0f };
	float g[4] = { 0.0f,1.0f,0.0f,1.0f };
	float b[4] = { 0.0f,0.0f,1.0f,1.0f };
	float bl[4] = { 0.0f,0.0f,0.0f,1.0f };

	wchar_t str[256];

	RECT_F src;
	RECT_F dst;

	if (sc == false)
	{

	//表示　ROAD
	if (sw == false)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 85.0f;
		src.m_bottom = 40.0f;
	}

	else
	{
		src.m_top = 0.0f;
		src.m_left = 178.0f;
		src.m_right = 263.0f;
		src.m_bottom = 40.0f;
	}

		dst.m_top = 55.0f;
		dst.m_left = 600.0f;
		dst.m_right = 750.0f;
		dst.m_bottom = 105.0f;

		Draw::Draw(2, &src, &dst, c, 0.0f);
		
	//表示　PLAYER
	if (sw == true)
	{
		src.m_top = 0.0f;
		src.m_left = 88.0f;
		src.m_right = 173.0f;
		src.m_bottom = 40.0f;
	}

	else
	{
		src.m_top = 0.0f;
		src.m_left = 178.0f;
		src.m_right = 263.0f;
		src.m_bottom = 40.0f;

		
	}

		dst.m_top = 110.0f;
		dst.m_left = 600.0f;
		dst.m_right = 750.0f;
		dst.m_bottom = 160.0f;

		Draw::Draw(2, &src, &dst, c, 0.0f);
	}

	if (sw == false)
	{
		Font::StrDraw(L"ROAD", 645, 65, 30, c);
		Font::StrDraw(L"PLAYER", 630, 120, 30, bl);
	}

	else
	{
		Font::StrDraw(L"PLAYER", 630, 120, 30, c);
		Font::StrDraw(L"ROAD", 645, 65, 30, bl);
	}

	//開始前とクリア後の表示
	if(sc==true)
	{
		src.m_top = 0.0f;
		src.m_left = 178.0f;
		src.m_right = 263.0f;
		src.m_bottom = 40.0f;

		dst.m_top = 55.0f;
		dst.m_left = 600.0f;
		dst.m_right = 750.0f;
		dst.m_bottom = 105.0f;

		Draw::Draw(2, &src, &dst, c, 0.0f);

		src.m_top = 0.0f;
		src.m_left = 178.0f;
		src.m_right = 263.0f;
		src.m_bottom = 40.0f;

		dst.m_top = 110.0f;
		dst.m_left = 600.0f;
		dst.m_right = 750.0f;
		dst.m_bottom = 160.0f;

		Draw::Draw(2, &src, &dst, c, 0.0f);

		Font::StrDraw(L"ROAD", 645, 65, 30, bl);
		Font::StrDraw(L"PLAYER", 630, 120, 30, bl);
	}



}
