/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													 ENEMY4 ƒAƒNƒVƒ‡ƒ“													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*					  ENEMY4 ƒAƒNƒVƒ‡ƒ“					*/
/*PPPPPPPPPPPPPPPPPPPPPPPPPPP*/
void ActEnemy4( void )
{
	int no ;
	static int num ;

	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY1 ‰ŠúƒZƒbƒg
			*/
			pp->xsize = 70 ;
			pp->ysize = 70 ;
			pp->xboff = 0 ;
			pp->yboff = 0 ;
			pp->xmoff = 0 ;
			pp->ymoff = 140 ;
			pp->xoff = -35 ;									// ’†S“_‚Ì•ÏX XŽ²
			pp->yoff = -35 ;									// ’†S“_‚Ì•ÏX YŽ²
			pp->idx = 2 ;
			pp->mode = 1 ;										// mode1 ‚ÉˆÚ‚é

			pp->yspd = 20.0 ;									// YŽ²‚ÌƒXƒs[ƒh
			pp->xspd = 2.0 ;									// XŽ²‚ÌƒXƒs[ƒh
			break ;

		case 1 :
			if ( pp->flg == 1 )
			{
				pp->xspd = -2.0 ;
			}
			pp->xpos += pp->xspd ;
			pp->yspd += -0.5 ;
			pp->ypos += pp->yspd ;
			break ;

		case 2 :
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

	EPscheck( ) ;
	EPcheck( ) ;
	Fout( ) ;					//	‰æ–ÊŠOƒ`ƒFƒbƒN

}



