//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"

#include "GameHead.h"
#include "ObjGameOver.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGameOver::Init()
{
	mou_x = 0.0f;
	mou_y = 0.0f;
	mou_r = false;
	mou_l = false;

	f_p = 0.0f;
	pxc = 0.0f;
	pyc = 0.0f;
}

//アクション
void CObjGameOver::Action()
{
	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

	if (mou_l == true)
	{
		if (f_p == true)
		{
			pxc = mou_x;
			pyc = mou_y;

			f_p = false;
		}
	}
	else
	{
		f_p = true;

	}

	//選択でシーン移動
	
	//2F
	if (mou_x > 581.0f && mou_y > 568.0f && mou_x < 615.0f && mou_y > 580.0f)
	{
		if (mou_l == true)
		{
			Scene::SetScene(new CSceneStage2());
		}
	}

	//3F
	if (mou_x > 635.0f && mou_y > 568.0f && mou_x < 666.0f && mou_y > 580.0f)
	{
		if (mou_l == true)
		{
			Scene::SetScene(new CSceneStage3());
		}
	}

	//4F
	if (mou_x > 680.0f && mou_y > 568.0f && mou_x < 717.0f && mou_y > 580.0f)
	{
		if (mou_l == true)
		{
			Scene::SetScene(new CSceneStage4());
		}
	}

	//5F
	if (mou_x > 742.0f && mou_y > 568.0f && mou_x < 772.0f && mou_y > 580.0f)
	{
		if (mou_l == true)
		{
			Scene::SetScene(new CSceneStage5());
		}
	}

}

//ドロー
void CObjGameOver::Draw()
{
	//描画カラー情報 R=RED B=Biue A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,0.5f };

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

	swprintf_s(str, L"x=%f,y=%f", pxc, pyc);
	Font::StrDraw(str, 600, 20, 15, c);

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}