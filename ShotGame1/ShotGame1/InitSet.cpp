/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*														 初期セット														*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*						  初期セット					*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void InitSet( void )
{
	obj[O_BG].idnum = ID_BG ;									// 背景 を呼ぶ
	obj[O_BG].mode = 0 ;										// 初期セットを呼び出す

	obj[O_PLY].idnum = ID_PLY ;									// PLAYER を呼ぶ
	obj[O_PLY].mode = 0 ;										// 初期セットを呼び出す

	obj[O_SCORE+0].idnum = ID_STEXT ;							// PLAYER を呼ぶ
	obj[O_SCORE+0].mode = 0 ;									// 初期セットを呼び出す

	obj[O_SCORE+1].idnum = ID_SCORE ;							// PLAYER を呼ぶ
	obj[O_SCORE+1].mode = 0 ;									// 初期セットを呼び出す
	obj[O_SCORE+1].cnt = 0 ;									// 初期セットを呼び出す

	obj[O_SCORE+2].idnum = ID_SCORE ;							// PLAYER を呼ぶ
	obj[O_SCORE+2].mode = 0 ;									// 初期セットを呼び出す
	obj[O_SCORE+2].cnt = 1 ;									// 初期セットを呼び出す

	obj[O_SCORE+3].idnum = ID_SCORE ;							// PLAYER を呼ぶ
	obj[O_SCORE+3].mode = 0 ;									// 初期セットを呼び出す
	obj[O_SCORE+3].cnt = 2 ;									// 初期セットを呼び出す

	obj[O_SCORE+4].idnum = ID_SCORE ;							// PLAYER を呼ぶ
	obj[O_SCORE+4].mode = 0 ;									// 初期セットを呼び出す
	obj[O_SCORE+4].cnt = 3 ;									// 初期セットを呼び出す

	obj[O_SCORE+5].idnum = ID_SCORE ;							// PLAYER を呼ぶ
	obj[O_SCORE+5].mode = 0 ;									// 初期セットを呼び出す
	obj[O_SCORE+5].cnt = 4 ;									// 初期セットを呼び出す

	obj[O_LIFE+0].idnum = ID_LBASE ;									// PLAYER を呼ぶ
	obj[O_LIFE+0].mode = 0 ;										// 初期セットを呼び出す

	obj[O_LIFE+1].idnum = ID_LIFE ;									// PLAYER を呼ぶ
	obj[O_LIFE+1].mode = 0 ;										// 初期セットを呼び出す

	etim = 0 ;
	ecnt = 0 ;

	psflg = 0 ;													// 弾制限のフラグ
	pscore = 0 ;
	plife = 300 ;
}



