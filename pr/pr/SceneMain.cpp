//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL_	(0)
#define _HAS_ITERATOR_DEBUGING	(0)

//�g�p����w�b�_�[(GameL)
#include "GameL\DrawTexture.h"

//�g�p����w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneMain::CSceneMain()
{
}

//�f�X�g���N�^
CSceneMain::~CSceneMain()
{
}

//�Q�[�����C��������
void CSceneMain::InitScene()
{
	Draw::LoadImageW(L"image.png", 0, TEX_SIZE_512);
}

//�Q�[�����C�����s��
void CSceneMain::Scene()
{
}
