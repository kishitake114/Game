//STLデバック機能をOFFにする
#define _SECURE_SCL_	(0)
#define _HAS_ITERATOR_DEBUGING	(0)

//使用するヘッダー(GameL)
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"

//使用するヘッダー
#include "SceneStage4.h"
#include "GameHead.h"
#include "ObjStage4.h"

//コンストラクタ
CSceneStage4::CSceneStage4()
{
}

//デストラクタ
CSceneStage4::~CSceneStage4()
{
}

//ゲームメイン初期化
void CSceneStage4::InitScene()
{
	//外部データの読み込み（ステージ情報）
	unique_ptr<wchar_t> p; //ステージ情報ポインター
	int size;			   //ステージ情報大きさ
	p = Save::ExternalDataOpen(L"k.csv", &size);//外部データ読み込み

	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);

	CObjStage4* CObj = new CObjStage4();
	Objs::InsertObj(CObj, OBJ_STAGE4, 1);
}

//ゲームメイン実行中
void CSceneStage4::Scene()
{

}