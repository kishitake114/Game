#include "ObjStage3item1.h"
#include "ObjRoad3.h"
#include "GameHead.h"
#include "ObjPlayer.h"
#include "GameL/DrawTexture.h"
#include"GameL/Audio.h"


#define ITEM31 20
#define ITEMSIZE31 25.0f

void CObjStage3item1::Init()
{
}

void CObjStage3item1::Action()
{
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	CObjRoad3* road = (CObjRoad3*)Objs::GetObj(OBJ_ROAD3);
	float px = player->GetX();
	float py = player->GetY();

	for (int i = 0; i < ITEM31; i++)
	{
		for (int j = 0; j < ITEM31; j++)
		{
			map[i][j] = road->map[i][j];
		}
	}

	//アイテム（１）
	for (int i = 0; i < ITEM31; i++)
	{
		for (int j = 0; j < ITEM31; j++)
		{
			if (map[i][j] == 3)
			{
				float x = j * ITEMSIZE31;
				float y = i * ITEMSIZE31;

				if ((px + ITEMSIZE31 > x) && (px < x + ITEMSIZE31) && (py + ITEMSIZE31 > y) && (py < y + ITEMSIZE31))
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

void CObjStage3item1::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//表示：アイテム
	src.m_top = 130.0f;
	src.m_left = 1.0f;
	src.m_right = 51.0f;
	src.m_bottom = 180.0f;

	for (int i = 0; i < ITEM31; i++)
	{
		for (int j = 0; j < ITEM31; j++)
		{
			if (map[i][j] == 3)
			{
				dst.m_top = i * ITEMSIZE31;
				dst.m_left = j * ITEMSIZE31;
				dst.m_right = dst.m_left + ITEMSIZE31;
				dst.m_bottom = dst.m_top + ITEMSIZE31;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}

}
