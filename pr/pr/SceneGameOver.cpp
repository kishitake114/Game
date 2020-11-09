//SL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//�g�p����w�b�_�[(GameL)
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL/UserData.h"
#include "GameL/Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneGameOver.h"
#include "GameHead.h"

//�R���g���N�^
CSceneGameOver::CSceneGameOver()
{

}

//�f�X�g���N�^
CSceneGameOver::~CSceneGameOver()
{

}

//���������\�b�h
void CSceneGameOver::InitScene()
{
	Audio::LoadAudio(0, L"�łт̕� (online-audio-converter.com).wav", BACK_MUSIC);

	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster(-0.8f);

	Audio::Start(0);
	Draw::LoadImage(L"GameOver.png", 0, TEX_SIZE_512);

	CObjGameOver* CObjGO = new CObjGameOver();
	Objs::InsertObj(CObjGO, OBJ_GAME_OVER, 1);
}

//���s�����\�b�h
void CSceneGameOver::Scene()
{
	

}