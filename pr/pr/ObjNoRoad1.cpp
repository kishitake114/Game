#include "ObjNoRoad1.h"
#include "ObjRoad.h"
#include "GameHead.h"
#include "ObjPlayer.h"
#include "GameL/DrawTexture.h"

#define NOROAD1 14
#define NOROADSIZE1 40.0f

void CObjNoRoad1::Init()
{

}

void CObjNoRoad1::Action()
{
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	CObjRoad* road = (CObjRoad*)Objs::GetObj(OBJ_ROAD1);
	float px = player->GetX();
	float py = player->GetY();

	for (int i = 0; i < NOROAD1; i++)
	{
		for (int j = 0; j < NOROAD1; j++)
		{
			map[i][j] = road->map[i][j];
		}
	}

	//mapにアクセス
	for (int i = 0; i < NOROAD1; i++)
	{
		for (int j = 0; j < NOROAD1; j++)
		{
			if (map[i][j] < 2)
			{
				float x = j * NOROADSIZE1;
				float y = i * NOROADSIZE1;

				if ((px + NOROADSIZE1 > x) && (px < x + NOROADSIZE1) && (py + NOROADSIZE1 > y) && (py < y + NOROADSIZE1))
				{
					//ベクトル作成
					float vx = px - x;
					float vy = py - y;

					float len = sqrt(vx * vx + vy * vy);

					float r = atan2(vy, vx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
					{
						r = abs(r);
					}

					else
					{
						r = 360.0f - abs(r);
					}

					//上
					if (r > 45 && r < 135)
					{
						player->SetVY(y - NOROADSIZE1);
					}

					//左
					else if (r > 135 && r < 225)
					{
						player->SetVX(x - NOROADSIZE1);
					}

					//下
					else if (r > 225 && r < 315)
					{
						player->SetVY(y + NOROADSIZE1);
					}

					else
					{
						player->SetVX(x + NOROADSIZE1);
					}

				}
			}
		}
	}
}

void CObjNoRoad1::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//表示：通行不可
	src.m_top = 90.0f;
	src.m_left = 0.0f;
	src.m_right = 45.0f;
	src.m_bottom = 125.0f;

	for (int i = 0; i < NOROAD1; i++)
	{
		for (int j = 0; j < NOROAD1; j++)
		{
			if (map[i][j] == 1)
			{
				dst.m_top = i * NOROADSIZE1;
				dst.m_left = j * NOROADSIZE1;
				dst.m_right = dst.m_left + NOROADSIZE1;
				dst.m_bottom = dst.m_top + NOROADSIZE1;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}
}
