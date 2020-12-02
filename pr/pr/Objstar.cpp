#include "Objstar.h"
#include "ObjTitle.h"
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL/UserData.h"

void CObjStar::Init()
{
	HardStar = ((UserData*)Save::GetData())->Hperfect;
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

	for (int i = 0; i < HardStar; i++)
	{
		dst.m_top = 310.0f;
		dst.m_left = 410.0f + (i * 25.0f);
		dst.m_right = dst.m_left +25.0f;
		dst.m_bottom = dst.m_top+25.0f;

		Draw::Draw(2, &src, &dst, c, 0.0f);
	}


}
