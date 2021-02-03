#include "ObjStage2LifeiTem.h"
#include "ObjNoRoad2.h"
#include "ObjRoad2.h"
#include "GameHead.h"
#include "ObjPlayer.h"
#include "GameL/DrawTexture.h"
#include"GameL/Audio.h"

#define ITEML2 17
#define ITEMSIZEL2 30.0f

void CObjStage2Lifeitem::Init()
{
}

void CObjStage2Lifeitem::Action()
{
	CObjRoad2* road = (CObjRoad2*)Objs::GetObj(OBJ_ROAD2);
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	float px = player->GetX();
	float py = player->GetY();

	for (int i = 0; i < ITEML2; i++)
	{
		for (int j = 0; j < ITEML2; j++)
		{
			map[i][j] = road->map[i][j];
		}
	}

	for (int i = 0; i < ITEML2; i++)
	{
		for (int j = 0; j < ITEML2; j++)
		{
			if (map[i][j] == 6)
			{
				float x = j * ITEMSIZEL2;
				float y = i * ITEMSIZEL2;

				if ((px + ITEMSIZEL2 > x) && (px < x + ITEMSIZEL2) && (py + ITEMSIZEL2 > y) && (py < y + ITEMSIZEL2))
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
						if (map[i][j] == 6)
						{
							road->map[i][j] = 2;
						}

						if (player->HP < 5)
						{
							player->HP++;
							Audio::Start(8);
						}
					}

				}
			}
		}
	}
}

void CObjStage2Lifeitem::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 130.0f;
	src.m_left = 152.0f;
	src.m_right = 203.0f;
	src.m_bottom = 180.0f;

	//表示：回復アイテム
	for (int i = 0; i < ITEML2; i++)
	{
		for (int j = 0; j < ITEML2; j++)
		{
			if (map[i][j] == 6)
			{
				dst.m_top = i * ITEMSIZEL2;
				dst.m_left = j * ITEMSIZEL2;
				dst.m_right = dst.m_left + ITEMSIZEL2;
				dst.m_bottom = dst.m_top + ITEMSIZEL2;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}

}
