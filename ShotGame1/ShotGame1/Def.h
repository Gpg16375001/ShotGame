/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*														 DEFINE �錾													*/
/*														 �\���̐錾														*/
/*													  �v���g�^�C�v�錾													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ DEFINE ____ */
#define WINDOW_W	800					// �E�B���h�E�̉���
#define WINDOW_H	700					// �E�B���h�E�̏c��
#define MAXOBJ		2000				// �ő�`�搔

#define ID_BG		1					// �w�i��ID
#define ID_PLY		4					// �v���C���[��ID
#define ID_PS1		5					// �v���C��V���b�g1��ID
#define ID_STEXT	6
#define ID_SCORE	7
#define ID_LBASE	8
#define ID_LIFE		9

#define O_BG		1
#define O_PS		10					// 10 - 89 (80)
#define O_PLY		100					// 100 - 109
#define O_ES		200					// 200 - 1799
#define O_ENE		1800				// 1800 - 1849
#define O_BOMB		1850				// 1850 - 1899

#define O_SCORE		1900
#define O_LIFE		1910
#define O_LBASE		1911

#define MAX_PS		80					// 80		�v���C���[�̒e�`��̍ő吔
#define MAX_ES		1600				// 1600		�G�l�~�[�̒e�`��̍ő吔
#define MAX_ENE		50					// 50		�G�l�~�[�`��̍ő吔
#define MAX_BM		50					// 50		�����`��̍ő吔

#define PSPD		8.0					// �v���C���[�̃X�s�[�h
#define PI			3.1415926535		// �~����

// ----- �g��Ȃ� -----
#define ID_ENE1		10
#define ID_E1S		11
#define ID_ENE2		12
#define ID_E2S		13
#define ID_ENE3		17
#define ID_E3S		18
#define ID_ENE4		19
// --------------------

#define ID_BOSS		16

#define ID_ENE5		20
#define ID_E5S		21
#define ID_ENE6		22
#define ID_E6S		23
#define ID_ENE7		24
#define ID_E7S		25
#define ID_ENE8		26
#define ID_E8S		27

#define ID_ESET1	40
#define ID_ESET2	41
#define ID_ESET3	42
#define ID_ESET4	43

#define ID_BOMB		59

/* ____ �}�N�� ____ */
#define MNAME(  )		(  )

/* ____ �\���� ____ */
typedef struct {
	int idnum ;							// �z��ʒu ( �ԍ� )
	int mode ;							// ���[�h , ���	0 = ������
	double xpos ;						// X���̍��W
	double ypos ;						// Y���̍��W
	int xsize ;							// ����
	int ysize ;							// �c��
	int xboff ;							// �x�[�X�̊G��X���̍��W
	int yboff ;							// �x�[�X�̊G��Y���̍��W
	int xmoff ;							// �}�X�N�̊G��X���̍��W
	int ymoff ;							// �}�X�N�̊G��Y���̍��W
	int idx ;							// ���̊G��
	int xoff ;							// ���S�_�̕ύX
	int yoff ;
	double xspd ;
	double yspd ;
	double xm ;		
	double ym ;
	int pchg[2] ;
	int time ;
	int cnt ;
	int flg ;
	BYTE color ;
} DT ;

/* ____ �e�[�u���W�����v ____ */
typedef void ( *TBLJP )( void ) ;

/* ____ �v���g�^�C�v�錾 ____ */
LRESULT CALLBACK WndProc ( HWND , UINT , WPARAM , LPARAM ) ;
void InitSet( void ) ;
void DispLoop( void ) ;
void ActionLoop( void ) ;
void ActBg( void ) ;
void ActPlayer( void ) ;
void ActPshot( void ) ;
int ObjSearch( int , int ) ;
void ActEnemy1( void ) ;
void ActE1Shot( void ) ;
void ActEnemy2( void ) ;
void ActBomb( void ) ;
void ActNull( void ) ;
void ActEnemy3( void ) ;
void ActE3Shot( void ) ;
BOOL Fout( void ) ;
void EnemySet( void ) ;
void ActEnemy4( void ) ;
int EPcheck( void ) ;
int EPscheck( void ) ;
int PEscheck( void ) ;
void ActEnemy5( void ) ;
void ActE5Shot( void ) ;
void ActEnemy6( void ) ;
void ActE6Shot( void ) ;
void ActStext( void ) ;								//  6
void ActScore( void ) ;								//  7
void ActLbase( void ) ;								//  8
void ActLife( void ) ;								//  9
void ActBoss( void ) ;
void BulletColor( void ) ;
void Enemy1Roll( void ) ;
void ActEnemy7( void ) ;							// ENEMY7 �̃A�N�V����
void ActE7Shot( void ) ;							// ENEMY8 �e �̃A�N�V����
void ActEnemy8( void ) ;
void ActE8Shot( void ) ;
void ActEnemySet1( void ) ;


