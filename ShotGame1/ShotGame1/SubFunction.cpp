/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*														 ���̑��֐�														*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*				  �󂫃I�u�W�F�N�g �T�[�`				*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
int ObjSearch( int st , int tm )
{
	int no = -1 ;												// �����Z�b�g

	for (  ; st < (st+tm) ; st++ )								// �w��l�܂ŃJ�E���g
	{
		if ( obj[st].idnum == 0 )								// �`�悳��ĂȂ� idnum
		{
			no = st ;											// no �� ���̔z�� ������
			break ;												// �I������
		}
	}

	return no ;													// no ��Ԃ�

}

/*______________________________________________________*/
/*			�������Ȃ��֐� �e�[�u���W�����v�p			*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActNull( void )
{
}

/*______________________________________________________*/
/*					   ��ʊO�`�F�b�N					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
BOOL Fout( void )
{
	BOOL iRet = 0 ;

	if ( (pp->xpos < -100) || (pp->xpos > (WINDOW_W+100.0))
		|| (pp->ypos < -100) || (pp->ypos > (WINDOW_H+100.0)) )
	{
		pp->idnum = 0 ;
		pp->mode = 0 ;
		pp->cnt ;
		iRet = 1 ;
	}

	return iRet ;

}


