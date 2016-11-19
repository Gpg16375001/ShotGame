/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													 ENEMY5 �A�N�V����													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"
#include "math.h"

/*______________________________________________________*/
/*					  ENEMY5 �A�N�V����					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActEnemy5( void )
{
	int no ;
	int i ;
	static int num ;

	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY5 �����Z�b�g
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
			pp->cnt = 0 ;
			break ;

		case 1 :
			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;

			switch ( pp->flg )
			{
				// left
				case 0 :
					if ( pp->cnt != 0 )
					{
						// ���ɓ�����
						pp->xspd = -4.0 ;
					}
					else if ( pp->ypos >= 300 )
					{
						pp->pchg[1] = pp->flg ;
						pp->flg = 6 ;
					}
					break ;

				// right
				case 1 :
					if ( pp->cnt != 0 )
					{
						// ���ɓ�����
						pp->xspd = 4.0 ;
					}
					else if ( pp->ypos >= 300 )
					{
						pp->pchg[1] = pp->flg ;
						pp->flg = 6 ;
					}
					break ;

				// center
				case 2 :
					if ( pp->cnt != 0 )
					{
						pp->yspd = -4.0 ;
					}
					else if ( pp->ypos >= 250 )
					{
						pp->pchg[1] = pp->flg ;
						pp->flg = 6 ;
					}
					break ;

				// right
				case 3 :
					if ( pp->cnt != 0 )
					{
						pp->xspd = -4.0 ;
					}
					else if ( pp->ypos >= 450 )
					{
						pp->pchg[1] = pp->flg ;
						pp->flg = 6 ;
					}
					break ;

				// right
				case 4 :
					if ( pp->cnt != 0 )
					{
						pp->xspd = 4.0 ;
					}
					else if ( pp->ypos >= 450 )
					{
						pp->pchg[1] = pp->flg ;
						pp->flg = 6 ;
					}
					break ;

				case 6 :
					pp->yspd = 0 ;
					if ( pp->time < 0 )
					{
						mciSendString( TEXT("play SE_ES2 from 0 notify") , NULL , 0 , hwnd ) ;	// 01
						for ( i = 0 ; i < 360 ; (i += 36) )
						{
							no = ObjSearch( O_ES , MAX_ES ) ;			// �󂢂Ă���z���������
							if ( no != -1 )								// �󂢂Ă�����
							{
								pp->cnt += 10 ;
								obj[no].idnum = ID_E5S ;				// ���̔z��ɒe������
								obj[no].mode = 0 ;
								obj[no].color = pp->color ;
								obj[no].xpos = pp->xpos ;
								obj[no].ypos = pp->ypos ;
								obj[no].xspd = cos( 3.14 / 180 * i + pp->cnt ) * 8.0 ;
								obj[no].yspd = sin( 3.14 / 180 * i + pp->cnt ) * 8.0 ;

								pp->time = 4 ;

								if ( pp->cnt > 1000 )
								{
									pp->flg = pp->pchg[1] ;
								}
							}
						}
					}
					pp->time-- ;
					break ;

			}
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
			pscore += 100 ;
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
	Fout( ) ;					//	��ʊO�`�F�b�N

}

/*______________________________________________________*/
/*					  ENEMY5 �e �A�N�V����				*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActE5Shot( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY5 �e �����Z�b�g
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
	BulletColor( ) ;									// �e����֐�
	Fout( ) ;					//	��ʊO�`�F�b�N

}



