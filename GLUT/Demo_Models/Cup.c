#include <GL/freeglut.h>
#include <math.h> // For sin() and cos()
#include <stdbool.h>

enum CUP_HANDLE_DIRECTION
{
    UP = 1,
    DOWN,
    RIGHT,
    LEFT
};

#define CUP_OUTER_RADIUS 0.1f
#define CUP_INNER_RADIUS 0.08f
#define M_PI 3.14159265358979323846

// global variable
bool bFullScreen = false;

// entry-point function
int main(int argc, char *argv[])
{
    // local function declarations
    void initialize(void);
    void resize(int, int);
    void display(void);
    void keyboard(unsigned char, int, int);
    void mouse(int, int, int, int);
    void uninitialize(void);

    void DrawCoffee(float, float);
    void DrawCupOuterBody(float, float);
    void DrawCupInnerBody(float, float);
    void DrawCupHandle(int);

    void DrawHighlightArc(float, float);

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

void initialize()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void resize(int width, int height)
{
    glViewport(0, 0, width, height);
}

void DrawCoffee(float x, float y)
{
    // code
    glColor3f(0.65f, 0.25f, 0.19f);

    glBegin(GL_POLYGON);

    for (int i = 0; i < 100; i++)
    {
        float angle = 2.0f * M_PI * i / 100;
        float dx = (CUP_INNER_RADIUS - 0.013f) * cos(angle);
        float dy = (CUP_INNER_RADIUS - 0.013f) * sin(angle);
        glVertex2f(x + dx, y + dy);
    }

    glEnd();
}

void DrawCupInnerBody(float x, float y)
{
    // variable declarations

    // code
    // glColor3f(0.65f, 0.25f, 0.19f);
    glColor3f(0.8f, 0.8f, 0.8f);

    glBegin(GL_POLYGON);

    for (int i = 0; i < 100; i++)
    {
        float angle = 2.0f * M_PI * i / 100;
        float dx = CUP_INNER_RADIUS * cos(angle);
        float dy = CUP_INNER_RADIUS * sin(angle);
        glVertex2f(x + dx, y + dy);
    }

    glEnd();
}

void DrawCupOuterBody(float x, float y)
{
    // code
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_POLYGON);

    for (int i = 0; i < 100; i++)
    {
        float angle = 2.0f * M_PI * i / 100;
        float dx = CUP_OUTER_RADIUS * cos(angle);
        float dy = CUP_OUTER_RADIUS * sin(angle);
        glVertex2f(x + dx, y + dy);
    }

    glEnd();
}

void DrawCupHandle(int direction)
{
    // code
    if (direction < 1 || direction > 4)
        return;

    glColor3f(1.0f, 1.0f, 1.0f);

    glLineWidth(10.0f);

    glEnable(GL_LINE_SMOOTH);

    glBegin(GL_LINES);

    if (direction == UP)
    {
        glVertex2f(0.0f, CUP_OUTER_RADIUS);         // Start point
        glVertex2f(0.0f, 0.05f + CUP_OUTER_RADIUS); // End point
    }
    else if (direction == DOWN)
    {
        glVertex2f(0.0f, -CUP_OUTER_RADIUS);         // Start point
        glVertex2f(0.0f, -0.05f - CUP_OUTER_RADIUS); // End point
    }
    else if (direction == RIGHT)
    {
        glVertex2f(CUP_OUTER_RADIUS, 0.0f);         // Start point
        glVertex2f(0.05f + CUP_OUTER_RADIUS, 0.0f); // End point
    }
    else
    {
        glVertex2f(-CUP_OUTER_RADIUS, 0.0f);         // Start point
        glVertex2f(-0.05f - CUP_OUTER_RADIUS, 0.0f); // End point
    }

    glEnd();

    glDisable(GL_LINE_SMOOTH);
}

void DrawHighlightArc(float x, float y)
{
    // variable declarations
    float start_angle = M_PI / 4;
    float end_angle = (3 * M_PI) / 4;
    float arc_radius = CUP_INNER_RADIUS * 0.70f;

    // code
    glColor3f(1.0f, 1.0f, 1.0f);

    glLineWidth(2.0f);
    glBegin(GL_LINE_STRIP);

    for (int i = 0; i <= 50; i++)
    {
        float angle = start_angle + (end_angle - start_angle) * i / 50;
        float dx = arc_radius * cos(angle);
        float dy = arc_radius * sin(angle);
        glVertex2f(x + dx, y + dy);
    }

    glEnd();
}

void display()
{
    // code
    glClear(GL_COLOR_BUFFER_BIT);

    DrawCupOuterBody(0.0f, 0.0f);

    DrawCupInnerBody(0.0f, 0.0f);

    DrawCoffee(0.0f, 0.0f);

    DrawHighlightArc(0.0f, 0.0f);

    DrawCupHandle(LEFT);

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    // code
    switch (key)
    {
    case 27: // escape key
        glutLeaveMainLoop();
        break;

    case 'F':
    case 'f':
        if (!bFullScreen)
        {
            glutFullScreen();
            bFullScreen = true;
        }
        else
        {
            glutLeaveFullScreen();
            bFullScreen = false;
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

void uninitialize()
{
    // code
}