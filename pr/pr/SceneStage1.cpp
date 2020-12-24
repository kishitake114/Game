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
#include "ObjItem.h"
#include "Background01.h"


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

	Audio::LoadAudio(1, L"あるく.wav", ::EFFECT);

	Audio::LoadAudio(2, L"剣.wav", ::EFFECT);

	float Volume = Audio::VolumeMaster(-0.8f);

	//Font作成
	Font::SetStrTex(L"0123456789分秒");

	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"stage0,1background.png", 1, TEX_SIZE_512);

	CObjPlayer* CObj = new CObjPlayer();
	Objs::InsertObj(CObj, OBJ_PLAYER, 2);

	CObjEnemy* CObjE = new CObjEnemy();
	Objs::InsertObj(CObjE, OBJ_ENEMY, 2);

	CObjRoad* CObjR = new CObjRoad();
	Objs::InsertObj(CObjR, OBJ_ROAD, 2);

	CObjTime* CObjT = new CObjTime();
	Objs::InsertObj(CObjT, OBJ_TIME, 2);

	CObjBackGround01* CObbg = new 	CObjBackGround01();
	Objs::InsertObj(CObbg, OBJ_BACKGROUND01, 1);

	CObjNoRoad1* CObjN = new CObjNoRoad1();
	Objs::InsertObj(CObjN, OBJ_NO_ROAD1, 2);
}

//ゲームメイン実行中
void CSceneStage1::Scene()
{


}
