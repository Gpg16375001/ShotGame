/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*														 �G�Z�b�g ����													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"

int EneTbl[][5] = {
	{    1 , ID_ESET3 ,   0 ,    0 , 0 } ,
//	{   10 , ID_ESET1 ,   0 ,    0 , 0 } ,					// SET 1	�z�u
//	{  150 , ID_ENE10 , 400 ,  -50 , 0 } ,					// ENEMY 10	�z�u
	{  500 , ID_ESET2 ,   0 ,    0 , 0 } ,					// SET 2	�z�u
	{  650 , ID_ESET3 ,   0 ,    0 , 0 } ,					// SET 3	�z�u
	{ 1200 ,  ID_BOSS , 400 , -150 , 0 } ,					// BOOS		�z�u
	{   -1 ,	    0 ,   0 ,	 0 , 0 } ,
} ;

/*______________________________________________________*/
/*						  Enemy�Z�b�g					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void EnemySet( void )
{
	int no ;

	etim++ ;
	if (EneTbl[ecnt][0] == etim)
	{
		no = ObjSearch( O_ENE , MAX_ENE ) ;
		if ( no != -1 )
		{
			obj[no].idnum = EneTbl[ecnt][1] ;
			obj[no].mode = 0 ;
			obj[no].xpos = (double)EneTbl[ecnt][2] ;
			obj[no].ypos = (double)EneTbl[ecnt][3] ;
			obj[no].flg = EneTbl[ecnt][4] ;
		}
		ecnt++ ;
	}

}


