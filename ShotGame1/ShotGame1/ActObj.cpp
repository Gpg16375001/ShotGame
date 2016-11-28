/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*												 ÉIÉuÉWÉFÉNÉg ÉAÉNÉVÉáÉì												*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*					  îwåi ÉAÉNÉVÉáÉì					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActBg( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				îwåi èâä˙ÉZÉbÉg
			*/
			pp->xpos = 0.0 ;
			pp->ypos = 0.0 ;
			pp->xsize = WINDOW_W ;
			pp->ysize = WINDOW_H ;
			pp->xboff = 0 ;
			pp->yboff = WINDOW_H ;
			pp->xmoff = 0 ;
			pp->ymoff = WINDOW_H ;
			pp->xoff = 0 ;										// íÜêSì_ÇÃïœçX Xé≤
			pp->yoff = 0 ;										// íÜêSì_ÇÃïœçX Yé≤
			pp->idx = 0 ;
			pp->mode = 1 ;
			break ;

		case 1 :
			pp->yboff -= 2 ;
			pp->ymoff = pp->yboff ;
			if ( pp->yboff < 0 )
			{
				pp->yboff = WINDOW_H ;
				pp->ymoff = pp->yboff ;
			}
			break ;

	}

}

/*______________________________________________________*/
/*					  îöî≠ ÉAÉNÉVÉáÉì					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActBomb( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				îöî≠ èâä˙ÉZÉbÉg
			*/
			pp->xsize = 80 ;
			pp->ysize = 80 ;
			pp->xboff = 0 ;
			pp->yboff = 0 ;
			pp->xmoff = 0 ;
			pp->ymoff = 80 ;
			pp->idx = 5 ;
			pp->xoff = -40 ;										// íÜêSì_ÇÃïœçX Xé≤
			pp->yoff = -40 ;										// íÜêSì_ÇÃïœçX Yé≤

			pp->mode = 1 ;

			pp->pchg[0] = 0 ;
			mciSendString( TEXT("play SE_BOMB1 from 0 notify") , NULL , 0 , hwnd ) ;// bomb
			break ;

		case 1 :
			pp->pchg[0]++ ;
			if ( pp->pchg[0] < 12 )
			{
				pp->xboff = pp->pchg[0] * 80 ;
				pp->xmoff = pp->pchg[0] * 80 ;
			}
			else
			{
				pp->idnum = 0 ;
				pp->mode = 0 ;
			}
			break ;
	}

}

/*______________________________________________________*/
/*					   ENEMY íeÇÃêF						*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void BulletColor( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				îöî≠ èâä˙ÉZÉbÉg
			*/
			pp->xsize = 80 ;
			pp->ysize = 80 ;
			pp->xboff = 0 ;
			pp->yboff = 16 ;
			pp->xmoff = 0 ;
			pp->ymoff = 80 ;
			pp->idx = 5 ;
			pp->xoff = -40 ;										// íÜêSì_ÇÃïœçX Xé≤
			pp->yoff = -40 ;										// íÜêSì_ÇÃïœçX Yé≤

			pp->mode = 1 ;

			pp->pchg[0] = 0 ;
			break ;

		case 1 :
		case 2 :
		case 3 :
			if ( pp->pchg[0] < 4 )
			{
				pp->xboff = pp->pchg[0] * 16 ;
			}
			pp->pchg[0]++ ;

			if ( pp->pchg[0] >= 4 )
			{
				pp->pchg[0] = 0 ;
			}
			break ;

	}
}

/*______________________________________________________*/
/*					   ENEMY1ÇÃâÒì]						*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void Enemy1Roll( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY1 èâä˙ÉZÉbÉg
			*/
			pp->xsize = 70 ;
			pp->ysize = 70 ;
			pp->xboff = 0 ;
			pp->yboff = 0 ;
			pp->xmoff = 0 ;
			pp->ymoff = 140 ;
			pp->idx = 10 ;
			pp->xoff = -35 ;										// íÜêSì_ÇÃïœçX Xé≤
			pp->yoff = -35 ;										// íÜêSì_ÇÃïœçX Yé≤

			pp->mode = 1 ;

			pp->pchg[0] = 0 ;
			break ;

		case 1 :
		case 2 :
		case 3 :
			if ( pp->pchg[0] < 3 )
			{
				pp->xboff = pp->pchg[0] * 70 ;
				pp->xmoff = pp->pchg[0] * 70 ;
			}
			pp->pchg[0]++ ;

			if ( pp->pchg[0] >= 3 )
			{
				pp->pchg[0] = 0 ;
			}
			break ;

	}
}

/*______________________________________________________*/
/*					   SCORE TEXT						*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActStext( void )
{
	int s1 , s2 , s3 , s4 , s5 , s ;

	switch ( pp->mode )
	{
		case 0 :
			/*
				SCORE TEXT èâä˙ÉZÉbÉg
			*/
			pp->xpos = 550.0 ;
			pp->ypos = 20.0 ;
			pp->xsize = 90 ;
			pp->ysize = 30 ;
			pp->xboff = 220 ;
			pp->yboff = 0 ;
			pp->xmoff = 220 ;
			pp->ymoff = 30 ;
			pp->xoff = 0 ;										// íÜêSì_ÇÃïœçX Xé≤
			pp->yoff = 0 ;										// íÜêSì_ÇÃïœçX Yé≤
			pp->idx = 8 ;
			pp->mode = 1 ;
			break ;

		case 1 :
			s5 = pscore / 10000 ;
			s  = pscore % 10000 ;
			s4 = s / 1000 ;
			s  = s % 1000 ;
			s3 = s / 100 ;
			s  = s % 100 ;
			s2 = s / 10 ;
			s1 = s % 10 ;

			obj[O_SCORE+1].xboff = s1 * 22 ;
			obj[O_SCORE+2].xboff = s2 * 22 ;
			obj[O_SCORE+3].xboff = s3 * 22 ;
			obj[O_SCORE+4].xboff = s4 * 22 ;
			obj[O_SCORE+5].xboff = s5 * 22 ;
			break ;

	}

}

/*______________________________________________________*/
/*					      SCORE							*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActScore( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				SCORE TEXT èâä˙ÉZÉbÉg
			*/
			pp->xpos = 750.0 - pp->cnt * 22 ;
			pp->ypos = 20.0 ;
			pp->xsize = 22 ;
			pp->ysize = 30 ;
			pp->xboff = 0 ;
			pp->yboff = 0 ;
			pp->xmoff = 0 ;
			pp->ymoff = 30 ;
			pp->xoff = 0 ;										// íÜêSì_ÇÃïœçX Xé≤
			pp->yoff = 0 ;										// íÜêSì_ÇÃïœçX Yé≤
			pp->idx = 8 ;
			pp->mode = 1 ;
			break ;

		case 1 :
			pp->xmoff = pp->xboff ;
			break ;

	}

}

/*______________________________________________________*/
/*					    LIFE BASE						*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActLbase( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				LIFE BASE èâä˙ÉZÉbÉg
			*/
			pp->xpos = 80.0 ;
			pp->ypos = 20.0 ;
			pp->xsize = 428 ;
			pp->ysize = 38 ;
			pp->xboff = 0 ;
			pp->yboff = 0 ;
			pp->xmoff = 0 ;
			pp->ymoff = 56 ;
			pp->xoff = 0 ;										// íÜêSì_ÇÃïœçX Xé≤
			pp->yoff = 0 ;										// íÜêSì_ÇÃïœçX Yé≤
			pp->idx = 7 ;
			pp->mode = 1 ;
			break ;

		case 1 :
			break ;

	}

}

/*______________________________________________________*/
/*						   LIFE							*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActLife( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				LIFE èâä˙ÉZÉbÉg
			*/
			pp->xpos = 189.0 ;
			pp->ypos = 29.0 ;
			pp->xsize = 300 ;
			pp->ysize = 18 ;
			pp->xboff = 0 ;
			pp->yboff = 38 ;
			pp->xmoff = 0 ;
			pp->ymoff = 38 ;
			pp->xoff = 0 ;										// íÜêSì_ÇÃïœçX Xé≤
			pp->yoff = 0 ;										// íÜêSì_ÇÃïœçX Yé≤
			pp->idx = 7 ;
			pp->mode = 1 ;
			break ;

		case 1 :
			if ( plife < 0 )
			{
				plife = 300 ;
			}

			pp->xsize = plife ;
			break ;

	}

}

/*______________________________________________________*/
/*						  RESET							*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActReset( void )
{
	if ( GetKeyState(VK_ESCAPE) < 0 )
	{
		InitSet( ) ;
	}
}



