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
#include "SceneStage3.h"
#include "GameHead.h"
#include "ObjRoad3.h"
#include "ObjNoRoad3.h"
#include "ObjStage3item1.h"
#include "ObjStage3item2.h"
#include "ObjStage3item3.h"
#include "ObjStage3LifeiTem.h"
#include "ObjRP.h"
#include "Background03.h"

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
	Audio::LoadAudio(0, L"Stage3.wav", SOUND_TYPE::BACK_MUSIC);
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
	v = Audio::VolumeMaster((0.5 - v));

	//外部データの読み込み（ステージ情報）
	unique_ptr<wchar_t> p; //ステージ情報ポインター
	int size;			   //ステージ情報大きさ
	p = Save::ExternalDataOpen(L"k.csv", &size);//外部データ読み込み

	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"image2.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"etc.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"stage3,background.png", 3, TEX_SIZE_512);

	CObjPlayer* CObj = new CObjPlayer();
	Objs::InsertObj(CObj, OBJ_PLAYER, 1);

	CObjRoad3* CObj3 = new CObjRoad3();
	Objs::InsertObj(CObj3, OBJ_ROAD3, 1);

	CObjNoRoad3* CObjN = new CObjNoRoad3();
	Objs::InsertObj(CObjN, OBJ_NO_ROAD3, 1);

	CObjBackGround03* CObg = new 	CObjBackGround03();
	Objs::InsertObj(CObg, OBJ_BACKGROUND03, 1);

	CObjEnemy3* CObjE3 = new CObjEnemy3();
	Objs::InsertObj(CObjE3, OBJ_ENEMY3, 2);

	CObjTime* CObjT = new CObjTime();
	Objs::InsertObj(CObjT, OBJ_TIME, 3);

	CObjStage3item1* CObjI1 = new CObjStage3item1();
	Objs::InsertObj(CObjI1, OBJ_ITEM, 1);

	CObjStage3item2* CObjI2 = new CObjStage3item2();
	Objs::InsertObj(CObjI2, OBJ_ITEM, 1);

	CObjStage3item3* CObjI3 = new CObjStage3item3();
	Objs::InsertObj(CObjI3, OBJ_ITEM, 1);

	CObjStage3Lifeitem* CObjL = new CObjStage3Lifeitem();
	Objs::InsertObj(CObjL, OBJ_ITEM, 3);

	CObjRP* CObjS = new CObjRP();
	Objs::InsertObj(CObjS, OBJ_SWITCH, 10);
}

//ゲームメイン実行中
void CSceneStage3::Scene()
{

}