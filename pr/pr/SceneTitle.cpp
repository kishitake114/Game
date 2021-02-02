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
	CObjTitle* CObjt = new CObjTitle();
	Objs::InsertObj(CObjt, OBJ_TITLE, 1);

	Font::SetStrTex(L"���N���b�N�ő���E���[��������");

	Draw::LoadImage(L"star.png", 2, TEX_SIZE_512);

	Draw::LoadImage(L"Title.png", 0, TEX_SIZE_1024);

	Draw::LoadImage(L"Title2.png", 1, TEX_SIZE_512);

	

	Audio::LoadAudio(0, L"�^�C�g�����.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(1, L"��������.wav", ::EFFECT);
	Audio::LoadAudio(2, L"�����ӂ�.wav", ::EFFECT);

	float  Voiume = Audio::VolumeMaster(-0.8f);

	CObjStar* CObjs = new CObjStar();
	Objs::InsertObj(CObjs, OBJ_STAR, 2);

	Audio::Start(0);
}

//�Q�[�����C�����s��
void CSceneTitle::Scene()
{

}