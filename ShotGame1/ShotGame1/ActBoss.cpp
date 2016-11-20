/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													 BOSS ƒAƒNƒVƒ‡ƒ“													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"
#include "math.h"

/*______________________________________________________*/
/*					  BOSS ƒAƒNƒVƒ‡ƒ“					*/
/*PPPPPPPPPPPPPPPPPPPPPPPPPPP*/
void ActBoss( void )
{
	int no ;
	static int num ;
	static int dere[2] ;
	int i ;

	switch ( pp->mode )
	{
		case 0 :
			/*
				BOSS ‰ŠúƒZƒbƒg
			*/
			pp->xsize = 620 ;
			pp->ysize = 242 ;
			pp->xboff = 0 ;
			pp->yboff = 0 ;
			pp->xmoff = 0 ;
			pp->ymoff = 242 ;
			pp->xoff = -310 ;									// ’†S“_‚Ì•ÏX XŽ²
			pp->yoff = -121 ;									// ’†S“_‚Ì•ÏX YŽ²
			pp->idx = 6 ;
			pp->mode = 1 ;										// mode1 ‚ÉˆÚ‚é

			pp->yspd = 4.0 ;
			mciSendString( TEXT("play SE_END from 0 notify") , NULL , 0 , hwnd ) ;	// 01
			break ;

		case 1 :
			pp->ypos += (int)pp->yspd ;

			if ( pp->ypos >= 180.0 )
			{
				pp->mode = 3 ;
				pp->yspd = 0.0 ;
			}
			break ;

		case 2 :
			if ( pp->time < 0 )
			{
				for ( i = 0 ; i < 120 ; (i += 10) )
				{
					no = ObjSearch( O_ES , MAX_ES ) ;			// ‹ó‚¢‚Ä‚¢‚é”z—ñ‚ðŒ©‚Â‚¯‚é
					if ( no != -1 )								// ‹ó‚¢‚Ä‚¢‚½‚ç
					{
						obj[no].idnum = ID_BSHOT ;				// ‚»‚Ì”z—ñ‚É’e‚ð“ü‚ê‚é
						obj[no].mode = 0 ;
						obj[no].color = 4 ;
						obj[no].xpos = pp->xpos ;
						obj[no].ypos = pp->ypos ;
						obj[no].xspd = cos( 3.14 / 180 * (i + dere[0]) ) * 1.2 ;
						obj[no].yspd = sin( 3.14 / 180 * (i + dere[0]) ) * 8.0 ;
						obj[no].yspd *= -1 ;

						pp->time = 2 ;
					}
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
			pp->time-- ;
			break ;

		case 3 :
			break ;

		case 98 :
			no = ObjSearch( O_BOMB , MAX_BM ) ;					// ‹ó‚¢‚Ä‚¢‚é”z—ñ‚ðŒ©‚Â‚¯‚é
			if ( no != -1 )										// ‹ó‚¢‚Ä‚¢‚½‚ç
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

}

/*______________________________________________________*/
/*					  BOSS ’e ƒAƒNƒVƒ‡ƒ“				*/
/*PPPPPPPPPPPPPPPPPPPPPPPPPPP*/
void ActBossShot( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				BOSS ’e ‰ŠúƒZƒbƒg
			*/
			pp->xsize = 16 ;
			pp->ysize = 16 ;
			pp->xboff = 0 ;
			pp->yboff = 16 * 6 ;
			pp->xmoff = 64 ;
			pp->ymoff = 96 ;
			pp->idx = 4 ;
			pp->mode = 1 ;
			pp->xoff = -8 ;										// ’†S“_‚Ì•ÏX XŽ²
			pp->yoff = -8 ;										// ’†S“_‚Ì•ÏX YŽ²
			pp->cnt = 0 ;
			break ;

		case 1 :
			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;
			pp->yspd += 0.1 ;
			pp->xboff = 16 * pp->cnt ;
			pp->xmoff = 16 * pp->cnt ;
			pp->cnt++ ;

			if ( pp->cnt > 3 )
			{
				pp->cnt = 0 ;
			}

			break ;

	}
	Fout( ) ;													//	‰æ–ÊŠOƒ`ƒFƒbƒN

}



