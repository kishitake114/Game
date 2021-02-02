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
	CObjTitle* CObjt = new CObjTitle();
	Objs::InsertObj(CObjt, OBJ_TITLE, 1);

	Font::SetStrTex(L"左クリックで操作・ルール説明へ");

	Draw::LoadImage(L"star.png", 2, TEX_SIZE_512);

	Draw::LoadImage(L"Title.png", 0, TEX_SIZE_1024);

	Draw::LoadImage(L"Title2.png", 1, TEX_SIZE_512);

	

	Audio::LoadAudio(0, L"タイトル画面.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(1, L"こうげき.wav", ::EFFECT);
	Audio::LoadAudio(2, L"かいふく.wav", ::EFFECT);

	float  Voiume = Audio::VolumeMaster(-0.8f);

	CObjStar* CObjs = new CObjStar();
	Objs::InsertObj(CObjs, OBJ_STAR, 2);

	Audio::Start(0);
}

//ゲームメイン実行中
void CSceneTitle::Scene()
{

}