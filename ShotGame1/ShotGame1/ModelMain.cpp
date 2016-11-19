/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*																														*/
/*													�E�B���h�E�\���v���O����											*/
/*														11�� 11�� (��)													*/
/*																														*/
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

/* ____ INCLUDE ____ */
#include <windows.h>
#include "resource.h"
#include "Def.h"
#include "Work.h"

/* ____ �G���g���|�C���g ____ */
int APIENTRY WinMain (
		HINSTANCE hInstance ,
		HINSTANCE hPrevInstance ,
		LPSTR lpCmdLine ,
		int nCmdShow )
{
	WNDCLASSEX wc ;													// �E�B���h�E�N���X�\����
	HWND hWnd ;														// �E�B���h�E�n���h��
	MSG msg ;														// ���b�Z�[�W�\����
	RECT sPos ;														// �E�B���h�E�̑傫��

	/* ____ �E�B���h�E�N���X�\���̂̒�` ____ */
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

	RegisterClassEx ( &wc ) ;										// �E�B���h�E�N���X�o�^
	/*
		�E�B���h�E�̂����Ƃ���
		�T�C�Y�����
	*/
	SetRect( &sPos , 0 , 0 , WINDOW_W , WINDOW_H ) ;
	AdjustWindowRect( &sPos , WS_OVERLAPPEDWINDOW , FALSE ) ;

	hWnd = CreateWindow ( wc.lpszClassName ,						// �E�B���h�E�N���X��
		TEXT("�V���[�e�B���O�Q�[��") ,								// �L���v�V����������
		WS_OVERLAPPEDWINDOW ,										// �E�B���h�E�X�^�C��
		200 ,														// �������W�̈ʒu
		0 ,															// �������W�̈ʒu
		sPos.right - sPos.left ,									// ��
		sPos.bottom - sPos.top ,									// ����
		NULL ,														// �e�E�B���h�E
		NULL ,														// �E�B���h�E���j���[
		hInstance ,													// �C���X�^���X�n���h��
		NULL ) ;													// WM_CREATE���

	hwnd = hWnd ;													// Window Handle ���O���[�o���ϐ���

//	if ( hWnd == NULL )
//		return FALSE ;

	/* ____ �E�B���h�E��\�� ____ */
	ShowWindow ( hWnd , nCmdShow ) ;
	UpdateWindow ( hWnd ) ;

	/* ____ ���b�Z�[�W�`�F�b�N���[�v ____ */
	while ( GetMessage ( &msg , NULL , 0 , 0 ) )
	{
		TranslateMessage ( &msg ) ;
		DispatchMessage ( &msg ) ;
	}

	return msg.wParam ;
}

/*______________________________________________________________________________________________________________________*/
/*																														*/
/*											�E�B���h�E�v���V�[�W�� ( CALLBACK�֐� )										*/
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
			// �C���X�^���X�n���h���̎擾
			hInst = (HINSTANCE)GetWindowLong( hWnd , GWL_HINSTANCE ) ;

			// �e�[�u���Ƀr�b�g�}�b�v�����[�h
			hBmpTbl[0] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_BG) ) ;		// �w�i
			hBmpTbl[1] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_PLAYER) ) ;	// �v���C���[
			hBmpTbl[2] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_ENEMY) ) ;		// �G
			hBmpTbl[3] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_SHOT1) ) ;		// �e1
			hBmpTbl[4] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_SHOT2) ) ;		// �e2
			hBmpTbl[5] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_BOMB) ) ;		// ����
			hBmpTbl[6] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_BOSS) ) ;		// �e1
			hBmpTbl[7] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_LIFE) ) ;		// �e2
			hBmpTbl[8] = LoadBitmap( hInst , MAKEINTRESOURCE(IDB_SCORE) ) ;		// ����

			// ����ʂ̐���
			hDC = GetDC( hWnd ) ;
			hDCBack = CreateCompatibleDC( hDC ) ;
			hBitmap = CreateCompatibleBitmap( hDC , WINDOW_W , WINDOW_H ) ;
			SelectObject( hDCBack , hBitmap ) ;
			DeleteObject( hBitmap ) ;
			ReleaseDC( hWnd , hDC ) ;

			// �������̌Ăяo��		
			InitSet( ) ;

			// Sound Set
			mciSendString( TEXT("close all") , NULL , 0 , hWnd ) ;	// 00
			mciSendString( TEXT("open sound/start.wav alias SE_ST type waveaudio") , NULL , 0 , hWnd ) ;	// Player�̒e
			mciSendString( TEXT("open sound/shot1.wav alias SE_PS type waveaudio") , NULL , 0 , hWnd ) ;	// Player�̒e
			mciSendString( TEXT("open sound/shot2.wav alias SE_ES1 type waveaudio") , NULL , 0 , hWnd ) ;	// ENEMY �̒e
			mciSendString( TEXT("open sound/shot3.wav alias SE_ES2 type waveaudio") , NULL , 0 , hWnd ) ;	// ENEMY �̒e
			mciSendString( TEXT("open sound/shot4.wav alias SE_ES3 type waveaudio") , NULL , 0 , hWnd ) ;	// ENEMY �̒e
			mciSendString( TEXT("open sound/hitplayer.wav alias SE_PHIT type waveaudio") , NULL , 0 , hWnd ) ;// player hit
			mciSendString( TEXT("open sound/bomb1.wav alias SE_BOMB1 type waveaudio") , NULL , 0 , hWnd ) ;	// bomb1
			mciSendString( TEXT("open sound/bomb2.wav alias SE_BOMB2 type waveaudio") , NULL , 0 , hWnd ) ;	// bomb2
			mciSendString( TEXT("open sound/splayer.wav alias SE_SP type waveaudio") , NULL , 0 , hWnd ) ;	// PLAYER ���i
			mciSendString( TEXT("open sound/splayer2.wav alias SE_SP1 type waveaudio") , NULL , 0 , hWnd ) ;// PLAYER ���i
			mciSendString( TEXT("open sound/splayer3.wav alias SE_SP2 type waveaudio") , NULL , 0 , hWnd ) ;// PLAYER ���i
			mciSendString( TEXT("open sound/splayer4.wav alias SE_SP3 type waveaudio") , NULL , 0 , hWnd ) ;// PLAYER ���i

			SetTimer( hWnd , 1 , 50 , NULL ) ;
			break ;

		case WM_TIMER :
			if ( tmf == 0 )
			{
				tmf = 1 ;											// �^�C�}�[�����J�n
				EnemySet( ) ;
				DispLoop( ) ;										// �`��̃��[�v
				ActionLoop( ) ;										// �`��̃A�N�V����

				InvalidateRect( hWnd , NULL , FALSE ) ;
			}
			break ;

		case WM_PAINT :
			// ����ʂ���ʂɕ\��
			hDC = BeginPaint( hWnd , &ps ) ;
			BitBlt( hDC , 0 , 0 ,WINDOW_W ,WINDOW_H , hDCBack , 0 , 0 , SRCCOPY ) ;

			wsprintf( s , TEXT("time = %d") , etim ) ;
			TextOut( hDC , 0 , 0 , s , lstrlen(s) ) ;

			wsprintf( s , TEXT("[plyer]cnt = %d") , obj[O_PLY].cnt ) ;
			TextOut( hDC , 0 , 20 , s , lstrlen(s) ) ;

			EndPaint( hWnd , &ps ) ;
			tmf = 0 ;
			break ;

		/* ____ �E�B���h�E�j������ ____ */
		case WM_DESTROY :
			KillTimer( hWnd , 1 ) ;
			DeleteDC( hDCBack ) ;									// ����ʂ̍폜

			/*
				�I�u�W�F�N�g�폜
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

		/* ____ �f�t�H���g���� ____ */
		default :
			return DefWindowProc ( hWnd , message , wParam , lParam ) ;
	}

	return 0 ;

}


