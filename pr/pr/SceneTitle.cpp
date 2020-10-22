//STLデバック機能をOFFにする
#define _SECURE_SCL_	(0)
#define _HAS_ITERATOR_DEBUGING	(0)

//使用するヘッダー(GameL)
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL/DrawFont.h"

//使用するヘッダー
#include "SceneTitle.h"
#include "GameHead.h"

//コンストラクタ
CSceneTitle::CSceneTitle()
{
}

//デストラクタ
CSceneTitle::~CSceneTitle()
{
}

//ゲームメイン初期化
void CSceneTitle::InitScene()
{
	Font::SetStrTex(L"Enterキーで操作・ルール説明へ");

	Draw::LoadImage(L"Title.png", 0, TEX_SIZE_1024);

	CObjTitle* CObj = new CObjTitle();
	Objs::InsertObj(CObj, OBJ_TITLE, 1);
}

//ゲームメイン実行中
void CSceneTitle::Scene()
{
}