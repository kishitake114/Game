#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：ゲームメイン
class CSceneStage1:public CScene
{
	public:
		CSceneStage1();
		~CSceneStage1();
		void InitScene();	//初期化
		void Scene();		//実行中
	private:
		
};