//STLデバック機能をOFFにする
#define _SECURE_SCL_	(0)
#define _HAS_ITERATOR_DEBUGING	(0)

//使用するヘッダー(GameL)
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL/UserData.h"

using namespace GameL;

//使用するヘッダー
#include "SceneMain.h"
#include "GameHead.h"
#include "Objplayer.h"
#include "ObjRoad.h"
#include "ObjItem.h"

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
	
	//外部データの読み込み（ステージ情報）
	unique_ptr<wchar_t> p; //ステージ情報ポインター
	int size;			   //ステージ情報大きさ
	p = Save::ExternalDataOpen(L"k.csv", &size);//外部データ読み込み

	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);

	CObjPlayer* CObj = new CObjPlayer();
	Objs::InsertObj(CObj, OBJ_PLAYER, 1);

	CObjEnemy* CObjE = new CObjEnemy();
	Objs::InsertObj(CObjE, OBJ_ENEMY, 1);

	CObjRoad* CObjR = new CObjRoad();
	Objs::InsertObj(CObjR, OBJ_ROAD, 1);

	CObjItem* CObjI = new CObjItem();
	Objs::InsertObj(CObjI, OBJ_ITEM, 1);



}

//ゲームメイン実行中
void CSceneMain::Scene()
{

}
