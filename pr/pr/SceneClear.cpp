//SL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//�g�p����w�b�_�[(GameL)
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL/UserData.h"
#include "GameL/DrawFont.h"
#include "GameL/Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneClear.h"
#include "GameHead.h"

//�R���g���N�^
CSceneClear::CSceneClear()
{

}

//�f�X�g���N�^
CSceneClear::~CSceneClear()
{

}

//���������\�b�h
void CSceneClear::InitScene()
{
	Audio::LoadAudio(0, L"GameClear.wav", BACK_MUSIC);

	Draw::LoadImage(L"rogo.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"image.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"image2.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"image3.png", 3, TEX_SIZE_512);

	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster(-0.8f);

	Audio::Start(0);


	Font::SetStrTex(L"GAME CLEAR!");

	CObjClear* CObj = new CObjClear();
	Objs::InsertObj(CObj, OBJ_CLEAR, 1);

}

//���s�����\�b�h
void CSceneClear::Scene()
{


}