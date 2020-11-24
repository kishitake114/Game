//STLデバック機能をOFFにする
#define _SECURE_SCL_	(0)
#define _HAS_ITERATOR_DEBUGING	(0)

//使用するヘッダー(GameL)
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL/DrawFont.h"
#include "GameL/Audio.h"

//使用するヘッダー
#include "SceneRule.h"
#include "GameHead.h"

//コンストラクタ
CSceneRule::CSceneRule()
{
}

//デストラクタ
CSceneRule::~CSceneRule()
{
}

//ゲームメイン初期化
void CSceneRule::InitScene()
{
	Audio::LoadAudio(0, L"ルール説明.wav",SOUND_TYPE::BACK_MUSIC);

	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster(1.0 - v);

	Audio::Start(0);

	Draw::LoadImage(L"Rule.png", 0, TEX_SIZE_1024);

	CObjRule* CObj = new CObjRule();
	Objs::InsertObj(CObj, OBJ_RULE, 1);
}

//ゲームメイン実行中
void CSceneRule::Scene()
{
}