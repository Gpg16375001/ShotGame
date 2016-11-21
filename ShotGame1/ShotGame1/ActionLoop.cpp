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
	ActSmallPlayer ,						// 10
	ActSmallPlayer2 ,								// 11
	ActNull ,								// 12
	ActNull ,								// 13
	ActEnemy3 ,								// 14	ENEMY3 のアクション
	ActE3Shot ,								// 15	ENEMY3 弾 のアクション
	ActBoss ,								// 16	BOSS のアクション
	ActBossShot ,							// 17	BOSS 弾 のアクション
	ActEnemy4 ,								// 18	ENEMY4 のアクション
	ActE4Shot ,								// 19	ENEMY4 弾 のアクション
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
	ActEnemy10 ,							// 30	ENEMY10 のアクション
	ActE10Shot ,							// 31	ENEMY10 弾 のアクション
	ActEnemy11 ,							// 32	ENEMY11 のアクション
	ActE11Shot ,							// 33	ENEMY11 弾 のアクション
	ActEnemy12 ,							// 34	ENEMY12 のアクション
	ActE12Shot ,							// 35	ENEMY12 弾 のアクション
	ActEnemy13 ,							// 36	ENEMY13 のアクション
	ActE13Shot ,							// 37	ENEMY13 弾 のアクション
	ActEnemy14 ,							// 38	ENEMY14 のアクション
	ActE14Shot ,							// 39	ENEMY14 弾 のアクション
	ActEnemySet1 ,							// 40	ActEnemySet1
	ActEnemySet2 , 							// 41	ActEnemySet2
	ActEnemySet3 , 							// 42	ActEnemySet3
	ActEnemySet4 , 							// 43	ActEnemySet4
	ActEnemySet5 ,							// 44	ActEnemySet5
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


