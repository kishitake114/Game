//STLデバック機能をOFFにする
#define _SECURE_SCL_	(0)
#define _HAS_ITERATOR_DEBUGING	(0)

//使用するヘッダー(GameL)
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

//使用するヘッダー
#include "SceneTitle.h"
#include "GameHead.h"

//コンストラクタ
CSceneTitle::CSceneTitle()
{
}

//デストラクタ
CSceneTitle::~CSceneTitle()
{
}

//ゲームメイン初期化
void CSceneTitle::InitScene()
{
	Font::SetStrTex(L"左クリックで操作・ルール説明へ");

	Draw::LoadImage(L"Title.png", 0, TEX_SIZE_1024);

	CObjTitle* CObjt = new CObjTitle();
	Objs::InsertObj(CObjt, OBJ_TITLE, 1);
	
	Audio::LoadAudio(0, L"できるかな？ (online-audio-converter.com).wav ", SOUND_TYPE::BACK_MUSIC);

	float  Voiume = Audio::VolumeMaster(-0.8f); 

	Audio::Start(0);
}

//ゲームメイン実行中
void CSceneTitle::Scene()
{
}