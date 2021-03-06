/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													 ENEMY1 アクション													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"

/*______________________________________________________*/
/*					  ENEMY1 アクション					*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void ActEnemy1( void )
{
	int no ;
	static int num ;

	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY1 初期セット
			*/
			pp->xsize = 70 ;
			pp->ysize = 70 ;
			pp->xboff = 0 ;
			pp->yboff = 0 ;
			pp->xmoff = 0 ;
			pp->ymoff = 140 ;
			pp->xoff = -35 ;									// 中心点の変更 X軸
			pp->yoff = -35 ;									// 中心点の変更 Y軸
			pp->idx = 2 ;
			pp->mode = 1 ;										// mode1 に移る

			pp->yspd = 4.0 ;
			break ;

		case 1 :
			pp->ypos += (int)pp->yspd ;

			if ( pp->ypos >= 100.0 )
			{
				pp->mode = 2 ;
				pp->yspd = 0.0 ;
				pp->xspd = 4.0 ;
			}
			break ;

		case 2 :
			if ( GetKeyState(VK_UP) < 0 )
			{
				pp->mode = 98 ;
			}

			pp->xpos += pp->xspd ;

			if ( (pp->xpos < 35 ) || (pp->xpos > (WINDOW_W - 35)) )
			{
				pp->xspd *= -1 ;
			}

			if ( pp->time < 0 )
			{
				no = ObjSearch( O_ES , MAX_ES ) ;				// 空いている配列を見つける
				if ( no != -1 )									// 空いていたら
				{
					obj[no].idnum = ID_E1S ;					// その配列に弾を入れる
					obj[no].mode = 0 ;
					obj[no].xpos = pp->xpos ;
					obj[no].ypos = pp->ypos ;
					pp->time = 30 ;
				}
			}
			pp->time-- ;
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
			pp->ypos += 4 ;
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
/*					  ENEMY1 弾 アクション				*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void ActE1Shot( void )
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

			pp->yspd = 10.0 ;
			break ;

		case 1 :
			pp->ypos += pp->yspd ;
			break ;

	}
	Fout( ) ;					//	画面外チェック

}



