#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームメイン
class CSceneStage2 :public CScene
{
public:
	CSceneStage2();
	~CSceneStage2();
	void InitScene();	//初期化
	void Scene();		//実行中
private:
};
