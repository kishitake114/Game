//STLデバック機能をOFFにする
#define _SECURE_SCL_	(0)
#define _HAS_ITERATOR_DEBUGING	(0)

//使用するヘッダー(GameL)
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL/UserData.h"
#include "GameL/DrawFont.h"
#include "GameL/Audio.h"

using namespace GameL;

//使用するヘッダー
#include "SceneStage1.h"
#include "ObjNoRoad1.h"
#include "GameHead.h"
#include "Objplayer.h"
#include "ObjRoad.h"
#include "Background01.h"
#include "ObjStage1item1.h"
#include "ObjStage1item2.h"
#include "ObjStage1item3.h"
#include "ObjStage1LifeiTem.h"
#include "ObjRP.h"




//コンストラクタ
CSceneStage1::CSceneStage1()
{
}

//デストラクタ
CSceneStage1::~CSceneStage1()
{
}

//ゲームメイン初期化
void CSceneStage1::InitScene()
{		
	Audio::LoadAudio(0, L"Stage1.wav", SOUND_TYPE::BACK_MUSIC);

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
	v = Audio::VolumeMaster((1.0 - v));
	Audio::Start(0);
	
	//Font作成
	Font::SetStrTex(L"0123456789分秒");

	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"stage0,1background.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"etc.png", 2, TEX_SIZE_512);

	CObjPlayer* CObj = new CObjPlayer();
	Objs::InsertObj(CObj, OBJ_PLAYER, 20);

	CObjEnemy* CObjE = new CObjEnemy();
	Objs::InsertObj(CObjE, OBJ_ENEMY, 20);

	CObjRoad* CObjR = new CObjRoad();
	Objs::InsertObj(CObjR, OBJ_ROAD1, 10);

	CObjTime* CObjT = new CObjTime();
	Objs::InsertObj(CObjT, OBJ_TIME, 2);

	CObjBackGround01* CObg = new 	CObjBackGround01();
	Objs::InsertObj(CObg, OBJ_BACKGROUND01, 1);

	CObjNoRoad1* CObjN = new CObjNoRoad1();
	Objs::InsertObj(CObjN, OBJ_NO_ROAD1, 2);

	CObjStage1item1* CObjI1 = new CObjStage1item1();
	Objs::InsertObj(CObjI1, OBJ_ITEM, 3);

	CObjStage1item2* CObjI2 = new CObjStage1item2();
	Objs::InsertObj(CObjI2, OBJ_ITEM, 3);

	CObjStage1item3* CObjI3 = new CObjStage1item3();
	Objs::InsertObj(CObjI3, OBJ_ITEM, 3);

	CObjStage1Lifeitem* CObjL = new CObjStage1Lifeitem();
	Objs::InsertObj(CObjL, OBJ_ITEM, 3);
	
	CObjRP* CObjS = new CObjRP();
	Objs::InsertObj(CObjS, OBJ_SWITCH, 10);

}

//ゲームメイン実行中
void CSceneStage1::Scene()
{

}
