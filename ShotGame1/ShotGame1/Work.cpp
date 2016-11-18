/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													  グローバル宣言													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"

/* ____ グローバル変数宣言 ____ */
DT		obj[MAXOBJ] ;
DT		*pp ;
HDC		hDCBack ;
HBITMAP	hBmpTbl[20] ;
BOOL	tmf = 0 ;
HWND	hwnd ;															// 1 = タイマー処理チェックフラグ
BOOL	psflg ;
int etim ;																// エネミーが出てくるときのカウント数
int ecnt ;
int pscore ;															// score
int plife ;																// player life
int ecount ;															// エネミーセットのエネミーの数


