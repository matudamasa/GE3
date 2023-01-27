#pragma once
#include <windows.h>

#include <wrl.h>
#define DIRECTINPUT_VERSION     0x0800   // DirectInput�̃o�[�W�����w��
#include <dinput.h>

#include "WinApp.h"

class Input
{
public:
	template<class T>using ComPtr = Microsoft::WRL::ComPtr<T>;

public:		// �����o�֐�

// ������
	void Initialize(WinApp* winApp);

	
// �X�V
	void Update();

// �L�[�̉������`�F�b�N
// <param name="keyNumber">�L�[�ԍ�(DIK_0 ��)</param>
	bool PushKey(BYTE keyNumber);

// �L�[�̃g���K�[���`�F�b�N
// <param name="keyNumber">�L�[�ԍ�(DIK_0 ��)</param>
// <returns>�g���K�[��</returns>
	bool TriggerKey(BYTE keyNumber);


private:

	// WindowsAPI
	WinApp* winApp = nullptr;


	// �����o�ϐ�
	// �L�[�{�[�h�̃f�o�C�X
	ComPtr<IDirectInputDevice8>keyboard;

	// DirectInput�̃C���X�^���X
	//ComPtr<IDirectInput8> directInput;


	// �S�L�[�̏��
	// ���݂̓��͏��
	BYTE key[256] = {};
	// �O��̓��͏��
	BYTE keyPre[256] = {};
};

