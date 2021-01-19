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
	Audio::LoadAudio(0, L"Stage4.wav", SOUND_TYPE::BACK_MUSIC);

	Audio::LoadAudio(1, L"あるく.wav", ::EFFECT);

	Audio::LoadAudio(2, L"剣.wav", ::EFFECT);


	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster(-0.8f);

	//外部データの読み込み（ステージ情報）
	unique_ptr<wchar_t> p; //ステージ情報ポインター
	int size;			   //ステージ情報大きさ
	p = Save::ExternalDataOpen(L"k.csv", &size);//外部データ読み込み

	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);

	CObjPlayer* CObj = new CObjPlayer();
	Objs::InsertObj(CObj, OBJ_PLAYER, 1);

	CObjStage4* CObj4 = new CObjStage4();
	Objs::InsertObj(CObj4, OBJ_ROAD4, 1);

	CObjTime* CObjT = new CObjTime();
	Objs::InsertObj(CObjT, OBJ_TIME, 1);

	Draw::LoadImage(L"image2.png", 1, TEX_SIZE_512);

	CObjEnemy4* CObjE4 = new CObjEnemy4();
	Objs::InsertObj(CObjE4, OBJ_ENEMY4, 2);

}

//ゲームメイン実行中
void CSceneStage4::Scene()
{

}