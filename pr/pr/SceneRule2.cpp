//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL_	(0)
#define _HAS_ITERATOR_DEBUGING	(0)

//�g�p����w�b�_�[(GameL)
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL/DrawFont.h"

//�g�p����w�b�_�[
#include "SceneRule2.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneRule2::CSceneRule2()
{
}

//�f�X�g���N�^
CSceneRule2::~CSceneRule2()
{
}

//�Q�[�����C��������
void CSceneRule2::InitScene()
{
	Draw::LoadImage(L"Rule2.png", 0, TEX_SIZE_1024);

	CObjRule2* CObj = new CObjRule2();
	Objs::InsertObj(CObj, OBJ_RULE2, 1);
}

//�Q�[�����C�����s��
void CSceneRule2::Scene()
{
}