#include "ObjStage2item2.h"
#include "ObjNoRoad2.h"
#include "ObjRoad2.h"
#include "GameHead.h"
#include "ObjPlayer.h"
#include "GameL/DrawTexture.h"
#include"GameL/Audio.h"

#define ITEM22 17
#define ITEMSIZE22 30.0f

void CObjStage2item2::Init()
{
}

void CObjStage2item2::Action()
{
	CObjRoad2* road = (CObjRoad2*)Objs::GetObj(OBJ_ROAD2);
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	float px = player->GetX();
	float py = player->GetY();

	for (int i = 0; i < ITEM22; i++)
	{
		for (int j = 0; j < ITEM22; j++)
		{
			map[i][j] = road->map[i][j];
		}
	}

	for (int i = 0; i < ITEM22; i++)
	{
		for (int j = 0; j < ITEM22; j++)
		{
			if (map[i][j] == 4)
			{
				float x = j * ITEMSIZE22;
				float y = i * ITEMSIZE22;

				if ((px + ITEMSIZE22 > x) && (px < x + ITEMSIZE22) && (py + ITEMSIZE22 > y) && (py < y + ITEMSIZE22))
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

						player->atk+=2;
						Audio::Start(7);
					}

				}
			}
		}
	}
}

void CObjStage2item2::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//表示：アイテム2
	src.m_top = 130.0f;
	src.m_left = 52.0f;
	src.m_right = 101.0f;
	src.m_bottom = 180.0f;

	for (int i = 0; i < ITEM22; i++)
	{
		for (int j = 0; j < ITEM22; j++)
		{
			if (map[i][j] == 4)
			{
				dst.m_top = i * ITEMSIZE22;
				dst.m_left = j * ITEMSIZE22;
				dst.m_right = dst.m_left + ITEMSIZE22;
				dst.m_bottom = dst.m_top + ITEMSIZE22;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}
}
