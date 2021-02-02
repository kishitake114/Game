#include "Background01.h"
#include "ObjRoad.h"
#include "ObjRoad2.h"
#include "GameHead.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"

void CObjBackGround01::Init()
{
	stage = ((UserData*)Save::GetData())->stage;
}

void CObjBackGround01::Action()
{

}

void CObjBackGround01::Draw()
{
	float one[4] = { 1.0f,1.0f,1.0f,1.0f };
	float two[4] = { 0.2f,0.3f,0.1f,1.0f };

	RECT_F src;
	RECT_F dst;
	if (stage == 1)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 512.0f;
		src.m_bottom = 512.0f;

		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;

		Draw::Draw(1, &src, &dst, one, 0.0f);
	}
	else if (stage == 2)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 512.0f;
		src.m_bottom = 512.0f;

		dst.m_top = 600.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 0.0f;

		Draw::Draw(1, &src, &dst, two, 0.0f);
	}
}
