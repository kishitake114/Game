//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL_	(0)
#define _HAS_ITERATOR_DEBUGING	(0)

//�g�p����w�b�_�[(GameL)
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"

//�g�p����w�b�_�[
#include "SceneStage4.h"
#include "GameHead.h"
#include "ObjStage4.h"

//�R���X�g���N�^
CSceneStage4::CSceneStage4()
{
}

//�f�X�g���N�^
CSceneStage4::~CSceneStage4()
{
}

//�Q�[�����C��������
void CSceneStage4::InitScene()
{
	//�O���f�[�^�̓ǂݍ��݁i�X�e�[�W���j
	unique_ptr<wchar_t> p; //�X�e�[�W���|�C���^�[
	int size;			   //�X�e�[�W���傫��
	p = Save::ExternalDataOpen(L"k.csv", &size);//�O���f�[�^�ǂݍ���

	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);

	CObjStage4* CObj = new CObjStage4();
	Objs::InsertObj(CObj, OBJ_STAGE4, 1);
}

//�Q�[�����C�����s��
void CSceneStage4::Scene()
{

}