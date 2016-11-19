/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													 �v���C���[ �A�N�V����												*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*					  PLAYER �A�N�V����					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActPlayer( void )
{
	int no ;

	switch ( pp->mode )
	{
		case 0 :
			/*
				PLAYER �����Z�b�g
			*/
			pp->xpos = 400.0 ;
			pp->ypos = WINDOW_H + 120 ;
			pp->xsize = 60 ;
			pp->ysize = 60 ;
			pp->xboff = 0 ;
			pp->yboff = 0 ;
			pp->xmoff = 0 ;
			pp->ymoff = 60 ;
			pp->xoff = -30 ;									// ���S�_�̕ύX X��
			pp->yoff = -40 ;									// ���S�_�̕ύX Y��
			pp->idx = 1 ;
			pp->mode = 1 ;

			pp->cnt = 0 ;
			pp->yspd = -4.0 ;
			mciSendString( TEXT("play SE_SP3 from 0 notify") , NULL , 0 , hwnd ) ;	// 01
//			mciSendString( TEXT("play SE_ST from 0 notify") , NULL , 0 , hwnd ) ;	// 01
			break ;

		case 1 :
			pp->ypos += pp->yspd ;
			if ( pp->ypos < 550.0 )
			{
				pp->mode = 2 ;
			}
			break ;

		case 2 :
			pp->xspd = 0 ;
			pp->yspd = 0 ;

			if ( GetKeyState(VK_UP) < 0 )
			{
				if ( pp->cnt > 10 )
				{
					mciSendString( TEXT("play SE_SP2 from 0 notify") , NULL , 0 , hwnd ) ;	// 01
					pp->cnt = 0 ;
				}
				pp->yspd = -PSPD ;
			}
			if ( GetKeyState(VK_DOWN) < 0 )
			{
				if ( pp->cnt > 10 )
				{
					mciSendString( TEXT("play SE_SP2 from 0 notify") , NULL , 0 , hwnd ) ;	// 01
					pp->cnt = 0 ;
				}
				pp->yspd = PSPD ;
			}
			if ( GetKeyState(VK_LEFT) < 0 )
			{
				if ( pp->cnt > 10 )
				{
					mciSendString( TEXT("play SE_SP2 from 0 notify") , NULL , 0 , hwnd ) ;	// 01
					pp->cnt = 0 ;
				}
				pp->xspd = -PSPD ;
			}
			if ( GetKeyState(VK_RIGHT) < 0 )
			{
				if ( pp->cnt > 10 )
				{
					mciSendString( TEXT("play SE_SP2 from 0 notify") , NULL , 0 , hwnd ) ;	// 01
					pp->cnt = 0 ;
				}
				pp->xspd = PSPD ;
			}

			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;

			if ( (GetKeyState(VK_SPACE) < 0) && (psflg == 0) )
			{
				no = ObjSearch( O_PS , MAX_PS ) ;				// �󂢂Ă���z���������
				if ( no != -1 )									// �󂢂Ă�����
				{
					mciSendString( TEXT("play SE_PS from 0 notify") , NULL , 0 , hwnd ) ;	// 01

					obj[no].idnum = ID_PS1 ;					// ���̔z��ɒe������
					obj[no].mode = 0 ;
				}
				psflg = 1 ;
			}

			if ( (GetKeyState(VK_SPACE) >= 0) && (psflg) )
			{
				psflg = 0 ;
			}
			if ( pp->cnt < 11 )
			{
				pp->cnt++ ;
			}
			PlayerMove( ) ;
			break ;

	}
	PEscheck( ) ;

}

/*______________________________________________________*/
/*					  �e1 �A�N�V����					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActPshot( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				PLAYER �e �����Z�b�g
			*/
			pp->xpos = obj[O_PLY].xpos ;
			pp->ypos = obj[O_PLY].ypos - 50 ;					// �����`��̈ʒu�ύX
			pp->xsize = 7 ;
			pp->ysize = 30 ;
			pp->xboff = 0 ;
			pp->yboff = 0 ;
			pp->xmoff = 0 ;
			pp->ymoff = 30 ;
			pp->idx = 3 ;
			pp->mode = 1 ;
			pp->xoff = -4 ;										// ���S�_�̕ύX X��
			pp->yoff = -5 ;										// ���S�_�̕ύX Y��
			pp->yspd = -10.0 ;
			break ;

		case 1 :
			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;
			break ;

	}
	Fout( ) ;					//	��ʊO�`�F�b�N

}

/*______________________________________________________*/
/*				 �v���C���[�̃A�j���[�V����				*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void PlayerMove( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				PLAYER �����Z�b�g
			*/
			pp->xboff = 60 ;
			pp->yboff = 0 ;
			pp->xmoff = 60 ;
			pp->ymoff = 60 ;

			pp->pchg[0] = 0 ;
			break ;

		case 1 :
		case 2 :
			if ( pp->pchg[0] < 3 )
			{
				pp->xboff = pp->pchg[0] * 60 ;
				pp->xmoff = pp->pchg[0] * 60 ;
			}
			pp->pchg[0]++ ;

			if ( pp->pchg[0] >= 3 )
			{
				pp->pchg[0] = 0 ;
			}
			break ;

	}
}



