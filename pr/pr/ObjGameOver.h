#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ゲームオーバー
class CObjGameOver :public CObj
{
    public:
        CObjGameOver() {};
        ~CObjGameOver() {};
        void Init();    //イニシャライズ
        void Action();  //アクション
        void Draw();    //ドロー
    private:
        float m_x;
        float m_y;
        float mou_x;  //マウスカーソル：横
        float mou_y;  //マウスカーソル：縦
        bool  mou_r;  //マウスボタン：右
        bool  mou_l;  //マウスボタン：左
        float f_p;
        float pxc;
        float pyc;
        int time;
        int second;

};
