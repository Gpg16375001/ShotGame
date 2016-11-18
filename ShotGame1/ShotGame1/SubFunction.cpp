/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*														 ÇªÇÃëºä÷êî														*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*				  ãÛÇ´ÉIÉuÉWÉFÉNÉg ÉTÅ[É`				*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
int ObjSearch( int st , int tm )
{
	int no = -1 ;												// èâä˙ÉZÉbÉg

	for (  ; st < (st+tm) ; st++ )								// éwíËílÇ‹Ç≈ÉJÉEÉìÉg
	{
		if ( obj[st].idnum == 0 )								// ï`âÊÇ≥ÇÍÇƒÇ»Ç¢ idnum
		{
			no = st ;											// no Ç… ÇªÇÃîzóÒ Çì¸ÇÍÇÈ
			break ;												// èIóπÇ∑ÇÈ
		}
	}

	return no ;													// no Çï‘Ç∑

}

/*______________________________________________________*/
/*			âΩÇ‡ÇµÇ»Ç¢ä÷êî ÉeÅ[ÉuÉãÉWÉÉÉìÉvóp			*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActNull( void )
{
}

/*______________________________________________________*/
/*					   âÊñ äOÉ`ÉFÉbÉN					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
BOOL Fout( void )
{
	BOOL iRet = 0 ;

	if ( (pp->xpos < -100) || (pp->xpos > (WINDOW_W+100.0))
		|| (pp->ypos < -100) || (pp->ypos > (WINDOW_H+100.0)) )
	{
		pp->idnum = 0 ;
		pp->mode = 0 ;
		pp->cnt ;
		iRet = 1 ;
	}

	return iRet ;

}


