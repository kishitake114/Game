//使用するヘッダー
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameL/SceneManager.h"
#include "ObjClear.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h" 

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

	m_y -= 3;

	m_time++;

	//if (mou_x > 200 && mou_x < 629 && mou_y > 391 && mou_y < 423)
	//{
	//	if (mou_l == true)
	//	{
	//		Scene::SetScene(new CSceneTitle());
	//	}
	//}
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




	//表示：タイトル画面
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 460.0f;
	src.m_bottom = 265.0f;

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 450.0f;
	dst.m_bottom = 200.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}
