#include "ObjRoad.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameHead.h" 


//イニシャライズ
void CObjRoad::Init()
{
		int mapdata[14][14] =
	{
	{0,0,2,0,0,2,0,0,2,0,0,2,0,0},
	{0,1,2,1,1,2,1,1,1,1,1,1,1,0},
	{2,2,2,2,1,2,1,2,2,1,2,2,2,2},
	{0,1,2,1,1,2,1,1,1,1,1,1,1,0},
	{2,1,2,1,2,2,2,2,2,1,1,2,2,2},
	{0,1,2,1,1,2,1,1,2,1,1,2,1,0},
	{0,1,1,1,1,2,1,1,2,1,1,2,1,0},
	{2,2,2,2,1,2,2,2,2,2,2,2,1,2},
	{0,1,1,1,0,0,0,1,2,1,1,1,1,0},
	{2,2,2,2,0,0,0,1,2,1,2,2,2,2},
	{0,1,1,1,0,0,0,1,2,1,1,1,1,0},
	{0,0,2,0,0,2,0,0,2,0,0,2,0,0},
	};

	memcpy(map, mapdata, sizeof(int) * (14 * 14));

}

//アクション
void CObjRoad::Action()
{

}

//ドロー
void CObjRoad::Draw()
{
	//表示：通行可

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 90.0f;
	src.m_left = 45.0f;
	src.m_right = 85.0f;
	src.m_bottom = 125.0f;
	
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			if (map[i][j] == 3)
			{
				;
			}

			if (map[i][j] == 2)
			{
				dst.m_top = i * 50.0f;
				dst.m_left = j * 50.0f;
				dst.m_right = dst.m_left + 50.0f;
				dst.m_bottom = dst.m_top + 50.0f;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}

			if (map[i][j] == 4)
			{
				;
			}
		}
	}

	//表示：通行不可

	src.m_top = 90.0f;
	src.m_left = 0.0f;
	src.m_right = 45.0f;
	src.m_bottom = 125.0f;

	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			if (map[i][j] == 1)
			{
				dst.m_top = i * 50.0f;
				dst.m_left = j * 50.0f;
				dst.m_right = dst.m_left + 50.0f;
				dst.m_bottom = dst.m_top + 50.0f;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}

}
