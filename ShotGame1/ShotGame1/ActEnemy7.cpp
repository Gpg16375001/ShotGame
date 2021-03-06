/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													 ENEMY7 アクション													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"
#include "math.h"

/*______________________________________________________*/
/*					  ENEMY7 アクション					*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void ActEnemy7( void )
{
	int no ;
	static int num ;
	int i ;

	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY7 初期セット
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
			pp->time = 10 ;
			pp->flg = 2 ;
			break ;

		case 1 :
			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;

			if ( pp->time < 0 )
			{
				for ( i = 0 ; i < 360 ; (i += 4) )
				{
					no = ObjSearch( O_ES , MAX_ES ) ;			// 空いている配列を見つける
					if ( no != -1 )								// 空いていたら
					{
						obj[no].idnum = ID_E7S ;				// その配列に弾を入れる
						obj[no].mode = 0 ;
						obj[no].xpos = pp->xpos ;
						obj[no].ypos = pp->ypos ;
						switch ( pp->flg )
						{
							case  0 :
								obj[no].xspd = cos( 3.14 / 180 * i ) * 1.0 ;
								obj[no].yspd = sin( 3.14 / 180 * i ) * 4.0 ;
								break ;

							case  1 :
								obj[no].xspd = cos( 3.14 / 180 * i ) * 4.0 ;
								obj[no].yspd = sin( 3.14 / 180 * i ) * 1.0 ;
								break ;

						}
						pp->flg++ ;
						pp->time = 60 ;
						if ( pp->flg > 2 )
						{
							pp->flg = 0 ;
						}
					}
				}
			}
			pp->time-- ;
			Enemy1Roll( ) ;
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
	EPscheck( ) ;
	EPcheck( ) ;
	Fout( ) ;													//	画面外チェック

}

/*______________________________________________________*/
/*					  ENEMY7 弾 アクション				*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void ActE7Shot( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY7 弾 初期セット
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
			break ;

		case 1 :
			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;
			break ;

	}
	BulletColor( ) ;											// 弾光る関数
	Fout( ) ;													//	画面外チェック

}



