//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL_	(0)
#define _HAS_ITERATOR_DEBUGING	(0)

//�g�p����w�b�_�[(GameL)
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL/DrawFont.h"
#include "GameL/Audio.h"

//�g�p����w�b�_�[
#include "SceneRule.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneRule::CSceneRule()
{
}

//�f�X�g���N�^
CSceneRule::~CSceneRule()
{
}

//�Q�[�����C��������
void CSceneRule::InitScene()
{
	Audio::LoadAudio(0, L"���[������.wav",SOUND_TYPE::BACK_MUSIC);

	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster(1.0 - v);

	Audio::Start(0);

	Draw::LoadImage(L"Rule.png", 0, TEX_SIZE_1024);

	CObjRule* CObj = new CObjRule();
	Objs::InsertObj(CObj, OBJ_RULE, 1);
}

//�Q�[�����C�����s��
void CSceneRule::Scene()
{
}