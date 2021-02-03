#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
#define HNOROAD0 8

class CObjNoRoad0 :public CObj
{
	 public:
		 CObjNoRoad0() {};
		 ~CObjNoRoad0() {};
		 void Init();
		 void Action();
		 void Draw();
	private:
		int map[HNOROAD0][HNOROAD0];
};