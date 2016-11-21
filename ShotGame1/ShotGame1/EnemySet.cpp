/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*														 ìGÉZÉbÉg èàóù													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"

int EneTbl[][5] = {
	{    1 ,  ID_SPLY ,   0 ,    0 , 0 } ,					// Small Player	îzíu
	{    2 , ID_SPLY2 ,   0 ,    0 , 0 } ,					// Small Player	îzíu
	{    6 ,  ID_BOMB , 180 ,  600 , 0 } ,					// SET 1	îzíu
	{    7 ,  ID_BOMB , 330 ,  500 , 0 } ,					// SET 1	îzíu
	{    8 ,  ID_BOMB , 500 ,  650 , 0 } ,					// SET 1	îzíu
	{    9 ,  ID_BOMB , 650 ,  580 , 0 } ,					// SET 1	îzíu
	{   10 , ID_ESET1 ,   0 ,    0 , 0 } ,					// SET 1	îzíu
	{  150 , ID_ENE10 , 400 ,  -50 , 0 } ,					// ENEMY 10	îzíu
	{  450 , ID_ESET2 ,   0 ,    0 , 0 } ,					// SET 2	îzíu
	{  600 , ID_ESET3 ,   0 ,    0 , 0 } ,					// SET 3	îzíu
	{  650 , ID_ESET4 ,   0 ,    0 , 0 } ,					// SET 4	îzíu
	{  930 , ID_ESET5 ,   0 ,    0 , 0 } ,					// SET 5	îzíu
	{ 1200 ,  ID_BOSS , 400 , -150 , 0 } ,					// BOOS		îzíu
	{   -1 ,	    0 ,   0 ,	 0 , 0 } ,
} ;

/*______________________________________________________*/
/*						  EnemyÉZÉbÉg					*/
/*ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP*/
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


