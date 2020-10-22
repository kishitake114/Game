//STLデバック機能をOFFにする
#define _SECURE_SCL_	(0)
#define _HAS_ITERATOR_DEBUGING	(0)

//使用するヘッダー(GameL)
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL/UserData.h"

//使用するヘッダー
#include "SceneMain.h"
#include "GameHead.h"
#include "Objplayer.h"
#include "ObjNoRoad.h"

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

	CObjNoRoad* CObj1 = new CObjNoRoad();
	Objs::InsertObj(CObj1, OBJ_NO_ROAD, 1);

	//外部データの読み込み（ステージ情報）
	unique_ptr<wchar_t> p; //ステージ情報ポインター
	int size;			   //ステージ情報大きさ
	p = Save::ExternalDataOpen(L"Book1.csv", &size);//外部データ読み込み
}

//ゲームメイン実行中
void CSceneMain::Scene()
{
}
