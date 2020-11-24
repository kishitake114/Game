//STLデバック機能をOFFにする
#define _SECURE_SCL_	(0)
#define _HAS_ITERATOR_DEBUGING	(0)

//使用するヘッダー(GameL)
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"
#include "GameL/Audio.h"

//使用するヘッダー
#include "SceneStage2.h"
#include "GameHead.h"
#include "ObjStage2.h"

//コンストラクタ
CSceneStage2::CSceneStage2()
{
}

//デストラクタ
CSceneStage2::~CSceneStage2()
{
}

//ゲームメイン初期化
void CSceneStage2::InitScene()
{
	Audio::LoadAudio(0, L"Stage2.wav", BACK_MUSIC);

	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster(-0.8f);

	//外部データの読み込み（ステージ情報）
	unique_ptr<wchar_t> p; //ステージ情報ポインター
	int size;			   //ステージ情報大きさ
	p = Save::ExternalDataOpen(L"k.csv", &size);//外部データ読み込み

	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);

	CObjPlayer* CObj = new CObjPlayer(0.0f, 30.0f);
	Objs::InsertObj(CObj, OBJ_PLAYER, 1);

	CObjStage2* CObj2 = new CObjStage2();
	Objs::InsertObj(CObj2, OBJ_STAGE2, 1);


	Draw::LoadImage(L"image3.png", 1, TEX_SIZE_512);

	CObjEnemy2* CObjE2 = new CObjEnemy2();
	Objs::InsertObj(CObjE2, OBJ_ENEMY2, 2);

	CObjTime* CObjT = new CObjTime();
	Objs::InsertObj(CObjT, OBJ_TIME, 3);

}

//ゲームメイン実行中
void CSceneStage2::Scene()
{
	CObjnul* CObjn = new CObjnul();
	Objs::InsertObj(CObjn, OBJ_NUL, 1);
}