/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													ENEMY14 アクション													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"
#include "math.h"

/*______________________________________________________*/
/*					 ENEMY14 アクション					*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void ActEnemy14( void )
{
	int no ;
	static int num ;
	static int dere[2] ;
	int i ;

	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY14 初期セット
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
			pp->time = 4 ;
			break ;

		case 1 :
			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;

			if ( pp-> ypos >= 70 )
			{
				pp->mode = 2 ;
			}
			break ;

		case 2 :
			if ( pp->time < 0 )
			{
				mciSendString( TEXT("play SE_ES2 from 0 notify") , NULL , 0 , hwnd ) ;	// 01
				pp->cnt += 1 ;

				/*
					星型
				*/
				for ( i = 55 ; i < 415 ; (i += 72) )
				{
					no = ObjSearch( O_ES , MAX_ES ) ;			// 空いている配列を見つける
					if ( no != -1 )								// 空いていたら
					{
						obj[no].idnum = ID_E14S ;				// その配列に弾を入れる
						obj[no].mode = 0 ;
						obj[no].color = 2 ;
						obj[no].xpos = pp->xpos ;
						obj[no].ypos = pp->ypos ;
						obj[no].xspd = cos( 3.14 / 180 * i ) * 3.0 ;
						obj[no].yspd = sin( 3.14 / 180 * i ) * 3.0 ;

						pp->time = 10 ;
					}

					no = ObjSearch( O_ES , MAX_ES ) ;			// 空いている配列を見つける
					if ( no != -1 )								// 空いていたら
					{
						obj[no].idnum = ID_E14S ;				// その配列に弾を入れる
						obj[no].mode = 0 ;
						obj[no].color = 2 ;
						obj[no].xpos = pp->xpos ;
						obj[no].ypos = pp->ypos ;
						obj[no].xspd = cos( 3.14 / 180 * (i + 60) ) * 2.2 ;
						obj[no].yspd = sin( 3.14 / 180 * (i + 60) ) * 2.2 ;

						pp->time = 10 ;
					}

					no = ObjSearch( O_ES , MAX_ES ) ;			// 空いている配列を見つける
					if ( no != -1 )								// 空いていたら
					{
						obj[no].idnum = ID_E14S ;				// その配列に弾を入れる
						obj[no].mode = 0 ;
						obj[no].color = 2 ;
						obj[no].xpos = pp->xpos ;
						obj[no].ypos = pp->ypos ;
						obj[no].xspd = cos( 3.14 / 180 * (i - 60) ) * 2.2 ;
						obj[no].yspd = sin( 3.14 / 180 * (i - 60) ) * 2.2 ;

						pp->time = 10 ;
					}

					no = ObjSearch( O_ES , MAX_ES ) ;			// 空いている配列を見つける
					if ( no != -1 )								// 空いていたら
					{
						obj[no].idnum = ID_E14S ;				// その配列に弾を入れる
						obj[no].mode = 0 ;
						obj[no].color = 2 ;
						obj[no].xpos = pp->xpos ;
						obj[no].ypos = pp->ypos ;
						obj[no].xspd = cos( 3.14 / 180 * (i + 120) ) * 1.5 ;
						obj[no].yspd = sin( 3.14 / 180 * (i + 120) ) * 1.5 ;

						pp->time = 10 ;
					}

					no = ObjSearch( O_ES , MAX_ES ) ;			// 空いている配列を見つける
					if ( no != -1 )								// 空いていたら
					{
						obj[no].idnum = ID_E14S ;				// その配列に弾を入れる
						obj[no].mode = 0 ;
						obj[no].color = 2 ;
						obj[no].xpos = pp->xpos ;
						obj[no].ypos = pp->ypos ;
						obj[no].xspd = cos( 3.14 / 180 * (i - 120) ) * 1.5 ;
						obj[no].yspd = sin( 3.14 / 180 * (i - 120) ) * 1.5 ;

						pp->time = 10 ;
					}

					if ( pp->cnt > 150 )
					{
						pp->mode = 3 ;
					}
				}
			}
			pp->time-- ;
			break ;

		case 3 :
			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;
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
	Enemy1Roll( ) ;
	EPscheck( ) ;
	EPcheck( ) ;
	Fout( ) ;													//	画面外チェック

}

/*______________________________________________________*/
/*					 ENEMY14 弾 アクション				*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void ActE14Shot( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY14 弾 初期セット
			*/
			pp->xsize = 16 ;
			pp->ysize = 16 ;
			pp->xboff = 0 ;
			pp->yboff = 16 * pp->color ;
			pp->xmoff = 64 ;
			pp->ymoff = 0 ;
			pp->idx = 4 ;
			pp->mode = 1 ;
			pp->xoff = -8 ;										// 中心点の変更 X軸
			pp->yoff = -8 ;										// 中心点の変更 Y軸
			pp->cnt = 0 ;
			break ;

		case 1 :
			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;

			if ( pp->cnt > 20 )
			{
				pp->mode = 0 ;
				pp->idnum = 0 ;
			}
			pp->cnt++ ;
			break ;

	}
	BulletColor( ) ;											// 弾光る関数
	Fout( ) ;													//	画面外チェック

}



