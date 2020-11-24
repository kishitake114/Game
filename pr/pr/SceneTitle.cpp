//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL_	(0)
#define _HAS_ITERATOR_DEBUGING	(0)

//�g�p����w�b�_�[(GameL)
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

//�g�p����w�b�_�[
#include "SceneTitle.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneTitle::CSceneTitle()
{
}

//�f�X�g���N�^
CSceneTitle::~CSceneTitle()
{
}

//�Q�[�����C��������
void CSceneTitle::InitScene()
{
	Font::SetStrTex(L"���N���b�N�ő���E���[��������");

	Draw::LoadImage(L"Title.png", 0, TEX_SIZE_1024);

	CObjTitle* CObjt = new CObjTitle();
	Objs::InsertObj(CObjt, OBJ_TITLE, 1);
	
	Audio::LoadAudio(0, L"�ł��邩�ȁH (online-audio-converter.com).wav ", SOUND_TYPE::BACK_MUSIC);

	float  Voiume = Audio::VolumeMaster(-0.8f); 

	Audio::Start(0);
}

//�Q�[�����C�����s��
void CSceneTitle::Scene()
{
}