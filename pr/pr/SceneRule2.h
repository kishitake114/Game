#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームメイン
class CSceneRule2 :public CScene
{
public:
	CSceneRule2();
	~CSceneRule2();
	void InitScene();	//初期化
	void Scene();		//実行中
private:
};
