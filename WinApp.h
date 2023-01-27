#include <Windows.h>
#pragma once

// WindowsAPI
class WinApp
{
public:		
	// �ÓI�����o�֐�
	static LRESULT WindowProc(HWND hwnd, UINT msg, 
						WPARAM wparam, LPARAM lparam);

// �萔
public:
	// �E�B���h�E����
	static const int window_width = 1280;
	// �E�B���h�E�c��
	static const int window_height = 720;


public:		// �����o�ϐ�
	
	// ������
	void Initialize();

	// �I��
	void Finalize();

	// ���b�Z�[�W�̏���
	bool ProcesMessage();

	// getter
	HWND GetHwnd() const { return hwnd; }
	HINSTANCE GetHInstance()const { return w.hInstance; }

private:	// �����o�ϐ�
	// �E�B���h�E�n���h��
	HWND hwnd = nullptr;

	// �E�B���h�E�N���X�̐ݒ�
	WNDCLASSEX w{};


};