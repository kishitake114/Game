#include "ObjNoRoad3.h"
#include "ObjRoad3.h"
#include "GameHead.h"
#include "ObjPlayer.h"
#include "GameL/DrawTexture.h"

#define NOROAD3 20
#define NOROADSIZE3 25.0f

void CObjNoRoad3::Init()
{

}

void CObjNoRoad3::Action()
{
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	CObjRoad3* road = (CObjRoad3*)Objs::GetObj(OBJ_ROAD3);
	float px = player->GetX();
	float py = player->GetY();

	for (int i = 0; i < NOROAD3; i++)
	{
		for (int j = 0; j < NOROAD3; j++)
		{
			map[i][j] = road->map[i][j];
		}
	}

	//通行不可
	for (int i = 0; i < NOROAD3; i++)
	{
		for (int j = 0; j < NOROAD3; j++)
		{
			if (map[i][j] <= 1)
			{
				float x = j * NOROADSIZE3;
				float y = i * NOROADSIZE3;

				if ((px + NOROADSIZE3 > x) && (px < x + NOROADSIZE3) && (py + NOROADSIZE3 > y) && (py < y + NOROADSIZE3))
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
						player->SetVY(y - NOROADSIZE3);
					}

					//左
					else if (r > 135 && r < 225)
					{
						player->SetVX(x - NOROADSIZE3);
					}

					//下
					else if (r > 225 && r < 315)
					{
						player->SetVY(y + NOROADSIZE3);
					}

					else
					{
						player->SetVX(x + NOROADSIZE3);
					}

				}

			}


		}

	}

}

void CObjNoRoad3::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//表示：通行不可
	src.m_top = 90.0f;
	src.m_left = 195.0f;
	src.m_right = 224.0f;
	src.m_bottom = 125.0f;

	for (int i = 0; i < NOROAD3; i++)
	{
		for (int j = 0; j < NOROAD3; j++)
		{
			if (map[i][j] == 1)
			{
				dst.m_top = i * NOROADSIZE3;
				dst.m_left = j * NOROADSIZE3;
				dst.m_right = dst.m_left + NOROADSIZE3;
				dst.m_bottom = dst.m_top + NOROADSIZE3;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}
}
