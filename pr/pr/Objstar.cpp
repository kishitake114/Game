#include "Objstar.h"
#include "ObjTitle.h"
#include "GameL/DrawTexture.h"

void CObjStar::Init()
{
}

void CObjStar::Action()
{
}

void CObjStar::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 211.0f;
	src.m_bottom = 211.0f;

	dst.m_top = 750.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 50.0f;

	Draw::Draw(2, &src, &dst, c, 0.0f);
}
