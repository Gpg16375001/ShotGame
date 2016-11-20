/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*														 �G�Z�b�g ����													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"

int EneSet3[][8] = {
/*
	0: enemy count
	1: ID  2: Sporn.xpos  3: S.ypos  4: S.xspd  5: S.yspd  6: flg  7: color
*/
//	   0 |	   1	|   2  |  3	 |  4  |  5  | 6 | 7
	{  1 , ID_ENE11 ,  400 , -50 ,   0 ,  10 , 0 , 1 } ,			// ENEMY 8	�ΐF	������
	{  1 ,  ID_ENE8 ,  -50 , 200 ,  10 ,   0 , 0 , 1 } ,			// ENEMY 8	�ΐF	������
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// �Ȃ�
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// �Ȃ�
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// �Ȃ�
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// �Ȃ�
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// �Ȃ�
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// �Ȃ�
	{  1 ,  ID_ENE8 ,  -50 , 200 ,  10 ,   0 , 0 , 1 } ,			// ENEMY 8	�ΐF	������
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// �Ȃ�
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// �Ȃ�
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// �Ȃ�
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// �Ȃ�
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// �Ȃ�
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// �Ȃ�
	{  1 ,  ID_ENE8 ,  -50 , 200 ,  10 ,   0 , 0 , 1 } ,			// ENEMY 8	�ΐF	������
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// �Ȃ�
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// �Ȃ�
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// �Ȃ�
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// �Ȃ�
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// �Ȃ�
	{  1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// �Ȃ�
	{  1 ,  ID_ENE8 ,  -50 , 200 ,  10 ,   0 , 0 , 1 } ,			// ENEMY 8	�ΐF	������
	{ -1 ,		  0 , 	 0 ,   0 ,   0 ,   0 , 0 , 0 } ,			// �Z�b�g�I��
} ;

/*______________________________________________________*/
/*						 Enemy�Z�b�g2					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActEnemySet3( void )
{
	int no ;

	if ( EneSet3[ecount[2]][0] != -1 )
	{
		no = ObjSearch( O_ENE , MAX_ENE ) ;
		if ( no != -1 )
		{
			obj[no].idnum = EneSet3[ecount[2]][1] ;
			obj[no].mode = 0 ;
			obj[no].xpos = (double)EneSet3[ecount[2]][2] ;
			obj[no].ypos = (double)EneSet3[ecount[2]][3] ;
			obj[no].xspd = (double)EneSet3[ecount[2]][4] ;
			obj[no].yspd = (double)EneSet3[ecount[2]][5] ;
			obj[no].flg = EneSet3[ecount[2]][6] ;
			obj[no].color = EneSet3[ecount[2]][7] ;
		}
		ecount[2]++ ;
	}

}

