// Header Files
#include <math.h>
#include <Windows.h>

#include "ShadersLogo.h"

// Global Variables
GLint viewPort[4];

UINT uRecordingFrameX = 100;
UINT uRecordingFrameY = 100;

UINT uLetterDisplay = 0;

BOOL bIsRed = TRUE;
FLOAT fColorCodeR = 1.0f;

BOOL bStopScene = FALSE;

void timerRecordingIndicator(int value)
{
	if (!bStopScene)
	{
		if (bIsRed)
		{
			fColorCodeR = 0.0f;
			bIsRed = FALSE;
		}
		else
		{
			fColorCodeR = 1.0f;
			bIsRed = TRUE;
		}

		glutTimerFunc(RECORDING_INDICATOR_TIMER_MILLISECONDS, timerRecordingIndicator, RECORDING_INDICATOR_TIMER);
	}

	glutPostRedisplay();
}

void timerLetterDisplay(int value)
{
	if (uLetterDisplay <= 1020)
	{
		uLetterDisplay = uLetterDisplay + 5;
		glutTimerFunc(LETTER_DISPLAY_TIMER_MILLISECONDS, timerLetterDisplay, LETTER_DISPLAY_TIMER);
	}
	glutPostRedisplay();
}

void timerRecordingFrame(int value)
{
	if (uRecordingFrameX <= 800 && uRecordingFrameY <= 800)
	{
		uRecordingFrameX = uRecordingFrameX + 5;
		uRecordingFrameY = uRecordingFrameY + 5;
		glutTimerFunc(RECORDING_FRAME_TIMER_MILLISECONDS, timerRecordingFrame, RECORDING_FRAME_TIMER);
	}
	else
	{
		glutTimerFunc(LETTER_DISPLAY_TIMER_MILLISECONDS, timerLetterDisplay, LETTER_DISPLAY_TIMER);
		glutTimerFunc(RECORDING_INDICATOR_TIMER_MILLISECONDS, timerRecordingIndicator, RECORDING_INDICATOR_TIMER);
	}
	glutPostRedisplay();
}

void RecordingFrame(float x, float y)
{
	// Recording Borders

	glLineWidth(20.0f);

	// Top - left
	glBegin(GL_LINES);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((-x) / viewPort[2], (y) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((-x + 100.0f) / viewPort[2], (y) / viewPort[3], 0.0f);

	glEnd();

	glBegin(GL_LINES);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((-x) / viewPort[2], (y) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((-x) / viewPort[2], (y - 100.0f) / viewPort[3], 0.0f);

	glEnd();

	// Bottom - Left
	glBegin(GL_LINES);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((-x) / viewPort[2], (-y) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((-x + 100.0f) / viewPort[2], (-y) / viewPort[3], 0.0f);

	glEnd();

	glBegin(GL_LINES);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((-x) / viewPort[2], (-y) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((-x) / viewPort[2], (-y + 100.0f) / viewPort[3], 0.0f);

	glEnd();

	// Top - Right
	glBegin(GL_LINES);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((x) / viewPort[2], (y) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((x - 100.0f) / viewPort[2], (y) / viewPort[3], 0.0f);

	glEnd();

	glBegin(GL_LINES);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((x) / viewPort[2], (y) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((x) / viewPort[2], (y - 100.0f) / viewPort[3], 0.0f);

	glEnd();

	// Bottom - Right
	glBegin(GL_LINES);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((x) / viewPort[2], (-y) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((x - 100.0f) / viewPort[2], (-y) / viewPort[3], 0.0f);

	glEnd();

	glBegin(GL_LINES);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((x) / viewPort[2], (-y) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((x) / viewPort[2], (-y + 100.0f) / viewPort[3], 0.0f);

	glEnd();
}

void LetterHider(float x)
{
	glBegin(GL_QUADS);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f((-10.0f - WIDTH + x) / viewPort[2], (60.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f((-10.0f - WIDTH + x) / viewPort[2], (-210.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f((1020.0f - WIDTH) / viewPort[2], (-210.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f((1020.0f - WIDTH) / viewPort[2], (60.0f - HEIGHT) / viewPort[3], 0.0f);

	glEnd();

}

void LetterS(void)
{
	glBegin(GL_LINES);

	// S
	// x: 0 - 100
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((0.0f - WIDTH) / viewPort[2], (50.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((1010.0f - WIDTH) / viewPort[2], (50.0f - HEIGHT) / viewPort[3], 0.0f);


	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((0.0f - WIDTH) / viewPort[2], (50.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((0.0f - WIDTH) / viewPort[2], (-100.0f - HEIGHT) / viewPort[3], 0.0f);


	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((0.0f - WIDTH) / viewPort[2], (-100.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((100.0f - WIDTH) / viewPort[2], (-100.0f - HEIGHT) / viewPort[3], 0.0f);


	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((100.0f - WIDTH) / viewPort[2], (-100.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((100.0f - WIDTH) / viewPort[2], (-200.0f - HEIGHT) / viewPort[3], 0.0f);


	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((100.0f - WIDTH) / viewPort[2], (-200.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((0.0f - WIDTH) / viewPort[2], (-200.0f - HEIGHT) / viewPort[3], 0.0f);

	glEnd();
}

void LetterH(void)
{
	glBegin(GL_LINES);
	// H
	// x: 150 - 250
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((150.0f - WIDTH) / viewPort[2], (0.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((150.0f - WIDTH) / viewPort[2], (-200.0f - HEIGHT) / viewPort[3], 0.0f);


	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((150.0f - WIDTH) / viewPort[2], (-100.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((250.0f - WIDTH) / viewPort[2], (-100.0f - HEIGHT) / viewPort[3], 0.0f);


	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((250.0f - WIDTH) / viewPort[2], (0.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((250.0f - WIDTH) / viewPort[2], (-200.0f - HEIGHT) / viewPort[3], 0.0f);

	glEnd();
}

void LetterA(void)
{
	glBegin(GL_LINES);
	// A
	// x: 300 - 400
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((350.0f - WIDTH) / viewPort[2], (0.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((300.0f - WIDTH) / viewPort[2], (-200.0f - HEIGHT) / viewPort[3], 0.0f);


	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((350.0f - WIDTH) / viewPort[2], (0.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((400.0f - WIDTH) / viewPort[2], (-200.0f - HEIGHT) / viewPort[3], 0.0f);


	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((325.0f - WIDTH) / viewPort[2], (-100.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((375.0f - WIDTH) / viewPort[2], (-100.0f - HEIGHT) / viewPort[3], 0.0f);

	glEnd();
}

void LetterD(void)
{
	glBegin(GL_LINES);
	// D
	// x: 450 - 550
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((450.0f - WIDTH) / viewPort[2], (0.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((525.0f - WIDTH) / viewPort[2], (0.0f - HEIGHT) / viewPort[3], 0.0f);


	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((525.0f - WIDTH) / viewPort[2], (0.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((550.0f - WIDTH) / viewPort[2], (-25.0f - HEIGHT) / viewPort[3], 0.0f);


	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((550.0f - WIDTH) / viewPort[2], (-25.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((550.0f - WIDTH) / viewPort[2], (-175.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((550.0f - WIDTH) / viewPort[2], (-175.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((525.0f - WIDTH) / viewPort[2], (-200.0f - HEIGHT) / viewPort[3], 0.0f);


	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((525.0f - WIDTH) / viewPort[2], (-200.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((450.0f - WIDTH) / viewPort[2], (-200.0f - HEIGHT) / viewPort[3], 0.0f);


	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((450.0f - WIDTH) / viewPort[2], (-200.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((450.0f - WIDTH) / viewPort[2], (0.0f - HEIGHT) / viewPort[3], 0.0f);


	glEnd();
}

void LetterE(void)
{
	glBegin(GL_LINES);
	// E
	// x: 600 - 700
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((600.0f - WIDTH) / viewPort[2], (0.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((600.0f - WIDTH) / viewPort[2], (-200.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((600.0f - WIDTH) / viewPort[2], (0.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((700.0f - WIDTH) / viewPort[2], (0.0f - HEIGHT) / viewPort[3], 0.0f);


	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((600.0f - WIDTH) / viewPort[2], (-100.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((650.0f - WIDTH) / viewPort[2], (-100.0f - HEIGHT) / viewPort[3], 0.0f);


	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((600.0f - WIDTH) / viewPort[2], (-200.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((700.0f - WIDTH) / viewPort[2], (-200.0f - HEIGHT) / viewPort[3], 0.0f);


	glEnd();
}

void LetterR(void)
{
	glBegin(GL_LINES);
	// R
	// x: 750 - 850
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((750.0f - WIDTH) / viewPort[2], (0.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((750.0f - WIDTH) / viewPort[2], (-200.0f - HEIGHT) / viewPort[3], 0.0f);


	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((750.0f - WIDTH) / viewPort[2], (0.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((850.0f - WIDTH) / viewPort[2], (0.0f - HEIGHT) / viewPort[3], 0.0f);


	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((850.0f - WIDTH) / viewPort[2], (0.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((850.0f - WIDTH) / viewPort[2], (-100.0f - HEIGHT) / viewPort[3], 0.0f);


	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((850.0f - WIDTH) / viewPort[2], (-100.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((750.0f - WIDTH) / viewPort[2], (-100.0f - HEIGHT) / viewPort[3], 0.0f);


	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((750.0f - WIDTH) / viewPort[2], (-100.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((850.0f - WIDTH) / viewPort[2], (-200.0f - HEIGHT) / viewPort[3], 0.0f);

	glEnd();
}

void LetterSL(void)
{
	glBegin(GL_LINES);
	// S
	// 900 - 1000
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((900.0f - WIDTH) / viewPort[2], (0.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((1000.0f - WIDTH) / viewPort[2], (0.0f - HEIGHT) / viewPort[3], 0.0f);


	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((900.0f - WIDTH) / viewPort[2], (0.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((900.0f - WIDTH) / viewPort[2], (-100.0f - HEIGHT) / viewPort[3], 0.0f);


	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((900.0f - WIDTH) / viewPort[2], (-100.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((1000.0f - WIDTH) / viewPort[2], (-100.0f - HEIGHT) / viewPort[3], 0.0f);


	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((1000.0f - WIDTH) / viewPort[2], (-100.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((1000.0f - WIDTH) / viewPort[2], (-200.0f - HEIGHT) / viewPort[3], 0.0f);


	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((900.0f - WIDTH) / viewPort[2], (-200.0f - HEIGHT) / viewPort[3], 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((1000.0f - WIDTH) / viewPort[2], (-200.0f - HEIGHT) / viewPort[3], 0.0f);

	glEnd();
}

void RecordingIndicator(void)
{
	// Record Indicator

	glPointSize(20);
	glEnable(GL_POINT_SMOOTH);

	glBegin(GL_POINTS);

	glColor3f(fColorCodeR, 0.0f, 0.0f);
	glVertex3f((600.0f + 50.0f) / viewPort[2], (600.0f + 100.0f) / viewPort[3], 0.0f);

	glEnd();
}


void LogoScene(void)
{
	glGetIntegerv(GL_VIEWPORT, viewPort);

	// Recording Frame

	RecordingFrame((float)uRecordingFrameX, (float)uRecordingFrameY);

	if (uRecordingFrameX >= 800 && uRecordingFrameY >= 800)
	{
		glLineWidth(10.0f);
		glEnable(GL_LINE_SMOOTH);

		if(getTimeInSeconds() < 7)
		{
			LetterS();
			LetterH();
			LetterA();
			LetterD();
			LetterE();
			LetterR();
			LetterSL();
		LetterHider(uLetterDisplay);

		}

		RecordingIndicator();
	}
}