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

    // code
    switch (iMsg)
    {
    // WM_PAINT 8 situations madhe yeto
    // 1. Jevha jevha window pahilyanda display hote
    // 2. Jevha window move karto tevha
    // 3. Jevha window varun icon across nela tr
    // 4. Pull down kelela menu pull up kela
    // 5. Window resize karto tevha
    // 6. Scrolling karto tevha
    case WM_PAINT:
        GetClientRect(hwnd, &rc);
        hdc = BeginPaint(hwnd, &ps);
        SetBkColor(hdc, RGB(0, 0, 0));
        SetTextColor(hdc, RGB(0, 255, 0));
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