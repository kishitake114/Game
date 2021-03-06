//SLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//使用するヘッダー(GameL)
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL/UserData.h"
#include "GameL/Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneGameOver.h"
#include "GameHead.h"
#include "SceneGameOver.h"

//コントラクタ
CSceneGameOver::CSceneGameOver()
{

}

//デストラクタ
CSceneGameOver::~CSceneGameOver()
{

}

//初期化メソッド
void CSceneGameOver::InitScene()
{
	Audio::LoadAudio(0, L"GameOver.wav", BACK_MUSIC);

	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((0.7 - v));
	Audio::Start(0);

	CObjGameOver* CObjGO = new CObjGameOver();
	Objs::InsertObj(CObjGO, OBJ_GAME_OVER, 1);

	Draw::LoadImage(L"GameOver.png", 0, TEX_SIZE_512);
}

//実行中メソッド
void CSceneGameOver::Scene()
{
	

}