/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													 ENEMY2 �A�N�V����													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "Def.h"
#include "Work.h"


/*______________________________________________________*/
/*					  ENEMY2 �A�N�V����					*/
/*�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P*/
void ActEnemy2( void )
{
	int no ;

	switch ( pp->mode )
	{
		case 0 :
			/*
				ENEMY2 �����Z�b�g
			*/
			pp->xsize = 70 ;
			pp->ysize = 70 ;
			pp->xboff = 140 ;
			pp->yboff = 70 ;
			pp->xmoff = 140 ;
			pp->ymoff = 210 ;
			pp->xoff = -35 ;									// ���S�_�̕ύX X��
			pp->yoff = -35 ;									// ���S�_�̕ύX Y��
			pp->idx = 2 ;
			pp->mode = 1 ;										// mode1 �Ɉڂ�

			pp->yspd = 4.0 ;
			break ;

		case 1 :
			pp->ypos += pp->yspd ;

			if ( pp->ypos >= 200.0 )
			{
				pp->mode = 2 ;
				pp->yspd = 4.0 ;
				if ( (rand( ) % 2) != 1 )
				{
					pp->xspd = 4.0 ;
				}
				else
				{
					pp->xspd = -4.0 ;
				}
			}
			break ;

		case 2 :
			pp->xpos += pp->xspd ;
			pp->ypos += pp->yspd ;
			break ;

	}
	Fout( ) ;					//	��ʊO�`�F�b�N

}


