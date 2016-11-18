/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													 ÉvÉåÉCÉÑÅ[ ÉAÉNÉVÉáÉì												*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*					  PLAYER ÉAÉNÉVÉáÉì					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActPlayer( void )
{
	int no ;

	switch ( pp->mode )
	{
		case 0 :
			/*
				PLAYER èâä˙ÉZÉbÉg
			*/
			pp->xpos = 400.0 ;
			pp->ypos = WINDOW_H + 120 ;
			pp->xsize = 60 ;
			pp->ysize = 60 ;
			pp->xboff = 0 ;
			pp->yboff = 0 ;
			pp->xmoff = 0 ;
			pp->ymoff = 60 ;
			pp->xoff = -30 ;									// íÜêSì_ÇÃïœçX Xé≤
			pp->yoff = -40 ;									// íÜêSì_ÇÃïœçX Yé≤
			pp->idx = 1 ;
			pp->mode = 1 ;

			pp->yspd = -4.0 ;
			break ;

		case 1 :
			pp->ypos += pp->yspd ;
			if ( pp->ypos < 550.0 )
			{
				pp->mode = 2 ;
			}
			break ;

		case 2 :
			pp->xspd = 0 ;
			pp->yspd = 0 ;

			if ( GetKeyState(VK_UP) < 0 )
			{
				pp->yspd = -PSPD ;
			}
			if ( GetKeyState(VK_DOWN) < 0 )
			{
				pp->yspd = PSPD ;
			}
			if ( GetKeyState(VK_LEFT) < 0 )
			{
				pp->xspd = -PSPD ;
			}
			if ( GetKeyState(VK_RIGHT) < 0 )
			{
				pp->xspd = PSPD ;
			}

			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;

			if ( (GetKeyState(VK_SPACE) < 0) && (psflg == 0) )
			{
				no = ObjSearch( O_PS , MAX_PS ) ;				// ãÛÇ¢ÇƒÇ¢ÇÈîzóÒÇå©Ç¬ÇØÇÈ
				if ( no != -1 )									// ãÛÇ¢ÇƒÇ¢ÇΩÇÁ
				{
					mciSendString( TEXT("play SE_PS from 0 notify") , NULL , 0 , hwnd ) ;	// 01

					obj[no].idnum = ID_PS1 ;					// ÇªÇÃîzóÒÇ…íeÇì¸ÇÍÇÈ
					obj[no].mode = 0 ;
				}
				psflg = 1 ;
			}

			if ( (GetKeyState(VK_SPACE) >= 0) && (psflg) )
			{
				psflg = 0 ;
			}
			break ;

	}
	PEscheck( ) ;

}

/*______________________________________________________*/
/*					  íe1 ÉAÉNÉVÉáÉì					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActPshot( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				PLAYER íe èâä˙ÉZÉbÉg
			*/
			pp->xpos = obj[O_PLY].xpos ;
			pp->ypos = obj[O_PLY].ypos - 50 ;					// èâä˙ï`âÊÇÃà íuïœçX
			pp->xsize = 7 ;
			pp->ysize = 30 ;
			pp->xboff = 0 ;
			pp->yboff = 0 ;
			pp->xmoff = 0 ;
			pp->ymoff = 30 ;
			pp->idx = 3 ;
			pp->mode = 1 ;
			pp->xoff = -4 ;										// íÜêSì_ÇÃïœçX Xé≤
			pp->yoff = -5 ;										// íÜêSì_ÇÃïœçX Yé≤
			pp->yspd = -10.0 ;
			break ;

		case 1 :
			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;
			break ;

	}
	Fout( ) ;					//	âÊñ äOÉ`ÉFÉbÉN

}



