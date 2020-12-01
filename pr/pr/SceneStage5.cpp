//STLデバック機能をOFFにする
#define _SECURE_SCL_	(0)
#define _HAS_ITERATOR_DEBUGING	(0)

//使用するヘッダー(GameL)
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"

//使用するヘッダー
#include "SceneStage5.h"
#include "GameHead.h"
#include "ObjStage5.h"
#include "Background01.h"

//コンストラクタ
CSceneStage5::CSceneStage5()
{
}

//デストラクタ
CSceneStage5::~CSceneStage5()
{
}

//ゲームメイン初期化
void CSceneStage5::InitScene()
{
	//外部データの読み込み（ステージ情報）
	unique_ptr<wchar_t> p; //ステージ情報ポインター
	int size;			   //ステージ情報大きさ
	p = Save::ExternalDataOpen(L"k.csv", &size);//外部データ読み込み

	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"stage0,1背景.png", 1, TEX_SIZE_512);

	CObjPlayer* CObj = new CObjPlayer(0.0f, 200.0f);
	Objs::InsertObj(CObj, OBJ_PLAYER, 1);

	CObjStage5* CObj5 = new CObjStage5();
	Objs::InsertObj(CObj5, OBJ_STAGE5, 1);

	CObjnul* CObjn = new CObjnul();
	Objs::InsertObj(CObjn, OBJ_NUL, 1);

	CObjBackGround01* CObbg = new 	CObjBackGround01();
	Objs::InsertObj(CObbg, OBJ_BACKGROUND01, 0);

}

//ゲームメイン実行中
void CSceneStage5::Scene()
{
	
}