//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL_	(0)
#define _HAS_ITERATOR_DEBUGING	(0)

//�g�p����w�b�_�[(GameL)
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"

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
	Draw::LoadImage(L"Title.png", 0, TEX_SIZE_512);

	CObjTitle* CObj = new CObjTitle();
	Objs::InsertObj(CObj, OBJ_TITLE, 1);
}

//�Q�[�����C�����s��
void CSceneTitle::Scene()
{
}