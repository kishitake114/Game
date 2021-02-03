#include "ObjStage3LifeiTem.h"
#include "ObjRoad3.h"
#include "GameHead.h"
#include "ObjPlayer.h"
#include "GameL/DrawTexture.h"
#include"GameL/Audio.h"

#define ITEML3 20
#define ITEMSIZEL3 25.0f

void CObjStage3Lifeitem::Init()
{

}

void CObjStage3Lifeitem::Action()
{
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	CObjRoad3* road = (CObjRoad3*)Objs::GetObj(OBJ_ROAD3);
	float px = player->GetX();
	float py = player->GetY();

	for (int i = 0; i < ITEML3; i++)
	{
		for (int j = 0; j < ITEML3; j++)
		{
			map[i][j] = road->map[i][j];
		}
	}

	//回復アイテム
	for (int i = 0; i < ITEML3; i++)
	{
		for (int j = 0; j < ITEML3; j++)
		{
			if (map[i][j] == 6)
			{
				float x = j * ITEMSIZEL3;
				float y = i * ITEMSIZEL3;

				if ((px + ITEMSIZEL3 > x) && (px < x + ITEMSIZEL3) && (py + ITEMSIZEL3 > y) && (py < y + ITEMSIZEL3))
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

void CObjStage3Lifeitem::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 130.0f;
	src.m_left = 152.0f;
	src.m_right = 203.0f;
	src.m_bottom = 180.0f;

	//表示：回復アイテム
	for (int i = 0; i < ITEML3; i++)
	{
		for (int j = 0; j < ITEML3; j++)
		{
			if (map[i][j] == 6)
			{
				dst.m_top = i * ITEMSIZEL3;
				dst.m_left = j * ITEMSIZEL3;
				dst.m_right = dst.m_left + ITEMSIZEL3;
				dst.m_bottom = dst.m_top + ITEMSIZEL3;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}

}
