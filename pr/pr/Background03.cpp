#include "Background03.h"
#include "ObjRoad3.h"
#include "GameHead.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"

void CObjBackGround03::Init()
{

}

void CObjBackGround03::Action()
{

}

void CObjBackGround03::Draw()
{
	float c[4] = { 0.6f,0.6f,0.6f,1.0f };

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