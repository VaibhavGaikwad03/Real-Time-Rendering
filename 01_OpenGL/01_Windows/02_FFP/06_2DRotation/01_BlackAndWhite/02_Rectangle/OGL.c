// श्री स्वामी समर्थ
// Win32 headers
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

// custom header file
#include "OGL.h"

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

// rotation angles
GLfloat angleRectangle = 0.0f;

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
    BOOL bDone = FALSE;

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
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
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
    }
    else
    {
        SetWindowPlacement(&wpPrev, SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW));
        SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);
        ShowCursor(TRUE);
    }
}

int initialize(void)
{
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

void display(void)
{
    // code
    // clear OpenGL buffers
    glClear(GL_COLOR_BUFFER_BIT);

    // triangle
    // set matrix to model view mode
    glMatrixMode(GL_MODELVIEW);

    // rectangle
    // set it to identity matrix
    glLoadIdentity();

    // translate triangle backwards by Z
    glTranslatef(0.0f, 0.0f, -6.0f);

    glRotatef(angleRectangle, 1.0f, 0.0f, 0.0f);

    // triangle drawing code
    glBegin(GL_QUADS);

    glVertex3f(1.0f, 1.0f, 0.0f);

    glVertex3f(-1.0f, 1.0f, 0.0f);

    glVertex3f(-1.0f, -1.0f, 0.0f);

    glVertex3f(1.0f, -1.0f, 0.0f);

    glEnd();

    // swap the buffers
    SwapBuffers(ghdc);
}

void update(void)
{
    // code

    angleRectangle = angleRectangle - 0.1f;
    if (angleRectangle <= 0.0f)
    {
        angleRectangle = angleRectangle + 360.0f;
    }
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
