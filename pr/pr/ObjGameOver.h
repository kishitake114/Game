#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�Q�[���I�[�o�[
class CObjGameOver :public CObj
{
    public:
        CObjGameOver() {};
        ~CObjGameOver() {};
        void Init();    //�C�j�V�����C�Y
        void Action();  //�A�N�V����
        void Draw();    //�h���[
    private:
        float m_x;
        float m_y;
        float mou_x;  //�}�E�X�J�[�\���F��
        float mou_y;  //�}�E�X�J�[�\���F�c
        bool  mou_r;  //�}�E�X�{�^���F�E
        bool  mou_l;  //�}�E�X�{�^���F��
        float f_p;
        float pxc;
        float pyc;
        int time;
        int second;

};
