#include "ObjStage1item1.h"
#include "ObjNoRoad1.h"
#include "ObjRoad.h"
#include "GameHead.h"
#include "ObjPlayer.h"
#include "GameL/DrawTexture.h"
#include"GameL/Audio.h"

#define ITEM11 14
#define ITEMSIZE11 40.0f

void CObjStage1item1::Init()
{
}

void CObjStage1item1::Action()
{
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	CObjRoad* road = (CObjRoad*)Objs::GetObj(OBJ_ROAD1);
	float px = player->GetX();
	float py = player->GetY();

	for (int i = 0; i < ITEM11; i++)
	{
		for (int j = 0; j < ITEM11; j++)
		{
			map[i][j] = road->map[i][j];
		}
	}

	//アイテム（１）
	for (int i = 0; i < ITEM11; i++)
	{
		for (int j = 0; j < ITEM11; j++)
		{
			if (map[i][j] == 3)
			{
				float x = j * ITEMSIZE11;
				float y = i * ITEMSIZE11;

				if ((px + ITEMSIZE11 > x) && (px < x + ITEMSIZE11) && (py + ITEMSIZE11 > y) && (py < y + ITEMSIZE11))
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

void CObjStage1item1::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//表示：マウスカーソルとボタン
	wchar_t str[256];

	//表示：アイテム1
	src.m_top = 130.0f;
	src.m_left = 1.0f;
	src.m_right = 51.0f;
	src.m_bottom = 180.0f;

	for (int i = 0; i < ITEM11; i++)
	{
		for (int j = 0; j < ITEM11; j++)
		{
			if (map[i][j] == 3)
			{
				dst.m_top = i * ITEMSIZE11;
				dst.m_left = j * ITEMSIZE11;
				dst.m_right = dst.m_left + ITEMSIZE11;
				dst.m_bottom = dst.m_top + ITEMSIZE11;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}
}
