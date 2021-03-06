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
#include "SceneStage4.h"
#include "GameHead.h"
#include "ObjRoad4.h"
#include "ObjNoRoad4.h"
#include "ObjStage4item1.h"
#include "ObjStage4item2.h"
#include "ObjStage4item3.h"
#include "ObjStage4LifeiTem.h"
#include "ObjRP.h"
#include "Background04.h"

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
	Audio::LoadAudio(0, L"Stage4.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(1, L"足音.wav", ::EFFECT);
	Audio::LoadAudio(2, L"ロード.wav", ::EFFECT);
	Audio::LoadAudio(3, L"剣.wav", ::EFFECT);
	Audio::LoadAudio(4, L"リセット.wav", ::EFFECT);
	Audio::LoadAudio(5, L"マウス.wav", ::EFFECT);
	Audio::LoadAudio(6, L"にげる.wav", ::EFFECT);
	Audio::LoadAudio(7, L"こうげき.wav", ::EFFECT);
	Audio::LoadAudio(8, L"かいふく.wav", ::EFFECT);
	Audio::LoadAudio(9, L"カウント.wav", ::EFFECT);
	Audio::LoadAudio(10, L"スタート.wav", ::EFFECT);

	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((0.3 - v));

	//外部データの読み込み（ステージ情報）
	unique_ptr<wchar_t> p; //ステージ情報ポインター
	int size;			   //ステージ情報大きさ
	p = Save::ExternalDataOpen(L"k.csv", &size);//外部データ読み込み

	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"stage4,background.png", 3, TEX_SIZE_512);

	CObjPlayer* CObj = new CObjPlayer();
	Objs::InsertObj(CObj, OBJ_PLAYER, 20);

	CObjRoad4* CObj4 = new CObjRoad4();
	Objs::InsertObj(CObj4, OBJ_ROAD4, 10);

	CObjNoRoad4* CObjN = new CObjNoRoad4();
	Objs::InsertObj(CObjN, OBJ_NO_ROAD4, 1);

	CObjTime* CObjT = new CObjTime();
	Objs::InsertObj(CObjT, OBJ_TIME, 1);

	CObjBackGround04* CObg = new 	CObjBackGround04();
	Objs::InsertObj(CObg, OBJ_BACKGROUND04, 1);

	Draw::LoadImage(L"image2.png", 1, TEX_SIZE_512);

	CObjEnemy4* CObjE4 = new CObjEnemy4();
	Objs::InsertObj(CObjE4, OBJ_ENEMY4, 12);

	CObjStage4item1* CObjI1 = new CObjStage4item1();
	Objs::InsertObj(CObjI1, OBJ_ITEM, 3);

	CObjStage4item2* CObjI2 = new CObjStage4item2();
	Objs::InsertObj(CObjI2, OBJ_ITEM, 3);

	CObjStage4item3* CObjI3 = new CObjStage4item3();
	Objs::InsertObj(CObjI3, OBJ_ITEM, 3);

	CObjStage4Lifeitem* CObjL = new CObjStage4Lifeitem();
	Objs::InsertObj(CObjL, OBJ_ITEM, 3);

	Draw::LoadImage(L"etc.png", 2, TEX_SIZE_512);

	CObjRP* CObjS = new CObjRP();
	Objs::InsertObj(CObjS, OBJ_SWITCH, 10);

}

//ゲームメイン実行中
void CSceneStage4::Scene()
{

}