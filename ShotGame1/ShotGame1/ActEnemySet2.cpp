/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*														 ìGÉZÉbÉg èàóù													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"

int EneSet2[][8] = {
/*
	0: enemy count
	1: ID  2: Sporn.xpos  3: S.ypos  4: S.xspd  5: S.yspd  6: flg  7: color
*/
//	   0 |	  1	   |   2   |  3	 |	4  |  5  | 6 | 7
	{  1 , ID_ENE6 ,   300 ,   0 ,   0 ,  10 , 0 , 0 } ,
	{  1 , ID_ENE7 ,   400 ,   0 ,   0 ,  10 , 1 , 0 } ,
	{  1 , ID_ENE6 ,   500 ,   0 ,   0 ,  10 , 2 , 0 } ,
	{ -1 ,		 0 ,	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,
} ;

/*______________________________________________________*/
/*						 EnemyÉZÉbÉg2					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActEnemySet2( void )
{
	int no ;

	if ( EneSet2[ecount2][0] != -1 )
	{
		no = ObjSearch( O_ENE , MAX_ENE ) ;
		if ( no != -1 )
		{
			obj[no].idnum = EneSet2[ecount2][1] ;
			obj[no].mode = 0 ;
			obj[no].xpos = (double)EneSet2[ecount2][2] ;
			obj[no].ypos = (double)EneSet2[ecount2][3] ;
			obj[no].xspd = (double)EneSet2[ecount2][4] ;
			obj[no].yspd = (double)EneSet2[ecount2][5] ;
			obj[no].flg = EneSet2[ecount2][6] ;
			obj[no].color = EneSet2[ecount2][7] ;
		}
		ecount2++ ;
	}

}


