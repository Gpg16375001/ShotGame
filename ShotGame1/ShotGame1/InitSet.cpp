/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*														 �����Z�b�g														*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*						  �����Z�b�g					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void InitSet( void )
{
	obj[O_BG].idnum = ID_BG ;									// �w�i ���Ă�
	obj[O_BG].mode = 0 ;										// �����Z�b�g���Ăяo��

	obj[O_PLY].idnum = ID_PLY ;									// PLAYER ���Ă�
	obj[O_PLY].mode = 0 ;										// �����Z�b�g���Ăяo��

	obj[O_SCORE+0].idnum = ID_STEXT ;							// PLAYER ���Ă�
	obj[O_SCORE+0].mode = 0 ;									// �����Z�b�g���Ăяo��

	obj[O_SCORE+1].idnum = ID_SCORE ;							// PLAYER ���Ă�
	obj[O_SCORE+1].mode = 0 ;									// �����Z�b�g���Ăяo��
	obj[O_SCORE+1].cnt = 0 ;									// �����Z�b�g���Ăяo��

	obj[O_SCORE+2].idnum = ID_SCORE ;							// PLAYER ���Ă�
	obj[O_SCORE+2].mode = 0 ;									// �����Z�b�g���Ăяo��
	obj[O_SCORE+2].cnt = 1 ;									// �����Z�b�g���Ăяo��

	obj[O_SCORE+3].idnum = ID_SCORE ;							// PLAYER ���Ă�
	obj[O_SCORE+3].mode = 0 ;									// �����Z�b�g���Ăяo��
	obj[O_SCORE+3].cnt = 2 ;									// �����Z�b�g���Ăяo��

	obj[O_SCORE+4].idnum = ID_SCORE ;							// PLAYER ���Ă�
	obj[O_SCORE+4].mode = 0 ;									// �����Z�b�g���Ăяo��
	obj[O_SCORE+4].cnt = 3 ;									// �����Z�b�g���Ăяo��

	obj[O_SCORE+5].idnum = ID_SCORE ;							// PLAYER ���Ă�
	obj[O_SCORE+5].mode = 0 ;									// �����Z�b�g���Ăяo��
	obj[O_SCORE+5].cnt = 4 ;									// �����Z�b�g���Ăяo��

	obj[O_LIFE+0].idnum = ID_LBASE ;									// PLAYER ���Ă�
	obj[O_LIFE+0].mode = 0 ;										// �����Z�b�g���Ăяo��

	obj[O_LIFE+1].idnum = ID_LIFE ;									// PLAYER ���Ă�
	obj[O_LIFE+1].mode = 0 ;										// �����Z�b�g���Ăяo��

	etim = 0 ;
	ecnt = 0 ;

	psflg = 0 ;													// �e�����̃t���O
	pscore = 0 ;
	plife = 300 ;
}



