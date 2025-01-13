#include <freeglut/GL/freeglut.h>
#include <BdayRoom.c>

float textPos = -2.0;
void BirthdaySceneCreator(void)
{
	DrawFrontWall();
	DrawLeftSideWall();
	DrawSlantedWall();
	DrawBackWall();
	DrawRightSideWall();
	DrawFloor();
	
	DrawStumpSet();

	glTranslatef(0.5, 0.25, 0.0);
	glScalef(0.4, 0.4, 0.);
	glRotatef(-60, 0, 0, 1);
	DrawShadowEllipse(0.03,-0.03,0.125,0.25,0.4);

	DrawBat();
	glLoadIdentity();

	glTranslatef(0.45, 0.3, 0.0);
	glScalef(0.03, 0.03, 0.);
	glRotatef(-30, 0, 0, 1);
	DrawBall();
	glLoadIdentity();

	glTranslatef(0.6, 0.10, 0.0);
	glScalef(0.3, 0.3, 0.);
	glRotatef(35, 0, 0, 1);
	DrawFlowerPot();
	glLoadIdentity();

	DrawDoor();
	DrawWindow();

//below TV shadow
	DrawShadowEllipse(.6,0.6,0.5,0.15,0.4);
	DrawShadowEllipse(.5,0.4,0.3,0.15,0.6);
	glTranslatef(0.4, 0.4, 0.0);

	DrawCupboard();
	glLoadIdentity();

	glTranslatef(-0.08, -0.6, 0.0);
	glScalef(0.12, 0.12, 0.12);
	DrawShadowCircle(0.1,-0.1,1.0,1);

	DrawLamp();	
	glLoadIdentity();

	glTranslatef(0.4, -0.8, 0.0);
	glScalef(0.4, 0.4, 0.4);
	DrawShadowEllipse(.5,-0.0,1,1,1);

	DrawCompleteKitchen();
	glLoadIdentity();



	glTranslatef(0.85, 0.35, 0.0);
	glScalef(0.09, -0.15, 0.);
	glRotatef(-180, 0, 0, 1);
	//glRotatef(-40, 0, 1, 0);

	DrawWagonWheel();
	glLoadIdentity();


	//below piano shadow
	DrawShadowEllipse(-0.6,0.25,0.3,0.5,0.5);

	//pianotable
	glTranslatef(-0.65, 0.4, 0.0);
	DrawRectWithColorBday(0.17,0.55,-0.04, -0.05,0.945,0.631, 0.353,1);
	DrawRectWithColorBday(0.15,0.53,-0.04, -0.05,0.745,0.431, 0.153,1);
	glLoadIdentity();

	glTranslatef(-0.65, 0.4, 0.0);
	glScalef(0.15, 0.25, 0.2);
	glRotatef(90, 0, 0, 1);
	DrawPiano1(-0.2,0.2);
	glLoadIdentity();

	glTranslatef(-0.6, 0.4, 0.0);
	glScalef(0.4, 0.4, 0.4);
	glRotatef(-78, 0, 0, 1);
	DrawShadowEllipse(0.1, 0.2,0.5,0.5,0.6);

	DrawChair();
	glLoadIdentity();

	glTranslatef(0.3, 0.55, 0.0);
	glScalef(0.4, 0.4, 0.);
	glRotatef(45, 0, 0, 1);
	DrawFlowerPot();
	glLoadIdentity();

	glTranslatef(-0.25, 0.55, 0.0);
	glScalef(0.4, 0.4, 0.);
	DrawFlowerPot();
	glLoadIdentity();

	if(getTimeInSeconds()<23.0)
	{
		glTranslatef(-0.80, 0.35, 0.0);
		glScalef(0.2, 0.25, 0.5);
		glRotatef(90, 0, 0, 1);
		DrawNotesOnSineWave(0.3, 1.0, 2.0, 0, 0.2);
		glLoadIdentity();
	}

	//under tea table shadow
	glTranslatef(0.04, 0.1, 0.0);
	glScalef(0.35, 0.35, 0.5);
	DrawShadowCircle(0.1,-0.1,0.7,1);

	DrawTable(0.0f, 0.0f, 0.5f);
	glLoadIdentity();

	glTranslatef(0.15, -0.08, 0.0);
	glScalef(0.4, 0.4, 0.4);
	glRotatef(-170, 0, 0, 1);
	DrawShadowEllipse(0.1, 0.2,0.5,0.5,0.6);
	DrawChair();
	glLoadIdentity();


	glTranslatef(-0.05, 0.1, 0.0);
	glScalef(0.35, 0.35, 0.5);
	DrawShadowCircle(0.05,-0.05,0.2,0.5);

    DrawCupOuterBody(0.0f, 0.0f);
    DrawCupInnerBody(0.0f, 0.0f);
    DrawCoffee(0.0f, 0.0f);
	DrawCupHandle(LEFT);
	DrawHighlightArcCUP(0.0f, 0.0f);

	glLoadIdentity();

	glTranslatef(0.09, 0.18, 0.0);
	glScalef(0.35, 0.35, 0.5);
	DrawShadowCircle(0.05,-0.05,0.2,0.5);
	DrawCupOuterBody(0.0f, 0.0f);
    DrawCupInnerBody(0.0f, 0.0f);
    DrawCoffee(0.0f, 0.0f);
	DrawCupHandle(UP);
	DrawHighlightArcCUP(0.0f, 0.0f);

	glLoadIdentity();

	glTranslatef(0.1, 0.05, 0.0);
	glScalef(0.04, 0.04, 0.0);
	glRotatef(30, 0, 0, 1);

	DrawShadowCircle(0.2, -0.1, 1.5, 0.3);
	DrawGreenCover();
	DrawC(0, 0, 0.5);
	 glLoadIdentity();

	glTranslatef(-0.01, 0.07, 0.0);
	glScalef(0.1, 0.1, 0.0);
	glRotatef(30, 0, 0, 1);
	DrawMusicLines1();
	glLoadIdentity();

	glTranslatef(0.10, 0.13, 0.0);
	glScalef(0.1, 0.1, 0.0);
	glRotatef(15, 0, 0, 1);
	DrawMusicLines1();
	glLoadIdentity();

	glTranslatef(0.53, -0.74, 0.0);
	glScalef(0.1, 0.1, 0.1);
	DrawShadowCircle(0.2,-0.2,0.7,1);

	DrawPanCircle();
	glLoadIdentity();


//below TV shadow
	DrawShadowEllipse(-0.0,0.5,0.3,0.15,0.7);

	glTranslatef(0.02, 0.55, 0.0);
	glScalef(0.5, -0.5, 0.5);
	DrawTV();
	glLoadIdentity();

	glTranslatef(0.63, -0.74, 0.0);
	glScalef(0.07, 0.02, 0.1);
	//glRotatef(70, 0, 0, 1);
	DrawPanHandle();
	glLoadIdentity();

	glTranslatef(0.53, -0.74, 0.0);
	glScalef(0.07, 0.07, 0.0);
	DrawEggWhite(0.0f, 0.0f, 0.5f);
	DrawShadowCircle(0.1,-0.1,0.3,0.3);

    DrawEggYolk(0.0f, 0.0f, 0.2f);
    DrawHighlightArc(0.0f, 0.0f);
	glLoadIdentity();

	glTranslatef(0.5, -0.8, 0.0);
	glScalef(-0.1, -0.1, 0.0);
	glRotatef(120, 0, 0, 1);
	DrawMusicLines1();
	glLoadIdentity();

	glTranslatef(0.85, 0.35, 0.0);
	glScalef(0.09, -0.15, 0.);
	glRotatef(-180, 0, 0, 1);
	DrawSachinWagon();
	glLoadIdentity();


	glTranslatef(0.6, -0.18, 0.0);
	glScalef(0.2, 0.2, 0.0);
	DrawDoorMat(0.0f, 0.0f, 0.5f);
	glLoadIdentity();

	glEnd();

}

