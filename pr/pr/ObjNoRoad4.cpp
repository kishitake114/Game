#include "ObjNoRoad4.h"
#include "ObjRoad4.h"
#include "GameHead.h"
#include "ObjPlayer.h"
#include "GameL/DrawTexture.h"

#define NOROAD4 26
#define NOROADSIZE4 22.0f

void CObjNoRoad4::Init()
{

}

void CObjNoRoad4::Action()
{
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	CObjRoad4* road = (CObjRoad4*)Objs::GetObj(OBJ_ROAD4);
	float px = player->GetX();
	float py = player->GetY();

	for (int i = 0; i < NOROAD4; i++)
	{
		for (int j = 0; j < NOROAD4; j++)
		{
			map[i][j] = road->map[i][j];
		}
	}

	//mapにアクセス
	for (int i = 0; i < NOROAD4; i++)
	{
		for (int j = 0; j < NOROAD4; j++)
		{
			if (map[i][j] < 2)
			{
				float x = j * NOROADSIZE4;
				float y = i * NOROADSIZE4;

				if ((px + NOROADSIZE4 > x) && (px < x + NOROADSIZE4) && (py + NOROADSIZE4 > y) && (py < y + NOROADSIZE4))
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
						player->SetVY(y - NOROADSIZE4);
					}

					//左
					else if (r > 135 && r < 225)
					{
						player->SetVX(x - NOROADSIZE4);
					}

					//下
					else if (r > 225 && r < 315)
					{
						player->SetVY(y + NOROADSIZE4);
					}

					else
					{
						player->SetVX(x + NOROADSIZE4);
					}

				}
			}
		}
	}
}

void CObjNoRoad4::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//表示：通行不可

	src.m_top = 90.0f;
	src.m_left = 286.0f;
	src.m_right = 329.0f;
	src.m_bottom = 125.0f;

	for (int i = 0; i < NOROAD4; i++)
	{
		for (int j = 0; j < NOROAD4; j++)
		{
			if (map[i][j] == 1)
			{
				dst.m_top = i * NOROADSIZE4;
				dst.m_left = j * NOROADSIZE4;
				dst.m_right = dst.m_left + NOROADSIZE4;
				dst.m_bottom = dst.m_top + NOROADSIZE4;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}
}

