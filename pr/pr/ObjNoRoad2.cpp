//使用するヘッダーファイル
#include "ObjNoRoad2.h"
#include "ObjPlayer.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h"
#include "GameL/HitBoxManager.h"
#include "GameL/SceneObjManager.h"
#include "GameL/UserData.h"
#include "GameL/Audio.h"
#include "SceneStage2.h"

#define PIECE 17
#define SIZE 30.0f

void CObjNoRoad2::Init()
{

}

void CObjNoRoad2::Action()
{
	CObjRoad2* road = (CObjRoad2*)Objs::GetObj(OBJ_ROAD2);

	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{
			map[i][j] = road->map[i][j];
		}
	}

	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	float px = player->GetX();
	float py = player->GetY();

	//通行不可
	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{
			if (map[i][j] <= 1)
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

					//上
					if (r > 45 && r < 135)
					{
						player->SetVY(y - SIZE);
					}

					//左
					else if (r > 135 && r < 225)
					{
						player->SetVX(x - SIZE);
					}

					//下
					else if (r > 225 && r < 315)
					{
						player->SetVY(y + SIZE);
					}

					else
					{
						player->SetVX(x + SIZE);
					}

				}

			}


		}

	}
}

void CObjNoRoad2::Draw()
{
	float c[4] = { 1.1f,1.1f,1.1f,1.0f };

	RECT_F src;
	RECT_F dst;

	//表示：通行不可

	src.m_top = 90.0f;
	src.m_left = 95.0f;
	src.m_right = 142.0f;
	src.m_bottom = 125.0f;

	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{
			if (map[i][j] == 1)
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
