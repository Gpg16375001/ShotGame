/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*														 ìGÉZÉbÉg èàóù													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"

int EneSet1[][8] = {
/*
	0: enemy count
	1: ID  2: Sporn.xpos  3: S.ypos  4: S.xspd  5: S.yspd  6: flg  7: color
*/
	{ 1 , ID_ENE5 , 200 , -50 , 0 , 10 , 0 , 2 } ,
	{ 1 , ID_ENE5 , 600 , -50 , 0 , 10 , 1 , 2 } ,
	{ 1 , ID_ENE5 , 400 , -50 , 0 , 10 , 2 , 1 } ,
	{ 1 , ID_ENE5 , 300 , -50 , 0 , 10 , 3 , 2 } ,
	{ 1 , ID_ENE5 , 500 , -50 , 0 , 10 , 4 , 2 } ,
	{ -1 ,		0 ,   0 ,   0 , 0 ,  0 , 0 , 0 } ,
} ;

/*______________________________________________________*/
/*						 EnemyÉZÉbÉg1					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
void ActEnemySet1( void )
{
	int no ;

	if ( EneSet1[ecount][0] != -1 )
	{
		no = ObjSearch( O_ENE , MAX_ENE ) ;
		if ( no != -1 )
		{
			obj[no].idnum = EneSet1[ecount][1] ;
			obj[no].mode = 0 ;
			obj[no].xpos = (double)EneSet1[ecount][2] ;
			obj[no].ypos = (double)EneSet1[ecount][3] ;
			obj[no].xspd = (double)EneSet1[ecount][4] ;
			obj[no].yspd = (double)EneSet1[ecount][5] ;
			obj[no].flg = EneSet1[ecount][6] ;
			obj[no].color = EneSet1[ecount][7] ;
		}
		ecount++ ;
	}

}


