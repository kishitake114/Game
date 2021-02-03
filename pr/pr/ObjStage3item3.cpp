#include "ObjStage3item3.h"
#include "ObjRoad3.h"
#include "GameHead.h"
#include "ObjPlayer.h"
#include "GameL/DrawTexture.h"
#include"GameL/Audio.h"


#define ITEM33 20
#define ITEMSIZE33 25.0f

void CObjStage3item3::Init()
{

}

void CObjStage3item3::Action()
{
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	CObjRoad3* road = (CObjRoad3*)Objs::GetObj(OBJ_ROAD3);
	float px = player->GetX();
	float py = player->GetY();

	for (int i = 0; i < ITEM33; i++)
	{
		for (int j = 0; j < ITEM33; j++)
		{
			map[i][j] = road->map[i][j];
		}
	}

	//アイテム（３）
	for (int i = 0; i < ITEM33; i++)
	{
		for (int j = 0; j < ITEM33; j++)
		{
			if (map[i][j] == 5)
			{
				float x = j * ITEMSIZE33;
				float y = i * ITEMSIZE33;

				if ((px + ITEMSIZE33 > x) && (px < x + ITEMSIZE33) && (py + ITEMSIZE33 > y) && (py < y + ITEMSIZE33))
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

void CObjStage3item3::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//表示：アイテム
	src.m_top = 130.0f;
	src.m_left = 102.0f;
	src.m_right = 151.0f;
	src.m_bottom = 180.0f;

	for (int i = 0; i < ITEM33; i++)
	{
		for (int j = 0; j < ITEM33; j++)
		{
			if (map[i][j] == 5)
			{
				dst.m_top = i * ITEMSIZE33;
				dst.m_left = j * ITEMSIZE33;
				dst.m_right = dst.m_left + ITEMSIZE33;
				dst.m_bottom = dst.m_top + ITEMSIZE33;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}
}

