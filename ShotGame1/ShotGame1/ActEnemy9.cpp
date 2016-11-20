/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													 ENEMY9 ÉAÉNÉVÉáÉì													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"
#include "math.h"

/*______________________________________________________*/
/*					  ENEMY9 ÉAÉNÉVÉáÉì					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActEnemy9( void )
{
	int no ;
	static int num ;
	int i ;

	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY9 èâä˙ÉZÉbÉg
			*/
			pp->xsize = 70 ;
			pp->ysize = 70 ;
			pp->xboff = 70 ;
			pp->yboff = 70 ;
			pp->xmoff = 70 ;
			pp->ymoff = 210 ;
			pp->xoff = -35 ;									// íÜêSì_ÇÃïœçX Xé≤
			pp->yoff = -35 ;									// íÜêSì_ÇÃïœçX Yé≤
			pp->idx = 2 ;
			pp->mode = 1 ;										// mode1 Ç…à⁄ÇÈ
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
						pp->pchg[1] = pp->flg ;					// ñﬂÇ¡ÇƒÇ≠ÇÈÇΩÇﬂëOÇ…óßÉtÉâÉOÇÇ‡ÇÁÇ§
						pp->flg = 6 ;							// íeÇë≈Ç¬ÉÇÅ[ÉhÇ÷
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
						pp->pchg[1] = pp->flg ;					// ñﬂÇ¡ÇƒÇ≠ÇÈÇΩÇﬂëOÇ…óßÉtÉâÉOÇÇ‡ÇÁÇ§
						pp->flg = 6 ;							// íeÇë≈Ç¬ÉÇÅ[ÉhÇ÷
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
						pp->pchg[1] = pp->flg ;					// ñﬂÇ¡ÇƒÇ≠ÇÈÇΩÇﬂëOÇ…óßÉtÉâÉOÇÇ‡ÇÁÇ§
						pp->flg = 6 ;							// íeÇë≈Ç¬ÉÇÅ[ÉhÇ÷
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
						pp->pchg[1] = pp->flg ;					// ñﬂÇ¡ÇƒÇ≠ÇÈÇΩÇﬂëOÇ…óßÉtÉâÉOÇÇ‡ÇÁÇ§
						pp->flg = 6 ;							// íeÇë≈Ç¬ÉÇÅ[ÉhÇ÷
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
						pp->pchg[1] = pp->flg ;					// ñﬂÇ¡ÇƒÇ≠ÇÈÇΩÇﬂëOÇ…óßÉtÉâÉOÇÇ‡ÇÁÇ§
						pp->flg = 6 ;							// íeÇë≈Ç¬ÉÇÅ[ÉhÇ÷
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
							no = ObjSearch( O_ES , MAX_ES ) ;	// ãÛÇ¢ÇƒÇ¢ÇÈîzóÒÇå©Ç¬ÇØÇÈ
							if ( no != -1 )						// ãÛÇ¢ÇƒÇ¢ÇΩÇÁ
							{
								obj[no].idnum = ID_E9S ;		// ÇªÇÃîzóÒÇ…íeÇì¸ÇÍÇÈ
								obj[no].mode = 0 ;
								obj[no].color = pp->color ;		// íeÇÃêF
								obj[no].xpos = pp->xpos ;		// Xé≤ ÇÃî≠éÀà íuÇENEMYÇ…Ç∑ÇÈ
								obj[no].ypos = pp->ypos ;		// Yé≤ ÇÃî≠éÀà íuÇENEMYÇ…Ç∑ÇÈ
								obj[no].xspd = i * 1.5 ;
								obj[no].yspd = 8.0 - (i * 0.9) ;

								pp->time = 20 ;
							}

							no = ObjSearch( O_ES , MAX_ES ) ;	// ãÛÇ¢ÇƒÇ¢ÇÈîzóÒÇå©Ç¬ÇØÇÈ
							if ( no != -1 )						// ãÛÇ¢ÇƒÇ¢ÇΩÇÁ
							{
								obj[no].idnum = ID_E9S ;		// ÇªÇÃîzóÒÇ…íeÇì¸ÇÍÇÈ
								obj[no].mode = 0 ;
								obj[no].color = pp->color ;		// íeÇÃêF
								obj[no].xpos = pp->xpos ;		// Xé≤ ÇÃî≠éÀà íuÇENEMYÇ…Ç∑ÇÈ
								obj[no].ypos = pp->ypos ;		// Yé≤ ÇÃî≠éÀà íuÇENEMYÇ…Ç∑ÇÈ
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
							no = ObjSearch( O_ES , MAX_ES ) ;	// ãÛÇ¢ÇƒÇ¢ÇÈîzóÒÇå©Ç¬ÇØÇÈ
							if ( no != -1 )						// ãÛÇ¢ÇƒÇ¢ÇΩÇÁ
							{
								obj[no].idnum = ID_E9S ;		// ÇªÇÃîzóÒÇ…íeÇì¸ÇÍÇÈ
								obj[no].mode = 0 ;
								obj[no].color = 2 ;				// íeÇÃêF
								obj[no].xpos = pp->xpos ;		// Xé≤ ÇÃî≠éÀà íuÇENEMYÇ…Ç∑ÇÈ
								obj[no].ypos = pp->ypos ;		// Yé≤ ÇÃî≠éÀà íuÇENEMYÇ…Ç∑ÇÈ
								obj[no].xspd = i * 1.5 ;
								obj[no].yspd = (8.0 - (i * 0.9)) * -1 ;

								pp->time = 5 ;
							}

							no = ObjSearch( O_ES , MAX_ES ) ;	// ãÛÇ¢ÇƒÇ¢ÇÈîzóÒÇå©Ç¬ÇØÇÈ
							if ( no != -1 )						// ãÛÇ¢ÇƒÇ¢ÇΩÇÁ
							{
								obj[no].idnum = ID_E9S ;		// ÇªÇÃîzóÒÇ…íeÇì¸ÇÍÇÈ
								obj[no].mode = 0 ;
								obj[no].color = 2 ;				// íeÇÃêF
								obj[no].xpos = pp->xpos ;		// Xé≤ ÇÃî≠éÀà íuÇENEMYÇ…Ç∑ÇÈ
								obj[no].ypos = pp->ypos ;		// Yé≤ ÇÃî≠éÀà íuÇENEMYÇ…Ç∑ÇÈ
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
	EPscheck( ) ;												// ÉvÉåÉCÉÑÅ[ÇÃíeÇ…ìñÇΩÇ¡ÇΩéû
	EPcheck( ) ;												// íºê⁄ìñÇΩÇ¡ÇΩéû
	Fout( ) ;													// âÊñ äOÉ`ÉFÉbÉN

}

/*______________________________________________________*/
/*					  ENEMY9 íe ÉAÉNÉVÉáÉì				*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActE9Shot( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY9 íe èâä˙ÉZÉbÉg
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
	BulletColor( ) ;											// íeåıÇÈä÷êî
	Fout( ) ;													// âÊñ äOÉ`ÉFÉbÉN

}



