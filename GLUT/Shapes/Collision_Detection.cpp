// header files
#include <GL/freeglut.h>
#include <iostream>
#include <random>

typedef int BOOL;
#define TRUE 1
#define FALSE 0
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
    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Vaibhav Tukaram Gaikwad");

    initialize();

    glutReshapeFunc(resize);

    glPointSize(30.0f);
    glEnable(GL_POINT_SMOOTH);
    glutDisplayFunc(display);
    glutIdleFunc(display);

    // std::thread t(glutDisplayFunc, display);

    // t.detach();

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
    static float x = -1.0f;       // Starting x-coordinate
    static float time = 0.0f;     // Time variable for sine wave
    static float amplitude = 0.8f; // Amplitude of the sine wave
    static float frequency = 0.5f; // Frequency of the sine wave
    static float time_step = 0.01f; // Time increment for sine wave
    static float x_displacement = 0.001f; // X-axis movement increment

    static float red = 1.0f;
    static float green = 0.0f;
    static float blue = 0.0f;

    static int collision_counter = 0;

    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Update the y-coordinate using the sine wave formula
    float y = amplitude * sin(2.0f * 3.14159f * frequency * time);

    // Update the x-coordinate for linear motion
    x += x_displacement;

    // Check for collision with x boundaries
    if (x >= 1.0f || x <= -1.0f)
    {
        x_displacement = -x_displacement; // Reverse direction
        collision_counter++;

        // Change color on collision
        switch (collision_counter % 3)
        {
        case 0:
            red = 0.0f; green = 1.0f; blue = 1.0f;
            break;
        case 1:
            red = 1.0f; green = 0.0f; blue = 1.0f;
            break;
        case 2:
            red = 1.0f; green = 1.0f; blue = 0.0f;
            break;
        }
    }

    // Render the moving point
    glBegin(GL_POINTS);
    glColor3f(red, green, blue);
    glVertex2f(x, y);
    // glEnd();

    // Update time for the sine wave animation
    time += time_step;

    // Swap buffers to display the frame
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