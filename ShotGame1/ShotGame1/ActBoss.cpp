/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													 BOSS ƒAƒNƒVƒ‡ƒ“													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*					  BOSS ƒAƒNƒVƒ‡ƒ“					*/
/*PPPPPPPPPPPPPPPPPPPPPPPPPPP*/
void ActBoss( void )
{
	int no ;
	static int num ;

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
			break ;

		case 1 :
			pp->ypos += (int)pp->yspd ;

			if ( pp->ypos >= 180.0 )
			{
				pp->mode = 2 ;
				pp->yspd = 0.0 ;
				pp->xspd = 4.0 ;
			}
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

}


