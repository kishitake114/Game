#include "ObjNoRoad0.h"
#include "ObjStage5.h"
#include "GameHead.h"
#include "ObjPlayer.h"
#include "GameL/DrawTexture.h"

#define NOROAD0 8
#define NOROADSIZE0 40.0f

void CObjNoRoad0::Init()
{

}

void CObjNoRoad0::Action()
{
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	float px = player->GetX();
	float py = player->GetY();

	CObjStage5* road = (CObjStage5*)Objs::GetObj(OBJ_ROAD5);

	for (int i = 0; i < NOROAD0; i++)
	{
		for (int j = 0; j < NOROAD0; j++)
		{
			map[i][j] = road->map[i][j];
		}
	}

	//mapにアクセス
	for (int i = 0; i < NOROAD0; i++)
	{
		for (int j = 0; j < NOROAD0; j++)
		{
			if (map[i][j] < 2)
			{
				float x = j * NOROADSIZE0;
				float y = i * NOROADSIZE0;

				if ((px + NOROADSIZE0 > x) && (px < x + NOROADSIZE0) && (py + NOROADSIZE0 > y) && (py < y + NOROADSIZE0))
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

					//上
					if (r > 45 && r < 135)
					{
						player->SetVY(y - NOROADSIZE0);
					}

					//左
					else if (r > 135 && r < 225)
					{
						player->SetVX(x - NOROADSIZE0);
					}

					//下
					else if (r > 225 && r < 315)
					{
						player->SetVY(y + NOROADSIZE0);
					}

					else
					{
						player->SetVX(x + NOROADSIZE0);
					}

				}
			}
		}
	}
}

void CObjNoRoad0::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//表示：通行不可
	src.m_top = 90.0f;
	src.m_left = 0.0f;
	src.m_right = 45.0f;
	src.m_bottom = 125.0f;

	for (int i = 0; i < NOROAD0; i++)
	{
		for (int j = 0; j < NOROAD0; j++)
		{
			if (map[i][j] == 1)
			{
				dst.m_top = i * NOROADSIZE0;
				dst.m_left = j * NOROADSIZE0;
				dst.m_right = dst.m_left + NOROADSIZE0;
				dst.m_bottom = dst.m_top + NOROADSIZE0;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}
}
