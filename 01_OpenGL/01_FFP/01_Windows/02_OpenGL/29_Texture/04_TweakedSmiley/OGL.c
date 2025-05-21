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

// texture related global variables
GLuint texture_smiley;

int keyValue;

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

        case '1':
            keyValue = 1;
            break;

        case '2':
            keyValue = 2;
            break;

        case '3':
            keyValue = 3;
            break;

        case '4':
            keyValue = 4;
            break;

        default:
            keyValue = 0;
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
    AllocConsole();
    freopen("CONOUT$", "w", stdout);

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

    pfd.cDepthBits = 32;

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

    // depth related code
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    // from here onward the OpenGL code starts
    // tell OpenGL to choose the colour to clear the screen
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // load smiley texture
    if (loadGLTexture(&texture_smiley, MAKEINTRESOURCE(IDBITMAP_SMILEY)) == FALSE)
    {
        fprintf(gpFile, "loadGLTexture() failed to load the smiley texture\n");
        return -6;
    }

    // enable texturing
    glEnable(GL_TEXTURE_2D);

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

BOOL loadGLTexture(GLuint *texture, TCHAR imageResourceID[])
{
    // variable declarations
    HBITMAP hBitmap = NULL;
    BITMAP bmp;
    BOOL bResult = FALSE;

    // code
    // load the bitmap as image
    hBitmap = (HBITMAP)LoadImage(GetModuleHandle(NULL), imageResourceID, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
    if (hBitmap)
    {
        bResult = TRUE;

        // get bitmap structure from the loaded bitmap image
        GetObject(hBitmap, sizeof(BITMAP), &bmp);

        // generate OpenGL texture object
        glGenTextures(1, texture);

        // bind to the newly created texture object
        glBindTexture(GL_TEXTURE_2D, *texture);

        // unpack the image in memory for faster loading
        glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

        gluBuild2DMipmaps(GL_TEXTURE_2D, 3, bmp.bmWidth, bmp.bmHeight, GL_BGR_EXT, GL_UNSIGNED_BYTE, bmp.bmBits);

        glBindTexture(GL_TEXTURE_2D, 0);

        DeleteObject(hBitmap);
        hBitmap = NULL;

        return bResult;
    }

    return bResult;
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set matrix to model view mode
    glMatrixMode(GL_MODELVIEW);

    // set it to identity matrix
    glLoadIdentity();

    // translate triangle backwards by Z
    glTranslatef(0.0f, 0.0f, -3.0f);

    // triangle drawing code

    if (keyValue == 1)
    {
        // key press 1
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture_smiley);

        glBegin(GL_QUADS);

        glTexCoord2f(0.5f, 0.5f);
        glVertex3f(1.0f, 1.0f, 0.0f);

        glTexCoord2f(0.0f, 0.5f);
        glVertex3f(-1.0f, 1.0f, 0.0f);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 0.0f);

        glTexCoord2f(0.5f, 0.0f);
        glVertex3f(1.0f, -1.0f, 0.0f);

        glEnd();
    }
    else if (keyValue == 2)
    {
        // key press 2
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture_smiley);

        glBegin(GL_QUADS);

        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 0.0f);

        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 0.0f);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 0.0f);

        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 0.0f);

        glEnd();
    }
    else if (keyValue == 3)
    {
        // key press 3
        // first quadrant
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture_smiley);

        glBegin(GL_QUADS);

        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 0.0f);

        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);

        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1.0f, 0.0f, 0.0f);

        // second quadrant
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);

        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 0.0f);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-1.0f, 0.0f, 0.0f);

        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);

        // third quadrant
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);

        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-1.0f, 0.0f, 0.0f);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 0.0f);

        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(0.0f, -1.0f, 0.0f);

        // forth quadrant
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(1.0f, 0.0f, 0.0f);

        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(0.0f, -1.0f, 0.0f);

        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 0.0f);

        glEnd();
    }
    else if (keyValue == 4)
    {
        // key press 4
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture_smiley);

        glBegin(GL_QUADS);

        glTexCoord2f(0.25f, 0.25f);
        glVertex3f(1.0f, 1.0f, 0.0f);

        glTexCoord2f(0.25f, 0.25f);
        glVertex3f(-1.0f, 1.0f, 0.0f);

        glTexCoord2f(0.25f, 0.25f);
        glVertex3f(-1.0f, -1.0f, 0.0f);

        glTexCoord2f(0.25f, 0.25f);
        glVertex3f(1.0f, -1.0f, 0.0f);

        glEnd();
    }
    else
    {
        glDisable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        
        glVertex3f(1.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 0.0f);

        glEnd();
    }

    glBindTexture(GL_TEXTURE_2D, 0);

    // swap the buffers
    SwapBuffers(ghdc);
}

void update(void)
{
    // code
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

    if (texture_smiley)
    {
        glDeleteTextures(1, &texture_smiley);
        texture_smiley = 0;
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
