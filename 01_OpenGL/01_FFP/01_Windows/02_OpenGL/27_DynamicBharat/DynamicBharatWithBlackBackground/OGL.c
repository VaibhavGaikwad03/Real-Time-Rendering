// श्री स्वामी समर्थ
// Win32 headers
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// custom header file
#include "OGL.h"
#include "math/math.h"
#include "utils/utils.h"
// #include "DynamicBharat/DynamicBharat.h"

// OpenGL header file
#include <gl/GL.h>
#include <gl/GLU.h>

// OpenGL related libraries
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

// macros
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

// OpenGL related variables
HDC ghdc = NULL;
HGLRC ghrc = NULL;

// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// global variable declarations
BOOL gbFullScreen = FALSE;
HWND ghwnd = NULL;
DWORD dwStyle;
WINDOWPLACEMENT wpPrev;

// active window related variables
BOOL gbActiveWindow = FALSE;

// exit keypress related
BOOL gbEscapeKeyIsPressed = FALSE;

// variables related with file I/O
char gszLogFileName[] = "Log.txt";
FILE *gpFile = NULL;

// for stopping the program
BOOL bDone = FALSE;

// entry-point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
    // local function declarations
    int initialize(void);
    void display(void);
    void update(void);
    void uninitialize(void);

    // local variable declarations
    WNDCLASSEX wndclass;
    HWND hwnd;
    MSG msg;
    TCHAR szAppName[] = TEXT("RTR-6");

    // create log file
    gpFile = fopen(gszLogFileName, "w");
    if (gpFile == NULL)
    {
        MessageBox(HWND_DESKTOP /*kiva NULL pn deu shakto. Tyala sangitla jatay ki tuza baap desktop ahe*/, TEXT("Log file creation failed."), TEXT("File I/O Error"), MB_OK);
        exit(0);
    }
    else
    {
        fprintf(gpFile, "Program started successfully.\n");
    }

    // code
    // window class initialization
    wndclass.cbSize = sizeof(WNDCLASSEX);
    wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.lpfnWndProc = WndProc;
    wndclass.hInstance = hInstance;
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = szAppName;
    wndclass.lpszMenuName = NULL;
    wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));

    // registration of window class
    RegisterClassEx(&wndclass);

    // create window
    hwnd = CreateWindowEx(WS_EX_APPWINDOW, szAppName, TEXT("Vaibhav Tukaram Gaikwad"), WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, WIN_WIDTH, WIN_HEIGHT, NULL, NULL, hInstance, NULL);

    ghwnd = hwnd;

    // show window
    ShowWindow(hwnd, iCmdShow);

    // paint background of window
    UpdateWindow(hwnd);

    // initialize
    int result = initialize();
    if (result != 0)
    {
        fprintf(gpFile, "initialize() failed.\n");
        DestroyWindow(hwnd);
        hwnd = NULL;
    }
    else
    {
        fprintf(gpFile, "initialize() completed successfully.\n");
    }

    // set this window as foreground and active window
    SetForegroundWindow(hwnd);
    SetFocus(hwnd);

    // game loop
    while (bDone == FALSE)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                bDone = TRUE;
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            if (gbActiveWindow == TRUE)
            {
                if (gbEscapeKeyIsPressed == TRUE)
                {
                    bDone = TRUE;
                }

                // render
                display();

                // update
                update();
            }
        }
    }

    uninitialize();

    return ((int)msg.wParam);
}

// callback function
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    // local function declarations
    void toggleFullScreen(void);
    void resize(int, int);
    void uninitialized(void);

    // code
    switch (iMsg)
    {
    case WM_CREATE:
        ZeroMemory((void *)&wpPrev, sizeof(WINDOWPLACEMENT));
        wpPrev.length = sizeof(WINDOWPLACEMENT);

        break;

    case WM_SETFOCUS:
        gbActiveWindow = TRUE;
        break;

    case WM_KILLFOCUS:
        gbActiveWindow = FALSE;
        break;

    case WM_ERASEBKGND:
        return (0);
        break;

    case WM_SIZE:
        resize(LOWORD(lParam), HIWORD(lParam));
        break;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:
            gbEscapeKeyIsPressed = TRUE;
            break;

        default:
            break;
        }
        break;

    case WM_CHAR:
        switch (wParam)
        {
        case 'F':
        case 'f':

            if (gbFullScreen == FALSE)
            {
                toggleFullScreen();

                gbFullScreen = TRUE;
            }
            else
            {
                toggleFullScreen();

                gbFullScreen = FALSE;
            }

            break;

        default:
            break;
        }

        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        break;
    }

    return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}

void toggleFullScreen(void) // 08-02-2025
{
    // variable declarations
    MONITORINFO mi;

    // code
    if (gbFullScreen == FALSE)
    {
        dwStyle = GetWindowLong(ghwnd, GWL_STYLE);

        if (dwStyle & WS_OVERLAPPEDWINDOW)
        {
            ZeroMemory((void *)&mi, sizeof(MONITORINFO));
            mi.cbSize = sizeof(MONITORINFO);

            if (GetWindowPlacement(ghwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))
            {
                SetWindowLong(ghwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);
                SetWindowPos(ghwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top, SWP_NOZORDER | SWP_FRAMECHANGED);
            }
        }
        ShowCursor(FALSE);
    }
    else
    {
        SetWindowPlacement(ghwnd, &wpPrev);
        SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
        SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);
        ShowCursor(TRUE);
    }
}

int initialize(void)
{
    // AllocConsole();
    // freopen("CONOUT$", "w", stdout);

    PlaySound("VandeMataramLataMangeshkarFinal.wav", NULL, SND_ASYNC);

    // variable declarations
    PIXELFORMATDESCRIPTOR pfd;
    int iPixelFormatIndex = 0;

    // function declarations
    void printGLInfo(void);
    void resize(int, int);

    // code
    // PIXELFORMATDESCRIPTOR initialization
    ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cRedBits = 8;
    pfd.cGreenBits = 8;
    pfd.cBlueBits = 8;
    pfd.cAlphaBits = 8;

    // get DC
    ghdc = GetDC(ghwnd);
    if (ghdc == NULL)
    {
        fprintf(gpFile, "GetDC() failed\n");
        return -1;
    }

    // get matching pixel format index using hdc and pfd
    iPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd);
    if (iPixelFormatIndex == 0)
    {
        fprintf(gpFile, "ChoosePixelFormat() failed\n");
        return -2;
    }

    // select the pixel format of found index
    if (SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == FALSE)
    {
        fprintf(gpFile, "SetPixelFormat() failed\n");
        return -3;
    }

    // create rendering context using hdc, pfd and choosen pixel format index
    ghrc = wglCreateContext(ghdc);
    if (ghrc == NULL)
    {
        fprintf(gpFile, "wglCreateContext() failed\n");
        return -4;
    }

    // make this rendering context as current contex
    if (wglMakeCurrent(ghdc, ghrc) == FALSE)
    {
        fprintf(gpFile, "wglMakeCurrent() failed\n");
        return -5;
    }

    printGLInfo();

    // from here onward the OpenGL code starts
    // tell OpenGL to choose the colour to clear the screen
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // warmup resize
    resize(WIN_WIDTH, WIN_HEIGHT);

    return 0;
}

void printGLInfo(void)
{
    // code
    // print OpenGL information
    fprintf(gpFile, "OPENGL INFORMATION\n");
    fprintf(gpFile, "******************\n");
    fprintf(gpFile, "OpenGL Vendor: %s\n", glGetString(GL_VENDOR));
    fprintf(gpFile, "OpenGL Renderer: %s\n", glGetString(GL_RENDERER));
    fprintf(gpFile, "OpenGL Version: %s\n", glGetString(GL_VERSION));
    fprintf(gpFile, "******************\n");
}

void resize(int width, int height)
{
    // code
    // if height by accident become zero or less than zero then make height 1
    if (height <= 0)
    {
        height = 1;
    }

    // set the view port
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);

    // set matrix projection mode
    glMatrixMode(GL_PROJECTION); // matrix cha mode projection la thev

    // set to identity matrix
    glLoadIdentity(); // jya matrix cha mode varti projection la set kela tya matrix la atta identity matrix kr

    // set perspective projection
    gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
}

//////////////////////////////////////////// DRAWING FUNCTIONS ////////////////////////////////////////////////////

float indiaSaffronRed = 0.75f;
float indiaSaffronGreen = 0.75f;
float indiaSaffronBlue = 0.75f;

float finalIndiaSaffronRed = 1.0f;
float finalIndiaSaffronGreen = 0.4039f;
float finalIndiaSaffronBlue = 0.1215f;

float indiaGreenRed = 0.75f;
float indiaGreenGreen = 0.75f;
float indiaGreenBlue = 0.75f;

float finalIndiaGreenRed = 1.0f;
float finalIndiaGreenGreen = 0.4039f;
float finalIndiaGreenBlue = 0.1215f;

void DrawB(float ox, float oy, float alpha)
{
    glBegin(GL_POLYGON); // upper right

    glColor4f(1.0f, 0.4039f, 0.1215f, alpha);
    glVertex2f(0.2f + ox, 0.35f + oy);
    glVertex2f(0.15f + ox, 0.4f + oy);
    glVertex2f(0.1f + ox, 0.4f + oy);
    glColor4f(1.0f, 1.0f, 1.0f, alpha);
    glVertex2f(0.1f + ox, -0.05f + oy);
    glVertex2f(0.2f + ox, 0.05f + oy);
    glVertex2f(0.2f + ox, 0.35f + oy);

    glEnd();

    glBegin(GL_POLYGON); // lower right

    glColor4f(1.0f, 1.0f, 1.0f, alpha);
    glVertex2f(0.2f + ox, -0.05f + oy);
    glVertex2f(0.1f + ox, 0.05f + oy);
    glColor4f(0.0156f, 0.4156f, 0.2196f, alpha);
    glVertex2f(0.1f + ox, -0.4f + oy);
    glVertex2f(0.15f + ox, -0.4f + oy);
    glVertex2f(0.2f + ox, -0.35f + oy);

    glEnd();

    glBegin(GL_QUADS);

    glColor4f(1.0f, 0.4039f, 0.1215f, alpha); // upper horizontal
    glVertex2f(0.1f + ox, 0.4f + oy);
    glVertex2f(-0.2f + ox, 0.4f + oy);
    glColor4f(1.0f, 0.552f, 0.341f, alpha);
    glVertex2f(-0.2f + ox, 0.3f + oy);
    glVertex2f(0.1f + ox, 0.3f + oy);

    glColor4f(0.2392f, 0.549f, 0.396f, alpha); // lower horizontal
    glVertex2f(0.1f + ox, -0.3f + oy);
    glVertex2f(-0.2f + ox, -0.3f + oy);
    glColor4f(0.0156f, 0.4156f, 0.2196f, alpha);
    glVertex2f(-0.2f + ox, -0.4f + oy);
    glVertex2f(0.1f + ox, -0.4f + oy);

    glColor4f(1.0f, 0.4039f, 0.1215f, alpha); // left vertical lower
    glVertex2f(-0.1f + ox, 0.4f + oy);
    glVertex2f(-0.2f + ox, 0.4f + oy);
    glColor4f(1.0f, 1.0f, 1.0f, alpha);
    glVertex2f(-0.2f + ox, 0.0f + oy);
    glVertex2f(-0.1f + ox, 0.0f + oy);

    glColor4f(1.0f, 1.0f, 1.0f, alpha); // middle
    glVertex2f(-0.2f + ox, 0.05f + oy);
    glVertex2f(-0.2f + ox, -0.05f + oy);
    glVertex2f(0.1f + ox, -0.05f + oy);
    glVertex2f(0.1f + ox, 0.05f + oy);

    glColor4f(1.0f, 1.0f, 1.0f, alpha); // left vertical upper
    glVertex2f(-0.1f + ox, 0.0f + oy);
    glVertex2f(-0.2f + ox, 0.0f + oy);
    glColor4f(0.0156f, 0.4156f, 0.2196f, alpha);
    glVertex2f(-0.2f + ox, -0.4f + oy);
    glVertex2f(-0.1f + ox, -0.4f + oy);

    glEnd();
}

void DrawBGrey(float ox, float oy, float alpha)
{
    glBegin(GL_POLYGON); // upper right

    glColor4f(0.75f, 0.75f, 0.75f, alpha);
    glVertex2f(0.2f + ox, 0.35f + oy);
    glVertex2f(0.15f + ox, 0.4f + oy);
    glVertex2f(0.1f + ox, 0.4f + oy);
    glColor4f(0.75f, 0.75f, 0.75f, alpha);
    glVertex2f(0.1f + ox, -0.05f + oy);
    glVertex2f(0.2f + ox, 0.05f + oy);
    glVertex2f(0.2f + ox, 0.35f + oy);

    glEnd();

    glBegin(GL_POLYGON); // lower right

    glColor4f(0.75f, 0.75f, 0.75f, alpha);
    glVertex2f(0.2f + ox, -0.05f + oy);
    glVertex2f(0.1f + ox, 0.05f + oy);
    glColor4f(0.75f, 0.75f, 0.75f, alpha);
    glVertex2f(0.1f + ox, -0.4f + oy);
    glVertex2f(0.15f + ox, -0.4f + oy);
    glVertex2f(0.2f + ox, -0.35f + oy);

    glEnd();

    glBegin(GL_QUADS);

    glColor4f(0.75f, 0.75f, 0.75f, alpha); // upper horizontal
    glVertex2f(0.1f + ox, 0.4f + oy);
    glVertex2f(-0.2f + ox, 0.4f + oy);
    glColor4f(0.75f, 0.75f, 0.75f, alpha);
    glVertex2f(-0.2f + ox, 0.3f + oy);
    glVertex2f(0.1f + ox, 0.3f + oy);

    glColor4f(0.75f, 0.75f, 0.75f, alpha); // lower horizontal
    glVertex2f(0.1f + ox, -0.3f + oy);
    glVertex2f(-0.2f + ox, -0.3f + oy);
    glColor4f(0.75f, 0.75f, 0.75f, alpha);
    glVertex2f(-0.2f + ox, -0.4f + oy);
    glVertex2f(0.1f + ox, -0.4f + oy);

    glColor4f(0.75f, 0.75f, 0.75f, alpha); // left vertical lower
    glVertex2f(-0.1f + ox, 0.4f + oy);
    glVertex2f(-0.2f + ox, 0.4f + oy);
    glColor4f(0.75f, 0.75f, 0.75f, alpha);
    glVertex2f(-0.2f + ox, 0.0f + oy);
    glVertex2f(-0.1f + ox, 0.0f + oy);

    glColor4f(0.75f, 0.75f, 0.75f, alpha); // middle
    glVertex2f(-0.2f + ox, 0.05f + oy);
    glVertex2f(-0.2f + ox, -0.05f + oy);
    glVertex2f(0.1f + ox, -0.05f + oy);
    glVertex2f(0.1f + ox, 0.05f + oy);

    glColor4f(0.75f, 0.75f, 0.75f, alpha); // left vertical upper
    glVertex2f(-0.1f + ox, 0.0f + oy);
    glVertex2f(-0.2f + ox, 0.0f + oy);
    glColor4f(0.75f, 0.75f, 0.75f, alpha);
    glVertex2f(-0.2f + ox, -0.4f + oy);
    glVertex2f(-0.1f + ox, -0.4f + oy);

    glEnd();
}

void DrawH(float ox, float oy, float alpha)
{
    glBegin(GL_QUADS);

    glColor4f(1.0f, 1.0f, 1.0f, alpha); // middle
    glVertex2f(-0.2f + ox, 0.05f + oy);
    glVertex2f(-0.2f + ox, -0.05f + oy);
    glVertex2f(0.1f + ox, -0.05f + oy);
    glVertex2f(0.1f + ox, 0.05f + oy);

    glColor4f(1.0f, 0.4039f, 0.1215f, alpha); // left vertical lower
    glVertex2f(-0.1f + ox, 0.4f + oy);
    glVertex2f(-0.2f + ox, 0.4f + oy);
    glColor4f(1.0f, 1.0f, 1.0f, alpha);
    glVertex2f(-0.2f + ox, 0.0f + oy);
    glVertex2f(-0.1f + ox, 0.0f + oy);

    glColor4f(1.0f, 1.0f, 1.0f, alpha); // left vertical upper
    glVertex2f(-0.1f + ox, 0.0f + oy);
    glVertex2f(-0.2f + ox, 0.0f + oy);
    glColor4f(0.0156f, 0.4156f, 0.2196f, alpha);
    glVertex2f(-0.2f + ox, -0.4f + oy);
    glVertex2f(-0.1f + ox, -0.4f + oy);

    glColor4f(1.0f, 0.4039f, 0.1215f, alpha); // right vertical lower
    glVertex2f(0.1f + ox, 0.4f + oy);
    glVertex2f(0.2f + ox, 0.4f + oy);
    glColor4f(1.0f, 1.0f, 1.0f, alpha);
    glVertex2f(0.2f + ox, 0.0f + oy);
    glVertex2f(0.1f + ox, 0.0f + oy);

    glColor4f(1.0f, 1.0f, 1.0f, alpha); // right vertical upper
    glVertex2f(0.1f + ox, 0.0f + oy);
    glVertex2f(0.2f + ox, 0.0f + oy);
    glColor4f(0.0156f, 0.4156f, 0.2196f, alpha);
    glVertex2f(0.2f + ox, -0.4f + oy);
    glVertex2f(0.1f + ox, -0.4f + oy);

    glEnd();
}

void DrawHGrey(float ox, float oy, float alpha)
{
    glBegin(GL_QUADS);

    glColor4f(0.75f, 0.75f, 0.75f, alpha); // middle
    glVertex2f(-0.2f + ox, 0.05f + oy);
    glVertex2f(-0.2f + ox, -0.05f + oy);
    glVertex2f(0.1f + ox, -0.05f + oy);
    glVertex2f(0.1f + ox, 0.05f + oy);

    glColor4f(0.75f, 0.75f, 0.75f, alpha); // left vertical lower
    glVertex2f(-0.1f + ox, 0.4f + oy);
    glVertex2f(-0.2f + ox, 0.4f + oy);
    glColor4f(0.75f, 0.75f, 0.75f, alpha);
    glVertex2f(-0.2f + ox, 0.0f + oy);
    glVertex2f(-0.1f + ox, 0.0f + oy);

    glColor4f(0.75f, 0.75f, 0.75f, alpha); // left vertical upper
    glVertex2f(-0.1f + ox, 0.0f + oy);
    glVertex2f(-0.2f + ox, 0.0f + oy);
    glColor4f(0.75f, 0.75f, 0.75f, alpha);
    glVertex2f(-0.2f + ox, -0.4f + oy);
    glVertex2f(-0.1f + ox, -0.4f + oy);

    glColor4f(0.75f, 0.75f, 0.75f, alpha); // right vertical lower
    glVertex2f(0.1f + ox, 0.4f + oy);
    glVertex2f(0.2f + ox, 0.4f + oy);
    glColor4f(0.75f, 0.75f, 0.75f, alpha);
    glVertex2f(0.2f + ox, 0.0f + oy);
    glVertex2f(0.1f + ox, 0.0f + oy);

    glColor4f(0.75f, 0.75f, 0.75f, alpha); // right vertical upper
    glVertex2f(0.1f + ox, 0.0f + oy);
    glVertex2f(0.2f + ox, 0.0f + oy);
    glColor4f(0.75f, 0.75f, 0.75f, alpha);
    glVertex2f(0.2f + ox, -0.4f + oy);
    glVertex2f(0.1f + ox, -0.4f + oy);

    glEnd();
}

void DrawA(float ox, float oy, float alpha)
{
    glBegin(GL_POLYGON);

    glColor4f(1.0f, 0.4039f, 0.1215f, alpha);
    glVertex2f(0.2f + ox, 0.35f + oy);
    glVertex2f(0.15f + ox, 0.4f + oy);
    glVertex2f(-0.15f + ox, 0.4f + oy);
    glVertex2f(-0.2f + ox, 0.35f + oy);
    glColor4f(1.0f, 0.552f, 0.341f, alpha);
    glVertex2f(-0.2f + ox, 0.3f + oy);
    glVertex2f(0.2f + ox, 0.3f + oy);

    glEnd();

    glBegin(GL_QUADS);

    glColor4f(1.0f, 1.0f, 1.0f, alpha); // middle
    glVertex2f(-0.2f + ox, 0.05f + oy);
    glVertex2f(-0.2f + ox, -0.05f + oy);
    glVertex2f(0.1f + ox, -0.05f + oy);
    glVertex2f(0.1f + ox, 0.05f + oy);

    glColor4f(1.0f, 0.552f, 0.341f, alpha); // left vertical upper
    glVertex2f(-0.1f + ox, 0.3f + oy);
    glVertex2f(-0.2f + ox, 0.3f + oy);
    glColor4f(1.0f, 1.0f, 1.0f, alpha);
    glVertex2f(-0.2f + ox, 0.0f + oy);
    glVertex2f(-0.1f + ox, 0.0f + oy);

    glColor4f(1.0f, 1.0f, 1.0f, alpha); // left vertical lower
    glVertex2f(-0.1f + ox, 0.0f + oy);
    glVertex2f(-0.2f + ox, 0.0f + oy);
    glColor4f(0.0156f, 0.4156f, 0.2196f, alpha);
    glVertex2f(-0.2f + ox, -0.4f + oy);
    glVertex2f(-0.1f + ox, -0.4f + oy);

    glColor4f(1.0f, 0.552f, 0.341f, alpha); // right vertical upper
    glVertex2f(0.1f + ox, 0.3f + oy);
    glVertex2f(0.2f + ox, 0.3f + oy);
    glColor4f(1.0f, 1.0f, 1.0f, alpha);
    glVertex2f(0.2f + ox, 0.0f + oy);
    glVertex2f(0.1f + ox, 0.0f + oy);

    glColor4f(1.0f, 1.0f, 1.0f, alpha); // right vertical lower
    glVertex2f(0.1f + ox, 0.0f + oy);
    glVertex2f(0.2f + ox, 0.0f + oy);
    glColor4f(0.0156f, 0.4156f, 0.2196f, alpha);
    glVertex2f(0.2f + ox, -0.4f + oy);
    glVertex2f(0.1f + ox, -0.4f + oy);

    glEnd();
}

void DrawAGrey(float ox, float oy, float alpha)
{
    glBegin(GL_POLYGON);

    glColor4f(0.75f, 0.75f, 0.75f, alpha);
    glVertex2f(0.2f + ox, 0.35f + oy);
    glVertex2f(0.15f + ox, 0.4f + oy);
    glVertex2f(-0.15f + ox, 0.4f + oy);
    glVertex2f(-0.2f + ox, 0.35f + oy);
    glColor4f(0.75f, 0.75f, 0.75f, alpha);
    glVertex2f(-0.2f + ox, 0.3f + oy);
    glVertex2f(0.2f + ox, 0.3f + oy);

    glEnd();

    glBegin(GL_QUADS);

    glColor4f(0.75f, 0.75f, 0.75f, alpha); // middle
    glVertex2f(-0.2f + ox, 0.05f + oy);
    glVertex2f(-0.2f + ox, -0.05f + oy);
    glVertex2f(0.1f + ox, -0.05f + oy);
    glVertex2f(0.1f + ox, 0.05f + oy);

    glColor4f(0.75f, 0.75f, 0.75f, alpha); // left vertical upper
    glVertex2f(-0.1f + ox, 0.3f + oy);
    glVertex2f(-0.2f + ox, 0.3f + oy);
    glColor4f(0.75f, 0.75f, 0.75f, alpha);
    glVertex2f(-0.2f + ox, 0.0f + oy);
    glVertex2f(-0.1f + ox, 0.0f + oy);

    glColor4f(0.75f, 0.75f, 0.75f, alpha); // left vertical lower
    glVertex2f(-0.1f + ox, 0.0f + oy);
    glVertex2f(-0.2f + ox, 0.0f + oy);
    glColor4f(0.75f, 0.75f, 0.75f, alpha);
    glVertex2f(-0.2f + ox, -0.4f + oy);
    glVertex2f(-0.1f + ox, -0.4f + oy);

    glColor4f(0.75f, 0.75f, 0.75f, alpha); // right vertical upper
    glVertex2f(0.1f + ox, 0.3f + oy);
    glVertex2f(0.2f + ox, 0.3f + oy);
    glColor4f(0.75f, 0.75f, 0.75f, alpha);
    glVertex2f(0.2f + ox, 0.0f + oy);
    glVertex2f(0.1f + ox, 0.0f + oy);

    glColor4f(0.75f, 0.75f, 0.75f, alpha); // right vertical lower
    glVertex2f(0.1f + ox, 0.0f + oy);
    glVertex2f(0.2f + ox, 0.0f + oy);
    glColor4f(0.75f, 0.75f, 0.75f, alpha);
    glVertex2f(0.2f + ox, -0.4f + oy);
    glVertex2f(0.1f + ox, -0.4f + oy);

    glEnd();
}

void DrawT(float ox, float oy, float alpha)
{
    glBegin(GL_QUADS);

    glColor4f(1.0f, 0.4039f, 0.1215f, alpha); // left vertical lower
    glVertex2f(0.05f + ox, 0.4f + oy);
    glVertex2f(-0.05f + ox, 0.4f + oy);
    glColor4f(1.0f, 1.0f, 1.0f, alpha);
    glVertex2f(-0.05f + ox, 0.0f + oy);
    glVertex2f(0.05f + ox, 0.0f + oy);

    glColor4f(1.0f, 1.0f, 1.0f, alpha); // left vertical upper
    glVertex2f(0.05f + ox, 0.0f + oy);
    glVertex2f(-0.05f + ox, 0.0f + oy);
    glColor4f(0.0156f, 0.4156f, 0.2196f, alpha);
    glVertex2f(-0.05f + ox, -0.4f + oy);
    glVertex2f(0.05f + ox, -0.4f + oy);

    glColor4f(1.0f, 0.4039f, 0.1215f, alpha); // middle
    glVertex2f(0.2f + ox, 0.4f + oy);
    glVertex2f(-0.2f + ox, 0.4f + oy);
    glColor4f(1.0f, 0.552f, 0.341f, alpha);
    glVertex2f(-0.2f + ox, 0.3f + oy);
    glVertex2f(0.2f + ox, 0.3f + oy);

    glEnd();
}

void DrawTGrey(float ox, float oy, float alpha)
{
    glBegin(GL_QUADS);

    glColor4f(0.75f, 0.75f, 0.75f, alpha); // left vertical lower
    glVertex2f(0.05f + ox, 0.4f + oy);
    glVertex2f(-0.05f + ox, 0.4f + oy);
    glColor4f(0.75f, 0.75f, 0.75f, alpha);
    glVertex2f(-0.05f + ox, 0.0f + oy);
    glVertex2f(0.05f + ox, 0.0f + oy);

    glColor4f(0.75f, 0.75f, 0.75f, alpha); // left vertical upper
    glVertex2f(0.05f + ox, 0.0f + oy);
    glVertex2f(-0.05f + ox, 0.0f + oy);
    glColor4f(0.75f, 0.75f, 0.75f, alpha);
    glVertex2f(-0.05f + ox, -0.4f + oy);
    glVertex2f(0.05f + ox, -0.4f + oy);

    glColor4f(0.75f, 0.75f, 0.75f, alpha); // middle
    glVertex2f(0.2f + ox, 0.4f + oy);
    glVertex2f(-0.2f + ox, 0.4f + oy);
    glColor4f(0.75f, 0.75f, 0.75f, alpha);
    glVertex2f(-0.2f + ox, 0.3f + oy);
    glVertex2f(0.2f + ox, 0.3f + oy);

    glEnd();
}

void DrawR(float ox, float oy, float alpha)
{
    glBegin(GL_POLYGON); // upper right

    glColor4f(1.0f, 0.4039f, 0.1215f, alpha);
    glVertex2f(0.2f + ox, 0.35f + oy);
    glVertex2f(0.15f + ox, 0.4f + oy);
    glVertex2f(0.1f + ox, 0.4f + oy);
    glColor4f(1.0f, 1.0f, 1.0f, alpha);
    glVertex2f(0.1f + ox, -0.05f + oy);
    glVertex2f(0.15f + ox, -0.05f + oy);
    glVertex2f(0.2f + ox, 0.0f + oy);
    glVertex2f(0.2f + ox, 0.35f + oy);

    glEnd();

    glBegin(GL_QUADS);

    glColor4f(1.0f, 0.4039f, 0.1215f, alpha); // left vertical lower
    glVertex2f(-0.1f + ox, 0.4f + oy);
    glVertex2f(-0.2f + ox, 0.4f + oy);
    glColor4f(1.0f, 1.0f, 1.0f, alpha);
    glVertex2f(-0.2f + ox, 0.0f + oy);
    glVertex2f(-0.1f + ox, 0.0f + oy);

    glColor4f(1.0f, 1.0f, 1.0f, alpha); // middle
    glVertex2f(-0.2f + ox, 0.05f + oy);
    glVertex2f(-0.2f + ox, -0.05f + oy);
    glVertex2f(0.1f + ox, -0.05f + oy);
    glVertex2f(0.1f + ox, 0.05f + oy);

    glColor4f(1.0f, 1.0f, 1.0f, alpha); // left vertical upper
    glVertex2f(-0.1f + ox, 0.0f + oy);
    glVertex2f(-0.2f + ox, 0.0f + oy);
    glColor4f(0.0156f, 0.4156f, 0.2196f, alpha);
    glVertex2f(-0.2f + ox, -0.4f + oy);
    glVertex2f(-0.1f + ox, -0.4f + oy);

    glColor4f(1.0f, 0.4039f, 0.1215f, alpha); // upper horizontal
    glVertex2f(0.1f + ox, 0.4f + oy);
    glVertex2f(-0.2f + ox, 0.4f + oy);
    glColor4f(1.0f, 0.552f, 0.341f, alpha);
    glVertex2f(-0.2f + ox, 0.3f + oy);
    glVertex2f(0.1f + ox, 0.3f + oy);

    glColor4f(1.0f, 1.0f, 1.0f, alpha);
    glVertex2f(-0.02f + ox, 0.0f + oy);
    glVertex2f(-0.12f + ox, 0.0f + oy);
    glColor4f(0.0156f, 0.4156f, 0.2196f, alpha);
    glVertex2f(0.1f + ox, -0.4f + oy);
    glVertex2f(0.2f + ox, -0.4f + oy);

    glEnd();
}

void DrawRGrey(float ox, float oy, float alpha)
{
    glBegin(GL_POLYGON); // upper right

    glColor4f(0.75f, 0.75f, 0.75f, alpha);
    glVertex2f(0.2f + ox, 0.35f + oy);
    glVertex2f(0.15f + ox, 0.4f + oy);
    glVertex2f(0.1f + ox, 0.4f + oy);
    glColor4f(0.75f, 0.75f, 0.75f, alpha);
    glVertex2f(0.1f + ox, -0.05f + oy);
    glVertex2f(0.15f + ox, -0.05f + oy);
    glVertex2f(0.2f + ox, 0.0f + oy);
    glVertex2f(0.2f + ox, 0.35f + oy);

    glEnd();

    glBegin(GL_QUADS);

    glColor4f(0.75f, 0.75f, 0.75f, alpha); // left vertical lower
    glVertex2f(-0.1f + ox, 0.4f + oy);
    glVertex2f(-0.2f + ox, 0.4f + oy);
    glColor4f(0.75f, 0.75f, 0.75f, alpha);
    glVertex2f(-0.2f + ox, 0.0f + oy);
    glVertex2f(-0.1f + ox, 0.0f + oy);

    glColor4f(0.75f, 0.75f, 0.75f, alpha); // middle
    glVertex2f(-0.2f + ox, 0.05f + oy);
    glVertex2f(-0.2f + ox, -0.05f + oy);
    glVertex2f(0.1f + ox, -0.05f + oy);
    glVertex2f(0.1f + ox, 0.05f + oy);

    glColor4f(0.75f, 0.75f, 0.75f, alpha); // left vertical upper
    glVertex2f(-0.1f + ox, 0.0f + oy);
    glVertex2f(-0.2f + ox, 0.0f + oy);
    glColor4f(0.75f, 0.75f, 0.75f, alpha);
    glVertex2f(-0.2f + ox, -0.4f + oy);
    glVertex2f(-0.1f + ox, -0.4f + oy);

    glColor4f(0.75f, 0.75f, 0.75f, alpha); // upper horizontal
    glVertex2f(0.1f + ox, 0.4f + oy);
    glVertex2f(-0.2f + ox, 0.4f + oy);
    glColor4f(0.75f, 0.75f, 0.75f, alpha);
    glVertex2f(-0.2f + ox, 0.3f + oy);
    glVertex2f(0.1f + ox, 0.3f + oy);

    glColor4f(0.75f, 0.75f, 0.75f, alpha);
    glVertex2f(-0.02f + ox, 0.0f + oy);
    glVertex2f(-0.12f + ox, 0.0f + oy);
    glColor4f(0.75f, 0.75f, 0.75f, alpha);
    glVertex2f(0.1f + ox, -0.4f + oy);
    glVertex2f(0.2f + ox, -0.4f + oy);

    glEnd();
}

void DrawCircle(float ox, float oy, float radius)
{
    const static int NUM_OF_SEGMENTS = 100;
    const static double PI = 3.14159265358979323846;

    glBegin(GL_TRIANGLE_FAN);

    for (int i = 0; i <= NUM_OF_SEGMENTS; i++)
    {
        float theta = 2.0f * PI * (float)i / (float)NUM_OF_SEGMENTS;
        float x = radius * cos(theta);
        float y = radius * sin(theta);

        glVertex2f(x + ox, y + oy);
    }

    glEnd();
}

void DrawFighterPlane(float ox, float oy, int flameColor)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_TRIANGLES); // flame

    if (flameColor == 1)
    {
        glColor4f(1.0f, 0.4039f, 0.1215f, (float)rand() / (float)RAND_MAX);
        glVertex2f(-0.667f + ox, 0.14f + oy);

        glColor4f(1.0f, 0.4039f, 0.1215f, 0.3f);
        glVertex2f(-0.9f + ox, 0.0f + oy);

        glColor4f(1.0f, 0.4039f, 0.1215f, (float)rand() / (float)RAND_MAX);
        glVertex2f(-0.667 + ox, -0.14f + oy);

        glColor4f(1.0f, 0.4039f, 0.1215f, (float)rand() / (float)RAND_MAX);
        glVertex2f(-0.667f + ox, 0.14f + oy);

        glColor4f(1.0f, 0.4039f, 0.1215f, 0.0f);
        glVertex2f(-1.0f + ox, 0.0f + oy);

        glColor4f(1.0f, 0.4039f, 0.1215f, (float)rand() / (float)RAND_MAX);
        glVertex2f(-0.667 + ox, -0.14f + oy);

        glColor4f(1.0f, 0.4039f, 0.1215f, (float)rand() / (float)RAND_MAX);
        glVertex2f(-0.667f + ox, 0.14f + oy);

        glColor4f(1.0f, 0.4039f, 0.1215f, 0.0f);
        glVertex2f(-1.1f + ox, 0.0f + oy);

        glColor4f(1.0f, 0.4039f, 0.1215f, (float)rand() / (float)RAND_MAX);
        glVertex2f(-0.667 + ox, -0.14f + oy);
    }
    else if (flameColor == 2)
    {
        glColor4f(1.0f, 1.0f, 1.0f, (float)rand() / (float)RAND_MAX);
        glVertex2f(-0.667f + ox, 0.14f + oy);

        glColor4f(1.0f, 1.0f, 1.0f, 0.3f);
        glVertex2f(-0.9f + ox, 0.0f + oy);

        glColor4f(1.0f, 1.0f, 1.0f, (float)rand() / (float)RAND_MAX);
        glVertex2f(-0.667 + ox, -0.14f + oy);

        glColor4f(1.0f, 1.0f, 1.0f, (float)rand() / (float)RAND_MAX);
        glVertex2f(-0.667f + ox, 0.14f + oy);

        glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
        glVertex2f(-1.0f + ox, 0.0f + oy);

        glColor4f(1.0f, 1.0f, 1.0f, (float)rand() / (float)RAND_MAX);
        glVertex2f(-0.667 + ox, -0.14f + oy);

        glColor4f(1.0f, 1.0f, 1.0f, (float)rand() / (float)RAND_MAX);
        glVertex2f(-0.667f + ox, 0.14f + oy);

        glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
        glVertex2f(-1.1f + ox, 0.0f + oy);

        glColor4f(1.0f, 1.0f, 1.0f, (float)rand() / (float)RAND_MAX);
        glVertex2f(-0.667 + ox, -0.14f + oy);
    }
    else
    {
        glColor4f(0.0156f, 0.4156f, 0.2196f, (float)rand() / (float)RAND_MAX);
        glVertex2f(-0.667f + ox, 0.14f + oy);

        glColor4f(0.0156f, 0.4156f, 0.2196f, 0.3f);
        glVertex2f(-0.9f + ox, 0.0f + oy);

        glColor4f(0.0156f, 0.4156f, 0.2196f, (float)rand() / (float)RAND_MAX);
        glVertex2f(-0.667 + ox, -0.14f + oy);

        glColor4f(0.0156f, 0.4156f, 0.2196f, (float)rand() / (float)RAND_MAX);
        glVertex2f(-0.667f + ox, 0.14f + oy);

        glColor4f(0.0156f, 0.4156f, 0.2196f, 0.0f);
        glVertex2f(-1.0f + ox, 0.0f + oy);

        glColor4f(0.0156f, 0.4156f, 0.2196f, (float)rand() / (float)RAND_MAX);
        glVertex2f(-0.667 + ox, -0.14f + oy);

        glColor4f(0.0156f, 0.4156f, 0.2196f, (float)rand() / (float)RAND_MAX);
        glVertex2f(-0.667f + ox, 0.14f + oy);

        glColor4f(0.0156f, 0.4156f, 0.2196f, 0.0f);
        glVertex2f(-1.1f + ox, 0.0f + oy);

        glColor4f(0.0156f, 0.4156f, 0.2196f, (float)rand() / (float)RAND_MAX);
        glVertex2f(-0.667 + ox, -0.14f + oy);
    }

    glEnd();

    glColor3f(0.168f, 0.153f, 0.125f);
    glBegin(GL_QUADS); // upper booster

    glVertex2f(-0.667f + ox, 0.0f + oy);
    glVertex2f(-0.675f + ox, 0.14f + oy);
    glVertex2f(-0.75f + ox, 0.154f + oy);
    glVertex2f(-0.75f + ox, 0.0f + oy);

    glEnd();

    glBegin(GL_QUADS); // lower booster

    glVertex2f(-0.667f + ox, 0.0f + oy);
    glVertex2f(-0.675f + ox, -0.14f + oy);
    glVertex2f(-0.75f + ox, -0.154f + oy);
    glVertex2f(-0.75f + ox, 0.0f + oy);

    glEnd();

    glColor3f(0.286f, 0.423f, 0.6f);
    glBegin(GL_QUADS); // booster divider

    glVertex2f(-0.667f + ox, 0.0f + oy);
    glVertex2f(-0.667f + ox, 0.03f + oy);
    glVertex2f(-0.78f + ox, 0.012f + oy);
    glVertex2f(-0.78f + ox, 0.0f + oy);

    glEnd();

    glBegin(GL_QUADS); // booster divider

    glVertex2f(-0.667f + ox, 0.0f + oy);
    glVertex2f(-0.667f + ox, -0.03f + oy);
    glVertex2f(-0.78f + ox, -0.012f + oy);
    glVertex2f(-0.78f + ox, 0.0f + oy);

    glEnd();

    glBegin(GL_POLYGON);

    glVertex2f(0.42f + ox, 0.0f + oy); // upper side wing
    glVertex2f(0.42f + ox, 0.1f + oy);
    glVertex2f(0.3f + ox, 0.2f + oy);
    glVertex2f(0.16f + ox, 0.2f + oy);
    glVertex2f(-0.25f + ox, 0.65f + oy);
    glVertex2f(-0.45f + ox, 0.64f + oy);
    glVertex2f(-0.5f + ox, 0.26f + oy);
    glVertex2f(-0.5f + ox, 0.0f + oy);

    glEnd();

    glBegin(GL_POLYGON);

    glVertex2f(0.42f + ox, 0.0f + oy); // lower side wing
    glVertex2f(0.42f + ox, -0.1f + oy);
    glVertex2f(0.3f + ox, -0.2f + oy);
    glVertex2f(0.16f + ox, -0.2f + oy);
    glVertex2f(-0.25f + ox, -0.65f + oy);
    glVertex2f(-0.45f + ox, -0.64f + oy);
    glVertex2f(-0.5f + ox, -0.26f + oy);
    glVertex2f(-0.5f + ox, 0.0f + oy);

    glEnd();

    glBegin(GL_POLYGON);

    glVertex2f(-0.5f + ox, 0.0f + oy);
    glVertex2f(-0.5f + ox, 0.26f + oy); // upper side tail
    glVertex2f(-0.68f + ox, 0.46f + oy);
    glVertex2f(-0.78f + ox, 0.45f + oy);
    glVertex2f(-0.85f + ox, 0.36f + oy);
    glVertex2f(-0.84f + ox, 0.18f + oy);
    glVertex2f(-0.675f + ox, 0.14f + oy);
    glVertex2f(-0.667f + ox, 0.0f + oy);

    glEnd();

    glBegin(GL_POLYGON);

    glVertex2f(-0.5f + ox, 0.0f + oy);
    glVertex2f(-0.5f + ox, -0.26f + oy); // lower side tail
    glVertex2f(-0.68f + ox, -0.46f + oy);
    glVertex2f(-0.78f + ox, -0.45f + oy);
    glVertex2f(-0.85f + ox, -0.36f + oy);
    glVertex2f(-0.84f + ox, -0.18f + oy);
    glVertex2f(-0.675f + ox, -0.14f + oy);
    glVertex2f(-0.667f + ox, 0.0f + oy);

    glEnd();

    glBegin(GL_POLYGON);

    glVertex2f(0.86f + ox, 0.0f + oy); // upper nose
    glVertex2f(0.86f + ox, 0.011f + oy);
    glVertex2f(0.745f + ox, 0.076f + oy);
    glVertex2f(0.26f + ox, 0.1f + oy);
    glVertex2f(0.26f + ox, 0.0f + oy);

    glEnd();

    glBegin(GL_POLYGON);

    glVertex2f(0.86f + ox, 0.0f + oy); // lower nose
    glVertex2f(0.86f + ox, -0.011f + oy);
    glVertex2f(0.745f + ox, -0.076f + oy);
    glVertex2f(0.26f + ox, -0.1f + oy);
    glVertex2f(0.26f + ox, 0.0f + oy);

    glEnd();

    glColor3f(0.478f, 0.607f, 0.772f);

    glBegin(GL_TRIANGLES);

    glVertex2f(-0.45f + ox, 0.14f + oy);
    glVertex2f(-0.59f + ox, 0.29f + oy);
    glVertex2f(-0.7f + ox, 0.16f + oy);

    glEnd();

    glBegin(GL_TRIANGLES);

    glVertex2f(-0.45f + ox, -0.14f + oy);
    glVertex2f(-0.59f + ox, -0.29f + oy);
    glVertex2f(-0.7f + ox, -0.16f + oy);

    glEnd();

    glBegin(GL_QUADS);

    glVertex2f(-0.415f + ox, 0.515f + oy);
    glVertex2f(-0.46f + ox, 0.51f + oy);
    glVertex2f(-0.48f + ox, 0.39f + oy);
    glVertex2f(-0.415f + ox, 0.389f + oy);

    glEnd();

    glBegin(GL_QUADS);

    glVertex2f(-0.415f + ox, -0.515f + oy);
    glVertex2f(-0.46f + ox, -0.51f + oy);
    glVertex2f(-0.48f + ox, -0.39f + oy);
    glVertex2f(-0.415f + ox, -0.389f + oy);

    glEnd();

    glBegin(GL_QUADS);

    glVertex2f(-0.1f + ox, 0.465f + oy);
    glVertex2f(-0.135f + ox, 0.43f + oy);
    glVertex2f(0.036f + ox, 0.25f + oy);
    glVertex2f(0.07f + ox, 0.29f + oy);

    glEnd();

    glBegin(GL_QUADS);

    glVertex2f(-0.1f + ox, -0.465f + oy);
    glVertex2f(-0.135f + ox, -0.43f + oy);
    glVertex2f(0.036f + ox, -0.25f + oy);
    glVertex2f(0.07f + ox, -0.29f + oy);

    glEnd();

    glColor3f(0.168f, 0.153f, 0.125f);
    glBegin(GL_QUADS);

    glVertex2f(0.12f + ox, 0.135f + oy);
    glVertex2f(0.1f + ox, 0.135f + oy);
    glVertex2f(0.1f + ox, 0.065f + oy);
    glVertex2f(0.12f + ox, 0.065f + oy);

    glEnd();

    glBegin(GL_QUADS);

    glVertex2f(0.12f + ox, -0.135f + oy);
    glVertex2f(0.1f + ox, -0.135f + oy);
    glVertex2f(0.1f + ox, -0.065f + oy);
    glVertex2f(0.12f + ox, -0.065f + oy);

    glEnd();

    glBegin(GL_QUADS);

    glVertex2f(-0.11f + ox, 0.12f + oy);
    glVertex2f(-0.335f + ox, 0.12f + oy);
    glVertex2f(-0.335f + ox, 0.1f + oy);
    glVertex2f(-0.11f + ox, 0.1f + oy);

    glEnd();

    glBegin(GL_QUADS);

    glVertex2f(-0.11f + ox, -0.12f + oy);
    glVertex2f(-0.335f + ox, -0.12f + oy);
    glVertex2f(-0.335f + ox, -0.1f + oy);
    glVertex2f(-0.11f + ox, -0.1f + oy);

    glEnd();

    glBegin(GL_POLYGON);

    glVertex2f(0.65f + ox, 0.0f + oy);
    glVertex2f(0.645f + ox, 0.015f + oy);
    glVertex2f(0.635f + ox, 0.025f + oy);
    glVertex2f(0.62f + ox, 0.035f + oy);
    glVertex2f(0.38f + ox, 0.035f + oy);
    glVertex2f(0.365f + ox, 0.03f + oy);
    glVertex2f(0.355f + ox, 0.02f + oy);
    glVertex2f(0.345f + ox, 0.0f + oy);

    glEnd();

    glBegin(GL_POLYGON);

    glVertex2f(0.65f + ox, 0.0f + oy);
    glVertex2f(0.645f + ox, -0.015f + oy);
    glVertex2f(0.635f + ox, -0.025f + oy);
    glVertex2f(0.62f + ox, -0.035f + oy);
    glVertex2f(0.38f + ox, -0.035f + oy);
    glVertex2f(0.365f + ox, -0.03f + oy);
    glVertex2f(0.355f + ox, -0.02f + oy);
    glVertex2f(0.345f + ox, 0.0f + oy);

    glEnd();

    // upper side insignia
    glColor3f(1.0f, 0.392f, 0.0f);
    DrawCircle(-0.27f + ox, 0.45f + oy, 0.09f);

    glColor3f(1.0f, 1.0f, 1.0f);
    DrawCircle(-0.27f + ox, 0.45f + oy, 0.06f);

    glColor3f(0.0f, 0.396f, 0.239f);
    DrawCircle(-0.27f + ox, 0.45f + oy, 0.03f);

    // lower side insignia
    glColor3f(1.0f, 0.392f, 0.0f);
    DrawCircle(-0.27f + ox, -0.45f + oy, 0.09f);

    glColor3f(1.0f, 1.0f, 1.0f);
    DrawCircle(-0.27f + ox, -0.45f + oy, 0.06f);

    glColor3f(0.0f, 0.396f, 0.239f);
    DrawCircle(-0.27f + ox, -0.45f + oy, 0.03f);
}

// void DrawBharat(float ox, float oy)
// {
//     DrawB(-1.25f + ox, 0.0f + oy);
//     DrawH(-0.75f + ox, 0.0f + oy);
//     DrawA(-0.25f + ox, 0.0f + oy);
//     DrawR(0.25f + ox, 0.0f + oy);
//     DrawA(0.75f + ox, 0.0f + oy);
//     DrawT(1.25f + ox, 0.0f + oy);
// }

void DrawHorizontalLines(float ox, float oy)
{
    glLineWidth(3.0f);

    glBegin(GL_LINES); // middle red thick line

    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(-1.0f + ox, 0.0f + oy);
    glVertex2f(1.0f + ox, 0.0f + oy);

    glEnd();

    glLineWidth(1.0f);

    glBegin(GL_LINES); // upper 20 and lower 20 blue lines with normal thickness

    glColor3f(0.0f, 0.0f, 1.0f);

    for (float space = 0.0f; space <= 1.0f; space = space + 0.05f)
    {
        glVertex2f(-1.65f + ox, 0.05f + oy + space);
        glVertex2f(1.65f + ox, 0.05f + oy + space);

        glVertex2f(-1.65f + ox, -0.05f + oy + (-space));
        glVertex2f(1.65f + ox, -0.05f + oy + (-space));
    }

    glEnd();
}

void DrawVerticalLines(float ox, float oy)
{
    glLineWidth(3.0f);

    glBegin(GL_LINES);

    glColor3f(0.0f, 1.0f, 0.0f);

    glVertex2f(0.0f + ox, 1.0f + oy);
    glVertex2f(0.0f + ox, -1.0f + oy);

    glEnd();

    glLineWidth(1.0f);

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 1.0f);

    for (float space = 0.0f; space <= 1.6f; space = space + 0.05f)
    {
        glVertex2f(0.05f + ox + space, 1.0f + oy);
        glVertex2f(0.05f + ox + space, -1.0f + oy);

        glVertex2f(-0.05f + ox + (-space), 1.0f + oy);
        glVertex2f(-0.05f + ox + (-space), -1.0f + oy);
    }

    glEnd();
}

void DrawGraphPaper(float ox, float oy)
{
    DrawVerticalLines(ox, oy);
    DrawHorizontalLines(ox, oy);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// float animatePlaneXAxis = -4.5f;

float transformationXLetterB = -3.5f;

float transformationXLetterH = -3.3f;
float transformationYLetterH = 3.3f;

float transformationXLetterA1 = -3.3f;
float transformationYLetterA1 = -3.3f;

float transformationXLetterR = 3.3f;
float transformationYLetterR = 3.3f;

float transformationXLetterA2 = 3.3f;
float transformationYLetterA2 = -3.3f;

float transformationXLetterT = 3.5f;

float plane1FinalXCoordinate;
float plane1FinalYCoordinate;
float plane1StartingTransformation = 0.0f;
float plane1MiddleTransformation = 0.0f;
float plane1EndingTransformation = 0.0f;

float plane3FinalXCoordinate;
float plane3FinalYCoordinate;
float plane3StartingTransformation = 0.0f;
float plane3MiddleTransformation = 0.0f;
float plane3EndingTransformation = 0.0f;

float plane1Angle = 180.0f;
float planeScalef = 0.15f;
float planeTransformationSpeed = 0.0005;

float letterBAlpha = 0.0f;
float letterHAlpha = 0.0f;
float letterA1Alpha = 0.0f;
float letterRAlpha = 0.0f;
float letterA2Alpha = 0.0f;
float letterTAlpha = 0.0f;

int index = 0;
struct Point2D plane1PathArr[1000000];
struct Point2D plane2PathArr[1000000];
struct Point2D plane3PathArr[1000000];

void drawLine()
{
    // glPointSize(100);
    glBegin(GL_POINTS);

    glColor3f(1.0f, 1.0f, 1.0f);

    for (int i = 0; i < index; i++)
    {
        // printf("%f:%f:%d\n", plane1PathArr[i].x, plane1PathArr[i].y, index);
        plane2PathArr[i].y = 0.0f;
        glVertex2f(plane1PathArr[i].x, plane1PathArr[i].y);
    }

    for (int i = 0; i < index; i++)
    {
        // printf("%f:%f:%d\n", plane2PathArr[i].x, plane2PathArr[i].y, index);
        glVertex2f(plane2PathArr[i].x, plane2PathArr[i].y);
    }

    for (int i = 0; i < index; i++)
    {
        // printf("%f:%f:%d\n", plane3PathArr[i].x, plane3PathArr[i].y, index);
        glVertex2f(plane3PathArr[i].x, plane3PathArr[i].y);
    }

    glEnd();
}

void displayAnimation()
{
    glPushMatrix();

    glScalef(0.365, 0.365, 0.0f);

    DrawBGrey(-1.25f + transformationXLetterB, 0.0f, 1.0f);
    DrawB(-1.25f + transformationXLetterB, 0.0f, letterBAlpha);

    DrawHGrey(-0.75f + transformationXLetterH, 0.0f + transformationYLetterH, 1.0f);
    DrawH(-0.75f + transformationXLetterH, 0.0f + transformationYLetterH, letterHAlpha);

    DrawAGrey(-0.25f + transformationXLetterA1, 0.0f + transformationYLetterA1, 1.0f);
    DrawA(-0.25f + transformationXLetterA1, 0.0f + transformationYLetterA1, letterA1Alpha);

    DrawRGrey(0.25f + transformationXLetterR, 0.0f + transformationYLetterR, 1.0f);
    DrawR(0.25f + transformationXLetterR, 0.0f + transformationYLetterR, letterRAlpha);

    DrawAGrey(0.75f + transformationXLetterA2, 0.0f + transformationYLetterA2, 1.0f);
    DrawA(0.75f + transformationXLetterA2, 0.0f + transformationYLetterA2, letterA2Alpha);

    DrawTGrey(1.25f + transformationXLetterT, 0.0f, 1.0f);
    DrawT(1.25f + transformationXLetterT, 0.0f, letterTAlpha);

    glPopMatrix();

    struct Point2D plane1StartingA1 = {-1.95f / planeScalef, 1.0f / planeScalef};
    struct Point2D plane1StartingB1 = {-1.1268f / planeScalef, 0.1249f / planeScalef};
    struct Point2D plane1StartingC1 = {-0.55f / planeScalef, 0.13f / planeScalef};

    struct Point2D plane1BazierStaringTransformation = quadraticBezier(plane1StartingA1, plane1StartingB1, plane1StartingC1, plane1StartingTransformation); // for plane 1 starting transformation
    plane1FinalXCoordinate = plane1BazierStaringTransformation.x;
    plane1FinalYCoordinate = plane1BazierStaringTransformation.y;


    if (plane1FinalXCoordinate >= -(0.55f / planeScalef) && plane1FinalXCoordinate <= 0.55f / planeScalef)
    {
        struct Point2D plane1MiddleA1 = {-0.55f / planeScalef, 0.13f / planeScalef};
        struct Point2D plane1MiddleB1 = {0.0f / planeScalef, 0.13f / planeScalef};
        struct Point2D plane1MiddleC1 = {0.55f / planeScalef, 0.13f / planeScalef};

        struct Point2D plane1BazierMiddleTransformation = quadraticBezier(plane1MiddleA1, plane1MiddleB1, plane1MiddleC1, plane1MiddleTransformation); // for plane 1 middle transformation
        plane1FinalXCoordinate = plane1BazierMiddleTransformation.x;
        plane1FinalYCoordinate = plane1BazierMiddleTransformation.y;
    }

    if (plane1FinalXCoordinate >= 0.55f / planeScalef)
    {
        struct Point2D plane1EndingA1 = {0.55f / planeScalef, 0.13f / planeScalef};
        struct Point2D plane1EndingB1 = {1.1268f / planeScalef, 0.1249f / planeScalef};
        struct Point2D plane1EndingC1 = {1.95f / planeScalef, 1.0f / planeScalef};

        struct Point2D plane1BazierEndingTransformation = quadraticBezier(plane1EndingA1, plane1EndingB1, plane1EndingC1, plane1EndingTransformation); // for plane 1 ending transformation
        plane1FinalXCoordinate = plane1BazierEndingTransformation.x;
        plane1FinalYCoordinate = plane1BazierEndingTransformation.y;
    }
    // printf("X: %f || Y: %f\n", plane1FinalXCoordinate, plane1FinalYCoordinate);


    ////////

    struct Point2D plane3StartingA1 = {-1.95f / planeScalef, -1.0f / planeScalef};
    struct Point2D plane3StartingB1 = {-1.1268f / planeScalef, -0.1249f / planeScalef};
    struct Point2D plane3StartingC1 = {-0.55f / planeScalef, -0.13f / planeScalef};

    struct Point2D plane3BazierStaringTransformation = quadraticBezier(plane3StartingA1, plane3StartingB1, plane3StartingC1, plane3StartingTransformation); // for plane 2 starting transformation
    plane3FinalXCoordinate = plane3BazierStaringTransformation.x;
    plane3FinalYCoordinate = plane3BazierStaringTransformation.y;

    if (plane3FinalXCoordinate >= -(0.55f / planeScalef) && plane3FinalXCoordinate <= 0.55f / planeScalef)
    {
        struct Point2D plane3MiddleA1 = {-0.55f / planeScalef, -0.13f / planeScalef};
        struct Point2D plane3MiddleB1 = {0.0f / planeScalef, -0.13f / planeScalef};
        struct Point2D plane3MiddleC1 = {0.55f / planeScalef, -0.13f / planeScalef};

        struct Point2D plane3BazierMiddleTransformation = quadraticBezier(plane3MiddleA1, plane3MiddleB1, plane3MiddleC1, plane3MiddleTransformation); // for plane 2 middle transformation
        plane3FinalXCoordinate = plane3BazierMiddleTransformation.x;
        plane3FinalYCoordinate = plane3BazierMiddleTransformation.y;
    }

    if (plane3FinalXCoordinate >= 0.55f / planeScalef)
    {
        struct Point2D plane3EndingA1 = {0.55f / planeScalef, -0.13f / planeScalef};
        struct Point2D plane3EndingB1 = {1.1268f / planeScalef, -0.1249f / planeScalef};
        struct Point2D plane3EndingC1 = {1.95f / planeScalef, -1.0f / planeScalef};

        struct Point2D plane3BazierEndingTransformation = quadraticBezier(plane3EndingA1, plane3EndingB1, plane3EndingC1, plane3EndingTransformation); // for plane 2 ending transformation
        plane3FinalXCoordinate = plane3BazierEndingTransformation.x;
        plane3FinalYCoordinate = plane3BazierEndingTransformation.y;
    }

    plane1PathArr[index].x = plane1FinalXCoordinate;
    plane1PathArr[index].y = plane1FinalYCoordinate;
    plane2PathArr[index].x = plane1FinalXCoordinate;
    plane2PathArr[index].y = 0.0f;
    plane3PathArr[index].x = plane3FinalXCoordinate;
    plane3PathArr[index].y = plane3FinalYCoordinate;
    index++;

    glPushMatrix();

    glScalef(planeScalef, planeScalef, 0.0f);
    // drawLine();
    DrawFighterPlane(plane1FinalXCoordinate, plane1FinalYCoordinate, 1);
    DrawFighterPlane(plane3FinalXCoordinate, plane3FinalYCoordinate, 3);
    DrawFighterPlane(plane1FinalXCoordinate + 1.0f, 0.0f, 2);

    glPopMatrix();
}

void updateAnimation()
{
    // const static float animationSpeed = 0.0025f;
    const static float animationSpeed = 0.004f;

    if (GetTimeInSeconds() >= 68.0f)
        bDone = TRUE;

    // code
    if (transformationXLetterB <= 0.0f) // B
    {
        transformationXLetterB += animationSpeed;

        if (transformationXLetterB > 0.0f)
        {
            transformationXLetterB = 0.0f;
        }
    }

    if (transformationXLetterB >= 0.0f) // H
    {
        if (transformationXLetterH <= 0.0f)
        {
            transformationXLetterH += animationSpeed;

            if (transformationXLetterH > 0.0f)
            {
                transformationXLetterH = 0.0f;
            }
        }

        if (transformationYLetterH >= 0.0f)
        {
            transformationYLetterH -= animationSpeed;

            if (transformationYLetterH < 0.0f)
            {
                transformationYLetterH = 0.0f;
            }
        }
    }

    if (transformationXLetterH >= 0.0f) // A
    {
        if (transformationXLetterA1 <= 0.0f)
        {
            transformationXLetterA1 += animationSpeed;

            if (transformationXLetterA1 > 0.0f)
            {
                transformationXLetterA1 = 0.0f;
            }
        }

        if (transformationYLetterA1 <= 0.0f)
        {
            transformationYLetterA1 += animationSpeed;

            if (transformationYLetterA1 > 0.0f)
            {
                transformationYLetterA1 = 0.0f;
            }
        }
    }

    if (transformationXLetterA1 >= 0.0f) // R
    {
        if (transformationXLetterR >= 0.0f)
        {
            transformationXLetterR -= animationSpeed;

            if (transformationXLetterR < 0.0f)
            {
                transformationXLetterR = 0.0f;
            }
        }

        if (transformationYLetterR >= 0.0f)
        {
            transformationYLetterR -= animationSpeed;

            if (transformationYLetterR < 0.0f)
            {
                transformationYLetterR = 0.0f;
            }
        }
    }

    if (transformationXLetterR <= 0.0f) // A
    {
        if (transformationXLetterA2 >= 0.0f)
        {
            transformationXLetterA2 -= animationSpeed;

            if (transformationXLetterA2 < 0.0f)
            {
                transformationXLetterA2 = 0.0f;
            }
        }

        if (transformationYLetterA2 <= 0.0f)
        {
            transformationYLetterA2 += animationSpeed;

            if (transformationYLetterA2 > 0.0f)
            {
                transformationYLetterA2 = 0.0f;
            }
        }
    }

    if (transformationXLetterA2 <= 0.0f) // T
    {
        if (transformationXLetterT >= 0.0f)
        {
            transformationXLetterT -= animationSpeed;

            if (transformationXLetterT < 0.0f)
            {
                transformationXLetterT = 0.0f;
            }
        }
    }

    if (transformationXLetterT <= 0.0f)
    {
        // plane 1
        if (plane1FinalXCoordinate <= -0.55f / planeScalef) // starting
        {
            plane1StartingTransformation += planeTransformationSpeed;
        }

        if (plane1FinalXCoordinate >= 0.55f / planeScalef) // ending
        {
            plane1EndingTransformation += planeTransformationSpeed;
        }

        if (plane1FinalXCoordinate >= -(0.55f / planeScalef) && plane1FinalXCoordinate <= 0.55f / planeScalef) // middle
        {
            plane1MiddleTransformation += planeTransformationSpeed;
        }

        /////////////////
        // color animation of BHARAT
        if (plane1FinalXCoordinate >= -(0.55 - 0.16175) / planeScalef)
        {
            letterBAlpha += calculateIncrementPerFrame(0.0f, 1.0f, 0.1294, planeTransformationSpeed);
        }

        if (plane1FinalXCoordinate >= -(0.3559 - 0.16175) / planeScalef)
        {
            letterHAlpha += calculateIncrementPerFrame(0.0f, 1.0f, 0.1294, planeTransformationSpeed);
        }

        if (plane1FinalXCoordinate >= -(0.1618 - 0.16175) / planeScalef)
        {
            letterA1Alpha += calculateIncrementPerFrame(0.0f, 1.0f, 0.1294, planeTransformationSpeed);
        }

        if (plane1FinalXCoordinate >= (0.0324 + 0.16175) / planeScalef)
        {
            letterRAlpha += calculateIncrementPerFrame(0.0f, 1.0f, 0.1294, planeTransformationSpeed);
        }

        if (plane1FinalXCoordinate >= (0.2265 + 0.16175) / planeScalef)
        {
            letterA2Alpha += calculateIncrementPerFrame(0.0f, 1.0f, 0.1294, planeTransformationSpeed);
        }

        if (plane1FinalXCoordinate >= (0.4205) / planeScalef)
        {
            letterTAlpha += calculateIncrementPerFrame(0.0f, 1.0f, 0.1294, planeTransformationSpeed);
        }

        ////////////////////

        // plane 3
        if (plane3FinalXCoordinate <= -0.55f / planeScalef) // starting
        {
            plane3StartingTransformation += planeTransformationSpeed;
        }

        if (plane3FinalXCoordinate >= 0.55f / planeScalef) // ending
        {
            plane3EndingTransformation += planeTransformationSpeed;
        }

        if (plane3FinalXCoordinate >= -(0.55f / planeScalef) && plane3FinalXCoordinate <= 0.55f / planeScalef) // middle
        {
            plane3MiddleTransformation += planeTransformationSpeed;
        }
    }
}

void display(void)
{
    // code
    // clear OpenGL buffers
    glClear(GL_COLOR_BUFFER_BIT);

    // set matrix to model view mode
    glMatrixMode(GL_MODELVIEW);

    // set it to identity matrix
    glLoadIdentity();

    // translate triangle backwards by Z
    glTranslatef(0.0f, 0.0f, -2.5f);

    // DrawGraphPaper(0.0f, 0.0f);

    displayAnimation();

    // swap the buffers
    SwapBuffers(ghdc);
}

void update(void)
{
    // const static float animationSpeed = 0.0025f;
    updateAnimation();
}

void uninitialize(void)
{
    // function declarations
    void toggleFullScreen(void);

    // code
    // if user is exiting in full screen then restore full screen back to normal
    if (gbFullScreen == TRUE)
    {
        toggleFullScreen();
        gbFullScreen = FALSE;
    }

    // make hdc and current contex by releasing rendering contex as current contex
    if (wglGetCurrentContext() == ghrc)
    {
        wglMakeCurrent(NULL, NULL);
    }

    // delete the rendering contex
    if (ghrc)
    {
        wglDeleteContext(ghrc);
        ghrc = NULL;
    }

    // release the DC
    if (ghdc)
    {
        ReleaseDC(ghwnd, ghdc);
        ghdc = NULL;
    }

    // destroy window
    if (ghwnd)
    {
        DestroyWindow(ghwnd);
        ghwnd = NULL;
    }

    // close the file
    fprintf(gpFile, "Program terminated successfully\n");
    if (gpFile)
    {
        fclose(gpFile);
        gpFile = NULL;
    }
}
