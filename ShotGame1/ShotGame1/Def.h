/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*														 DEFINE 宣言													*/
/*														 構造体宣言														*/
/*													  プロトタイプ宣言													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ DEFINE ____ */
#define WINDOW_W	800					// ウィンドウの横幅
#define WINDOW_H	700					// ウィンドウの縦幅
#define MAXOBJ		5000				// 最大描画数

#define ID_BG		1					// 背景のID
#define ID_PLY		4					// プレイヤーのID
#define ID_PS1		5					// プレイやショット1のID
#define ID_STEXT	6
#define ID_SCORE	7
#define ID_LBASE	8
#define ID_LIFE		9

#define O_BG		1
#define O_PS		10					// 10 - 89 (80)
#define O_PLY		100					// 100 - 109
#define O_ES		200					// 200 - 4799
#define O_ENE		4800				// 4800 - 1849
#define O_BOMB		4850				// 1850 - 1899

#define O_SCORE		4900
#define O_LIFE		4910
#define O_LBASE		4911

#define MAX_PS		80					// 80		プレイヤーの弾描画の最大数
#define MAX_ES		4600				// 4600		エネミーの弾描画の最大数
#define MAX_ENE		50					// 50		エネミー描画の最大数
#define MAX_BM		50					// 50		爆発描画の最大数

#define PSPD		8.0					// プレイヤーのスピード
#define PI			3.1415926535		// 円周率

// ----- 使わない -----
#define ID_ENE1		10
#define ID_E1S		11
#define ID_ENE2		12
#define ID_E2S		13
// --------------------

#define ID_BOSS		16
#define ID_BSHOT	17

#define ID_ENE3		14
#define ID_E3S		15
#define ID_ENE4		18
#define ID_E4S		19
#define ID_ENE5		20
#define ID_E5S		21
#define ID_ENE6		22
#define ID_E6S		23
#define ID_ENE7		24
#define ID_E7S		25
#define ID_ENE8		26
#define ID_E8S		27
#define ID_ENE9		28
#define ID_E9S		29
#define ID_ENE10	30
#define ID_E10S		31
#define ID_ENE11	32
#define ID_E11S		33
#define ID_ENE12	34
#define ID_E12S		35
#define ID_ENE13	36
#define ID_E13S		37
#define ID_ENE14	38
#define ID_E14S		39

#define ID_ESET1	40
#define ID_ESET2	41
#define ID_ESET3	42
#define ID_ESET4	43
#define ID_ESET5	44

#define ID_BOMB		59

/* ____ 構造体 ____ */
typedef struct {
	int idnum ;							// 配列位置 ( 番号 )
	int mode ;							// モード , 状態	0 = 初期化
	double xpos ;						// X軸 の座標
	double ypos ;						// Y軸 の座標
	int xsize ;							// 横幅
	int ysize ;							// 縦幅
	int xboff ;							// ベースの絵の X軸 の座標
	int yboff ;							// ベースの絵の Y軸 の座標
	int xmoff ;							// マスクの絵の X軸 の座標
	int ymoff ;							// マスクの絵の Y軸 の座標
	int idx ;							// 何の絵か
	int xoff ;							// 中心点の変更
	int yoff ;							// 
	double xspd ;						// X軸 のスピード
	double yspd ;						// Y軸 のスピード
	double xm ;							// 仮想の X軸
	double ym ;							// 仮想の Y軸
	double pch[2] ;						// 好きなものに使える
	int pchg[2] ;						// 好きなものに使える
	int time ;							// タイムカウント	敵の行動変更など
	int cnt ;							// カウント
	int flg ;							// フラグ			敵の状態変更など
	BYTE color ;
} DT ;

/* ____ テーブルジャンプ ____ */
typedef void ( *TBLJP )( void ) ;

/* ____ プロトタイプ宣言 ____ */
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
void ActEnemy7( void ) ;							// ENEMY7 のアクション
void ActE7Shot( void ) ;							// ENEMY8 弾 のアクション
void ActEnemy8( void ) ;
void ActE8Shot( void ) ;
void ActEnemySet1( void ) ;
void ActEnemy9( void ) ;
void ActE9Shot( void ) ;
void ActEnemy10( void ) ;
void ActE10Shot( void ) ;
void PlayerMove( void ) ;
void ActEnemySet2( void ) ;
void ActEnemySet3( void ) ;
void ActEnemy11( void ) ;
void ActE11Shot( void ) ;
void ActEnemy12( void ) ;
void ActE12Shot( void ) ;
void ActEnemySet4( void ) ;
void ActEnemySet5( void ) ;
void ActEnemy13( void ) ;
void ActE13Shot( void ) ;
void ActEnemy14( void ) ;
void ActE14Shot( void ) ;
void ActE4Shot( void ) ;
void ActBossShot( void ) ;



