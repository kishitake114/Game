//SLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//使用するヘッダー(GameL)
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL/UserData.h"
#include "GameL/DrawFont.h"
#include "GameL/Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneClear.h"
#include "GameHead.h"

//コントラクタ
CSceneClear::CSceneClear()
{

}

//デストラクタ
CSceneClear::~CSceneClear()
{

}

//初期化メソッド
void CSceneClear::InitScene()
{
	Audio::LoadAudio(0, L"GameClear.wav", BACK_MUSIC);

	Draw::LoadImage(L"Title.png", 0, TEX_SIZE_1024);

	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster(-0.8f);

	Audio::Start(0);


	Font::SetStrTex(L"GAME CLEAR!");

	CObjClear* CObj = new CObjClear();
	Objs::InsertObj(CObj, OBJ_CLEAR, 1);

	CObjnul* CObjn = new CObjnul();
	Objs::InsertObj(CObjn, OBJ_NUL,1);
}

//実行中メソッド
void CSceneClear::Scene()
{


}