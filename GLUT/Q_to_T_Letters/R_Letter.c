// header files
#include <GL/freeglut.h>

// global variable declarations
BOOL bFullScreen = FALSE;

// entry-point function
int main(int argc, char *argv[])
{
    // local function declarations
    int initialize(void);
    void resize(int, int);
    void display(void);
    void keyboard(unsigned char, int, int);
    void mouse(int, int, int, int);
    void uninitialize(void);

    // code
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Vaibhav Tukaram Gaikwad");

    initialize();

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutCloseFunc(uninitialize);

    glutMainLoop();

    return (0);
}

int initialize(void)
{
    // code
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    return (0);
}

void resize(int width, int height)
{
    // code
    glViewport(0, 0, width, height);
}

void display(void)
{
    // code
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);

    // uppper line
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.9f, 1.0f); // upper right point

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.1f, 1.0f); // upper left point

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.1f, 0.8f); // lower left point

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.9f, 0.8f); // lower right point

    // left line
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.1f, 1.0f); // upper right point

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.1f, 1.0f); // upper left point

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.1f, -1.0f); // lower left point

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.1f, -1.0f); // lower right point

    // lower line
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.9f, 0.1f); // upper right point

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.1f, 0.1f); // upper left point

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.1f, -0.1f); // lower left point

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.9f, -0.1f); // lower right point

    // right line
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.9f, 1.0f); // upper right point

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.7f, 1.0f); // upper left point

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.7f, 0.1f); // lower left point

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.9f, -0.1f); // lower right point

    // pota madhli line
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(1.0f, -1.0f); // upper right point

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.1f, 0.1f); // upper left point

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.0f, -0.1f); // lower left point

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.8f, -1.0f); // lower right point

    glEnd();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    // code
    switch (key)
    {
    case 27:
        glutLeaveMainLoop();
        break;

    case 'F':
    case 'f':
        if (bFullScreen == FALSE)
        {
            glutFullScreen();
            bFullScreen = TRUE;
        }
        else
        {
            glutLeaveFullScreen();
            bFullScreen = FALSE;
        }
        break;
    default:
        break;
    }
}

void mouse(int button, int state, int x, int y)
{
    // code
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        glutLeaveMainLoop();
        break;

    default:
        break;
    }
}

void uninitialize(void)
{
    // code
}
