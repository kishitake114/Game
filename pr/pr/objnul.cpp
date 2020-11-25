#include "objnul.h"
#include "GameL/DrawFont.h"
#include "GameHead.h"

void CObjnul::Init()
{
	count=0;
}

void CObjnul::plus(int c)
{
	count += c;
}


void CObjnul::Action()
{
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	CObjRoad* road = (CObjRoad*)Objs::GetObj(OBJ_ROAD);
	CObjStage2* road2 = (CObjStage2*)Objs::GetObj(OBJ_STAGE2);
	CObjStage3* road3 = (CObjStage3*)Objs::GetObj(OBJ_STAGE3);
	CObjStage4* road4 = (CObjStage4*)Objs::GetObj(OBJ_STAGE4);

	if (player->HP == 10 && road->reset == 0 && count < 1)
	{
		count++;
	}
}

void CObjnul::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float r[4] = { 1.0f,0.0f,0.0f,1.0f };
	float g[4] = { 0.0f,1.0f,0.0f,1.0f };
	float b[4] = { 0.0f,0.0f,1.0f,1.0f };

	//表示：プレイヤー
	wchar_t str[256];


	swprintf_s(str, L"%d", count);
	Font::StrDraw(str, 750, 0, 30, c);
}
