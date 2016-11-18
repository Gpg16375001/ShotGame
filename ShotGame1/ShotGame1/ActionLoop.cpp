/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													 アクション ループ													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*				  オブジェクト アクション				*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
TBLJP ActJpTbl[ ] = {
	ActNull ,								//  0
	ActBg ,									//  1	背景のアクション
	ActNull ,								//  2
	ActNull ,								//  3
	ActPlayer ,								//  4	プレイヤーのアクション
	ActPshot ,								//  5	プレイヤーの弾のアクション
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
	ActEnemy5 ,								// 20	ENEMY5 のアクション
	ActE5Shot ,								// 21	ENEMY5 弾 のアクション
	ActEnemy6 ,								// 22	ENEMY6 のアクション
	ActE6Shot ,								// 23	ENEMY6 弾 のアクション
	ActEnemy7 ,								// 24	ENEMY7 のアクション
	ActE7Shot ,								// 25	ENEMY7 弾 のアクション
	ActEnemy8 ,								// 26	ENEMY8 のアクション
	ActE8Shot ,								// 27	ENEMY8 弾 のアクション
	ActEnemy9 ,								// 28	ENEMY9 のアクション
	ActE9Shot ,								// 29	ENEMY9 弾 のアクション
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
	ActBomb ,								// 59	爆発のモーション
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


