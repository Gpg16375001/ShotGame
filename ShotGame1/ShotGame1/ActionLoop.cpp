/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													 �A�N�V���� ���[�v													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*				  �I�u�W�F�N�g �A�N�V����				*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
TBLJP ActJpTbl[ ] = {
	ActNull ,								//  0
	ActBg ,									//  1	�w�i�̃A�N�V����
	ActNull ,								//  2
	ActNull ,								//  3
	ActPlayer ,								//  4	�v���C���[�̃A�N�V����
	ActPshot ,								//  5	�v���C���[�̒e�̃A�N�V����
	ActStext ,								//  6
	ActScore ,								//  7
	ActLbase ,								//  8
	ActLife ,								//  9
	ActNull ,								// 10
	ActNull ,								// 11
	ActNull ,								// 12
	ActNull ,								// 13
	ActNull ,								// 14
	ActNull ,								// 15
	ActBoss ,								// 16
	ActNull ,								// 17
	ActNull ,								// 18
	ActNull ,								// 19
	ActEnemy5 ,								// 20	ENEMY5 �̃A�N�V����
	ActE5Shot ,								// 21	ENEMY5 �e �̃A�N�V����
	ActEnemy6 ,								// 22	ENEMY6 �̃A�N�V����
	ActE6Shot ,								// 23	ENEMY6 �e �̃A�N�V����
	ActEnemy7 ,								// 24	ENEMY7 �̃A�N�V����
	ActE7Shot ,								// 25	ENEMY7 �e �̃A�N�V����
	ActEnemy8 ,								// 26	ENEMY8 �̃A�N�V����
	ActE8Shot ,								// 27	ENEMY8 �e �̃A�N�V����
	ActEnemy9 ,								// 28	ENEMY9 �̃A�N�V����
	ActE9Shot ,								// 29	ENEMY9 �e �̃A�N�V����
	ActNull	,								// 30
	ActNull , 								// 31
	ActNull , 								// 32
	ActNull , 								// 33
	ActNull ,								// 34
	ActNull ,								// 35
	ActNull ,								// 36
	ActNull ,								// 37
	ActNull ,								// 38
	ActNull ,								// 39
	ActEnemySet1 ,							// 40	ActEnemySet1
	ActNull , 								// 41
	ActNull , 								// 42
	ActNull , 								// 43
	ActNull ,								// 44
	ActNull ,								// 45
	ActNull ,								// 46
	ActNull ,								// 47
	ActNull ,								// 48
	ActNull ,								// 49
	ActNull	,								// 50
	ActNull , 								// 51
	ActNull , 								// 52
	ActNull , 								// 53
	ActNull ,								// 54
	ActNull ,								// 55
	ActNull ,								// 56
	ActNull ,								// 57
	ActNull ,								// 58
	ActBomb ,								// 59	�����̃��[�V����
	ActNull	,								// 60
} ;

void ActionLoop( void )
{
	int i ;

	for ( i = 0 ; i < MAXOBJ ; i++ )
	{
		pp = &obj[i] ;
		if ( pp->idnum != 0 )
		{
			ActJpTbl[pp->idnum]( ) ;
		}
	}
}


