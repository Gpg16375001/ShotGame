/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													 ENEMY1 �A�N�V����													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*					  ENEMY1 �A�N�V����					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActEnemy1( void )
{
	int no ;
	static int num ;

	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY1 �����Z�b�g
			*/
			pp->xsize = 70 ;
			pp->ysize = 70 ;
			pp->xboff = 0 ;
			pp->yboff = 0 ;
			pp->xmoff = 0 ;
			pp->ymoff = 140 ;
			pp->xoff = -35 ;									// ���S�_�̕ύX X��
			pp->yoff = -35 ;									// ���S�_�̕ύX Y��
			pp->idx = 2 ;
			pp->mode = 1 ;										// mode1 �Ɉڂ�

			pp->yspd = 4.0 ;
			break ;

		case 1 :
			pp->ypos += (int)pp->yspd ;

			if ( pp->ypos >= 100.0 )
			{
				pp->mode = 2 ;
				pp->yspd = 0.0 ;
				pp->xspd = 4.0 ;
			}
			break ;

		case 2 :
			if ( GetKeyState(VK_UP) < 0 )
			{
				pp->mode = 98 ;
			}

			pp->xpos += pp->xspd ;

			if ( (pp->xpos < 35 ) || (pp->xpos > (WINDOW_W - 35)) )
			{
				pp->xspd *= -1 ;
			}

			if ( pp->time < 0 )
			{
				no = ObjSearch( O_ES , MAX_ES ) ;				// �󂢂Ă���z���������
				if ( no != -1 )									// �󂢂Ă�����
				{
					obj[no].idnum = ID_E1S ;					// ���̔z��ɒe������
					obj[no].mode = 0 ;
					obj[no].xpos = pp->xpos ;
					obj[no].ypos = pp->ypos ;
					pp->time = 30 ;
				}
			}
			pp->time-- ;
			break ;

		case 98 :
			no = ObjSearch( O_BOMB , MAX_BM ) ;					// �󂢂Ă���z���������
			if ( no != -1 )										// �󂢂Ă�����
			{
				num = no ;
				obj[no].idnum = ID_BOMB ;
				obj[no].mode = 0 ;
				obj[no].xpos = pp->xpos ;
				obj[no].ypos = pp->ypos ;
				pp->time = 6 ;
				pp->mode = 99 ;
			}
			break ;

		case 99 :
			pp->time-- ;
			obj[num].ypos = pp->ypos ;
			pp->ypos += 4 ;
			if ( pp->time < 0 )
			{
				pp->idnum = 0 ;
				pp->mode = 0 ;
			}
			break ;

	}
	Fout( ) ;					//	��ʊO�`�F�b�N

}

/*______________________________________________________*/
/*					  ENEMY1 �e �A�N�V����				*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActE1Shot( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY1 �e �����Z�b�g
			*/
			pp->xsize = 16 ;
			pp->ysize = 16 ;
			pp->xboff = 0 ;
			pp->yboff = 32 ;
			pp->xmoff = 64 ;
			pp->ymoff = 0 ;
			pp->idx = 4 ;
			pp->mode = 1 ;
			pp->xoff = -8 ;										// ���S�_�̕ύX X��
			pp->yoff = -8 ;										// ���S�_�̕ύX Y��

			pp->yspd = 10.0 ;
			break ;

		case 1 :
			pp->ypos += pp->yspd ;
			break ;

	}
	Fout( ) ;					//	��ʊO�`�F�b�N

}



