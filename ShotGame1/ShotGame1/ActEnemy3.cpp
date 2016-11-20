/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													 ENEMY3 �A�N�V����													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"
#include "math.h"

/*______________________________________________________*/
/*					  ENEMY3 �A�N�V����					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActEnemy3( void )
{
	int no ;
	int i ;
	static int num ;

	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY3 �����Z�b�g
			*/
			pp->xsize = 70 ;
			pp->ysize = 70 ;
			pp->xboff = 210 ;
			pp->yboff = 70 ;
			pp->xmoff = 210 ;
			pp->ymoff = 210 ;
			pp->xoff = -35 ;									// ���S�_�̕ύX X��
			pp->yoff = -35 ;									// ���S�_�̕ύX Y��
			pp->idx = 2 ;
			pp->mode = 1 ;										// mode1 �Ɉڂ�

			pp->cnt = 0 ;
			break ;

		case 1 :
			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;
			if ( pp->ypos <= 350 )
			{
				pp->mode = 2 ;
				pp->xm = pp->xpos ;
				pp->ym = pp->ypos - 140 ;
				pp->cnt = 90 ;
			}
			break ;

		case 2 :
			pp->cnt += 10 ;
			pp->xpos = cos( 3.14 / 180 * pp->cnt ) * 140.0 ;	// *���a
			pp->ypos = sin( 3.14 / 180 * pp->cnt ) * 140.0 ;

			pp->xpos += pp->xm ;
			pp->ypos += pp->ym ;

			if ( pp->cnt >= 450 )
			{
				pp->mode = 3 ;
				pp->cnt = 0 ;
			}
			break ;

		case 3 :
			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;
			break ;

		case 4 :
			pp->ym += 4.0 ;
			pp->cnt += 10 ;
			pp->xpos = cos( 3.14 / 180 * pp->cnt ) * 60.0 ;		// *���a
			pp->ypos = sin( 3.14 / 180 * pp->cnt ) * 60.0 ;

			pp->xpos += pp->xm ;
			pp->ypos += pp->ym ;
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
			pscore += 11040 ;
			break ;

		case 99 :
			pp->time-- ;
			obj[num].ypos = pp->ypos ;
			pp->ypos += 4.0 ;
			if ( pp->time < 0 )
			{
				pp->idnum = 0 ;
				pp->mode = 0 ;
			}
			break ;

	}
	EPscheck( ) ;
	EPcheck( ) ;
	Fout( ) ;													//	��ʊO�`�F�b�N

}

/*______________________________________________________*/
/*					  ENEMY3 �e �A�N�V����				*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActE3Shot( void )
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
			pp->cnt = 0 ;
			break ;

		case 1 :
			pp->cnt += 1 ;

			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;
			break ;

	}
	Fout( ) ;													//	��ʊO�`�F�b�N

}



