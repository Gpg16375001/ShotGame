/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													 ENEMY7 �A�N�V����													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"
#include "math.h"

/*______________________________________________________*/
/*					  ENEMY7 �A�N�V����					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActEnemy7( void )
{
	int no ;
	static int num ;
	int i ;

	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY7 �����Z�b�g
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
			pp->time = 10 ;
			pp->flg = 2 ;
			break ;

		case 1 :
			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;

			if ( pp->time < 0 )
			{
				for ( i = 0 ; i < 360 ; (i += 4) )
				{
					no = ObjSearch( O_ES , MAX_ES ) ;			// �󂢂Ă���z���������
					if ( no != -1 )								// �󂢂Ă�����
					{
						obj[no].idnum = ID_E7S ;				// ���̔z��ɒe������
						obj[no].mode = 0 ;
						obj[no].xpos = pp->xpos ;
						obj[no].ypos = pp->ypos ;
						switch ( pp->flg )
						{
							case  0 :
								obj[no].xspd = cos( 3.14 / 180 * i ) * 1.0 ;
								obj[no].yspd = sin( 3.14 / 180 * i ) * 4.0 ;
								break ;

							case  1 :
								obj[no].xspd = cos( 3.14 / 180 * i ) * 4.0 ;
								obj[no].yspd = sin( 3.14 / 180 * i ) * 1.0 ;
								break ;

						}
						pp->flg++ ;
						pp->time = 60 ;
						if ( pp->flg > 2 )
						{
							pp->flg = 0 ;
						}
					}
				}
			}
			pp->time-- ;
			Enemy1Roll( ) ;
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
/*					  ENEMY7 �e �A�N�V����				*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActE7Shot( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY7 �e �����Z�b�g
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
			break ;

		case 1 :
			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;
			break ;

	}
	BulletColor( ) ;											// �e����֐�
	Fout( ) ;													//	��ʊO�`�F�b�N

}



