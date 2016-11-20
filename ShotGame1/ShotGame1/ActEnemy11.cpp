/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													ENEMY11 �A�N�V����													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"
#include "math.h"

/*______________________________________________________*/
/*					 ENEMY11 �A�N�V����					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActEnemy11( void )
{
	int no ;
	static int num ;
	static int dere[2] ;
	int i ;

	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY11 �����Z�b�g
			*/
			pp->xsize = 70 ;
			pp->ysize = 70 ;
			pp->xboff = 0 ;
			pp->yboff = 70 ;
			pp->xmoff = 0 ;
			pp->ymoff = 210 ;
			pp->xoff = -35 ;									// ���S�_�̕ύX X��
			pp->yoff = -35 ;									// ���S�_�̕ύX Y��
			pp->idx = 2 ;
			pp->mode = 1 ;										// mode1 �Ɉڂ�
			pp->time = 10 ;
			break ;

		case 1 :
			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;

			if ( pp-> ypos >= 70 )
			{
				pp->mode = 2 ;
			}
			break ;

		case 2 :
			if ( pp->time < 0 )
			{
				mciSendString( TEXT("play SE_ES2 from 0 notify") , NULL , 0 , hwnd ) ;	// 01
				pp->cnt += 1 ;
				for ( i = 60 ; i < 70 ; (i += 10) )
				{
					no = ObjSearch( O_ES , MAX_ES ) ;	// �󂢂Ă���z���������
					if ( no != -1 )						// �󂢂Ă�����
					{
						obj[no].idnum = ID_E10S ;		// ���̔z��ɒe������
						obj[no].mode = 0 ;
						obj[no].color = pp->color ;
						obj[no].xpos = pp->xpos ;
						obj[no].ypos = pp->ypos ;
						obj[no].xspd = cos( 3.14 / 180 * (i + dere[0]) ) * 8.0 ;
						obj[no].yspd = sin( 3.14 / 180 * (i + dere[0]) ) * 8.0 ;

						pp->time = 1 ;

					}

					if ( pp->cnt > 120 )
					{
						pp->mode = 3 ;
					}

				}

				if ( dere[0] >= 60 )
				{
					dere[1] = 1 ;
				}
				else if ( dere[0] <= 0 )
				{
					dere[1] = 0 ;
				}

				if ( dere[1] != 1 )
				{
					dere[0] += 4 ;
				}
				else
				{
					dere[0] -= 4 ;
				}
			}

			pp->time-- ;
			break ;

		case 3 :
			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;

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
	EPscheck( ) ;
	EPcheck( ) ;
	Fout( ) ;													//	��ʊO�`�F�b�N

}

/*______________________________________________________*/
/*					 ENEMY11 �e �A�N�V����				*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActE11Shot( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY11 �e �����Z�b�g
			*/
			pp->xsize = 16 ;
			pp->ysize = 16 ;
			pp->xboff = 0 ;
			pp->yboff = 16 * pp->color ;
			pp->xmoff = 64 ;
			pp->ymoff = 0 ;
			pp->idx = 4 ;
			pp->mode = 1 ;
			pp->xoff = -8 ;										// ���S�_�̕ύX X��
			pp->yoff = -8 ;										// ���S�_�̕ύX Y��
			break ;

		case 1 :
			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;
			break ;

	}
	BulletColor( ) ;											// �e����֐�
	Fout( ) ;													//	��ʊO�`�F�b�N

}



