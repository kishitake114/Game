#include "ObjStage4item3.h"
#include "ObjRoad4.h"
#include "GameHead.h"
#include "ObjPlayer.h"
#include "GameL/DrawTexture.h"
#include"GameL/Audio.h"

#define ITEM43 26
#define ITEMSIZE43 22.0f

void CObjStage4item3::Init()
{

}

void CObjStage4item3::Action()
{
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	CObjRoad4* road = (CObjRoad4*)Objs::GetObj(OBJ_ROAD4);
	float px = player->GetX();
	float py = player->GetY();

	for (int i = 0; i < ITEM43; i++)
	{
		for (int j = 0; j < ITEM43; j++)
		{
			map[i][j] = road->map[i][j];
		}
	}

	//アイテム（３）
	for (int i = 0; i < ITEM43; i++)
	{
		for (int j = 0; j < ITEM43; j++)
		{
			if (map[i][j] == 5)
			{
				float x = j * ITEMSIZE43;
				float y = i * ITEMSIZE43;

				if ((px + ITEMSIZE43 > x) && (px < x + ITEMSIZE43) && (py + ITEMSIZE43 > y) && (py < y + ITEMSIZE43))
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

						player->atk += 3;
						Audio::Start(7);
					}

				}
			}
		}
	}
}

void CObjStage4item3::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//表示：アイテム
	src.m_top = 130.0f;
	src.m_left = 102.0f;
	src.m_right = 151.0f;
	src.m_bottom = 180.0f;

	for (int i = 0; i < ITEM43; i++)
	{
		for (int j = 0; j < ITEM43; j++)
		{
			if (map[i][j] == 5)
			{
				dst.m_top = i * ITEMSIZE43;
				dst.m_left = j * ITEMSIZE43;
				dst.m_right = dst.m_left + ITEMSIZE43;
				dst.m_bottom = dst.m_top + ITEMSIZE43;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}
}
