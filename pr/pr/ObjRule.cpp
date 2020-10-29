//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameHead.h"
#include "ObjRule.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjRule::Init()
{
	mou_x = 0.0f;
	mou_y = 0.0f;
	mou_r = false;
	mou_l = false;
}
//アクション
void CObjRule::Action()
{

	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

	if (mou_x > 550 && mou_x < 700 && mou_y > 480 && mou_y < 510)
	{
		if (mou_l == true)
		{
			Scene::SetScene(new CSceneMain());
		}
	}



}
//ドロー
void CObjRule::Draw()
{
	//描画カラー情報 R=RED B=Biue A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//表示：タイトル画面
	RECT_F src;
	RECT_F dst;

	src.m_top = 300.0f;
	src.m_left = 160.0f;
	src.m_right = 835.0f;
	src.m_bottom = 810.0f;

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);

}