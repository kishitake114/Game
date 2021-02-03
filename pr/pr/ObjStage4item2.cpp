#include "ObjStage4item2.h"
#include "ObjRoad4.h"
#include "GameHead.h"
#include "ObjPlayer.h"
#include "GameL/DrawTexture.h"
#include"GameL/Audio.h"

#define ITEM42 26
#define ITEMSIZE42 22.0f

void CObjStage4item2::Init()
{
}

void CObjStage4item2::Action()
{
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	CObjRoad4* road = (CObjRoad4*)Objs::GetObj(OBJ_ROAD4);
	float px = player->GetX();
	float py = player->GetY();

	for (int i = 0; i < ITEM42; i++)
	{
		for (int j = 0; j < ITEM42; j++)
		{
			map[i][j] = road->map[i][j];
		}
	}

	//アイテム（２）
	for (int i = 0; i < ITEM42; i++)
	{
		for (int j = 0; j < ITEM42; j++)
		{
			if (map[i][j] == 4)
			{
				float x = j * ITEMSIZE42;
				float y = i * ITEMSIZE42;

				if ((px + ITEMSIZE42 > x) && (px < x + ITEMSIZE42) && (py + ITEMSIZE42 > y) && (py < y + ITEMSIZE42))
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

					if (r > 45 && r < 315)
					{
						if (map[i][j] == 4)
						{
							road->map[i][j] = 2;
						}

						player->atk += 2;
						Audio::Start(7);
					}

				}
			}
		}
	}
}

void CObjStage4item2::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//表示：アイテム
	src.m_top = 130.0f;
	src.m_left = 52.0f;
	src.m_right = 101.0f;
	src.m_bottom = 180.0f;

	for (int i = 0; i < ITEM42; i++)
	{
		for (int j = 0; j < ITEM42; j++)
		{
			if (map[i][j] == 4)
			{
				dst.m_top = i * ITEMSIZE42;
				dst.m_left = j * ITEMSIZE42;
				dst.m_right = dst.m_left + ITEMSIZE42;
				dst.m_bottom = dst.m_top + ITEMSIZE42;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}

}
