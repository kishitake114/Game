#include "ObjStage1item3.h"
#include "ObjRoad.h"
#include "GameHead.h"
#include "ObjPlayer.h"
#include "GameL/DrawTexture.h"
#include"GameL/Audio.h"

#define PIECE13 14
#define ITEMSIZE13 40.0f

void CObjStage1item3::Init()
{
}

void CObjStage1item3::Action()
{
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	CObjRoad* road = (CObjRoad*)Objs::GetObj(OBJ_ROAD1);
	float px = player->GetX();
	float py = player->GetY();

	for (int i = 0; i < PIECE13; i++)
	{
		for (int j = 0; j < PIECE13; j++)
		{
			map[i][j] = road->map[i][j];
		}
	}

	//アイテム（３）
	for (int i = 0; i < PIECE13; i++)
	{
		for (int j = 0; j < PIECE13; j++)
		{
			if (map[i][j] == 5)
			{
				float x = j * ITEMSIZE13;
				float y = i * ITEMSIZE13;

				if ((px + ITEMSIZE13 > x) && (px < x + ITEMSIZE13) && (py + ITEMSIZE13 > y) && (py < y + ITEMSIZE13))
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

void CObjStage1item3::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;


	//表示：アイテム3
	src.m_top = 130.0f;
	src.m_left = 102.0f;
	src.m_right = 151.0f;
	src.m_bottom = 180.0f;

	for (int i = 0; i < PIECE13; i++)
	{
		for (int j = 0; j < PIECE13; j++)
		{
			if (map[i][j] == 5)
			{
				dst.m_top = i * ITEMSIZE13;
				dst.m_left = j * ITEMSIZE13;
				dst.m_right = dst.m_left + ITEMSIZE13;
				dst.m_bottom = dst.m_top + ITEMSIZE13;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}
}
