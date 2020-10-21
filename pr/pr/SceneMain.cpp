//STLデバック機能をOFFにする
#define _SECURE_SCL_	(0)
#define _HAS_ITERATOR_DEBUGING	(0)

//使用するヘッダー(GameL)
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"

//使用するヘッダー
#include "SceneMain.h"
#include "GameHead.h"
#include "Objplayer.h"

//コンストラクタ
CSceneMain::CSceneMain()
{
}

//デストラクタ
CSceneMain::~CSceneMain()
{
}

//ゲームメイン初期化
void CSceneMain::InitScene()
{
	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);

	CObjPlayer* CObj = new CObjPlayer();
	Objs::InsertObj(CObj, OBJ_PLAYER, 1);
}

//ゲームメイン実行中
void CSceneMain::Scene()
{
}
