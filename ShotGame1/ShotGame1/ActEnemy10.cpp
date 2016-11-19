/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													 ENEMY10 アクション													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"
#include "math.h"

/*______________________________________________________*/
/*					 ENEMY10 アクション					*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void ActEnemy10( void )
{
	int no ;
	int i ;
	static int num ;
	static double rol = 0.1 ;
	static int deblt ;

	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY10 初期セット
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

			pp->flg = 0 ;
			pp->yspd = 8.0 ;
			pp->time = 10 ;
			pp->color = 0 ;
			pp->cnt = 0 ;
			deblt = 0 ;
			break ;

		case 1 :
			pp->ypos += pp->yspd ;

			switch ( pp->flg )
			{
				// left
				case 0 :
					if ( pp->cnt != 0 )
					{
						// upに逃げる
						pp->yspd = -4.0 ;
					}
					else if ( pp->ypos >= 300 )
					{
						pp->pchg[1] = pp->flg ;
						pp->flg = 6 ;
					}
					break ;

				case 6 :
					pp->yspd = 0 ;
					if ( pp->time < 0 )
					{
						mciSendString( TEXT("play SE_ES1 from 0 notify") , NULL , 0 , hwnd ) ;	// 01
						pp->cnt += 1 ;
						for ( i = 120 ; i < 460 ; (i += 5) )
						{
							no = ObjSearch( O_ES , MAX_ES ) ;	// 空いている配列を見つける
							if ( no != -1 )						// 空いていたら
							{
								obj[no].idnum = ID_E10S ;		// その配列に弾を入れる
								obj[no].mode = 0 ;
								obj[no].color = pp->color ;
								obj[no].xpos = pp->xpos ;
								obj[no].ypos = pp->ypos ;
								obj[no].xspd = cos( 3.14 / 180 * (i + deblt) ) * 8.0 ;
								obj[no].yspd = sin( 3.14 / 180 * (i + deblt) ) * 8.0 ;

								pp->time = 2 ;

							}

							if ( pp->cnt > 90 )
							{
								pp->flg = pp->pchg[1] ;
							}

						}
						deblt += 4 ;
					}
					pp->time-- ;
					break ;

			}
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
			pscore += 100 ;
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
/*					  ENEMY10 弾 アクション				*/
/*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*/
void ActE10Shot( void )
{
	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY10 弾 初期セット
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
			break ;

		case 1 :
			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;
			break ;

	}
	BulletColor( ) ;											// 弾光る関数
	Fout( ) ;													//	画面外チェック

}



