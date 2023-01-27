#pragma once
#include <windows.h>

#include <wrl.h>
#define DIRECTINPUT_VERSION     0x0800   // DirectInputのバージョン指定
#include <dinput.h>

#include "WinApp.h"

class Input
{
public:
	template<class T>using ComPtr = Microsoft::WRL::ComPtr<T>;

public:		// メンバ関数

// 初期化
	void Initialize(WinApp* winApp);

	
// 更新
	void Update();

// キーの押下をチェック
// <param name="keyNumber">キー番号(DIK_0 等)</param>
	bool PushKey(BYTE keyNumber);

// キーのトリガーをチェック
// <param name="keyNumber">キー番号(DIK_0 等)</param>
// <returns>トリガーか</returns>
	bool TriggerKey(BYTE keyNumber);


private:

	// WindowsAPI
	WinApp* winApp = nullptr;


	// メンバ変数
	// キーボードのデバイス
	ComPtr<IDirectInputDevice8>keyboard;

	// DirectInputのインスタンス
	//ComPtr<IDirectInput8> directInput;


	// 全キーの状態
	// 現在の入力情報
	BYTE key[256] = {};
	// 前回の入力情報
	BYTE keyPre[256] = {};
};

