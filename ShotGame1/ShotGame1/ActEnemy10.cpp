/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													 ENEMY10 ÉAÉNÉVÉáÉì													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"
#include "math.h"

/*______________________________________________________*/
/*					 ENEMY10 ÉAÉNÉVÉáÉì					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActEnemy10( void )
{
	int no ;
	int i ;
	static int num ;
	static double rol = 0.1 ;
	static int deblt ;

	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY10 èâä˙ÉZÉbÉg
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

			pp->flg = 0 ;
			pp->yspd = 8.0 ;
			pp->time = 10 ;
			pp->color = 0 ;
			pp->cnt = 0 ;
			deblt = 0 ;
			break ;

		case 1 :
			pp->ypos += pp->yspd ;

			switch ( pp->flg )
			{
				// left
				case 0 :
					if ( pp->cnt != 0 )
					{
						// upÇ…ì¶Ç∞ÇÈ
						pp->yspd = -4.0 ;
					}
					else if ( pp->ypos >= 300 )
					{
						pp->pchg[1] = pp->flg ;
						pp->flg = 6 ;
					}
					break ;

				case 6 :
					pp->yspd = 0 ;
					if ( pp->time < 0 )
					{
						pp->cnt += 1 ;
						for ( i = 120 ; i < 460 ; (i += 5) )
						{
							no = ObjSearch( O_ES , MAX_ES ) ;	// ãÛÇ¢ÇƒÇ¢ÇÈîzóÒÇå©Ç¬ÇØÇÈ
							if ( no != -1 )						// ãÛÇ¢ÇƒÇ¢ÇΩÇÁ
							{
								obj[no].idnum = ID_E10S ;		// ÇªÇÃîzóÒÇ…íeÇì¸ÇÍÇÈ
								obj[no].mode = 0 ;
								obj[no].color = pp->color ;
								obj[no].xpos = pp->xpos ;
								obj[no].ypos = pp->ypos ;
								obj[no].xspd = cos( 3.14 / 180 * (i + deblt) ) * 8.0 ;
								obj[no].yspd = sin( 3.14 / 180 * (i + deblt) ) * 8.0 ;

								pp->time = 3 ;

							}

							if ( pp->cnt > 90 )
							{
								pp->flg = pp->pchg[1] ;
							}

						}
						deblt += 4 ;
					}
					pp->time-- ;
					break ;

			}
			Enemy1Roll( ) ;
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
	Fout( ) ;													//	âÊñ äOÉ`ÉFÉbÉN

}

/*______________________________________________________*/
/*					  ENEMY10 íe ÉAÉNÉVÉáÉì				*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActE10Shot( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY10 íe èâä˙ÉZÉbÉg
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
			mciSendString( TEXT("play SE_ES1 from 0 notify") , NULL , 0 , hwnd ) ;	// 01
			break ;

		case 1 :
			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;
			break ;

	}
	BulletColor( ) ;											// íeåıÇÈä÷êî
	Fout( ) ;													//	âÊñ äOÉ`ÉFÉbÉN

}



