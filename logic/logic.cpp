// logic.cpp : DLL �A�v���P�[�V�����p�ɃG�N�X�|�[�g�����֐����`���܂��B
//

#include "stdafx.h"
#include "logic.h"


// ����́A�G�N�X�|�[�g���ꂽ�ϐ��̗�ł��B
LOGIC_API int nlogic=0;

// ����́A�G�N�X�|�[�g���ꂽ�֐��̗�ł��B
LOGIC_API int fnlogic(void)
{
	return 42;
}

// ����́A�G�N�X�|�[�g���ꂽ�N���X�̃R���X�g���N�^�[�ł��B
// �N���X��`�Ɋւ��Ă� logic.h ���Q�Ƃ��Ă��������B
Clogic::Clogic()
{
	return;
}
