/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													 ÉqÉbÉgÉ`ÉFÉbÉNèàóù													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"

/*
	E	=>	P
	E	=>	Ps
	P	=>	Es
*/

/*______________________________________________________*/
/*					E => P Collision					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
int EPcheck( void )
{
	int pl , pr , pu , pd ;
	int el , er , eu , ed ;

	if ( pp->mode != 99 )
	{
		pl = (int)obj[O_PLY].xpos - 15 ;
		pr = (int)obj[O_PLY].xpos + 15 ;
		pu = (int)obj[O_PLY].ypos - 10 ;
		pd = (int)obj[O_PLY].ypos + 10 ;

		el = (int)pp->xpos - 20 ;
		er = (int)pp->xpos + 20 ;
		eu = (int)pp->ypos - 20 ;
		ed = (int)pp->ypos + 20 ;

		if ( (pu < ed) && (pd > eu) )
		{
			if ( (pl < er) && (pr > el) )
			{
//				obj[O_PLY].idnum = 0 ;
//				obj[O_PLY].mode = 0 ;
				plife-- ;
				mciSendString( TEXT("play SE_PHIT from 0 notify") , NULL , 0 , hwnd ) ;	// ES3

				pp->mode = 98 ;

			}
		}
	}
	return 0 ;
}

/*______________________________________________________*/
/*					E => Ps Collision					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
int EPscheck( void )
{
	int el , er , eu , ed ;
	int x , y ;
	int i ;

	if ( pp->mode != 99 )
	{
		el = (int)pp->xpos - 20 ;
		er = (int)pp->xpos + 20 ;
		eu = (int)pp->ypos - 20 ;
		ed = (int)pp->ypos + 20 ;

		for ( i = O_PS ; i < (O_PS+MAX_PS) ; i++ )
		{
			if ( obj[i].idnum != 0 )
			{
				x = (int)obj[i].xpos  ;
				y = (int)obj[i].ypos  ;

				if ( (el < x) && (er > x) && (eu < y) && (ed > y) )
				{
					pp->mode = 98 ;
					obj[i].idnum = 0 ;
					obj[i].mode = 0 ;
					obj[i].xpos = -200 ;
				}
			}
		}
	}

	return 0 ;
}

/*______________________________________________________*/
/*					P => Es	Collision					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
int PEscheck( void )
{
	int pl , pr , pu , pd ;
	int x , y ;
	int i ;

	if ( pp->mode != 99 )
	{
		pl = (int)pp->xpos - 10 ;
		pr = (int)pp->xpos + 10 ;
		pu = (int)pp->ypos - 5 ;
		pd = (int)pp->ypos + 5 ;

		for ( i = O_ES ; i < (O_ES+MAX_ES) ; i++ )
		{
			if ( obj[i].idnum != 0 )
			{
				x = (int)obj[i].xpos  ;
				y = (int)obj[i].ypos  ;

				if ( (pl < x) && (pr > x) && (pu < y) && (pd > y) )
				{
//					pp->idnum = 0 ;
//					pp->mode = 0 ;
					plife-- ;
					obj[i].idnum = 0 ;
					obj[i].mode = 0 ;
					mciSendString( TEXT("play SE_PHIT from 0 notify") , NULL , 0 , hwnd ) ;	// ES3
				}
			}
		}
	}

	return 0 ;

}



