#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_TITLE,
	OBJ_NO_ROAD,
	OBJ_GAME_OVER,
	OBJ_CLEAR,

	OBJ_PLAYER,

	OBJ_RULE,
	OBJ_RULE2,

	OBJ_ROAD,
	OBJ_STAGE2,
	OBJ_STAGE3,
	OBJ_STAGE4,
	OBJ_STAGE5,

	OBJ_TIME,
	OBJ_ITEM,

	OBJ_ENEMY,
	OBJ_ENEMY2,
	OBJ_ENEMY3,
	OBJ_ENEMY4,

	OBJ_HARD_ENEMY,
	OBJ_HARD_ENEMY2,
	OBJ_HARD_ENEMY3,
	OBJ_HARD_ENEMY4,

	OBJ_STAR,

	OBJ_BACKGROUND01,

	OBJ_HARD_STAGE1,
	OBJ_HARD_STAGE2,
	OBJ_HARD_STAGE3,
	OBJ_HARD_STAGE4,
	OBJ_HARD_STAGE5,
};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ
	int Hperfect;
	int EXperfect;
	
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--


//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include "ObjPlayer.h"
#include "ObjTitle.h"
#include "ObjRoad.h"
#include "ObjGameOver.h"
#include "ObjEnemy.h"
#include "ObjClear.h"
#include "ObjRule.h"
#include "ObjRule2.h"
#include "ObjStage2.h"
#include "ObjStage3.h"
#include "ObjStage4.h"
#include "ObjStage5.h"
#include "ObjTime.h"
#include "ObjItem.h"
#include "ObjEnemy2.h"
#include "ObjEnemy3.h"
#include "ObjEnemy4.h"
#include "ObjHardEnemy.h"
#include "ObjHardEnemy2.h"
#include "hardstage1.h"
#include "hardstage2.h"

#include "Objstar.h"

//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include "SceneMain.h"
#include "SceneTitle.h"
#include "SceneGameOver.h"
#include "SceneClear.h"
#include "SceneRule.h"
#include "SceneRule2.h"
#include "SceneStage2.h"
#include "SceneStage3.h"
#include "SceneStage4.h"
#include "SceneStage5.h"
#include "scenehardstage1.h"
#include "sceneHardstage2.h"

//-----------------------------------------------
//シーンスタートクラス---------------------------

//ゲーム開始時のシーンクラス登録
#define SET_GAME_START   CSceneClear
//-----------------------------------------------