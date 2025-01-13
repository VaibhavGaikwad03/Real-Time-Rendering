#include <GL/freeglut.h>
#include <math.h> // For sin() and cos()
#include <stdbool.h>

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

    void DrawEggWhite(float, float, float);
    void DrawEggYolk(float, float, float);
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

void DrawHighlightArc(float x, float y)
{
    // variable declarations
    float start_angle = M_PI / 4;
    float end_angle = (3 * M_PI) / 4;
    float arc_radius = 0.2f * 0.70f;

    // code
    glColor3f(1.0f, 1.0f, 1.0f);

    glLineWidth(5.0f);
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

void DrawEggWhite(float x, float y, float radius)
{
    // code
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);

    for (int i = 0; i <= 150; ++i)
    {
        float angle = 2.0f * M_PI * i / 150;
        float smooth_offset = radius * 0.07f * sin(3 * angle) + radius * 0.03f * cos(7 * angle);
        float dx = (radius + smooth_offset) * cos(angle);
        float dy = (radius + smooth_offset) * sin(angle);
        glVertex2f(x + dx, y + dy);
    }

    glEnd();
}

void DrawEggYolk(float x, float y, float radius)
{
    // code
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);

    for (int i = 0; i <= 100; ++i)
    {
        float angle = 2.0f * M_PI * i / 100;
        float dx = radius * cos(angle);
        float dy = radius * sin(angle);
        glVertex2f(x + dx, y + dy);
    }

    glEnd();
}

void display()
{
    // code
    glClear(GL_COLOR_BUFFER_BIT);

    DrawEggWhite(0.0f, 0.0f, 0.5f);

    DrawEggYolk(0.0f, 0.0f, 0.2f);

    DrawHighlightArc(0.0f, 0.0f);

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
