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
		m_y -= 1.5f;
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

	wchar_t str[256];

	swprintf_s(str, L"%d", m_time);
	Font::StrDraw(str, 0, 0, 30, c);

	swprintf_s(str, L"%f", m_y);
	Font::StrDraw(str, 0, 570, 30, c);


	//表示：タイトル画面
	RECT_F src;
	RECT_F dst;

	src.m_top = 5.0f;
	src.m_left = 20.0f;
	src.m_right = 505.0f;
	src.m_bottom = 315.0f;

	dst.m_top = 150.0f;
	dst.m_left = 150.0f;
	dst.m_right = 650.0f;
	dst.m_bottom = 350.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}
