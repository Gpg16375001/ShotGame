/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*														 その他関数														*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*				  空きオブジェクト サーチ				*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
int ObjSearch( int st , int tm )
{
	int no = -1 ;												// 初期セット

	for (  ; st < (st+tm) ; st++ )								// 指定値までカウント
	{
		if ( obj[st].idnum == 0 )								// 描画されてない idnum
		{
			no = st ;											// no に その配列 を入れる
			break ;												// 終了する
		}
	}

	return no ;													// no を返す

}

/*______________________________________________________*/
/*			何もしない関数 テーブルジャンプ用			*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void ActNull( void )
{
}

/*______________________________________________________*/
/*					   画面外チェック					*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
BOOL Fout( void )
{
	BOOL iRet = 0 ;

	if ( (pp->xpos < -100) || (pp->xpos > (WINDOW_W+100.0))
		|| (pp->ypos < -100) || (pp->ypos > (WINDOW_H+100.0)) )
	{
		pp->idnum = 0 ;
		pp->mode = 0 ;
		pp->cnt ;
		iRet = 1 ;
	}

	return iRet ;

}


