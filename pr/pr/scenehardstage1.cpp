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
#include "GameHead.h"
#include "Objplayer.h"
#include "hardstage1.h"
#include "ObjHardEnemy.h"

#include "scenehardstage1.h"

CSceneHardstage1::CSceneHardstage1()
{

}

CSceneHardstage1::~CSceneHardstage1()
{

}

void CSceneHardstage1::InitScene()
{
	Audio::LoadAudio(0, L"Stage1.wav", SOUND_TYPE::BACK_MUSIC);

	//Audio::LoadAudio(1, L"あるく.wav", ::EFFECT);

	Audio::LoadAudio(2, L"剣.wav", ::EFFECT);

	float Volume = Audio::VolumeMaster(-0.8f);
	Audio::Start(0);

	//Font作成
	Font::SetStrTex(L"0123456789分秒");

	//外部データの読み込み（ステージ情報）
	unique_ptr<wchar_t> p; //ステージ情報ポインター
	int size;			   //ステージ情報大きさ
	p = Save::ExternalDataOpen(L"k.csv", &size);//外部データ読み込み

	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"stage0,1背景.png", 1, TEX_SIZE_512);

	CObjPlayer* CObj = new CObjPlayer();
	Objs::InsertObj(CObj, OBJ_PLAYER, 2);

	CObjHardStage1* CObjh1 = new CObjHardStage1();
	Objs::InsertObj(CObjh1, OBJ_HARD_STAGE1, 2);

	CObjTime* CObjT = new CObjTime();
	Objs::InsertObj(CObjT, OBJ_TIME, 2);

	CObjHardEnemy* CObjE = new  CObjHardEnemy();
	Objs::InsertObj(CObjE, OBJ_HARD_ENEMY, 3);
}

void CSceneHardstage1::Scene()
{

}

