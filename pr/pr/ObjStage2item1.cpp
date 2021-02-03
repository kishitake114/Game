#include "ObjStage2item1.h"
#include "ObjNoRoad2.h"
#include "ObjRoad2.h"
#include "GameHead.h"
#include "ObjPlayer.h"
#include "GameL/DrawTexture.h"
#include"GameL/Audio.h"

#define ITEM21 17
#define ITEMSIZE21 30.0f

void CObjStage2item1::Init()
{
}

void CObjStage2item1::Action()
{
	CObjRoad2* road = (CObjRoad2*)Objs::GetObj(OBJ_ROAD2);
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	float px = player->GetX();
	float py = player->GetY();

	for (int i = 0; i < ITEM21; i++)
	{
		for (int j = 0; j < ITEM21; j++)
		{
			map[i][j] = road->map[i][j];
		}
	}

	//アイテム（１）
	for (int i = 0; i < ITEM21; i++)
	{
		for (int j = 0; j < ITEM21; j++)
		{
			if (map[i][j] == 3)
			{
				float x = j * ITEMSIZE21;
				float y = i * ITEMSIZE21;

				if ((px + ITEMSIZE21 > x) && (px < x + ITEMSIZE21) && (py + ITEMSIZE21 > y) && (py < y + ITEMSIZE21))
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
						if (map[i][j] == 3)
						{
							road->map[i][j] = 2;
						}

						player->atk++;
						Audio::Start(7);
					}

				}
			}
		}
	}
}

void CObjStage2item1::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//表示：アイテム1
	src.m_top = 130.0f;
	src.m_left = 1.0f;
	src.m_right = 51.0f;
	src.m_bottom = 180.0f;

	for (int i = 0; i < ITEM21; i++)
	{
		for (int j = 0; j < ITEM21; j++)
		{
			if (map[i][j] == 3)
			{
				dst.m_top = i * ITEMSIZE21;
				dst.m_left = j * ITEMSIZE21;
				dst.m_right = dst.m_left + ITEMSIZE21;
				dst.m_bottom = dst.m_top + ITEMSIZE21;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}

}
