/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													 ENEMY6 ÉAÉNÉVÉáÉì													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"
#include "math.h"

/*______________________________________________________*/
/*					  ENEMY6 ÉAÉNÉVÉáÉì					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActEnemy6( void )
{
	int no ;
	int i ;
	static int num ;

	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY6 èâä˙ÉZÉbÉg
			*/
			pp->xsize = 70 ;
			pp->ysize = 70 ;
			pp->xboff = 210 ;
			pp->yboff = 0 ;
			pp->xmoff = 210 ;
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

			if ( pp->time < 0 )
			{
				mciSendString( TEXT("play SE_ES3 from 0 notify") , NULL , 0 , hwnd ) ;	// ES3
				for ( i = 0 ; i < 8 ; i++ )
				{
					no = ObjSearch( O_ES , MAX_ES ) ;				// ãÛÇ¢ÇƒÇ¢ÇÈîzóÒÇå©Ç¬ÇØÇÈ
					if ( no != -1 )									// ãÛÇ¢ÇƒÇ¢ÇΩÇÁ
					{
						obj[no].idnum = ID_E6S ;					// ÇªÇÃîzóÒÇ…íeÇì¸ÇÍÇÈ
						obj[no].mode = 0 ;
						obj[no].xpos = pp->xpos ;
						obj[no].ypos = pp->ypos ;
						obj[no].xm = 0 ;
						obj[no].ym = 0.0 ;
						obj[no].flg = i ;

						pp->time = 60 ;
					}
				}
			}
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
	Fout( ) ;					//	âÊñ äOÉ`ÉFÉbÉN

}

/*______________________________________________________*/
/*					  ENEMY6 íe ÉAÉNÉVÉáÉì				*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActE6Shot( void )
{
	double x , y , z , c , pi ;
	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY6 íe èâä˙ÉZÉbÉg
			*/
			pp->xsize = 16 ;
			pp->ysize = 16 ;
			pp->xboff = 0 ;
			pp->yboff = 32 ;
			pp->xmoff = 64 ;
			pp->ymoff = 0 ;
			pp->idx = 4 ;
			pp->mode = 1 ;
			pp->xoff = -8 ;										// íÜêSì_ÇÃïœçX Xé≤
			pp->yoff = -8 ;										// íÜêSì_ÇÃïœçX Yé≤
			pp->cnt = 0 ;
			pp->xpos += pp->xm ;
			pp->ypos += pp->ym ;
			break ;

		case 1 :
			pp->cnt -= 10 ;

			switch ( pp->flg )
			{
				case  0 :
					pp->xpos += cos( 3.14 / 180 * pp->cnt ) * 16.0 ;	// *îºåa
					pp->ypos += sin( 3.14 / 180 * pp->cnt ) * 15.0 ;
					break ;

				case  1 :
					pp->xpos -= cos( 3.14 / 180 * pp->cnt ) * 16.0 ;	// *îºåa
					pp->ypos += sin( 3.14 / 180 * pp->cnt ) * 15.0 ;
					break ;

				case  2 :
					pp->xpos += cos( 3.14 / 180 * pp->cnt ) * 22.0 ;	// *îºåa
					pp->ypos += sin( 3.14 / 180 * pp->cnt ) * 11.0 ;
					break ;

				case  3 :
					pp->xpos -= cos( 3.14 / 180 * pp->cnt ) * 22.0 ;	// *îºåa
					pp->ypos += sin( 3.14 / 180 * pp->cnt ) * 11.0 ;
					break ;

				case  4 :
					pp->xpos += cos( 3.14 / 180 * pp->cnt ) * 25.0 ;	// *îºåa
					pp->ypos += sin( 3.14 / 180 * pp->cnt ) * 5.0 ;
					break ;

				case  5 :
					pp->xpos -= cos( 3.14 / 180 * pp->cnt ) * 25.0 ;	// *îºåa
					pp->ypos += sin( 3.14 / 180 * pp->cnt ) * 5.0 ;
					break ;

				case  6 :
					pp->xpos += cos( 3.14 / 180 * pp->cnt ) * 10.0 ;	// *îºåa
					pp->ypos += sin( 3.14 / 180 * pp->cnt ) * 17.0 ;
					break ;

				case  7 :
					pp->xpos -= cos( 3.14 / 180 * pp->cnt ) * 10.0 ;	// *îºåa
					pp->ypos += sin( 3.14 / 180 * pp->cnt ) * 17.0 ;
					break ;

			}

			if ( pp->cnt <= -90 )
			{
				pp->cnt = 0 ;
				pp->mode = 2 ;
			}
			break ;

		case 2 :
			if ( pp->cnt >= 20 )
			{
				pi = PI ;
				x = obj[O_PLY].xpos - pp->xpos ;
				y = obj[O_PLY].ypos - pp->ypos ;
				z = atan2( y , x ) ;
				c = z / ( pi/180 ) ;
				pp->xspd = cos( c * (pi / 180) ) * 8.0 ;
				pp->yspd = sin( c * (pi / 180) ) * 8.0 ; 

				pp->yspd += 12.0 ;

				pp->xpos += pp->xspd ;
				pp->ypos += pp->yspd ;
			}
			pp->cnt++ ;
			break ;

	}
	BulletColor( ) ;									// íeåıÇÈä÷êî
	Fout( ) ;					//	âÊñ äOÉ`ÉFÉbÉN

}


