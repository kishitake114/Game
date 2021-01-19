//使用するヘッダーファイル
#include "ObjNoRoad2.h"
#include "ObjPlayer.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h"
#include "GameL/HitBoxManager.h"
#include "GameL/SceneObjManager.h"
#include "GameL/UserData.h"
#include "GameL/Audio.h"
#include "SceneStage2.h"

#define PIECE 17
#define SIZE 30.0f

void CObjNoRoad2::Init()
{

}

void CObjNoRoad2::Action()
{
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	CObjEnemy* Enemy = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
	float px = player->GetX();
	float py = player->GetY();


}

void CObjNoRoad2::Draw()
{
}
