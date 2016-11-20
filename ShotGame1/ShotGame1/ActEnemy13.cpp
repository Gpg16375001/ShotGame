/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													ENEMY13 ÉAÉNÉVÉáÉì													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"
#include "math.h"

/*______________________________________________________*/
/*					 ENEMY13 ÉAÉNÉVÉáÉì					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActEnemy13( void )
{
	int no ;
	static int num ;
	static int dere[2] ;
	int i ;

	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY13 èâä˙ÉZÉbÉg
			*/
			pp->xsize = 70 ;
			pp->ysize = 70 ;
			pp->xboff = 0 ;
			pp->yboff = 70 ;
			pp->xmoff = 0 ;
			pp->ymoff = 210 ;
			pp->xoff = -35 ;									// íÜêSì_ÇÃïœçX Xé≤
			pp->yoff = -35 ;									// íÜêSì_ÇÃïœçX Yé≤
			pp->idx = 2 ;
			pp->mode = 1 ;										// mode1 Ç…à⁄ÇÈ
			pp->time = 4 ;
			pp->pchg[0] = 10 ;
			pp->pchg[1] = 10 ;
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
				mciSendString( TEXT("play SE_ES1 from 0 notify") , NULL , 0 , hwnd ) ;	// 01
				pp->cnt += 1 ;

				/*
					ñÿÇÃïîï™
				*/
				if ( pp->pchg[0] < 0 )
				{
					no = ObjSearch( O_ES , MAX_ES ) ;			// ãÛÇ¢ÇƒÇ¢ÇÈîzóÒÇå©Ç¬ÇØÇÈ
					if ( no != -1 )								// ãÛÇ¢ÇƒÇ¢ÇΩÇÁ
					{
						obj[no].idnum = ID_E13S ;				// ÇªÇÃîzóÒÇ…íeÇì¸ÇÍÇÈ
						obj[no].mode = 0 ;
						obj[no].color = 3 ;
						obj[no].xpos = pp->xpos ;
						obj[no].ypos = (pp->ypos + 30) ;
						obj[no].xspd = cos( 3.14 / 180 * 90 ) * 3.5 ;
						obj[no].yspd = sin( 3.14 / 180 * 90 ) * 3.5 ;

						pp->pchg[0] = 5 ;
					}
				}

				/*
					ëêÇÃïîï™
				*/
				for ( i = 70 ; i < 80 ; (i += 10) )
				{
					no = ObjSearch( O_ES , MAX_ES ) ;			// ãÛÇ¢ÇƒÇ¢ÇÈîzóÒÇå©Ç¬ÇØÇÈ
					if ( no != -1 )								// ãÛÇ¢ÇƒÇ¢ÇΩÇÁ
					{
						obj[no].idnum = ID_E13S ;				// ÇªÇÃîzóÒÇ…íeÇì¸ÇÍÇÈ
						obj[no].mode = 0 ;
						obj[no].color = pp->color ;				// ótÇ¡Çœïîï™
						obj[no].xpos = pp->xpos ;
						obj[no].ypos = pp->ypos ;
						obj[no].xspd = cos( 3.14 / 180 * (i + dere[0]) ) * 3.0 ;
						obj[no].yspd = sin( 3.14 / 180 * (i + dere[0]) ) * 3.0 ;

						pp->time = 1 ;

					}

					/*
						è¸ÇËïîï™
					*/
					if ( pp->pchg[1] < 0 )
					{
						no = ObjSearch( O_ES , MAX_ES ) ;		// ãÛÇ¢ÇƒÇ¢ÇÈîzóÒÇå©Ç¬ÇØÇÈ
						if ( no != -1 )							// ãÛÇ¢ÇƒÇ¢ÇΩÇÁ
						{
							obj[no].idnum = ID_E13S ;			// ÇªÇÃîzóÒÇ…íeÇì¸ÇÍÇÈ
							obj[no].mode = 0 ;
							obj[no].color = rand( ) % 3 ;		// è¸ÇËïîï™
							obj[no].xpos = pp->xpos ;
							obj[no].ypos = pp->ypos ;
							obj[no].xspd = cos( 3.14 / 180 * (i + dere[0]) ) * 3.0 ;
							obj[no].yspd = sin( 3.14 / 180 * (i + dere[0]) ) * 3.0 ;

							pp->pchg[1] = 4 ;
						}
					}

					if ( pp->cnt > 150 )
					{
						pp->mode = 3 ;
					}

				}

				if ( dere[0] >= 40 )
				{
					dere[1] = 1 ;
				}
				else if ( dere[0] <= 0 )
				{
					dere[1] = 0 ;
				}

				if ( dere[1] != 1 )
				{
					dere[0] += 8 ;
				}
				else
				{
					dere[0] -= 8 ;
				}
			}

			pp->time-- ;
			pp->pchg[0]-- ;
			pp->pchg[1]-- ;
			break ;

		case 3 :
			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;
			break ;

		case 98 :
			no = ObjSearch( O_BOMB , MAX_BM ) ;					// ãÛÇ¢ÇƒÇ¢ÇÈîzóÒÇå©Ç¬ÇØÇÈ
			if ( no != -1 )										// ãÛÇ¢ÇƒÇ¢ÇΩÇÁ
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
	Fout( ) ;													//	âÊñ äOÉ`ÉFÉbÉN

}

/*______________________________________________________*/
/*					 ENEMY13 íe ÉAÉNÉVÉáÉì				*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActE13Shot( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY13 íe èâä˙ÉZÉbÉg
			*/
			pp->xsize = 16 ;
			pp->ysize = 16 ;
			pp->xboff = 0 ;
			pp->yboff = 16 * pp->color ;
			pp->xmoff = 64 ;
			pp->ymoff = 0 ;
			pp->idx = 4 ;
			pp->mode = 1 ;
			pp->xoff = -8 ;										// íÜêSì_ÇÃïœçX Xé≤
			pp->yoff = -8 ;										// íÜêSì_ÇÃïœçX Yé≤
			pp->cnt = 0 ;
			break ;

		case 1 :
			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;

			if ( pp->cnt > 100 )
			{
				pp->mode = 0 ;
				pp->idnum = 0 ;
			}
			pp->cnt++ ;
			break ;

	}
	BulletColor( ) ;											// íeåıÇÈä÷êî
	Fout( ) ;													//	âÊñ äOÉ`ÉFÉbÉN

}



