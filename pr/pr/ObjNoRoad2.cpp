//�g�p����w�b�_�[�t�@�C��
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

#define NOROAD2 17
#define NOROADSIZE2 30.0f

void CObjNoRoad2::Init()
{

}

void CObjNoRoad2::Action()
{
	CObjRoad2* road = (CObjRoad2*)Objs::GetObj(OBJ_ROAD2);

	for (int i = 0; i < NOROAD2; i++)
	{
		for (int j = 0; j < NOROAD2; j++)
		{
			map[i][j] = road->map[i][j];
		}
	}

	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	float px = player->GetX();
	float py = player->GetY();

	//�ʍs�s��
	for (int i = 0; i < NOROAD2; i++)
	{
		for (int j = 0; j < NOROAD2; j++)
		{
			if (map[i][j] <= 1)
			{
				float x = j * NOROADSIZE2;
				float y = i * NOROADSIZE2;

				if ((px + NOROADSIZE2 > x) && (px < x + NOROADSIZE2) && (py + NOROADSIZE2 > y) && (py < y + NOROADSIZE2))
				{
					//�x�N�g���쐬
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

					//��
					if (r > 45 && r < 135)
					{
						player->SetVY(y - NOROADSIZE2);
					}

					//��
					else if (r > 135 && r < 225)
					{
						player->SetVX(x - NOROADSIZE2);
					}

					//��
					else if (r > 225 && r < 315)
					{
						player->SetVY(y + NOROADSIZE2);
					}

					else
					{
						player->SetVX(x + NOROADSIZE2);
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

	//�\���F�ʍs�s��

	src.m_top = 90.0f;
	src.m_left = 95.0f;
	src.m_right = 142.0f;
	src.m_bottom = 125.0f;

	for (int i = 0; i < NOROAD2; i++)
	{
		for (int j = 0; j < NOROAD2; j++)
		{
			if (map[i][j] == 1)
			{
				dst.m_top = i * NOROADSIZE2;
				dst.m_left = j * NOROADSIZE2;
				dst.m_right = dst.m_left + NOROADSIZE2;
				dst.m_bottom = dst.m_top + NOROADSIZE2;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}
}
