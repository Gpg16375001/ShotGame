/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													  �O���[�o���錾													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"

/* ____ �O���[�o���ϐ��錾 ____ */
DT		obj[MAXOBJ] ;
DT		*pp ;
HDC		hDCBack ;
HBITMAP	hBmpTbl[20] ;
BOOL	tmf = 0 ;
HWND	hwnd ;															// 1 = �^�C�}�[�����`�F�b�N�t���O
BOOL	psflg ;
int etim ;																// �G�l�~�[���o�Ă���Ƃ��̃J�E���g��
int ecnt ;
int pscore ;															// score
int plife ;																// player life
int ecount ;															// �G�l�~�[�Z�b�g�̃G�l�~�[�̐�


