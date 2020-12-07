//使用するヘッダー
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameL/SceneManager.h"
#include "ObjClear.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h" 
#include "GameL/UserData.h"

using namespace GameL;

//イニシャライズ
void CObjClear::Init()
{
	m_x = 170;
	m_y = 100;

	mou_x = 0.0f;
	mou_y = 0.0f;
	mou_r = false;
	mou_l = false;

	m_time = 0;
}

//アクション
void CObjClear::Action()
{
	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

	if (m_y > -1300.0f)
	{
		m_y -= 3;
	}


	m_time++;



	if (m_time>=800)
	{
		if (mou_l == true)
		{
			Scene::SetScene(new CSceneTitle());
		}
	}
}

//ドロー
void CObjClear::Draw()
{

	//描画カラー情報 R=RED B=Biue A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	/*Font::StrDraw(L"GAME CLEAR!", 300, 200, 32, c);
	Font::StrDraw(L"左クリックでタイトル画面へ", 200, 400, 32, c);*/

	if (m_time >= 5)
	{
		Font::StrDraw(L"総合ディレクター　　　　　　岸本　偉", 100, 600+m_y, 30, c);
	}

	if (m_time >= 15)
	{
		Font::StrDraw(L"サウンドディレクター　　　　南　理玖", 100, 645+ m_y, 30, c);
	}

	if (m_time >= 25)
	{
		Font::StrDraw(L"デザインディレクター　　　　林　雄大", 100, 690 + m_y, 30, c);
	}

	if (m_time >= 35)
	{
		Font::StrDraw(L"プランナーディレクター　竹之下　涼馬", 100, 735 + m_y, 30, c);
	}

	if (m_time >= 45)
	{
		Font::StrDraw(L"プログラマディレクター　中辻　祭斗吏", 100, 780 + m_y, 30, c);
	}

	if (m_time >= 500 && m_time<=700)
	{
		Font::StrDraw(L"ドラゴンは倒された。", 100, 350, 20, c);
	}

	if(	((UserData*)Save::GetData())->Hperfect>=2)
	{
		if (m_time >= 700 )
		{
			Font::StrDraw(L"画面の端を押すと何かが起こる", 100, 350, 20, c);
		}
	}

	else
	{
		if (m_time >= 700)
		{
			Font::StrDraw(L"PERFECT　を狙うのだ！！", 100, 350, 20, c);
		}
	}

	if (m_time >= 800)
	{
		Font::StrDraw(L"左クリックでタイトルに戻る", 100, 450, 30, c);
	}


	wchar_t str[256];

	swprintf_s(str, L"%d", m_time);
	Font::StrDraw(str, 0, 0, 30, c);

	swprintf_s(str, L"%f", m_y);
	Font::StrDraw(str, 0, 570, 30, c);


	//表示：タイトル画面
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 460.0f;
	src.m_bottom = 265.0f;

	dst.m_top = 1450.0f+m_y;
	dst.m_left = 100.0f;
	dst.m_right = 700.0f;
	dst.m_bottom = 1650.0f+m_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}
