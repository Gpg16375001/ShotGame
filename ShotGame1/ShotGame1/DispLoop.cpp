/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													 ÉfÉBÉXÉv ÉãÅ[Év													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*						  âÊëú ï`âÊ						*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void DispLoop( void )
{
	HDC		hDC , hDCWork ;
	int i ;
	int x , y ;

	hDC = GetDC( hwnd ) ;
	hDCWork = CreateCompatibleDC( hDC ) ;

	// 
	pp = obj ;
	for ( i = 0 ; i < MAXOBJ ; i++ )
	{
		if ( (pp->idnum  != 0) && (pp->mode  != 0) )
		{
			SelectObject( hDCWork , hBmpTbl[pp->idx] ) ;

			/*
				íÜêSì_ÇÇ∏ÇÁÇ∑èàóù
			*/
			x = (int)pp->xpos + pp->xoff ;
			y = (int)pp->ypos + pp->yoff ;
			BitBlt( hDCBack , x , y , pp->xsize , pp->ysize , hDCWork , pp->xmoff , pp->ymoff , SRCAND ) ;
			BitBlt( hDCBack , x , y , pp->xsize , pp->ysize , hDCWork , pp->xboff , pp->yboff , SRCPAINT ) ;
		}
		pp++ ;
	}

	DeleteDC( hDCWork ) ;
	ReleaseDC( hwnd , hDC ) ;

}



