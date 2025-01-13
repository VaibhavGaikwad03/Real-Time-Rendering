#include <GL/freeglut.h>
#include <math.h> // For sin() and cos()
#include <stdbool.h>

#define M_PI 3.14159265358979323846

// global variable
bool bFullScreen = false;

void DrawRadio();

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

    // void DrawTable(float, float, float);

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

void DrawTable(float x, float y, float radius)
{
    // code
    glColor3f(0.65f, 0.41f, 0.19f);
    glBegin(GL_POLYGON);

    for (int i = 0; i < 100; i++)
    {
        float angle = 2.0f * M_PI * i / 100;
        float dx = radius * cos(angle);
        float dy = radius * sin(angle);
        glVertex2f(x + dx, y + dy);
    }

    glEnd();
}

void DrawRadio()
{
    // printf("Called\n");

    // front part of radio
    glColor3f(0.922f, 0.569f, 0.008f);

    glBegin(GL_QUADS);

    glVertex2f(-0.87f, 0.575f);
    glVertex2f(-0.90f, 0.58f);

    glColor3f(0.529f, 0.329f, 0.012f);
    glVertex2f(-0.90f, 0.42f);

    glColor3f(0.922f, 0.569f, 0.008f);
    glVertex2f(-0.87f, 0.425f);

    glEnd();

    // top part of radio
    glColor3f(0.922f, 0.569f, 0.008f);

    glBegin(GL_QUADS);

    glVertex2f(-0.90f, 0.58f);
    glVertex2f(-0.92f, 0.58f);

    glColor3f(0.529f, 0.329f, 0.012f);
    glVertex2f(-0.92f, 0.42f);

    glColor3f(0.922f, 0.569f, 0.008f);
    glVertex2f(-0.90f, 0.42f);

    glEnd();

    // round player
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON); // Use GL_POLYGON for a filled oval
    for (int i = 0; i < 100; ++i)
    {
        float angle = 2.0f * M_PI * i / 100; // Calculate the angle
        float x = 0.008f * cos(angle);       // Calculate x coordinate
        float y = 0.013f * sin(angle);       // Calculate y coordinate
        glVertex2f(-0.883f + x, 0.55f + y);  // Plot the vertex
    }
    glEnd();
}

void display()
{
    // code
    glClear(GL_COLOR_BUFFER_BIT);

    // DrawTable(0.0f, 0.0f, 0.5f);
    DrawRadio();

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
