// header files
#include <freeglut/GL/freeglut.h>
#include <DrawShapes.c>
#include <SandipDaBday.c>
#include<mmsystem.h>
#include <ShadersLogo.c>
#include <Transitions.c>

// global variable declarations
BOOL bFullScreen = FALSE;
float darkRect1Alpha = 1.0;

// Entry-point function
int main(int argc, char *argv[])
{
	// local function declaration
	int initialize(void);
	void resize(int, int);
	void display(void);
	void keyboard(unsigned char, int, int);
	void mouse(int, int, int, int);
	void uninitialize(void);
	void update(void);

	//code
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Sagar Kalbande");

	initialize();

	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutCloseFunc(uninitialize);
    glutIdleFunc(update); 
	glutMainLoop();

	return(0);
}

int initialize(void)
{
	PlaySound("AudioCombined.wav", NULL, SND_ASYNC);
	
	// code
	glClearColor(0.6627f, 0.2198f, 0.2980f, 1.0f);

	return(0);
}

void resize(int width, int height)
{
	// code
	glViewport(0, 0, width, height);
	printf("Resizing\n");
}

void display(void)
{
	// code
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glViewport(0, 0, 800, 600);

	BirthdaySceneCreator();

    DrawFadingRectangle(2.0f, 2.0f, 5.0f, 10.0f, 0); // 0 to 4 seconds to fade in

    DrawFadingRectangle(2.0f, 2.0f, 35.0f, 10.0f, 1); //



	if(getTimeInSeconds() > 35.0) //text appears
	{
		glTranslatef(-0.7, textPos, 0 );
		glScalef(0.1, 0.1, 0 );

		glColor3f(0.7,0.2,0);
		float happyStartx = 3;
		float happyStarty = 0;
		Draw_H(happyStartx + 0, happyStarty);
		Draw_A(happyStartx + 1.5, happyStarty);
		Draw_P(happyStartx + 3, happyStarty);
		Draw_P(happyStartx + 4.5, happyStarty);
		Draw_Y(happyStartx + 7, happyStarty);

		float bdayStartx = 0;
		float bdayStarty = -3;
		Draw_B(bdayStartx + 0,bdayStarty);
		Draw_I(bdayStartx + 2,bdayStarty);
		Draw_R(bdayStartx + 3.5,bdayStarty);
		Draw_T(bdayStartx + 6,bdayStarty);
		Draw_H(bdayStartx + 7.5,bdayStarty);
		Draw_D(bdayStartx + 10,bdayStarty);
		Draw_A(bdayStartx + 11.5,bdayStarty);
		Draw_Y(bdayStartx + 14,bdayStarty);

		float sandipStartx = 2;
		float sandipStarty = -6;
		Draw_S(sandipStartx, sandipStarty);
		Draw_A(sandipStartx + 1.5, sandipStarty);
		Draw_N(sandipStartx + 4.0, sandipStarty);
		Draw_D(sandipStartx + 6.5, sandipStarty);
		Draw_I(sandipStartx + 8.5, sandipStarty);
		Draw_P(sandipStartx + 9.5, sandipStarty);



		//shadow
		glColor3f(0.9,0.9,0.9);
		float shadowOffset = -0.05;
		Draw_H(shadowOffset + happyStartx + 0, shadowOffset + happyStarty);

		//Draw_A(shadowOffset + happyStartx + 0, shadowOffset + happyStarty);
		Draw_A(shadowOffset + happyStartx + 1.5, shadowOffset + happyStarty);
		Draw_P(shadowOffset + happyStartx + 3, shadowOffset + happyStarty);
		Draw_P(shadowOffset + happyStartx + 4.5, shadowOffset + happyStarty);
		Draw_Y(shadowOffset + happyStartx + 7, shadowOffset + happyStarty);

		Draw_B(shadowOffset + bdayStartx + 0,shadowOffset + bdayStarty);
		Draw_I(shadowOffset + bdayStartx + 2,shadowOffset + bdayStarty);
		Draw_R(shadowOffset + bdayStartx + 3.5,shadowOffset + bdayStarty);
		Draw_T(shadowOffset + bdayStartx + 6,shadowOffset + bdayStarty);
		Draw_H(shadowOffset + bdayStartx + 7.5,shadowOffset + bdayStarty);
		Draw_D(shadowOffset + bdayStartx + 10,shadowOffset + bdayStarty);
		Draw_A(shadowOffset + bdayStartx + 11.5,shadowOffset + bdayStarty);
		Draw_Y(shadowOffset + bdayStartx + 14,shadowOffset + bdayStarty);

		Draw_S(shadowOffset + sandipStartx, shadowOffset + sandipStarty);
		Draw_A(shadowOffset + sandipStartx + 1.5, shadowOffset + sandipStarty);
		Draw_N(shadowOffset + sandipStartx + 4.0, shadowOffset + sandipStarty);
		Draw_D(shadowOffset + sandipStartx + 6.5, shadowOffset + sandipStarty);
		Draw_I(shadowOffset + sandipStartx + 8.5, shadowOffset + sandipStarty);
		Draw_P(shadowOffset + sandipStartx + 9.5, shadowOffset + sandipStarty);
		
		//DrawBalloon();
		glLoadIdentity();

		glTranslatef(0.0, 0.8, 0.0);
		//glScalef(0.2, 0.2, 0.0);
		//DrawBdayDecor();
		DrawBdayDecor(0,0);
		DrawBdayDecor(0,-1.6);


		glLoadIdentity();


		float max_y = 0.3;
		if(textPos < max_y) textPos = textPos + 0.003;
	}



	if(bFullScreen)
	{
		glScalef(1.7, 1.7, 0 );
		LogoScene();
		glLoadIdentity();
	}

	DrawFadingRectangle(2.0f, 2.0f, 50.0f, 5.0f, 1); //

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

			// ===================================================================================================
			// Starting Animation
			glutTimerFunc(RECORDING_FRAME_TIMER_MILLISECONDS, timerRecordingFrame, RECORDING_FRAME_TIMER);
			// ===================================================================================================

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
	switch(button)
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

void update(void)
{
	// code
	//resize();
    glutPostRedisplay();
}


