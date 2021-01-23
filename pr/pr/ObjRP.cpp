#include "ObjRP.h"
#include "GameL/DrawTexture.h"
#include "ObjPlayer.h"

void ObjRP::Init()
{

}

void ObjRP::Action()
{

}

void ObjRP::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float r[4] = { 1.0f,0.0f,0.0f,1.0f };
	float g[4] = { 0.0f,1.0f,0.0f,1.0f };
	float b[4] = { 0.0f,0.0f,1.0f,1.0f };


	RECT_F src;
	RECT_F dst;

	//表示：プレイヤー
	wchar_t str[256];

	src.m_top = 90.0f;
	src.m_left = 45.0f;
	src.m_right = 85.0f;
	src.m_bottom = 125.0f;

	dst.m_top = 40.0f;
	dst.m_left =  40.0f;
	dst.m_right = 80.0f;
	dst.m_bottom = 80.0f;

	Draw::Draw(2, &src, &dst, c, 0.0f);

}
