// header files
#include <GL/freeglut.h>
#include <math.h>

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

    glBegin(GL_LINE_LOOP); // Use GL_LINE_LOOP for hollow rectangle
    // first rectangle
    glColor3f(1.0f, 0.0f, 0.0f); // Set color for the edges
    glVertex2f(0.5f, 0.5f);      // Top-right vertex

    glColor3f(0.0f, 1.0f, 0.0f); // Set color for the edges
    glVertex2f(-0.5f, 0.5f);     // Top-left vertex

    glColor3f(0.0f, 0.0f, 1.0f); // Set color for the edges
    glVertex2f(-0.5f, -0.5f);    // Bottom-left vertex

    glColor3f(1.0f, 1.0f, 0.0f); // Set color for the edges
    glVertex2f(0.5f, -0.5f);     // Bottom-right vertex

    glEnd();

    glBegin(GL_LINE_LOOP);
    // second rectangle
    glColor3f(1.0f, 0.0f, 0.0f); // Set color for the edges
    glVertex2f(0.8f, 0.8f);      // Top-right vertex

    glColor3f(0.0f, 1.0f, 0.0f); // Set color for the edges
    glVertex2f(-0.2f, 0.8f);     // Top-left vertex

    glColor3f(0.0f, 0.0f, 1.0f); // Set color for the edges
    glVertex2f(-0.2f, -0.2f);    // Bottom-left vertex

    glColor3f(1.0f, 1.0f, 0.0f); // Set color for the edges
    glVertex2f(0.8f, -0.2f);     // Bottom-right vertex

    glEnd();

    glBegin(GL_LINES);
    // line 1
    glColor3f(1.0f, 0.0f, 0.0f); // Set color for the edges
    glVertex2f(-0.5f, 0.5f);     // Top-right vertex

    glColor3f(0.0f, 1.0f, 0.0f); // Set color for the edges
    glVertex2f(-0.2f, 0.8f);     // Top-left vertex

    // line 2
    glColor3f(1.0f, 0.0f, 0.0f); // Set color for the edges
    glVertex2f(0.5f, 0.5f);      // Top-right vertex

    glColor3f(0.0f, 1.0f, 0.0f); // Set color for the edges
    glVertex2f(0.8f, 0.8f);      // Top-left vertex

    // line 3
    glColor3f(1.0f, 0.0f, 0.0f); // Set color for the edges
    glVertex2f(0.5f, -0.5f);     // Bottom-right vertex

    glColor3f(0.0f, 1.0f, 0.0f); // Set color for the edges
    glVertex2f(0.8f, -0.2f);     // Bottom-right vertex

    // line 4
    glColor3f(1.0f, 0.0f, 0.0f); // Set color for the edges
    glVertex2f(-0.5f, -0.5f);     // Bottom-right vertex

    glColor3f(0.0f, 1.0f, 0.0f); // Set color for the edges
    glVertex2f(-0.2f, -0.2f);     // Bottom-right vertex

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
