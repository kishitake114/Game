//STLデバック機能をOFFにする
#define _SECURE_SCL_	(0)
#define _HAS_ITERATOR_DEBUGING	(0)

//使用するヘッダー(GameL)
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"

//使用するヘッダー
#include "SceneStage3.h"
#include "GameHead.h"
#include "ObjStage3.h"

//コンストラクタ
CSceneStage3::CSceneStage3()
{
}

//デストラクタ
CSceneStage3::~CSceneStage3()
{
}

//ゲームメイン初期化
void CSceneStage3::InitScene()
{
	//外部データの読み込み（ステージ情報）
	unique_ptr<wchar_t> p; //ステージ情報ポインター
	int size;			   //ステージ情報大きさ
	p = Save::ExternalDataOpen(L"k.csv", &size);//外部データ読み込み

	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);

	CObjPlayer* CObj = new CObjPlayer();
	Objs::InsertObj(CObj, OBJ_PLAYER, 1);

	CObjStage3* CObj3 = new CObjStage3();
	Objs::InsertObj(CObj3, OBJ_STAGE3, 1);
}

//ゲームメイン実行中
void CSceneStage3::Scene()
{

}