#include"Input.h"
#include"WinApp.h"
#include"DirectXCommon.h"
#include"Sprite.h"
#include"SpriteCommon.h"


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

#pragma region 基盤システムの初期化
    WinApp* winApp = nullptr;
    //WindowsAPIの初期化
    winApp = new WinApp();
    winApp->Initialize();

    DirectXCommon* dxCommon = nullptr;
    //DirectXの初期化
    dxCommon = new DirectXCommon();
    dxCommon->Initialize(winApp);

    //ポインタ
    Input* input = nullptr;
    //入力の初期化
    input = new Input();
    input->Initialize(winApp);

    SpriteCommon* spriteCommon = nullptr;
    //スプライト共通部の初期化
    spriteCommon = new SpriteCommon();
    spriteCommon->Initialize(dxCommon);
    spriteCommon->LoadTexture(0, "texture.png");
    spriteCommon->LoadTexture(1, "mario.jpg");
#pragma endregion

#pragma region 最初のシーンの初期化
    Sprite* sprite = new Sprite();
    sprite->Initialize(spriteCommon, 0);
    Sprite* sprite2 = new Sprite();
    sprite2->Initialize(spriteCommon, 1);

    
#pragma endregion

    //ゲームループ
    while (true) {

#pragma region 基盤システム更新
        if (winApp->ProcessMessage() == true) {
            break;
        }
        //入力処理
        input->Update();

#pragma endregion

#pragma region 最初のシーン更新
        //移動
        //ハエ
        DirectX::XMFLOAT2 pos = sprite->GetPosition();
        pos = {450,100};



        sprite->SetPosition(pos);

        sprite->Update();
        sprite2->Update();
#pragma endregion

        //描画前処理
        dxCommon->PreDraw();

#pragma region 最初のシーン描画
        spriteCommon->PreDraw();
        sprite->Draw();
        sprite2->Draw();
        spriteCommon->PostDraw();
#pragma endregion
        //描画後処理
        dxCommon->PostDraw();

    }

#pragma region 最初のシーン終了
    delete sprite;
    sprite = nullptr;
    delete sprite2;
    sprite2 = nullptr;
#pragma endregion

#pragma region 基盤システム終了
    delete spriteCommon;
    spriteCommon = nullptr;

    // ウィンドウクラスを登録解除
    delete input;
    input = nullptr;

    delete dxCommon;
    dxCommon = nullptr;

    winApp->Finalize();
    delete winApp;
    winApp = nullptr;
#pragma endregion

    return 0;
}
