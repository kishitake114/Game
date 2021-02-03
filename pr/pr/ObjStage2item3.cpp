#include "ObjStage2item3.h"
#include "ObjNoRoad2.h"
#include "ObjRoad2.h"
#include "GameHead.h"
#include "ObjPlayer.h"
#include "GameL/DrawTexture.h"
#include"GameL/Audio.h"

#define ITME23 17
#define ITEMSIZE23 30.0f

void CObjStage2item3::Init()
{
}

void CObjStage2item3::Action()
{
	CObjRoad2* road = (CObjRoad2*)Objs::GetObj(OBJ_ROAD2);
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	float px = player->GetX();
	float py = player->GetY();

	for (int i = 0; i < ITME23; i++)
	{
		for (int j = 0; j < ITME23; j++)
		{
			map[i][j] = road->map[i][j];
		}
	}

	for (int i = 0; i < ITME23; i++)
	{
		for (int j = 0; j < ITME23; j++)
		{
			if (map[i][j] == 5)
			{
				float x = j * ITEMSIZE23;
				float y = i * ITEMSIZE23;

				if ((px + ITEMSIZE23 > x) && (px < x + ITEMSIZE23) && (py + ITEMSIZE23 > y) && (py < y + ITEMSIZE23))
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
						if (map[i][j] == 5)
						{
							road->map[i][j] = 2;
						}

						player->atk+=3;
						Audio::Start(7);
					}

				}
			}
		}
	}
}

void CObjStage2item3::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//表示：アイテム3
	src.m_top = 130.0f;
	src.m_left = 102.0f;
	src.m_right = 151.0f;
	src.m_bottom = 180.0f;

	for (int i = 0; i < ITME23; i++)
	{
		for (int j = 0; j < ITME23; j++)
		{
			if (map[i][j] == 5)
			{
				dst.m_top = i * ITEMSIZE23;
				dst.m_left = j * ITEMSIZE23;
				dst.m_right = dst.m_left + ITEMSIZE23;
				dst.m_bottom = dst.m_top + ITEMSIZE23;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}
}
