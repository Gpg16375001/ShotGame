/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*														 敵セット 処理													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"

int EneSet5[][8] = {
/*
	0: enemy count
	1: ID  2: Sporn.xpos  3: S.ypos  4: S.xspd  5: S.yspd  6: flg  7: color
*/
//	   0 |	   1	|   2  |  3	 |  4  |  5  | 6 | 7
	{  1 ,  ID_ENE4 ,   50 , 300 ,  20 , -20 , 1 , 1 } ,			// ENEMY 4	白色
	{  1 ,  ID_ENE4 ,  750 , 300 , -20 , -20 , 1 , 1 } ,			// ENEMY 4	白色
	{  1 , ID_ENE13 ,  400 , 200 ,  10 , -20 , 1 , 1 } ,			// ENEMY 13	緑色
	{  1 , ID_ENE14 ,  400 , 200 ,  10 , -20 , 1 , 1 } ,			// ENEMY 14	黄色
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// なし
	{  1 ,  ID_ENE3 ,  750 , 400 , -16 ,  -3 , 1 , 1 } ,			// ENEMY 3	サンタ
	{ -1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// セット終了
} ;

/*______________________________________________________*/
/*						 Enemyセット5					*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void ActEnemySet5( void )
{
	int no ;

	if ( EneSet5[ecount[4]][0] != -1 )
	{
		no = ObjSearch( O_ENE , MAX_ENE ) ;
		if ( no != -1 )
		{
			obj[no].idnum = EneSet5[ecount[4]][1] ;
			obj[no].mode = 0 ;
			obj[no].xpos = (double)EneSet5[ecount[4]][2] ;
			obj[no].ypos = (double)EneSet5[ecount[4]][3] ;
			obj[no].xspd = (double)EneSet5[ecount[4]][4] ;
			obj[no].yspd = (double)EneSet5[ecount[4]][5] ;
			obj[no].flg = EneSet5[ecount[4]][6] ;
			obj[no].color = EneSet5[ecount[4]][7] ;
		}
		ecount[4]++ ;
	}

}


