#include "ObjStage2item3.h"
#include "ObjNoRoad2.h"
#include "ObjRoad2.h"
#include "GameHead.h"
#include "ObjPlayer.h"
#include "GameL/DrawTexture.h"
#include"GameL/Audio.h"

#define PIECE 17
#define SIZE 30.0f

void CObjStage2item3::Init()
{
}

void CObjStage2item3::Action()
{
	CObjRoad2* road = (CObjRoad2*)Objs::GetObj(OBJ_ROAD2);
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	float px = player->GetX();
	float py = player->GetY();

	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{
			map[i][j] = road->map[i][j];
		}
	}

	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{
			if (map[i][j] == 5)
			{
				float x = j * SIZE;
				float y = i * SIZE;

				if ((px + SIZE > x) && (px < x + SIZE) && (py + SIZE > y) && (py < y + SIZE))
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

	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{
			if (map[i][j] == 5)
			{
				dst.m_top = i * SIZE;
				dst.m_left = j * SIZE;
				dst.m_right = dst.m_left + SIZE;
				dst.m_bottom = dst.m_top + SIZE;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}
}
