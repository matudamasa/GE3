#include <Windows.h>
#pragma once

// WindowsAPI
class WinApp
{
public:		
	// 静的メンバ関数
	static LRESULT WindowProc(HWND hwnd, UINT msg, 
						WPARAM wparam, LPARAM lparam);

// 定数
public:
	// ウィンドウ横幅
	static const int window_width = 1280;
	// ウィンドウ縦幅
	static const int window_height = 720;


public:		// メンバ変数
	
	// 初期化
	void Initialize();

	// 終了
	void Finalize();

	// メッセージの処理
	bool ProcesMessage();

	// getter
	HWND GetHwnd() const { return hwnd; }
	HINSTANCE GetHInstance()const { return w.hInstance; }

private:	// メンバ変数
	// ウィンドウハンドル
	HWND hwnd = nullptr;

	// ウィンドウクラスの設定
	WNDCLASSEX w{};


};