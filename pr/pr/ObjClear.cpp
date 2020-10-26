//使用するヘッダー
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "ObjClear.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h" 

using namespace GameL;

//イニシャライズ
void CObjClear::Init()
{
   m_key_flag:false;
}

//アクション
void CObjClear::Action()
{
	//エンターキーを押してシーン：タイトルに移行する
	if (Input ::GetVKey(VK_RETURN)==true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjClear::Draw()
{

}
