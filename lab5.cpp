// HomeWork5.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "HomeWork5.h"
#include <commdlg.h>
#define MAX_LOADSTRING 100

// 全局变量: 
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名
int iCurrentBitmap = IDB_BITMAP1;
int RadioItem = IDC_CHECK10;
// 此代码模块中包含的函数的前向声明: 
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	DIALOG1(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	DIALOG2(HWND, UINT, WPARAM, LPARAM);
HWND hWnd2;
static int radiodraw[3] = { 0,0,0 };
static int RadioSec[3] = { IDB_BITMAP1,IDB_BITMAP2,IDB_BITMAP3 };

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 在此放置代码。

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_HOMEWORK5, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化: 
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_HOMEWORK5));

    MSG msg;

    // 主消息循环: 
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目的: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_HOMEWORK5);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

    return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目的: 保存实例句柄并创建主窗口
//
//   注释: 
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 将实例句柄存储在全局变量中

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的:    处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int iSelection = ID_CURSOR1;
	static HCURSOR hCusor = LoadCursor(NULL, IDC_ARROW);
	static int sion = ID_CHIN;
	static HBITMAP hBitmap;
	wchar_t szFile[260] = TEXT(" "); // buffer for file name 
	static int cx, cy;
	hWnd2 = hWnd;
	HDC hdcMem;
	BITMAP bitmap;
	HMENU hMenu = (HMENU)wParam;
	HWND hdiamodeless;
    switch (message)
    {
	case WM_INITMENU:
		hMenu = (HMENU)wParam;
		CheckMenuRadioItem(hMenu, ID_CURSOR1, ID_CURSOR3,iSelection, MF_BYCOMMAND);
		CheckMenuRadioItem(hMenu, ID_CHIN, ID_ENGLISH, sion, MF_BYCOMMAND);
		InvalidateRect(hWnd, false, true);
		UpdateWindow(hWnd);
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 分析菜单选择: 
            switch (wmId)
            {
			case ID_DIALOG1://模式对话框
				DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1),hWnd, DIALOG1);
				InvalidateRect(hWnd, NULL, TRUE);
				UpdateWindow(hWnd);
				break;
			case ID_DIALOG2://无模式对话框
				hdiamodeless = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, DIALOG2);
				ShowWindow(hdiamodeless, SW_SHOWNORMAL);
				InvalidateRect(hWnd, 0, 1);
				UpdateWindow(hWnd);
				break;
			case ID_DIALOG3://文件对话框
				OPENFILENAME ofn; // common dialog box structure 
				ZeroMemory(&ofn, sizeof(OPENFILENAME));
				ofn.lStructSize = sizeof(OPENFILENAME);
				ofn.hwndOwner = hWnd;
				ofn.lpstrFile = szFile;
				ofn.nMaxFile = sizeof(szFile);
				ofn.lpstrFilter = TEXT("All(*.*)\0*.*\0Text(*.txt)\0*.TXT\0PDF Files(*.pdf)\0*.PDF\0");
				ofn.nFilterIndex = 1;
				ofn.lpstrFileTitle = NULL;
				ofn.nMaxFileTitle = 0;
				ofn.lpstrInitialDir = NULL;
				ofn.Flags = OFN_HIDEREADONLY | OFN_CREATEPROMPT;
				if (GetOpenFileName(&ofn) == TRUE)
					MessageBox(hWnd, szFile, TEXT("打开"), MB_OK);
				break;
			case ID_CURSOR1:
			case ID_CURSOR2:
			case ID_CURSOR3://设置光标
				iSelection = LOWORD(wParam);
				CheckMenuRadioItem(hMenu, ID_CURSOR1, ID_CURSOR2,iSelection, MF_BYCOMMAND);
				if (iSelection == ID_CURSOR1) SetClassLong(hWnd, GCL_HCURSOR, (long)LoadCursor(NULL,IDC_ARROW));
				else if (iSelection == ID_CURSOR2) SetClassLong(hWnd, GCL_HCURSOR, (long)LoadCursor(NULL,IDC_CROSS));
				else SetClassLong(hWnd, GCL_HCURSOR, (long)LoadCursor(hInst, MAKEINTRESOURCE(IDC_CURSOR1)));
				SendMessage(hWnd, WM_SETCURSOR, (long)hWnd, 0x02010001);
				InvalidateRect(hWnd, false, true);
				UpdateWindow(hWnd);
				break;
			case ID_CHIN://切换中文菜单
			case ID_ENGLISH://切换英文菜单
				sion = LOWORD(wParam);
				CheckMenuRadioItem(hMenu, ID_CHIN, ID_ENGLISH, sion, MF_BYCOMMAND);
				if (sion == ID_CHIN) SetMenu(hWnd, LoadMenu(hInst, MAKEINTRESOURCE(IDR_MENU2)));
				else SetMenu(hWnd, LoadMenu(hInst, MAKEINTRESOURCE(IDR_MENU1)));
				InvalidateRect(hWnd, false, true);
				UpdateWindow(hWnd);
				break;
            case IDM_ABOUT: //F1显示程序信息
				MessageBox(hWnd, TEXT("第五次上机练习(SDK)\n对话框,光标,字符串,位图\n\n学号：10152130155\n姓名：陈越"), TEXT("Lab5 (SDK)"), MB_ICONASTERISK | MB_ICONINFORMATION);
                //DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 在此处添加使用 hdc 的任何绘图代码...
			wchar_t str[20];
			if (sion == ID_CHIN) {//复选框图片设置
				LoadString(hInst, IDS_CHIN_CURR_CURSOR, str, 20);
				TextOut(hdc, 100, 50, str, lstrlen(str));
				if(iSelection==ID_CURSOR3) LoadString(hInst, IDS_CHIN_CURSOR, str, 20);
				else if (iSelection == ID_CURSOR1) LoadString(hInst, IDS_CH1, str, 20);
				else LoadString(hInst, IDS_CH2, str, 20);
				TextOut(hdc, 180, 50, str, lstrlen(str));
			}
			else {
				LoadString(hInst, IDS_ENG_CURR_CURRSOR, str, 20);
				TextOut(hdc, 100, 50, str, lstrlen(str));
				if (iSelection == ID_CURSOR3) LoadString(hInst, IDS_ENG_CURRSOR, str, 20);
				else if (iSelection == ID_CURSOR1) LoadString(hInst, IDS_CH1, str, 20);
				else LoadString(hInst, IDS_CH2, str, 20);
				TextOut(hdc, 220, 50, str, lstrlen(str));
			}
			if (radiodraw[0]) {
				hBitmap = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
				GetObject(hBitmap, sizeof(BITMAP), &bitmap);
				cx = bitmap.bmWidth;
				cy = bitmap.bmHeight;
				hdcMem = CreateCompatibleDC(hdc);
				SelectObject(hdcMem, hBitmap);
				BitBlt(hdc, 100, 150, cx, cy, hdcMem, 0, 0, SRCCOPY);
				DeleteDC(hdcMem);
				DeleteObject(hBitmap);
			}
			if (radiodraw[1]) {
				hBitmap = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP2));
				GetObject(hBitmap, sizeof(BITMAP), &bitmap);
				cx = bitmap.bmWidth;
				cy = bitmap.bmHeight;
				hdcMem = CreateCompatibleDC(hdc);
				SelectObject(hdcMem, hBitmap);
				BitBlt(hdc, 100, 350, cx, cy, hdcMem, 0, 0, SRCCOPY);
				DeleteDC(hdcMem);
				DeleteObject(hBitmap);
			}
			if (radiodraw[2]) {
				hBitmap = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP3));
				GetObject(hBitmap, sizeof(BITMAP), &bitmap);
				cx = bitmap.bmWidth;
				cy = bitmap.bmHeight;
				hdcMem = CreateCompatibleDC(hdc);
				SelectObject(hdcMem, hBitmap);
				BitBlt(hdc, 100, 550, cx, cy, hdcMem, 0, 0, SRCCOPY);
				DeleteDC(hdcMem);
				DeleteObject(hBitmap);
			}
			//单选框设置
			hBitmap = LoadBitmap(hInst, MAKEINTRESOURCE(RadioSec[RadioItem-IDC_CHECK10]));
			GetObject(hBitmap, sizeof(BITMAP), &bitmap);
			cx = bitmap.bmWidth;
			cy = bitmap.bmHeight;
			hdcMem = CreateCompatibleDC(hdc);
			SelectObject(hdcMem, hBitmap);
			BitBlt(hdc, 500, 50, cx, cy, hdcMem, 0, 0, SRCCOPY);
			DeleteDC(hdcMem);
			DeleteObject(hBitmap);
			EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
	HMENU hMenu = (HMENU)wParam;
    switch (message)
    {
	//HMENU hMenu = (HMENU)wParam;
    case WM_INITDIALOG:

        return (INT_PTR)TRUE;
    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
		case IDCANCEL:
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
INT_PTR CALLBACK DIALOG1(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	HMENU hMenu = (HMENU)wParam;
	switch (message)
	{
	case WM_INITDIALOG:
		if (radiodraw[0] == 1)CheckDlgButton(hDlg, IDC_CHECK1, BST_CHECKED);
		if (radiodraw[1] == 1)CheckDlgButton(hDlg, IDC_CHECK2, BST_CHECKED);
		if (radiodraw[2] == 1)CheckDlgButton(hDlg, IDC_CHECK3, BST_CHECKED);
		break;
		return (INT_PTR)TRUE;
	case WM_DESTROY:
		EndDialog(hDlg, LOWORD(wParam));
		break;
		return (INT_PTR)TRUE;
		break;
	case WM_COMMAND:
		int wmId = LOWORD(wParam);
		switch (wmId)
		{
		case IDOK:
			if (IsDlgButtonChecked(hDlg, IDC_CHECK1) == BST_CHECKED) radiodraw[0] = 1;
			else radiodraw[0] = 0;
			if (IsDlgButtonChecked(hDlg, IDC_CHECK2) == BST_CHECKED) radiodraw[1] = 1;
			else radiodraw[1] = 0;
			if (IsDlgButtonChecked(hDlg, IDC_CHECK3) == BST_CHECKED) radiodraw[2] = 1;
			else radiodraw[2] = 0;
			EndDialog(hDlg, LOWORD(wParam));
			break;
		case IDNO:
			EndDialog(hDlg, LOWORD(wParam));
			break;
		case IDC_CHECK1:
		case IDC_CHECK2:
		case IDC_CHECK3:
			if (GetMenuState(hMenu, iCurrentBitmap, MF_BYCOMMAND)) CheckMenuItem(hMenu, iCurrentBitmap, MF_CHECKED);
			else CheckMenuItem(hMenu, iCurrentBitmap, MF_UNCHECKED);
			InvalidateRect(hDlg, false, true);
			UpdateWindow(hDlg);
			break;
		case WM_DESTROY:
			EndDialog(hDlg, LOWORD(wParam));
			break;
		default:
			break;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
INT_PTR CALLBACK DIALOG2(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	static int iSelection = RadioItem;
	switch (message)
	{
	case WM_INITDIALOG:
		CheckRadioButton(hDlg, IDC_CHECK10, IDC_CHECK30, iSelection);
		InvalidateRect(hDlg, false, true);
		UpdateWindow(hDlg);
		break;
	case WM_COMMAND:
		int wmId = LOWORD(wParam);
		switch (wmId)
		{
		case IDOK:
			RadioItem = iSelection;
			InvalidateRect(hWnd2, false, true);
			UpdateWindow(hWnd2);
			EndDialog(hDlg, LOWORD(wParam));
			break;
		case IDNO:
			EndDialog(hDlg, LOWORD(wParam));
			break;
		case WM_DESTROY:
			EndDialog(hDlg, LOWORD(wParam));
			break;
		case IDC_CHECK10:
		case IDC_CHECK20:
		case IDC_CHECK30:
			iSelection = wmId;
			CheckRadioButton(hDlg, IDC_CHECK10, IDC_CHECK30, iSelection);
			break;
		}
		break;
	}
	return (INT_PTR)FALSE;
}