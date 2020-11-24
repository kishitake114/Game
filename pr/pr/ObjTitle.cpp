//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameHead.h"
#include "ObjTitle.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTitle::Init()
{

	m_x = 170;
	m_y = 100;

	mou_x = 0.0f;
	mou_y = 0.0f;
	mou_r = false;
	mou_l = false;

	lup = false;
	rup = false;
	ldown = false;
	rdown = false;

	hard = false;
}
//アクション
void CObjTitle::Action()
{
	CObjnul* nul = (CObjnul*)Objs::GetObj(OBJ_NUL);

	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

	if (nul->count == 4)
	{
		if (mou_x > 0 && mou_x < 50 && mou_y > 0 && mou_y < 50)
		{
			if (mou_l == true)
			{
				lup = true;
			}
		}

		if (mou_x > 750 && mou_x < 800 && mou_y > 0 && mou_y < 50)
		{
			if (mou_l == true)
			{
				rup = true;
			}
		}

		if (mou_x > 0 && mou_x < 50 && mou_y > 550 && mou_y < 600)
		{
			if (mou_l == true)
			{
				ldown = true;
			}
		}

		if (mou_x > 750 && mou_x < 800 && mou_y > 550 && mou_y < 600)
		{
			if (mou_l == true)
			{
				rdown = true;
			}
		}

		if (lup == true && rup == true && ldown == true && rdown == true)
		{
			hard = true;
		}
	}


	if (mou_x > 161 && mou_x < 629 && mou_y > 391 && mou_y < 423)
	{
		if (mou_l == true)
		{
			Scene::SetScene(new CSceneRule());
		}
	}
	else
	{
		mou_l = true;
	}


	

}
//ドロー
void CObjTitle::Draw()
{
	CObjnul* nul = (CObjnul*)Objs::GetObj(OBJ_NUL);

	//描画カラー情報 R=RED B=Biue A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float r[4] = { 1.0f,0.0f,0.0f,1.0f };

	Font::StrDraw(L"左クリックで操作・ルール説明へ", 160, 400, 32, c);

	if (hard == true)
	{
		Font::StrDraw(L"？？？？？？", 160, 450, 32, r);
	}

	//表示：マウスカーソルとボタン
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", mou_x, mou_y);
	Font::StrDraw(str, 50, 20, 15, c);

	//右クリック
	if (mou_r == true)
		Font::StrDraw(L"右=押してる", 50, 40, 20, c);
	else
		Font::StrDraw(L"右=押してない", 50, 40, 20, c);

	//左クリック
	if (mou_l == true)
		Font::StrDraw(L"左=押してる", 50, 60, 20, c);
	else
		Font::StrDraw(L"左=押してない", 50, 60, 20, c);

	for (int i = 0; i < nul->count; i++)
	{
		Font::StrDraw(L"★", 200 + (i * 32), 300, 32, c);
	}

	//表示：タイトル画面
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 460.0f;
	src.m_bottom = 265.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 450.0f + m_x;
	dst.m_bottom = 200.0f + m_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 460.0f;
	src.m_bottom = 265.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 450.0f + m_x;
	dst.m_bottom = 200.0f + m_y;

	Draw::Draw(1, &src, &dst, c, 0.0f);

}