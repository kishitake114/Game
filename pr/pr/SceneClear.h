#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：クリア
class CSceneClear :public CScene
{
  public :
	  CSceneClear();
      ~CSceneClear();
      void InitScene();//初期化メソッド
      void Scene();    //実行中メソッド
  private:
};

