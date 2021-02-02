#include "Background04.h"
#include "ObjRoad4.h"
#include "GameHead.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"

void CObjBackGround04::Init()
{

}

void CObjBackGround04::Action()
{

}

void CObjBackGround04::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(3, &src, &dst, c, 0.0f);
}