//SLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneGameOver.h"
#include "GameHead.h"

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

}

//実行中メソッド
void CSceneGameOver::Scene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"GAME OVER");
	Font::SetStrTex(L"タイトル画面へ(Enter)");

	//ゲームオーバーオブジェクト作成
	//CObjGameOver* obj = new CObjGameOver();

}