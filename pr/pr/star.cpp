#include "star.h"
//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameHead.h"
#include "ObjTitle.h"
#include "GameL/UserData.h"

//使用するネームスペース
using namespace GameL;

void CObjStar::Init()
{
	CObjTitle* title = (CObjTitle*)Objs::GetObj(OBJ_TITLE);
	HardSter = title->count;
}

void CObjStar::Action()
{

}

void CObjStar::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//表示：タイトル画面
	RECT_F src;
	RECT_F dst;

	for (int i = 0; i < HardSter; i++)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 213.0f;
		src.m_bottom = 213.0f;

		dst.m_top = 310.0f;
		dst.m_left = 410.0f+(i*20.0f);
		dst.m_right = dst.m_left+20.0f;
		dst.m_bottom = dst.m_top + 20.0f;

		Draw::Draw(2, &src, &dst, c, 0.0f);
	}
}
