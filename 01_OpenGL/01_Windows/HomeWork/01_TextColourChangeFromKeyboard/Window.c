// श्री स्वामी समर्थ
// Win32 headers
#include <windows.h>
#include <minwindef.h>

// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Entry-point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
    // variable declarations
    WNDCLASSEX wndclass;
    HWND hwnd;
    MSG msg;
    TCHAR szAppName[] = TEXT("RTR-6");

    // code
    // window class initialization
    wndclass.cbSize = sizeof(WNDCLASSEX);
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.lpfnWndProc = WndProc;
    wndclass.hInstance = hInstance;
    wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = szAppName;
    wndclass.lpszMenuName = NULL;
    wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    // registration of window class
    RegisterClassEx(&wndclass);

    // create window
    hwnd = CreateWindow(szAppName, TEXT("Vaibhav Tukaram Gaikwad"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

    // show window
    ShowWindow(hwnd, iCmdShow);

    // paint background of window
    UpdateWindow(hwnd);

    // message loop
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return ((int)msg.wParam);
}

// callback function
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    // variable declarations
    HDC hdc; // handle to device context
    PAINTSTRUCT ps;
    RECT rc;
    TCHAR str[] = TEXT("Hello, World!");
    int iPaintFlag = -1;

    // code
    switch (iMsg)
    {
    case WM_CHAR:
        switch (wParam)
        {
        case 'R':
        case 'r':
            iPaintFlag = 1;
            InvalidateRect(hwnd, NULL, TRUE);

            break;

        case 'G':
        case 'g':
            iPaintFlag = 2;
            InvalidateRect(hwnd, NULL, TRUE);

            break;

        case 'B':
        case 'b':
            iPaintFlag = 3;
            InvalidateRect(hwnd, NULL, TRUE);

            break;

        case 'Y':
        case 'y':
            iPaintFlag = 4;
            InvalidateRect(hwnd, NULL, TRUE);

            break;

        case 'C':
        case 'c':
            iPaintFlag = 5;
            InvalidateRect(hwnd, NULL, TRUE);

            break;

        case 'M':
        case 'm':
            iPaintFlag = 6;
            InvalidateRect(hwnd, NULL, TRUE);

            break;

        case 'W':
        case 'w':
            iPaintFlag = 7;
            InvalidateRect(hwnd, NULL, TRUE);

            break;

        default:
            break;
        }

    case WM_PAINT:
        GetClientRect(hwnd, &rc);
        hdc = BeginPaint(hwnd, &ps);
        SetBkColor(hdc, RGB(0, 0, 0));
        if (iPaintFlag == 1)
            SetTextColor(hdc, RGB(255, 0, 0));
        else if (iPaintFlag == 2)
            SetTextColor(hdc, RGB(0, 255, 0));
        else if (iPaintFlag == 3)
            SetTextColor(hdc, RGB(0, 0, 255));
        else if (iPaintFlag == 4)
            SetTextColor(hdc, RGB(255, 255, 0));
        else if (iPaintFlag == 5)
            SetTextColor(hdc, RGB(0, 255, 255));
        else if (iPaintFlag == 6)
            SetTextColor(hdc, RGB(255, 0, 255));
        else if (iPaintFlag == 7)
            SetTextColor(hdc, RGB(255, 255, 255));
        DrawText(hdc, str, -1, &rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        EndPaint(hwnd, &ps);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        break;
    }

    return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}