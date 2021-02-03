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
#include "SceneStage5.h"
#include "GameHead.h"
#include "ObjStage5.h"
#include "Background01.h"
#include "ObjNoRoad0.h"
#include "ObjRP.h"

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
//p = Save::ExternalDataOpen(L"k.csv", &size);//外部データ読み込み

	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"stage0,1background.png", 1, TEX_SIZE_512);

	Audio::LoadAudio(1, L"足音.wav", ::EFFECT);
	Audio::LoadAudio(2, L"ロード.wav", ::EFFECT);
	Audio::LoadAudio(3, L"マウス.wav", ::EFFECT);
	Audio::LoadAudio(4, L"リセット.wav", ::EFFECT);

	float Volume = Audio::VolumeMaster(-0.8f);

	CObjPlayer* CObj = new CObjPlayer();
	Objs::InsertObj(CObj, OBJ_PLAYER, 1);

	CObjStage5* CObj5 = new CObjStage5();
	Objs::InsertObj(CObj5, OBJ_ROAD5, 1);

	CObjBackGround01* CObbg = new 	CObjBackGround01();
	Objs::InsertObj(CObbg, OBJ_BACKGROUND01, 0);

	CObjNoRoad0* CObjN = new CObjNoRoad0();
	Objs::InsertObj(CObjN, 	OBJ_NO_ROAD0, 1);

	Draw::LoadImage(L"etc.png", 2, TEX_SIZE_512);

	CObjRP* CObjS = new CObjRP();
	Objs::InsertObj(CObjS, OBJ_SWITCH, 10);

}

//ゲームメイン実行中
void CSceneStage5::Scene()
{
	
}