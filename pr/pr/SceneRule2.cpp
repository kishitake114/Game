//STLデバック機能をOFFにする
#define _SECURE_SCL_	(0)
#define _HAS_ITERATOR_DEBUGING	(0)

//使用するヘッダー(GameL)
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL/DrawFont.h"

//使用するヘッダー
#include "SceneRule2.h"
#include "GameHead.h"

//コンストラクタ
CSceneRule2::CSceneRule2()
{
}

//デストラクタ
CSceneRule2::~CSceneRule2()
{
}

//ゲームメイン初期化
void CSceneRule2::InitScene()
{
	Draw::LoadImage(L"Rule2.png", 0, TEX_SIZE_1024);

	CObjRule2* CObj = new CObjRule2();
	Objs::InsertObj(CObj, OBJ_RULE2, 1);
}

//ゲームメイン実行中
void CSceneRule2::Scene()
{
}