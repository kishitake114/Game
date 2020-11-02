#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームメイン
class CSceneStage4 :public CScene
{
public:
	CSceneStage4();
	~CSceneStage4();
	void InitScene();	//初期化
	void Scene();		//実行中
private:
};