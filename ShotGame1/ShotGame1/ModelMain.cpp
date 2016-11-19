/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													ウィンドウ表示プログラム											*/
/*														11月 11日 (金)													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "resource.h"
#include "Def.h"
#include "Work.h"

/* ____ エントリポイント ____ */
int APIENTRY WinMain (
		HINSTANCE hInstance ,
		HINSTANCE hPrevInstance ,
		LPSTR lpCmdLine ,
		int nCmdShow )
{
	WNDCLASSEX wc ;													// ウィンドウクラス構造体
	HWND hWnd ;														// ウィンドウハンドル
	MSG msg ;														// メッセージ構造体
	RECT sPos ;														// ウィンドウの大きさ

	/* ____ ウィンドウクラス構造体の定義 ____ */
	wc.cbSize = sizeof( WNDCLASSEX ) ;
	wc.style = CS_HREDRAW | CS_VREDRAW ;
	wc.lpfnWndProc = ( WNDPROC ) WndProc ;
	wc.cbClsExtra = 0 ;
	wc.cbWndExtra = 0 ;
	wc.hInstance = hInstance ;
	wc.hIcon = LoadIcon( NULL , IDI_APPLICATION ) ;
	wc.hCursor = LoadCursor( NULL , IDC_ARROW ) ;
	wc.hbrBackground = ( HBRUSH )( COLOR_WINDOW + 1 ) ;
	wc.lpszMenuName = NULL ;
	wc.lpszClassName = TEXT("ModelApp") ;
	wc.hIconSm = LoadIcon( NULL , IDI_APPLICATION ) ;

	RegisterClassEx ( &wc ) ;										// ウィンドウクラス登録
	/*
		ウィンドウのちゃんとした
		サイズを作る
	*/
	SetRect( &sPos , 0 , 0 , WINDOW_W , WINDOW_H ) ;
	AdjustWindowRect( &sPos , WS_OVERLAPPEDWINDOW , FALSE ) ;

	hWnd = CreateWindow ( wc.lpszClassName ,						// ウィンドウクラス名
		TEXT("シューティングゲーム") ,								// キャプション文字列
		WS_OVERLAPPEDWINDOW ,										// ウィンドウスタイル
		200 ,														// 水平座標の位置
		0 ,															// 垂直座標の位置
		sPos.right - sPos.left ,									// 幅
		sPos.bottom - sPos.top ,									// 高さ
		NULL ,														// 親ウィンドウ
		NULL ,														// ウィンドウメニュー
		hInstance ,													// インスタンスハンドル
		NULL ) ;													// WM_CREATE情報

	hwnd = hWnd ;													// Window Handle をグローバル変数へ

//	if ( hWnd == NULL )
//		return FALSE ;

	/* ____ ウィンドウを表示 ____ */
	ShowWindow ( hWnd , nCmdShow ) ;
	UpdateWindow ( hWnd ) ;

	/* ____ メッセージチェックループ ____ */
	while ( GetMessage ( &msg , NULL , 0 , 0 ) )
	{
		TranslateMessage ( &msg ) ;
		DispatchMessage ( &msg ) ;
	}

	return msg.wParam ;
}

/*______________________________________________________________________________________________________________________*/
/*																														*/
/*											ウィンドウプロシージャ ( CALLBACK関数 )										*/
/*______________________________________________________________________________________________________________________*/

LRESULT CALLBACK WndProc (
		HWND hWnd ,
		UINT message ,
		WPARAM wParam ,
		LPARAM lParam )
{
	static HINSTANCE	hInst ;
	HBITMAP				hBitmap ;
	PAINTSTRUCT			ps ;
	HDC					hDC ;
	TCHAR				s[100] ;

	switch ( message )
	{
		case WM_CREATE :
			// インスタンスハンドルの取得
			hInst = (HINSTANCE)GetWindowLong( hWnd , GWL_HINSTANCE ) ;

			// テーブルにビットマップをロード
			hBmpTbl[0] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_BG) ) ;		// 背景
			hBmpTbl[1] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_PLAYER) ) ;	// プレイヤー
			hBmpTbl[2] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_ENEMY) ) ;		// 敵
			hBmpTbl[3] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_SHOT1) ) ;		// 弾1
			hBmpTbl[4] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_SHOT2) ) ;		// 弾2
			hBmpTbl[5] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_BOMB) ) ;		// 爆発
			hBmpTbl[6] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_BOSS) ) ;		// 弾1
			hBmpTbl[7] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_LIFE) ) ;		// 弾2
			hBmpTbl[8] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_SCORE) ) ;		// 爆発

			// 裏画面の生成
			hDC = GetDC( hWnd ) ;
			hDCBack = CreateCompatibleDC( hDC ) ;
			hBitmap = CreateCompatibleBitmap( hDC , WINDOW_W , WINDOW_H ) ;
			SelectObject( hDCBack , hBitmap ) ;
			DeleteObject( hBitmap ) ;
			ReleaseDC( hWnd , hDC ) ;

			// 初期化の呼び出し		
			InitSet( ) ;

			// Sound Set
			mciSendString( TEXT("close all") , NULL , 0 , hWnd ) ;	// 00
			mciSendString( TEXT("open sound/start.wav alias SE_ST type waveaudio") , NULL , 0 , hWnd ) ;	// Playerの弾
			mciSendString( TEXT("open sound/shot1.wav alias SE_PS type waveaudio") , NULL , 0 , hWnd ) ;	// Playerの弾
			mciSendString( TEXT("open sound/shot2.wav alias SE_ES1 type waveaudio") , NULL , 0 , hWnd ) ;	// ENEMY の弾
			mciSendString( TEXT("open sound/shot3.wav alias SE_ES2 type waveaudio") , NULL , 0 , hWnd ) ;	// ENEMY の弾
			mciSendString( TEXT("open sound/shot4.wav alias SE_ES3 type waveaudio") , NULL , 0 , hWnd ) ;	// ENEMY の弾
			mciSendString( TEXT("open sound/hitplayer.wav alias SE_PHIT type waveaudio") , NULL , 0 , hWnd ) ;// player hit
			mciSendString( TEXT("open sound/bomb1.wav alias SE_BOMB1 type waveaudio") , NULL , 0 , hWnd ) ;	// bomb1
			mciSendString( TEXT("open sound/bomb2.wav alias SE_BOMB2 type waveaudio") , NULL , 0 , hWnd ) ;	// bomb2
			mciSendString( TEXT("open sound/splayer.wav alias SE_SP type waveaudio") , NULL , 0 , hWnd ) ;	// PLAYER 発進
			mciSendString( TEXT("open sound/splayer2.wav alias SE_SP1 type waveaudio") , NULL , 0 , hWnd ) ;// PLAYER 発進
			mciSendString( TEXT("open sound/splayer3.wav alias SE_SP2 type waveaudio") , NULL , 0 , hWnd ) ;// PLAYER 発進
			mciSendString( TEXT("open sound/splayer4.wav alias SE_SP3 type waveaudio") , NULL , 0 , hWnd ) ;// PLAYER 発進

			SetTimer( hWnd , 1 , 50 , NULL ) ;
			break ;

		case WM_TIMER :
			if ( tmf == 0 )
			{
				tmf = 1 ;											// タイマー処理開始
				EnemySet( ) ;
				DispLoop( ) ;										// 描画のループ
				ActionLoop( ) ;										// 描画のアクション

				InvalidateRect( hWnd , NULL , FALSE ) ;
			}
			break ;

		case WM_PAINT :
			// 裏画面を画面に表示
			hDC = BeginPaint( hWnd , &ps ) ;
			BitBlt( hDC , 0 , 0 ,WINDOW_W ,WINDOW_H , hDCBack , 0 , 0 , SRCCOPY ) ;

			wsprintf( s , TEXT("time = %d") , etim ) ;
			TextOut( hDC , 0 , 0 , s , lstrlen(s) ) ;

			wsprintf( s , TEXT("[plyer]cnt = %d") , obj[O_PLY].cnt ) ;
			TextOut( hDC , 0 , 20 , s , lstrlen(s) ) ;

			EndPaint( hWnd , &ps ) ;
			tmf = 0 ;
			break ;

		/* ____ ウィンドウ破棄処理 ____ */
		case WM_DESTROY :
			KillTimer( hWnd , 1 ) ;
			DeleteDC( hDCBack ) ;									// 裏画面の削除

			/*
				オブジェクト削除
			*/
			DeleteObject( hBmpTbl[0] ) ;
			DeleteObject( hBmpTbl[1] ) ;
			DeleteObject( hBmpTbl[2] ) ;
			DeleteObject( hBmpTbl[3] ) ;
			DeleteObject( hBmpTbl[4] ) ;
			DeleteObject( hBmpTbl[5] ) ;
			DeleteObject( hBmpTbl[6] ) ;
			DeleteObject( hBmpTbl[7] ) ;
			DeleteObject( hBmpTbl[8] ) ;

			PostQuitMessage ( 0 ) ;
			break ;

		/* ____ デフォルト処理 ____ */
		default :
			return DefWindowProc ( hWnd , message , wParam , lParam ) ;
	}

	return 0 ;

}


