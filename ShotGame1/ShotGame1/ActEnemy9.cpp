/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													 ENEMY9 �A�N�V����													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"
#include "math.h"

/*______________________________________________________*/
/*					  ENEMY9 �A�N�V����					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActEnemy9( void )
{
	int no ;
	static int num ;
	int i ;

	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY9 �����Z�b�g
			*/
			pp->xsize = 70 ;
			pp->ysize = 70 ;
			pp->xboff = 70 ;
			pp->yboff = 70 ;
			pp->xmoff = 70 ;
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

			switch ( pp->flg )
			{
				// left
				case 0 :
					if ( pp->cnt != 0 )
					{
						pp->yspd = 4.0 ;
						if ( pp->ypos == (WINDOW_H - 100) )
						{
							pp->flg = 7 ;
						}

					}
					else if ( pp->xpos >= 100 )
					{
						pp->pchg[1] = pp->flg ;					// �߂��Ă��邽�ߑO�ɗ��t���O�����炤
						pp->flg = 6 ;							// �e��ł��[�h��
					}
					break ;

				// right
				case 1 :
					if ( pp->cnt != 0 )
					{
						pp->yspd = 4.0 ;
						if ( pp->ypos == (WINDOW_H - 100) )
						{
							pp->flg = 7 ;
						}
					}
					else if ( pp->xpos >= 250 )
					{
						pp->pchg[1] = pp->flg ;					// �߂��Ă��邽�ߑO�ɗ��t���O�����炤
						pp->flg = 6 ;							// �e��ł��[�h��
					}
					break ;

				// center
				case 2 :
					if ( pp->cnt != 0 )
					{
						pp->yspd = 4.2 ;
						if ( pp->ypos == (WINDOW_H - 100) )
						{
							pp->flg = 7 ;
						}
					}
					else if ( pp->xpos >= 400 )
					{
						pp->pchg[1] = pp->flg ;					// �߂��Ă��邽�ߑO�ɗ��t���O�����炤
						pp->flg = 6 ;							// �e��ł��[�h��
					}
					break ;

				// right
				case 3 :
					if ( pp->cnt != 0 )
					{
						pp->yspd = 4.0 ;
						if ( pp->ypos == (WINDOW_H - 100) )
						{
							pp->flg = 7 ;
						}
					}
					else if ( pp->xpos <= 550 )
					{
						pp->pchg[1] = pp->flg ;					// �߂��Ă��邽�ߑO�ɗ��t���O�����炤
						pp->flg = 6 ;							// �e��ł��[�h��
					}
					break ;

				// right
				case 4 :
					if ( pp->cnt != 0 )
					{
						pp->yspd = 4.0 ;
						if ( pp->ypos == (WINDOW_H - 100) )
						{
							pp->flg = 7 ;
						}
					}
					else if ( pp->xpos <= 700 )
					{
						pp->pchg[1] = pp->flg ;					// �߂��Ă��邽�ߑO�ɗ��t���O�����炤
						pp->flg = 6 ;							// �e��ł��[�h��
					}
					break ;

				case 6 :
					pp->xspd = 0 ;
					pp->yspd = 0 ;
					if ( pp->time < 0 )
					{
						mciSendString( TEXT("play SE_ES2 from 0 notify") , NULL , 0 , hwnd ) ;	// 01
						pp->cnt += 10 ;
						for ( i = 0 ; i < 3 ; i++ )
						{
							no = ObjSearch( O_ES , MAX_ES ) ;	// �󂢂Ă���z���������
							if ( no != -1 )						// �󂢂Ă�����
							{
								obj[no].idnum = ID_E9S ;		// ���̔z��ɒe������
								obj[no].mode = 0 ;
								obj[no].color = pp->color ;		// �e�̐F
								obj[no].xpos = pp->xpos ;		// X�� �̔��ˈʒu��ENEMY�ɂ���
								obj[no].ypos = pp->ypos ;		// Y�� �̔��ˈʒu��ENEMY�ɂ���
								obj[no].xspd = i * 1.5 ;
								obj[no].yspd = 8.0 - (i * 0.9) ;

								pp->time = 20 ;
							}

							no = ObjSearch( O_ES , MAX_ES ) ;	// �󂢂Ă���z���������
							if ( no != -1 )						// �󂢂Ă�����
							{
								obj[no].idnum = ID_E9S ;		// ���̔z��ɒe������
								obj[no].mode = 0 ;
								obj[no].color = pp->color ;		// �e�̐F
								obj[no].xpos = pp->xpos ;		// X�� �̔��ˈʒu��ENEMY�ɂ���
								obj[no].ypos = pp->ypos ;		// Y�� �̔��ˈʒu��ENEMY�ɂ���
								obj[no].xspd = i * -1.5 ;
								obj[no].yspd = 8.0 - (i * 0.9) ;

								pp->time = 20 ;
							}
						}

						if ( pp->cnt > 120 )
						{
							pp->flg = pp->pchg[1] ;
						}

					}
					break ;

				case 7 :
					if ( pp->time < 0 )
					{
						mciSendString( TEXT("play SE_ES2 from 0 notify") , NULL , 0 , hwnd ) ;	// 01
						for ( i = 0 ; i < 3 ; i++ )
						{
							no = ObjSearch( O_ES , MAX_ES ) ;	// �󂢂Ă���z���������
							if ( no != -1 )						// �󂢂Ă�����
							{
								obj[no].idnum = ID_E9S ;		// ���̔z��ɒe������
								obj[no].mode = 0 ;
								obj[no].color = 2 ;				// �e�̐F
								obj[no].xpos = pp->xpos ;		// X�� �̔��ˈʒu��ENEMY�ɂ���
								obj[no].ypos = pp->ypos ;		// Y�� �̔��ˈʒu��ENEMY�ɂ���
								obj[no].xspd = i * 1.5 ;
								obj[no].yspd = (8.0 - (i * 0.9)) * -1 ;

								pp->time = 5 ;
							}

							no = ObjSearch( O_ES , MAX_ES ) ;	// �󂢂Ă���z���������
							if ( no != -1 )						// �󂢂Ă�����
							{
								obj[no].idnum = ID_E9S ;		// ���̔z��ɒe������
								obj[no].mode = 0 ;
								obj[no].color = 2 ;				// �e�̐F
								obj[no].xpos = pp->xpos ;		// X�� �̔��ˈʒu��ENEMY�ɂ���
								obj[no].ypos = pp->ypos ;		// Y�� �̔��ˈʒu��ENEMY�ɂ���
								obj[no].xspd = i * -1.5 ;
								obj[no].yspd = (8.0 - (i * 0.9)) * -1 ;

								pp->time = 5 ;
							}
						}

					}
					break ;
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
	EPscheck( ) ;												// �v���C���[�̒e�ɓ���������
	EPcheck( ) ;												// ���ړ���������
	Fout( ) ;													// ��ʊO�`�F�b�N

}

/*______________________________________________________*/
/*					  ENEMY9 �e �A�N�V����				*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActE9Shot( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY9 �e �����Z�b�g
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

			if ( pp->color == 0 )
			{
				pp->yspd += -0.2 ;
			}
			else
			{
				pp->yspd += 0.2 ;
			}
			break ;

	}
	BulletColor( ) ;											// �e����֐�
	Fout( ) ;													// ��ʊO�`�F�b�N

}



