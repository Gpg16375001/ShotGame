/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													 ENEMY3 アクション													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"
#include "math.h"

/*______________________________________________________*/
/*					  ENEMY3 アクション					*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void ActEnemy3( void )
{
	int no ;
	int i ;
	static int num ;

	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY3 初期セット
			*/
			pp->xm = 400.0 ;
			pp->ym = 300.0 ;
			pp->xpos = 0.0 ;
			pp->ypos = 0.0 ;
			pp->xsize = 70 ;
			pp->ysize = 70 ;
			pp->xboff = 0 ;
			pp->yboff = 0 ;
			pp->xmoff = 0 ;
			pp->ymoff = 140 ;
			pp->xoff = -35 ;									// 中心点の変更 X軸
			pp->yoff = -35 ;									// 中心点の変更 Y軸
			pp->idx = 2 ;
			pp->mode = 2 ;										// mode1 に移る

			pp->cnt = 0 ;
			break ;

		case 1 :
			pp->cnt += 10 ;
			pp->xpos = cos( 3.14 / 180 * pp->cnt ) * 60.0 ;		// *半径
			pp->ypos = sin( 3.14 / 180 * pp->cnt ) * 60.0 ;

			pp->xpos += pp->xm ;
			pp->ypos += pp->ym ;
			break ;

		case 2 :
			pp->xpos = 400.0 ;
			pp->ypos = 300.0 ;
			if ( GetKeyState(VK_F1) < 0 )
			{
				for ( i = 0 ; i < 360 ; (i += 45) )
				{
					no = ObjSearch( O_ES , MAX_ES ) ;
					if ( no != -1 )
					{
						obj[no].idnum = ID_E3S ;
						obj[no].mode = 0 ;
						obj[no].xpos = pp->xpos ;
						obj[no].ypos = pp->ypos ;
						obj[no].xspd = cos( 3.14 / 180 * i ) * 8.0 ;
						obj[no].yspd = sin( 3.14 / 180 * i ) * 8.0 ;
					}
				}
			}
			break ;

		case 3 :
			pp->ym += 4.0 ;
			pp->cnt += 10 ;
			pp->xpos = cos( 3.14 / 180 * pp->cnt ) * 60.0 ;		// *半径
			pp->ypos = sin( 3.14 / 180 * pp->cnt ) * 60.0 ;

			pp->xpos += pp->xm ;
			pp->ypos += pp->ym ;
			break ;

		case 98 :
			no = ObjSearch( O_BOMB , MAX_BM ) ;					// 空いている配列を見つける
			if ( no != -1 )										// 空いていたら
			{
				num = no ;
				obj[no].idnum = ID_BOMB ;
				obj[no].mode = 0 ;
				obj[no].xpos = pp->xpos ;
				obj[no].ypos = pp->ypos ;
				pp->time = 6 ;
				pp->mode = 99 ;
			}
			break ;

		case 99 :
			pp->time-- ;
			obj[num].ypos = pp->ypos ;
			pp->ypos += 4.0 ;
			if ( pp->time < 0 )
			{
				pp->idnum = 0 ;
				pp->mode = 0 ;
			}
			break ;

	}
	Fout( ) ;					//	画面外チェック

}

/*______________________________________________________*/
/*					  ENEMY3 弾 アクション				*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void ActE3Shot( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY1 弾 初期セット
			*/
			pp->xsize = 16 ;
			pp->ysize = 16 ;
			pp->xboff = 0 ;
			pp->yboff = 32 ;
			pp->xmoff = 64 ;
			pp->ymoff = 0 ;
			pp->idx = 4 ;
			pp->mode = 1 ;
			pp->xoff = -8 ;										// 中心点の変更 X軸
			pp->yoff = -8 ;										// 中心点の変更 Y軸
			pp->cnt = 0 ;
			break ;

		case 1 :
			pp->cnt += 1 ;

			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;
			break ;

	}
	Fout( ) ;					//	画面外チェック

}



