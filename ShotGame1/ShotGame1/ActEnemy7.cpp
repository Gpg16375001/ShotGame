/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													 ENEMY7 ÉAÉNÉVÉáÉì													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"
#include "math.h"

/*______________________________________________________*/
/*					  ENEMY7 ÉAÉNÉVÉáÉì					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActEnemy7( void )
{
	int no ;
	static int num ;
	int i ;

	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY7 èâä˙ÉZÉbÉg
			*/
			pp->xsize = 70 ;
			pp->ysize = 70 ;
			pp->xboff = 0 ;
			pp->yboff = 0 ;
			pp->xmoff = 0 ;
			pp->ymoff = 140 ;
			pp->xoff = -35 ;									// íÜêSì_ÇÃïœçX Xé≤
			pp->yoff = -35 ;									// íÜêSì_ÇÃïœçX Yé≤
			pp->idx = 2 ;
			pp->mode = 1 ;										// mode1 Ç…à⁄ÇÈ
			pp->time = 10 ;
			break ;

		case 1 :
			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;

			pp->yspd += 0.5 ;

			if ( pp->ypos < 300 )
			{
				pp->mode = 2 ;
			}
			break ;

		case 2 :
			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;

			if ( pp->time < 0 )
			{
				mciSendString( TEXT("play SE_ES1 from 0 notify") , NULL , 0 , hwnd ) ;	// 01
				for ( i = 0 ; i < 360 ; (i += 4) )
				{
					no = ObjSearch( O_ES , MAX_ES ) ;			// ãÛÇ¢ÇƒÇ¢ÇÈîzóÒÇå©Ç¬ÇØÇÈ
					if ( no != -1 )								// ãÛÇ¢ÇƒÇ¢ÇΩÇÁ
					{
						obj[no].idnum = ID_E7S ;				// ÇªÇÃîzóÒÇ…íeÇì¸ÇÍÇÈ
						obj[no].mode = 0 ;
						obj[no].color = pp->color ;
						obj[no].xpos = pp->xpos ;
						obj[no].ypos = pp->ypos ;
						switch ( pp->flg )
						{
							case  0 :
								obj[no].xspd = cos( PI / 180 * i ) *  3.0 ;
								obj[no].yspd = sin( PI / 180 * i ) * 12.0 ;
								break ;

							case  1 :
								obj[no].xspd = cos( PI / 180 * i ) * 12.0 ;
								obj[no].yspd = sin( PI / 180 * i ) *  3.0 ;
								break ;

						}
						pp->flg++ ;
						pp->time = 10 ;
						if ( pp->flg > 1 )
						{
							pp->flg = 0 ;
						}
					}
				}
			}
			pp->mode = 1 ;
			pp->time-- ;
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
	Enemy1Roll( ) ;
	EPscheck( ) ;
	EPcheck( ) ;
	Fout( ) ;													//	âÊñ äOÉ`ÉFÉbÉN

}

/*______________________________________________________*/
/*					  ENEMY7 íe ÉAÉNÉVÉáÉì				*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActE7Shot( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY7 íe èâä˙ÉZÉbÉg
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
			break ;

		case 1 :
			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;
			break ;

	}
	BulletColor( ) ;											// íeåıÇÈä÷êî
	Fout( ) ;													//	âÊñ äOÉ`ÉFÉbÉN

}



