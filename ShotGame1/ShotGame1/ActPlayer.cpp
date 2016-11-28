/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													 プレイヤー アクション												*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"
#include "math.h"

/*______________________________________________________*/
/*					  PLAYER アクション					*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void ActPlayer( void )
{
	int no ;

	switch ( pp->mode )
	{
		case 0 :
			/*
				PLAYER 初期セット
			*/
			pp->xpos = 400.0 ;
			pp->ypos = WINDOW_H + 120 ;
			pp->xsize = 60 ;
			pp->ysize = 60 ;
			pp->xboff = 0 ;
			pp->yboff = 0 ;
			pp->xmoff = 0 ;
			pp->ymoff = 60 ;
			pp->xoff = -30 ;									// 中心点の変更 X軸
			pp->yoff = -40 ;									// 中心点の変更 Y軸
			pp->idx = 1 ;
			pp->mode = 1 ;

			pp->cnt = 0 ;
			pp->yspd = -4.0 ;
			mciSendString( TEXT("play SE_SP3 from 0 notify") , NULL , 0 , hwnd ) ;	// 01
			mciSendString( TEXT("play SE_ST from 0 notify") , NULL , 0 , hwnd ) ;	// 01
			break ;

		case 1 :
			pp->ypos += pp->yspd ;
			if ( pp->ypos < 550.0 )
			{
				pp->mode = 2 ;
			}
			break ;

		case 2 :
			pp->xspd = 0 ;
			pp->yspd = 0 ;

			if ( GetKeyState(VK_UP) < 0 )
			{
				if ( pp->cnt > 10 )
				{
					mciSendString( TEXT("play SE_SP2 from 0 notify") , NULL , 0 , hwnd ) ;	// 01
					pp->cnt = 0 ;
				}
				pp->yspd = -PSPD ;
			}
			if ( GetKeyState(VK_DOWN) < 0 )
			{
				if ( pp->cnt > 10 )
				{
					mciSendString( TEXT("play SE_SP2 from 0 notify") , NULL , 0 , hwnd ) ;	// 01
					pp->cnt = 0 ;
				}
				pp->yspd = PSPD ;
			}
			if ( GetKeyState(VK_LEFT) < 0 )
			{
				if ( pp->cnt > 10 )
				{
					mciSendString( TEXT("play SE_SP2 from 0 notify") , NULL , 0 , hwnd ) ;	// 01
					pp->cnt = 0 ;
				}
				pp->xspd = -PSPD ;
			}
			if ( GetKeyState(VK_RIGHT) < 0 )
			{
				if ( pp->cnt > 10 )
				{
					mciSendString( TEXT("play SE_SP2 from 0 notify") , NULL , 0 , hwnd ) ;	// 01
					pp->cnt = 0 ;
				}
				pp->xspd = PSPD ;
			}

			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;

			if ( (GetKeyState(VK_SPACE) < 0) && (psflg[0] == 0) )
			{
				no = ObjSearch( O_PS , MAX_PS ) ;				// 空いている配列を見つける
				if ( no != -1 )									// 空いていたら
				{
					mciSendString( TEXT("play SE_PS from 0 notify") , NULL , 0 , hwnd ) ;	// 01

					obj[no].xpos = pp->xpos ;
					obj[no].ypos = pp->ypos - 50 ;				// 初期描画の位置変更
					obj[no].idnum = ID_PS1 ;					// その配列に弾を入れる
					obj[no].mode = 0 ;
				}
				psflg[0] = 1 ;
			}

			if ( (GetKeyState(VK_SPACE) >= 0) && (psflg) )
			{
				psflg[0] = 0 ;
			}
			if ( pp->cnt < 11 )
			{
				pp->cnt++ ;
			}
			PlayerMove( ) ;
			break ;

	}
	PEscheck( ) ;
	ActReset( ) ;
}

/*______________________________________________________*/
/*					  弾1 アクション					*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void ActPshot( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				PLAYER 弾 初期セット
			*/
			pp->xsize = 7 ;
			pp->ysize = 30 ;
			pp->xboff = 0 ;
			pp->yboff = 0 ;
			pp->xmoff = 0 ;
			pp->ymoff = 30 ;
			pp->idx = 3 ;
			pp->mode = 1 ;
			pp->xoff = -4 ;										// 中心点の変更 X軸
			pp->yoff = -5 ;										// 中心点の変更 Y軸
			pp->yspd = -10.0 ;
			break ;

		case 1 :
			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;
			break ;

	}
	Fout( ) ;					//	画面外チェック

}

/*______________________________________________________*/
/*				 プレイヤーのアニメーション				*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void PlayerMove( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				PLAYER 初期セット
			*/
			pp->xboff = 60 ;
			pp->yboff = 0 ;
			pp->xmoff = 60 ;
			pp->ymoff = 60 ;

			pp->pchg[0] = 0 ;
			break ;

		case 1 :
		case 2 :
			if ( pp->pchg[0] < 3 )
			{
				pp->xboff = pp->pchg[0] * 60 ;
				pp->xmoff = pp->pchg[0] * 60 ;
			}
			pp->pchg[0]++ ;

			if ( pp->pchg[0] >= 3 )
			{
				pp->pchg[0] = 0 ;
			}
			break ;

	}
}

/*______________________________________________________*/
/*				  SMALL PLAYER アクション				*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void ActSmallPlayer( void )
{
	int no ;

	switch ( pp->mode )
	{
		case 0 :
			/*
				PLAYER 初期セット
			*/
			pp->xsize = 16 ;
			pp->ysize = 16 ;
			pp->xboff = 0 ;
			pp->yboff = 16 * 5 ;
			pp->xmoff = 64 ;
			pp->ymoff = 16 * 5 ;
			pp->xoff = -8 ;										// 中心点の変更 X軸
			pp->yoff = -8 ;										// 中心点の変更 Y軸
			pp->idx = 4 ;
			pp->mode = 1 ;

			pp->cnt = 0 ;
			pp->yspd = -4.0 ;
			break ;

		case 1 :
			pp->cnt += 10 ;
			pp->xm = obj[O_PLY].xpos ;
			pp->ym = obj[O_PLY].ypos ;
			pp->xpos = cos( 3.14 / 180 * pp->cnt ) * 60.0 ;		// *半径
			pp->ypos = sin( 3.14 / 180 * pp->cnt ) * 60.0 ;

			pp->xpos += pp->xm ;
			pp->ypos += pp->ym ;

			if ( (GetKeyState(VK_SPACE) < 0) && (psflg[1] == 0) )
			{
				no = ObjSearch( O_PS , MAX_PS ) ;				// 空いている配列を見つける
				if ( no != -1 )									// 空いていたら
				{
					obj[no].xpos = pp->xpos ;
					obj[no].ypos = pp->ypos ;					// 初期描画の位置変更
					obj[no].idnum = ID_PS1 ;					// その配列に弾を入れる
					obj[no].mode = 0 ;
				}
				psflg[1] = 1 ;
			}

			if ( (GetKeyState(VK_SPACE) >= 0) && (psflg[1]) )
			{
				psflg[1] = 0 ;
			}
			if ( pp->cnt < 11 )
			{
				pp->cnt++ ;
			}
			break ;

	}
	BulletColor( ) ;											// 弾光る関数

}

/*______________________________________________________*/
/*				  SMALL PLAYER2 アクション				*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void ActSmallPlayer2( void )
{
	int no ;

	switch ( pp->mode )
	{
		case 0 :
			/*
				PLAYER 初期セット
			*/
			pp->xsize = 16 ;
			pp->ysize = 16 ;
			pp->xboff = 0 ;
			pp->yboff = 16 * 5 ;
			pp->xmoff = 64 ;
			pp->ymoff = 16 * 5 ;
			pp->xoff = -8 ;										// 中心点の変更 X軸
			pp->yoff = -8 ;										// 中心点の変更 Y軸
			pp->idx = 4 ;
			pp->mode = 1 ;

			pp->cnt = 0 ;
			pp->yspd = -4.0 ;
			break ;

		case 1 :
			pp->cnt -= 10 ;
			pp->xm = obj[O_PLY].xpos ;
			pp->ym = obj[O_PLY].ypos ;
			pp->xpos = cos( 3.14 / 180 * pp->cnt ) * 40.0 ;		// *半径
			pp->ypos = sin( 3.14 / 180 * pp->cnt ) * 40.0 ;

			pp->xpos += pp->xm ;
			pp->ypos += pp->ym ;

			if ( (GetKeyState(VK_SPACE) < 0) && (psflg[2] == 0) )
			{
				no = ObjSearch( O_PS , MAX_PS ) ;				// 空いている配列を見つける
				if ( no != -1 )									// 空いていたら
				{
					obj[no].xpos = pp->xpos ;
					obj[no].ypos = pp->ypos ;					// 初期描画の位置変更
					obj[no].idnum = ID_PS1 ;					// その配列に弾を入れる
					obj[no].mode = 0 ;
				}
				psflg[2] = 1 ;
			}

			if ( (GetKeyState(VK_SPACE) >= 0) && (psflg[2]) )
			{
				psflg[2] = 0 ;
			}
			if ( pp->cnt < 11 )
			{
				pp->cnt++ ;
			}
			break ;

	}
	BulletColor( ) ;											// 弾光る関数

}



