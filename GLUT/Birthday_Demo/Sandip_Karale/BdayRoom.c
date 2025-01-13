#include <freeglut/GL/freeglut.h>

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

void DrawLeftSideWall()
{
	// code

	glBegin(GL_POLYGON);
		glColor3f(0.855f, 0.506f, 0.506f);
		glVertex3f(-1.0f, 0.84f, 0.0f);
		glVertex3f(-0.74f, 0.65f, 0.0f);
		glVertex3f(-0.74f, -0.02f, 0.0f);
		glVertex3f(-1.0f, -0.18f, 0.0f);
	glEnd();

}

void DrawSlantedWall()
{
	// code

	glBegin(GL_POLYGON);
		glColor3f(0.7529f, 0.2901f, 0.3529f);
		glVertex3f(-1.0f, -0.18f, 0.0f);
		glVertex3f(-0.74f, -0.02f, 0.0f);
		glVertex3f(-0.18f, -0.7f, 0.0f);
		glVertex3f(-0.21f, -1.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 0.0f);
	glEnd();
}

void DrawBackWall()
{
	glBegin(GL_QUADS);
		glColor3f(0.8235f, 0.4549f, 0.4705f);
		glVertex3f(-0.21f, -1.0f, 0.0f);
		glVertex3f(-0.18f, -0.7f, 0.0f);
		glVertex3f(-0.1f, -0.7f, 0.0f);
		glVertex3f(-0.09f, -1.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0.9852f, 0.8156f, 0.7176f);
		glVertex3f(-0.09f, -1.0f, 0.0f);
		glVertex3f(-0.1f, -0.7f, 0.0f);
		glVertex3f(0.01f, -0.7f, 0.0f);
		glVertex3f(0.01f, -1.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.9764f, 0.7450f, 0.7686f);
		glVertex3f(0.01f, -0.7f, 0.0f);
		glVertex3f(0.01f, -1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, 0.0f);
		glVertex3f(1.0f, -0.9f, 0.0f);
		glVertex3f(0.7f, -0.7f, 0.0f);
	glEnd();
}

void DrawRightSideWall()
{
	// code

	glBegin(GL_POLYGON);
		glColor3f(0.9960f, 0.9058f, 0.6941f);
		glVertex3f(1.0f, 0.88f, 0.0f);
		glVertex3f(0.7f, 0.65f, 0.0f);
		glVertex3f(0.7f, -0.7f, 0.0f);
		glVertex3f(1.0f, -0.9f, -0.0f);
	glEnd();

}


void DrawFrontWall()
{
	// code

	glBegin(GL_POLYGON);
		glColor3f(0.92f, 0.797f, 0.729f);
		//glColor3f(0.252f, 0.197f, 0.192f);
		glVertex3f(-1.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, 0.84f, 0.0f);
		glVertex3f(-0.74f, 0.65f, 0.0f);
		glVertex3f(0.7f, 0.65f, 0.0f);
		glVertex3f(1.0f, 0.88f, 0.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);
	glEnd();

}

void DrawFloor()
{
	// local variable declarations
	int iNumX = 12;
	int iNumY = 12;
	float fMarkX = 0.0f;
	float fMarkY = 0.0f;

	// code

	glBegin(GL_POLYGON);
		glColor3f(0.6627f, 0.2198f, 0.2980f);
		glVertex3f(-0.74f, 0.65f, 0.0f);
		glVertex3f(0.7f, 0.65f, 0.0f);
		glVertex3f(0.7f, -0.7f, 0.0f);
		glVertex3f(-0.18f, -0.7f, 0.0f);
		glVertex3f(-0.74f, -0.02f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
		glVertex3f(0.7f, 0.08f, 0.0f);
		glVertex3f(0.92f, -0.54f, 0.0f);
		glVertex3f(0.92f, 0.115f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(0.7f, 0.08f, 0.0f);
		glVertex3f(0.92f, -0.54f, 0.0f);
		glVertex3f(0.7f, -0.419f, 0.0f);
	glEnd();

	glLineWidth(5);
	glBegin(GL_LINES);
		glColor3f(0.9607f, 0.4352f, 0.1960f);
		glVertex3f(-0.74f, 0.65f, 0.0f);
		glVertex3f(0.7f, 0.65f, 0.0f);
		glVertex3f(0.7f, 0.65f, 0.0f);
		glVertex3f(0.7f, 0.09f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
		glVertex3f(0.7f, -0.419f, 0.0f);
		glVertex3f(0.7f, -0.7f, 0.0f);
		glVertex3f(0.7f, -0.7f, 0.0f);
		glVertex3f(-0.18f, -0.7f, 0.0f);
		glVertex3f(-0.18f, -0.7f, 0.0f);
		glVertex3f(-0.74f, -0.02f, 0.0f);
		glVertex3f(-0.74f, -0.02f, 0.0f);
		glVertex3f(-0.74f, 0.65f, 0.0f);
	glEnd();
	glLineWidth(500);
	glColor3f(0.5422f, 0.1450f, 0.2156f);
	glBegin(GL_LINES);
		for (iNumY = 0; iNumY < 8; iNumY++) {
			for (iNumX=0; iNumX<12; iNumX++)
				glVertex3f((-0.68 + (iNumX * 0.12f)), (0.5f - (iNumY * 0.16f)), 0.0f);
		}
	glEnd();
	glLineWidth(1);
}

void DrawDoor()
{
	// local variable declarations
	int i;
	float fXMark;
	float fYMark;
	// code

	glBegin(GL_QUADS);
//	glBegin(GL_LINE_LOOP);
		glColor3f(0.9607f, 0.4352f, 0.1960f);
		glVertex3f(0.68f, 0.07f, 0.0f);
		glVertex3f(0.68f, 0.09f, 0.0f);
		glVertex3f(0.94f, 0.13f, 0.0f);
		glVertex3f(0.94f, 0.11f, 0.0f);
//		glVertex3f(0.94f, -0.58f, 0.0f);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(0.92f, 0.13f, 0.0f);
		glVertex3f(0.94f, 0.13f, 0.0f);
		glVertex3f(0.94f, -0.58f, 0.0f);
		glVertex3f(0.92f, -0.54f, 0.0f);
//		glVertex3f(0.68f, -0.41f, 0.0f);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(0.94f, -0.58f, 0.0f);
		glVertex3f(0.68f, -0.42f, 0.0f);
		glVertex3f(0.68f, -0.41f, 0.0f);
		glVertex3f(0.92f, -0.54f, 0.0f);
	glEnd();
}

void DrawWindow()
{
	DrawShadowEllipse(-.4,-.4,0.5,0.5,0.7);

	glBegin(GL_POLYGON);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, -0.4f, 0.0f);
		glVertex3f(-1.0f, -0.5f, 0.0f);
		glVertex3f(-0.6f, -1.0f, 0.0f);
		glVertex3f(-0.48f, -1.0f, 0.0f);
		glVertex3f(-0.3f, -0.61f, 0.0f);
		glVertex3f(-0.68f, -0.15f, 0.0f);
	glEnd();
	// Window frame
	glLineWidth(5);
	glBegin(GL_LINES);
		glColor3f(0.8549f, 0.7333f, 0.3176f);
		glVertex3f(-1.0f, -0.42f, 0.0f);
		glVertex3f(-0.72f, -0.2f, 0.0f);
		glVertex3f(-0.51f, -1.0f, 0.0f);
		glVertex3f(-0.32f, -0.62f, 0.0f);
	glEnd();
	
	// Grills
	glBegin(GL_LINES);
		glVertex3f(-0.78f, -0.4f, 0.0f);
		glVertex3f(-0.71f, -0.33f, 0.0f);
		glVertex3f(-0.64f, -0.57f, 0.0f);
		glVertex3f(-0.57f, -0.49f, 0.0f);
		glVertex3f(-0.53f, -0.7f, 0.0f);
		glVertex3f(-0.45f, -0.62f, 0.0f);
	glEnd();

	glLineWidth(1);

	// Yellow half curtain
	glBegin(GL_POLYGON);
		glColor3f(0.9960f, 0.7450f, 0.1607f);
		glVertex3f(-1.0f, -0.42f, 0.0f);
		glVertex3f(-1.0f, -0.51f, 0.0f);
		glVertex3f(-0.6f, -1.0f, 0.0f);
		glVertex3f(-0.5f, -1.0f, 0.0f);
		glVertex3f(-0.42f, -0.83f, 0.0f);
		glVertex3f(-0.85f, -0.31f, 0.0f);
	glEnd();

	// Dark yellow strip
	glBegin(GL_POLYGON);
		glColor3f(0.9882f, 0.6392f, 0.1686f);
		glVertex3f(-0.97f, -0.4f, 0.0f);
		glVertex3f(-1.0f, -0.42f, 0.0f);
		glVertex3f(-1.0f, -0.5f, 0.0f);
		glVertex3f(-0.58f, -1.0f, 0.0f);
		glVertex3f(-0.5f, -1.0f, 0.0f);
		glVertex3f(-0.49f, -0.98f, 0.0f);
	glEnd();

	// Sofa
	glBegin(GL_POLYGON);
		glColor3f(0.9333f, 0.5490f, 0.2078f);
		glVertex3f(-0.72f, -0.2f, 0.0f);
		glVertex3f(-0.61f, 0.02f, 0.0f);
		glVertex3f(-0.58f, 0.02f, 0.0f);
		glVertex3f(-0.18f, -0.45f, 0.0f);
		glVertex3f(-0.33f, -0.65f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.4431f, 0.5607f, 0.2078f);
		glVertex3f(-0.72f, -0.22f, 0.0f);
		glVertex3f(-0.61f, -0.0f, 0.0f);
		glVertex3f(-0.58f, -0.0f, 0.0f);
		glVertex3f(-0.2f, -0.45f, 0.0f);
		glVertex3f(-0.21f, -0.46f, 0.0f);
		glVertex3f(-0.35f, -0.64f, 0.0f);
	glEnd();

	// pillows
	glBegin(GL_QUADS);
		glColor3f(0.9725f, 0.6980f, 0.2196f);
		glVertex3f(-0.78f, -0.26f, 0.0f);
		glVertex3f(-0.71f, -0.22f, 0.0f);
		glVertex3f(-0.61f, -0.33f, 0.0f);
		glVertex3f(-0.66f, -0.41f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
		glVertex3f(-0.64f, -0.42f, 0.0f);
		glVertex3f(-0.58f, -0.36f, 0.0f);
		glVertex3f(-0.5f, -0.46f, 0.0f);
		glVertex3f(-0.53f, -0.52f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
		glVertex3f(-0.46f, -0.5f, 0.0f);
		glVertex3f(-0.37f, -0.59f, 0.0f);
		glVertex3f(-0.42f, -0.66f, 0.0f);
		glVertex3f(-0.52f, -0.56f, 0.0f);
	glEnd();

	glEnd();
}


void DrawChair(void)
{
	glBegin(GL_QUADS);

	// Seat Cusion
	glColor3f(0.82f, 0.65f, 0.32f);
	glVertex3f(0.05f, 0.0f, 0.0f);

	glColor3f(0.82f, 0.65f, 0.32f);
	glVertex3f(0.45f, 0.0f, 0.0f);

	glColor3f(0.82f, 0.65f, 0.32f);
	glVertex3f(0.45f, 0.45f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.05f, 0.45f, 0.0f);

	// Handrest Left
	glColor3f(0.98f, 0.718f, 0.333f);
	glVertex3f(0.0f, 0.05f, 0.0f);

	glColor3f(0.98f, 0.718f, 0.333f);
	glVertex3f(0.10f, 0.05f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.0f); // ---
	glVertex3f(0.10f, 0.45f, 0.0f);

	glColor3f(0.98f, 0.718f, 0.333f); 
	glVertex3f(0.0f, 0.45f, 0.0f);

	// Handrest Right
	glColor3f(0.98f, 0.718f, 0.333f);
	glVertex3f(0.40f, 0.05f, 0.0f);

	glColor3f(0.98f, 0.718f, 0.333f);
	glVertex3f(0.50f, 0.05f, 0.0f);

	glColor3f(0.98f, 0.718f, 0.333f);
	glVertex3f(0.50f, 0.45f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.0f); // ---
	glVertex3f(0.40f, 0.45f, 0.0f);

	// Backrest Front
	glColor3f(0.5f, 0.4f, 0.3f); // ----
	glVertex3f(0.10f, 0.30f, 0.0f);

	glColor3f(0.5f, 0.4f, 0.3f); // ----
	glVertex3f(0.40f, 0.30f, 0.0f);

	glColor3f(0.98f, 0.718f, 0.333f);
	glVertex3f(0.45f, 0.40f, 0.0f);
	
	glColor3f(0.98f, 0.718f, 0.333f);
	glVertex3f(0.05f, 0.40f, 0.0f);

	// Backrest Top
	glColor3f(0.82f, 0.65f, 0.32f);
	glVertex3f(0.05f, 0.40f, 0.0f);

	glColor3f(0.82f, 0.65f, 0.32f);
	glVertex3f(0.45f, 0.40f, 0.0f);

	glColor3f(0.82f, 0.65f, 0.32f);
	glVertex3f(0.45f, 0.50f, 0.0f);

	glColor3f(0.82f, 0.65f, 0.32f);
	glVertex3f(0.05f, 0.50f, 0.0f);

	glEnd();
}
//width, height, originx, originy, angle
void DrawRectWithColorBday(float w, float h, float ox, float oy, float r, float g, float b, float a) {
    glColor4f(r, g, b, a);
    glBegin(GL_TRIANGLES);
	glVertex4f(ox-w/2, oy+h/2, 0.0f, 1);
	glVertex4f(ox-w/2, oy-h/2, 0.0f, 1);
	glVertex4f(ox+w/2, oy-h/2, 0.0f, 1);
	glVertex4f(ox+w/2, oy-h/2, 0.0f, 1);
	glVertex4f(ox+w/2, oy+h/2, 0.0f, 1);
	glVertex4f(ox-w/2, oy+h/2, 0.0f, 1);

    glEnd();
}

void DrawIsoscelesTriangleColorBday(float baseWidth, float height, float ox, float oy, float r, float g, float b, float a) {
    glColor4f(r, g, b, a);
    glBegin(GL_TRIANGLES);
        glVertex3f(ox, oy + height / 2, 0.0f);
        glVertex3f(ox - baseWidth / 2, oy - height / 2, 0.0f);
        glVertex3f(ox + baseWidth / 2, oy - height / 2, 0.0f);
    glEnd();
}

void DrawPiano1(float originX, float originY) {
    // Draw the base rectangle for the piano
    DrawRectWithColorBday(2.0, 0.8, originX, originY + 0.1, 0.2, 0.2, 0.2, 1.0);

    float numWhiteKeys = 15;
    float whiteKeyWidth = 1 / numWhiteKeys;

    // Draw the white keys
    for (float i = -0.9; i < 0.9; i += whiteKeyWidth) {
        float x = originX + i; // Adjust for the origin
        DrawRectWithColorBday(whiteKeyWidth - 0.005, 0.5, x, originY, 0.95, 0.95, 0.95, 1.0);
    }

    int count = 0;
    int maxcount = 2;

    // Draw the black keys
    for (float i = -0.9; i < 0.85; i += whiteKeyWidth) {
        if (count == maxcount) {
            maxcount = (maxcount == 2) ? 3 : 2;
            count = 0;
        } else {
            float x = originX + i + (whiteKeyWidth / 2.0); // Center black key on top of white key
            float y = originY + (0.5 - 0.32) / 2.0;        // Vertical offset for black keys
            DrawRectWithColorBday(whiteKeyWidth - 0.02, 0.32, x, y, 0.0, 0.0, 0.0, 1.0);
            count++;
        }
    }
}

void DrawKitchenFront()
{
    // code
    glBegin(GL_POLYGON);
    glColor3f(0.93725490196, 0.50980392156, 0.22745098039);
    glVertex2f(-0.8f, 0.5f);

    glColor3f(0.93725490196, 0.50980392156, 0.22745098039);
    glVertex2f(-0.8f, -0.3f);

    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.8f, -0.3f);

    glColor3f(0.93725490196, 0.50980392156, 0.22745098039);
    glVertex2f(0.8f, 0.5f);

    glEnd();
}

void DrawHandle3_In()
{
    glBegin(GL_POLYGON);
  
    glColor3f(0.91, 0.76, 0.65);
    glVertex2f(-0.13f, 0.6f);
    glVertex2f(-0.14f, 0.58f);
    glVertex2f(-0.08f, 0.58f);
    glVertex2f(-0.09f, 0.6f);

    glEnd();
}
void DrawHandle3_Out()
{
    glBegin(GL_POLYGON);
    glColor3f(0.36, 0.25, 0.20);
 
    glVertex2f(-0.14f, 0.61f);
    glVertex2f(-0.15f, 0.57f);
    glVertex2f(-0.07f, 0.57f);
    glVertex2f(-0.08f, 0.61f);

    glEnd();
}
void DrawHandle3_OutIn()
{
    glBegin(GL_POLYGON);
    glColor3f(0.91, 0.76, 0.65);

    glVertex2f(-0.14f, 0.58f);
    glVertex2f(-0.15f, 0.57f);
    glVertex2f(-0.07f, 0.57f);
    glVertex2f(-0.08f, 0.58f);

    glEnd();
}

void DrawHandle2_Out()
{
    glBegin(GL_POLYGON);
    glColor3f(0.36, 0.25, 0.20);

    glVertex2f(-0.14f, 0.76f);
    glVertex2f(-0.15f, 0.73f);
    glVertex2f(-0.06f, 0.73f);
    glVertex2f(-0.07f, 0.76f);

    glEnd();
}
void DrawHandle2_In()
{
    glBegin(GL_POLYGON);

    glColor3f(0.91, 0.76, 0.65);

    glVertex2f(-0.13f, 0.75f);
    glVertex2f(-0.14f, 0.74f);
    glVertex2f(-0.07f, 0.74f);
    glVertex2f(-0.08f, 0.75f);

    glEnd();
}
void DrawHandle2_OutIn()
{
    glBegin(GL_POLYGON);
    glColor3f(0.91, 0.76, 0.65);

    glVertex2f(-0.14f, 0.74f);
    glVertex2f(-0.15f, 0.73f);
    glVertex2f(-0.06f, 0.73f);
    glVertex2f(-0.07f, 0.74f);

    glEnd();
}
void DrawHandle3Poly()
{
    glBegin(GL_POLYGON);

    glColor3f(0.36, 0.25, 0.20);

    glVertex2f(-0.52f, 0.7f);
    glVertex2f(-0.53f, 0.63f);
    glVertex2f(-0.52f, 0.63f);
    glVertex2f(-0.51f, 0.7f);

    glEnd();
}
void DrawHandle3Traingle1()
{
    glBegin(GL_TRIANGLES);

    glColor3f(0.36, 0.25, 0.20);

    glVertex2f(-0.52f, 0.7f);;
    glVertex2f(-0.55f, 0.68f);
    glVertex2f(-0.52f, 0.69f);
    

    glEnd();
}
void DrawHandle3Traingle2()
{
    glBegin(GL_TRIANGLES);

    glColor3f(0.36, 0.25, 0.20);

    glVertex2f(-0.53f, 0.63f);
    glVertex2f(-0.52f, 0.64f);
    glVertex2f(-0.56f, 0.63f);  

    glEnd();
}
void DrawHandleMicrowave()
{
    glBegin(GL_TRIANGLES);

    glColor3f(0.36, 0.25, 0.20);

    glVertex2f(0.36f, 0.7f);
    glVertex2f(0.38f, 0.6f);
    glVertex2f(0.4f, 0.68f);

    glVertex2f(0.5f, 0.68f);
    glVertex2f(0.51f, 0.6f);
    glVertex2f(0.53f, 0.7f);

    glEnd();
}
void DrawHandleMicrowavePoly()
{
    glColor3f(0.36, 0.25, 0.20);

    glBegin(GL_POLYGON);

    glVertex2f(0.36f, 0.7f);
    glVertex2f(0.4f, 0.68f);
    glVertex2f(0.5f, 0.68f);
    glVertex2f(0.53f, 0.7f);
    glEnd();
}
void DrawKitchenTop()
{
    glBegin(GL_QUADS);

    glColor3f(0.91, 0.76, 0.65);

    glVertex2f(-0.7f, 0.8f);   
    glVertex2f(-0.8f, 0.5f);
    glVertex2f(0.8f, 0.5f);   
    glVertex2f(0.7f, 0.8f); 

    glEnd();
}
void DrawKitchenCounterBorderHori1()
{
    glBegin(GL_QUADS);

    glColor3f(0.556863f, 0.137255f, 0.419608f);
    glVertex2f(-0.8f, 0.51f);
    glVertex2f(-0.8f, 0.5f);
    glVertex2f(0.8f, 0.5f);
    glVertex2f(0.8f, 0.51f);

    glEnd();
}
void DrawKitchenCounterBorderVert1()
{
    glBegin(GL_QUADS);

    glColor3f(0.65f, 0.50f, 0.39f);
    glVertex2f(-0.4f, 0.8f);
    glVertex2f(-0.43f, 0.5f);
    glVertex2f(-0.42f, 0.5f);
    glVertex2f(-0.39f,0.8f);

    glEnd();
}
void DrawKitchenCounterHori2()
{
    glBegin(GL_QUADS);

    glColor3f(0.65f, 0.50f, 0.39f);

    glVertex2f(-0.41f, 0.7f);
    glVertex2f(-0.41f, 0.69f);
    glVertex2f(0.16f, 0.7f);
    glVertex2f(0.18f, 0.69f);

    glEnd();
}

void DrawKitchenMicrowave1()
{
    glBegin(GL_QUADS);

    glColor3f(0.62352, 0.372549, 0.623529);

    glVertex2f(0.15f, 0.8f);
    glVertex2f(0.2f, 0.5f);
    glVertex2f(0.8f, 0.5f);
    glVertex2f(0.7f, 0.8f);

    glEnd();
}
void DrawKitchenMicrowave2()
{
    glBegin(GL_QUADS);

    glColor3f(0.858824, 0.439216, 0.576471);

    glVertex2f(0.23f, 0.75f);
    glVertex2f(0.27f, 0.57f);
    glVertex2f(0.7f, 0.57f);
    glVertex2f(0.65f, 0.75f);

    glEnd();
}
void DrawKitchenStove()
{
    // code

    glBegin(GL_POLYGON);
		glColor3f(0.46666666666, 0.4*sin(getTimeInSeconds()),  0.4*sin(getTimeInSeconds()));

    glVertex2f(0.2f, 0.4f);

    glColor3f(0.46666666666, 0.29411764705, 0.39607843137);

    glVertex2f(0.2f, 0.0f);

    glVertex2f(0.7f, 0.0f);
    glColor3f(0.46666666666, 0.29411764705, 0.39607843137);

    glVertex2f(0.7f, 0.4f);


    glEnd();
}
void DrawCircle11(float cx, float cy, float rx, float ry, int num_segments)
{
    glBegin(GL_TRIANGLE_FAN);  
    glColor3f(0.255, 0.098, 0.239);
 
    for (int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * (float)(ii) / (float)(num_segments);
        float x = rx * cosf(theta);  
        float y = ry * sinf(theta); 

        glVertex2f(x + cx, y + cy);
    }

    glEnd();  
}
void DrawCircle2(float cx, float cy, float rx, float ry, int num_segments)
{
    glBegin(GL_TRIANGLE_FAN); 
    glColor3f(0.255, 0.098, 0.239);
    for (int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * (float)(ii) / (float)(num_segments);
        float x = rx * cosf(theta);  
        float y = ry * sinf(theta); 

        glVertex2f(x + cx, y + cy);
    }

    glEnd();  
}
void DrawCircle3(float cx, float cy, float rx, float ry, int num_segments)
{
    glBegin(GL_TRIANGLE_FAN); 
    glColor3f(0.255, 0.098, 0.239);
    for (int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * (float)(ii) / (float)(num_segments);
        float x = rx * cosf(theta);  
        float y = ry * sinf(theta);  

        glVertex2f(x + cx, y + cy);
    }

    glEnd();  
}
void DrawCircle4(float cx, float cy, float rx, float ry, int num_segments)
{
    glBegin(GL_TRIANGLE_FAN); 
    glColor3f(0.255, 0.098, 0.239);
    for (int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * (float)(ii) / (float)(num_segments);
        float x = rx * cosf(theta); 
        float y = ry * sinf(theta);  

        glVertex2f(x + cx, y + cy);
    }

    glEnd();  
}
 //Lines
void DrawRightVertical()
{
    glBegin(GL_LINES);

    glColor3f(0.65f, 0.50f, 0.39f);
    glVertex2f(0.15f, 0.8f);
    glVertex2f(0.2f, 0.5f);
  
    glEnd();
}


void DrawCompleteKitchen()
{
    DrawKitchenTop();
    DrawKitchenFront();
    DrawKitchenStove();
    DrawKitchenMicrowave1();
    DrawKitchenMicrowave2();
    DrawRightVertical();
    DrawKitchenCounterBorderHori1();
    DrawKitchenCounterBorderVert1();
    DrawKitchenCounterHori2();

    DrawCircle11(0.35f, 0.3f,  0.06f, 0.06f, 100);
    DrawCircle2(0.35f, 0.13f, 0.05f, 0.05f, 50);
    DrawCircle3(0.55f, 0.13f, 0.07f, 0.07f, 100);
    DrawCircle4(0.55f, 0.29f, 0.05f, 0.05f, 100);
    DrawHandle2_Out();
    DrawHandle2_In();
    DrawHandle2_OutIn();
    DrawHandle3_Out();
    DrawHandle3_In();
    DrawHandle3_OutIn();
    DrawHandle3Poly();
    DrawHandle3Traingle1();
    DrawHandle3Traingle2();
    DrawHandleMicrowave();
    DrawHandleMicrowavePoly();
}

void DrawWagonWheel(void)
{
	glLineWidth(3.0f);
	glColor3f(0, 1, 0);

	int iNumberOfTriangle = 40;
	int i, j, x = 0, y = 0;
	double radius = 0.9;
	double twicePi = 2 * 3.142;
	

	glBegin(GL_TRIANGLE_FAN);
	
	for (i = 0; i <= iNumberOfTriangle; i++)
	{
		glVertex3f((radius * cos(i * twicePi / iNumberOfTriangle)), (radius * sin(i * twicePi / iNumberOfTriangle)), (0.0f));
	}
	
	glColor3f(0.72, 0.54, 0.38);
	glVertex3f(0.5f, 0.8f, 0.0f);

	glEnd();

	// pitch
	glBegin(GL_QUADS);

	glVertex3f(-0.3f, 0.1f, 0.0f);
	glVertex3f(-0.3f, -0.1f, 0.0f);
	glVertex3f(0.3f, -0.1f, 0.0f);
	glVertex3f(0.3f, 0.1f, 0.0f);
	
	glEnd();
	
	// boundry lines
	glBegin(GL_LINES);
	
	glColor3f(0.96, 0.96, 0.96);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.8f, 0.0f);
	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(0.0f, -0.8f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.1f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(0.62f, -0.63f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(0.5f, -0.8f, 0.0f);
	
	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(0.4f, -0.7f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(-0.3f, -0.8f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(-0.35f, -0.8f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(-0.28f, -0.8f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(0.5f, -0.75f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(0.03f, 0.9f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(-0.5f, 0.75f, 0.0f);

	glColor3f(0.96, 0.96, 0.96);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(0.3f, -0.85f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(-0.2f, -0.88f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(-0.1f, -0.86f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(0.06f, 0.0f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(-0.15f, -0.88f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(-0.03f, -0.9f, 0.0f);
	
	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(-0.05f, -0.9f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(-0.5f, -0.75f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(-0.4f, -0.8f, 0.0f);
	
	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(-0.83f, -0.35f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(-0.8f, -0.4f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(-0.82f, -0.3f, 0.0f);
	glEnd();

}

void DrawLamp(void)
{
        glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.992f, 0.855f, 0.624f);

    float centerX = 0.0f;
    float centerY = 0.0f;
    float radius = 0.7f;
    int numSegments = 100;


    glVertex2f(centerX, centerY);

    for (int i = 0; i <= numSegments; i++)
    {
        float angle = 2.0f * 3.14159265359f * i / numSegments;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }

    glEnd();

    //Black Filled circle
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.3f, 0.0f, 0.0f);

    centerX = 0.0f;
    centerY = 0.0f;
    radius = 0.55f;
    numSegments = 100;


    glVertex2f(centerX, centerY);

    for (int i = 0; i <= numSegments; i++)
    {
        float angle = 2.0f * 3.14159265359f * i / numSegments;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }

    glEnd();

      

    //Blue Circle
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.608f, 0.541f, 0.659f);

    centerX = 0.05f;
    centerY = 0.05f;
    radius = 0.38f;
    numSegments = 100;


    glVertex2f(centerX, centerY);

    for (int i = 0; i <= numSegments; i++)
    {
        float angle = 2.0f * 3.14159265359f * i / numSegments;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }

    glEnd();

    //Black Half Circle
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.357f, 0.227f, 0.235f);

    centerX = 0.047f;
    centerY = -0.015f;
    radius = 0.31f;
    numSegments = 100;


    glVertex2f(centerX, centerY);

    for (int i = 0; i <= numSegments; i++)
    {
        float angle = 2.0f * 3.14159265359f * i / numSegments;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }

    glEnd();
    
    //White Circle
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);

    centerX = 0.0f;
    centerY = -0.05f;
    radius = 0.28f;
    numSegments = 100;


    glVertex2f(centerX, centerY);

    for (int i = 0; i <= numSegments; i++)
    {
        float angle = 2.0f * 3.14159265359f * i / numSegments;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }

    glEnd();
}

void DrawCupboard(void)
{
	glBegin(GL_QUADS);

	// Layer 1 Lowest 
	glColor3f(0.82f, 0.65f, 0.32f);
	glVertex3f(0.00f, 0.00f, 0.0f);

	glColor3f(0.82f, 0.65f, 0.32f);
	glVertex3f(0.30f, 0.00f, 0.0f);
	
	glColor3f(0.82f, 0.65f, 0.32f);
	glVertex3f(0.30f, 0.15f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.00f, 0.15f, 0.0f);

	// Layer 2 Right Side Partision
	glColor3f(0.4f, 0.31f, 0.15f);
	glVertex3f(0.30f, 0.00f, 0.0f);

	glColor3f(0.4f, 0.31f, 0.15f);
	glVertex3f(0.30f, 0.15f, 0.0f);

	glColor3f(0.4f, 0.31f, 0.15f);
	glVertex3f(0.40f, 0.40f, 0.0f);

	glColor3f(0.4f, 0.31f, 0.15f);
	glVertex3f(0.40f, 0.20f, 0.0f);
	
	// Layer 3 Books at Lowest Level
	// Book 1
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.06f, 0.02f, 0.0f);

	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.14f, 0.01f, 0.0f);

	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.15f, 0.07f, 0.0f);

	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.07f, 0.08f, 0.0f);

	// Book 2
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.20f, 0.02f, 0.0f);

	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.29f, 0.01f, 0.0f);

	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.30f, 0.07f, 0.0f);

	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.21f, 0.08f, 0.0f);
	
	// Layer 4 Middle Level
	glColor3f(0.82f, 0.65f, 0.32f);
	glVertex3f(0.02f, 0.10f, 0.0f);

	glColor3f(0.82f, 0.65f, 0.32f);
	glVertex3f(0.35f, 0.10f, 0.0f);

	glColor3f(0.82f, 0.65f, 0.32f);
	glVertex3f(0.35f, 0.25f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.02f, 0.25f, 0.0f);
	 
	// Layer 5 Books at Middle Level
	// Book 1 Front
	glColor3f(0.0f, 0.0f, 0.5f);
	glVertex3f(0.20f, 0.22f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.5f);
	glVertex3f(0.21f, 0.11f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.5f);
	glVertex3f(0.24f, 0.20f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.5f);
	glVertex3f(0.21f, 0.24f, 0.0f);

	// Book 1 Side

	glColor3f(0.0f, 0.0f, 0.5f);
	glVertex3f(0.21f, 0.11f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.5f);
	glVertex3f(0.24f, 0.11f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.5f);
	glVertex3f(0.26f, 0.20f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.5f);
	glVertex3f(0.24f, 0.20f, 0.0f);

	// Book 2 Side
	glColor3f(0.5f, 0.0f, 0.0f);
	glVertex3f(0.24f, 0.11f, 0.0f);

	glColor3f(0.5f, 0.0f, 0.0f);
	glVertex3f(0.26f, 0.11f, 0.0f);

	glColor3f(0.5f, 0.0f, 0.0f);
	glVertex3f(0.28f, 0.20f, 0.0f);

	glColor3f(0.5f, 0.0f, 0.0f);
	glVertex3f(0.26f, 0.20f, 0.0f);

	// Book 3 Side
	glColor3f(0.0f, 0.5f, 0.0f);
	glVertex3f(0.26f, 0.11f, 0.0f);

	glColor3f(0.0f, 0.5f, 0.0f);
	glVertex3f(0.28f, 0.11f, 0.0f);

	glColor3f(0.0f, 0.5f, 0.0f);
	glVertex3f(0.30f, 0.20f, 0.0f);

	glColor3f(0.0f, 0.5f, 0.0f);
	glVertex3f(0.28f, 0.20f, 0.0f);


	// Layer 6 Left Side Partision
	// Layer 2 Right Side Partision
	glColor3f(0.4f, 0.31f, 0.15f);
	glVertex3f(0.00f, 0.00f, 0.0f);

	glColor3f(0.4f, 0.31f, 0.15f);
	glVertex3f(0.04f, 0.20f, 0.0f);

	glColor3f(0.4f, 0.31f, 0.15f);
	glVertex3f(0.04f, 0.40f, 0.0f);

	glColor3f(0.4f, 0.31f, 0.15f);
	glVertex3f(0.00f, 0.15f, 0.0f);

	// Layer 7 Frame Thickness
	// Left Side thickness
	glColor3f(0.95f, 0.90f, 0.78f);
	glVertex3f(0.00f, 0.00f, 0.0f);

	glColor3f(0.95f, 0.90f, 0.78f);
	glVertex3f(0.01f, 0.00f, 0.0f);

	glColor3f(0.95f, 0.90f, 0.78f);
	glVertex3f(0.06f, 0.20f, 0.0f);

	glColor3f(0.95f, 0.90f, 0.78f);
	glVertex3f(0.04f, 0.20f, 0.0f);

	// Right Side Thickness
	glColor3f(0.95f, 0.90f, 0.78f);
	glVertex3f(0.29f, 0.00f, 0.0f);

	glColor3f(0.95f, 0.90f, 0.78f);
	glVertex3f(0.30f, 0.00f, 0.0f);

	glColor3f(0.95f, 0.90f, 0.78f);
	glVertex3f(0.40f, 0.20f, 0.0f);

	glColor3f(0.95f, 0.90f, 0.78f);
	glVertex3f(0.38f, 0.20f, 0.0f);

	// Top Level Thickness
	glColor3f(0.95f, 0.90f, 0.78f);
	glVertex3f(0.04f, 0.19f, 0.0f);

	glColor3f(0.95f, 0.90f, 0.78f);
	glVertex3f(0.38f, 0.19f, 0.0f);

	glColor3f(0.95f, 0.90f, 0.78f);
	glVertex3f(0.40f, 0.20f, 0.0f);

	glColor3f(0.95f, 0.90f, 0.78f);
	glVertex3f(0.04f, 0.20f, 0.0f);

	// Mid Level Thickness
	glColor3f(0.95f, 0.90f, 0.78f);
	glVertex3f(0.02f, 0.09f, 0.0f);

	glColor3f(0.95f, 0.90f, 0.78f);
	glVertex3f(0.35f, 0.09f, 0.0f);

	glColor3f(0.95f, 0.90f, 0.78f);
	glVertex3f(0.35f, 0.10f, 0.0f);

	glColor3f(0.95f, 0.90f, 0.78f);
	glVertex3f(0.02f, 0.10f, 0.0f);

	// layer 8 Top Level
	glColor3f(0.82f, 0.65f, 0.32f);
	glVertex3f(0.04f, 0.20f, 0.0f);

	glColor3f(0.82f, 0.65f, 0.32f);
	glVertex3f(0.40f, 0.20f, 0.0f);

	glColor3f(0.82f, 0.65f, 0.32f);
	glVertex3f(0.40f, 0.40f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.04f, 0.40f, 0.0f);


	glEnd();
}


void DrawFlowerPot(void)
{
	// Function Prototype

	DrawShadowCircle(0.1,-0.1,0.3,0.6);

	void DrawOuterBorder(void);
	void DrawInnerMud(void);
	void DrawLeaves(void);


	DrawOuterBorder();
	DrawInnerMud();
	DrawLeaves();
}

void DrawOuterBorder(void)
{
	//Variable Declaration
	const int iSectionNos = 100;
	int i;
	double radius = 0.20;
	const double twicePi = 2 * 3.142;
	glColor3f(0.99, 0.85, 0.62);

	//Outer Border of flower pot
	glBegin(GL_TRIANGLE_FAN);

	for (i = 0; i <= iSectionNos; i++)
	{
		glVertex3f((radius * cos(i * twicePi / iSectionNos)), (radius * sin(i * twicePi / iSectionNos)), (0.0f));
	}
	glEnd();
}

void DrawInnerMud(void)
{
	// Variable Declarations
	const int iSectionNos = 100;
	int i;
	double radius = 0.15;
	const double twicePi = 2 * 3.142;

	glColor3f(0.16, 0.04, 0.17);
	//Inner Mud
	glBegin(GL_TRIANGLE_FAN);

	for (i = 0; i <= iSectionNos; i++)
	{
		glVertex3f((radius * cos(i * twicePi / iSectionNos)), (radius * sin(i * twicePi / iSectionNos)), (0.0f));
	}
	glEnd();
}

void DrawLeaves(void)
{
	//Stems
	glLineWidth(2.0f);
	glColor3f(0.4, 0.37, 0.29);
	glBegin(GL_LINES);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(-0.1f, 0.2f);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.1f, 0.05f);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(-0.12f, -0.12f);
	glEnd();

	//Leaves
	glColor3f(0.38, 0.47, 0.22);
	glLineWidth(4.0f);

	glBegin(GL_LINES);
	glVertex2f(0.01f, 0.02f);
	glVertex2f(0.2f, 0.15f);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(0.05f, 0.03f);
	glVertex2f(0.09f, 0.06f);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(0.02f, 0.02f);
	glVertex2f(0.09f, -0.1f);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-0.02f, -0.02f);
	glVertex2f(-0.2f, 0.25f);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-0.04f, -0.04f);
	glVertex2f(-0.3f, 0.05f);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-0.04f, -0.04f);
	glVertex2f(0.05f, -0.25f);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-0.09f, -0.09f);
	glVertex2f(-0.3f, 0.08f);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-0.07f, -0.07f);
	glVertex2f(0.08f, -0.3f);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-0.06f, 0.1f);
	glVertex2f(-0.2f, 0.2f);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-0.04f, 0.1f);
	glVertex2f(0.1f, 0.3f);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-0.04f, 0.07f);
	glVertex2f(-0.22f, 0.22f);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-0.04f, 0.07f);
	glVertex2f(0.1f, 0.3f);
	glEnd();
}

void DrawTable(float x, float y, float radius)
{
    // code
    glColor3f(0.75f, 0.51f, 0.19f);
    glBegin(GL_POLYGON);

    for (int i = 0; i < 100; i++)
    {
        float angle = 2.0f * 3.14 * i / 100;
        float dx = radius * cos(angle);
        float dy = radius * sin(angle);
        glVertex2f(x + dx, y + dy);
    }

    glEnd();

    glColor3f(0.65f, 0.41f, 0.19f);
    glBegin(GL_POLYGON);

    for (int i = 0; i < 100; i++)
    {
        float angle = 2.0f * 3.14 * i / 100;
        float dx = 0.9*radius * cos(angle);
        float dy = 0.9*radius * sin(angle);
        glVertex2f(x + dx, y + dy);
    }

    glEnd();
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


void DrawHighlightArcCUP(float x, float y)
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

void DrawHighlightArc(float x, float y)
{
    // variable declarations
    float start_angle = M_PI / 4;
    float end_angle = (3 * M_PI) / 4;
    float arc_radius = 0.2f * 0.70f;

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

void DrawDoorMat(float x, float y, float radius)
{
	DrawShadowCircle(0.2,-0.2, .7, 0.15);

    // code
    glBegin(GL_POLYGON);
	glColor3f(0.5, 0.325, 0.678);


    for (int i = 0; i <= 150; ++i)
    {
        float angle = 2.0f * M_PI * i / 150;
        float smooth_offset = radius * 0.007f * sin(3 * angle) + radius * 0.03f * cos(7 * angle);
        float dx = (radius + smooth_offset) * cos(angle);
        float dy = (radius + smooth_offset) * sin(angle);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
	
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.9, 0.3);

    for (int i = 0; i <= 150; ++i)
    {
        float angle = 2.0f * M_PI * i / 150;
        float smooth_offset = radius * 0.007f * sin(3 * angle) + radius * 0.03f * cos(7 * angle);
        float dx = (radius*0.8 + smooth_offset) * cos(angle);
        float dy = (radius*0.8 + smooth_offset) * sin(angle);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1, 1, 0.9);

    for (int i = 0; i <= 150; ++i)
    {
        float angle = 2.0f * M_PI * i / 150;
        float smooth_offset = radius * 0.007f * sin(3 * angle) + radius * 0.03f * cos(7 * angle);
        float dx = (radius*0.5 + smooth_offset) * cos(angle);
        float dy = (radius*0.5 + smooth_offset) * sin(angle);
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


void DrawPanCircle(){
	float r1 = 0.7;
	glBegin(GL_POLYGON);
	glColor3f(0.35294117647, 0.35294117647,0.35294117647);
	for (int i = 0; i < 360; i++)
	{
		float theta = i * (PI / 180.0);
		float x = r1 * cos(theta);
		float y = r1 * sin(theta);
		glVertex2f(x, y);
	}
	glEnd();

	float r2 = 0.5;
	glBegin(GL_POLYGON);
	glColor3f(0.23, 0.23,0.23);
	for (int i = 0; i < 360; i++)
	{
		float theta = i * (PI / 180.0);
		float x = r2 * cos(theta);
		float y = r2 * sin(theta);
		glVertex2f(x, y);
	}
	glEnd();
}

void DrawPanHandle(){
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.71568627451, 0.11764705882);

	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(-0.5, -0.5);
	glEnd();
}

void DrawSachinWagon(void)
{
	glLineWidth(3.0f);
	glColor3f(0.27, 0.63, 0.32);

	int iNumberOfTriangle = 40;
	int i, j, x = 0, y = 0;
	double radius = 0.9;
	double twicePi = 2 * 3.142;


	glBegin(GL_TRIANGLE_FAN);

	for (i = 0; i <= iNumberOfTriangle; i++)
	{
		glVertex3f((radius * cos(i * twicePi / iNumberOfTriangle)), (radius * sin(i * twicePi / iNumberOfTriangle)), (0.0f));
	}

	glColor3f(0.72, 0.54, 0.38);
	glVertex3f(0.5f, 0.8f, 0.0f);

	glEnd();

	// pitch
	glBegin(GL_QUADS);

	glVertex3f(-0.3f, 0.1f, 0.0f);
	glVertex3f(-0.3f, -0.1f, 0.0f);
	glVertex3f(0.3f, -0.1f, 0.0f);
	glVertex3f(0.3f, 0.1f, 0.0f);

	glEnd();

	// boundry lines
	glBegin(GL_LINES);

	glColor3f(0.96, 0.96, 0.96);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.8f, 0.0f);
	glVertex3f(-0.25f, 0.0f, 0.0f);
	//glVertex3f(0.0f, -0.8f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	//glVertex3f(0.0f, 0.1f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(0.62f, -0.63f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(0.5f, -0.8f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(0.75f, -0.5f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(0.9f, -0.1f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(0.88f, -0.2f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	//glVertex3f(-0.28f, -0.8f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(0.5f, -0.75f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(0.03f, 0.9f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(-0.5f, 0.75f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(0.3f, -0.85f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(-0.2f, -0.88f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(-0.1f, -0.86f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(0.06f, 0.0f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(-0.15f, -0.88f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	//glVertex3f(-0.03f, -0.9f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(-0.05f, -0.9f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(-0.5f, -0.75f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(-0.4f, -0.8f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(-0.83f, -0.35f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(-0.8f, -0.4f, 0.0f);

	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(-0.82f, -0.3f, 0.0f);
	glEnd();
}


void BalloonDrawCircle2_In(float cx, float cy, float rx, float ry, int num_segments)
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.917647, 0.678431, 0.917647);  //plum

    for (int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * (float)(ii) / (float)(num_segments);
        float x = rx * cosf(theta);
        float y = ry * sinf(theta);

        glVertex2f(x + cx, y + cy);
    }
}

void BalloonDrawCircle3_Out(float cx, float cy, float rx, float ry, int num_segments)
{
    glBegin(GL_TRIANGLE_FAN); 
    glColor3f(0.917647, 0.678431, 0.917647);  //plum
    for (int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * (float)(ii) / (float)(num_segments);
        float x = rx * cosf(theta);  
        float y = ry * sinf(theta);  

        glVertex2f(x + cx, y + cy);
    }

    glEnd();  
}


void DrawBalloon(){
	BalloonDrawCircle2_In(0.70f, 0.13f, 0.001f, 0.001f, 100);

    BalloonDrawCircle3_Out(0.55f, 0.13f, 0.09f, 0.09f, 100);
}
void DrawBat()
{
	DrawRectWithColorBday(0.1, 0.4, 0, 0, 0.910,0.718, 0.447, 1.0);
	DrawRectWithColorBday(0.036, 0.2, 0.0, 0.3, 0.20,0.20, 0.20, 1.0);
	DrawRectWithColorBday(0.04, 0.02, 0.0, 0.40, 0.243,0.247, 0.235, 1.0);
}

void DrawBall()
{
	DrawShadowCircle(0.3,-0.2,0.8,0.6);
	DrawCircleWithColor(0, 0, 0.5, 0.608,0.031, 0.055, 1.0);
	DrawRectWithColorBday(0.05,1.0,-0.07,0, 1,1,1,1);
	DrawRectWithColorBday(0.05,1.0, 0.07,0, 1,1,1,1);
}

void DrawOneStump(float x, float y, float z){
	DrawShadowEllipse(x, y,0.125,0.3,0.2);
	DrawRectWithColorBday(0.02, 0.5, x, y, 0.827,0.576, 0.594, 1);
	DrawIsoscelesTriangleColorBday(0.02, 0.03, x, y+ 0.265, 0.827,0.576, 0.594, 1);
}

void DrawStumpSet()
{
	float x = 0.5;
	float y = 0.2;
	glTranslatef(x, y, 0.0);
	glScalef(0.45, 0.45, 0.0);
	glRotatef(-55, 0, 0, 1);
	DrawOneStump(0,0,0);
	glLoadIdentity();

	glTranslatef(x, y, 0.0);
	glScalef(0.45, 0.45, 0.0);
	glRotatef(-35, 0, 0, 1);
	DrawOneStump(0.05,0,0);
	glLoadIdentity();

	glTranslatef(x, y, 0.0);
	glScalef(0.45, 0.45, 0.0);
	glRotatef(-45, 0, 0, 1);
	DrawOneStump(0.1,0,0);
	glLoadIdentity();
}

void DrawBdayDecor(float x, float y)
{

	for(float i = -1.0; i <= 1.1; i = i + 0.1)
	{
		DrawIsoscelesTriangleColorBday(0.05, -0.1, x + i, y + 0.1*sin(-3.8+5*i + getTimeInSeconds()), 1-i, i, 0, 1);
	}
	for(float i = -1.0; i <= 1.1; i = i + 0.1)
	{
		DrawIsoscelesTriangleColorBday(0.05, -0.1, x + i+0.05, y +0.1*sin(-3.8+5*i + getTimeInSeconds()), i, 1-i, 0, 1);
	}
}



void PlotH1(float x, float y)
{
    glBegin(GL_POLYGON);

    glColor3f(1.0, 0.43, 0.78);
    glVertex2f(x + -1 + 0.0f, y + 1.0f);
    glVertex2f(x  - 0.9f, y + 0.0f);
    glVertex2f(x + -1 + 0.1f, y + 0.0f);
    glVertex2f(x + -1 + 0.1f, y + 1.0f);

    glEnd();
}

void PlotH2(float x, float y)
{
    glBegin(GL_POLYGON);

    //glColor3f(1.0, 0.43, 0.78);
    glVertex2f(x + 0.7f, y + 1.0f);
    glVertex2f(x + 0.7f, y + 0.0f);
    glVertex2f(x + 0.8f, y + 0.0f);
    glVertex2f(x + 0.8f, y + 1.0f);

    glEnd();
}
void PlotH3(float x, float y)
{
    glBegin(GL_POLYGON);

    //glColor3f(1.0, 0.43, 0.78);
    glVertex2f(x + 0.0f, y + 0.6f);
    glVertex2f(x + 0.0f, y + 0.4f);
    glVertex2f(x + 0.8f, y + 0.4f);
    glVertex2f(x + 0.8f, y + 0.6f);

    glEnd();
}


void PlotT1(float x, float y)
{
    glBegin(GL_POLYGON);

    //glColor3f(1.0, 0.43, 0.78);
    glVertex2f(x + 0.0f, y + 1.0f);
    glVertex2f(x + 0.0f, y + 0.0f);
    glVertex2f(x + 0.1f, y + 0.0f);
    glVertex2f(x + 0.1f, y + 1.0f);

    glEnd();
}

void PlotT2(float x, float y)
{
    glBegin(GL_POLYGON);

    //glColor3f(1.0, 0.43, 0.78);
    glVertex2f(x + -0.3f,y +  1.0f);
    glVertex2f(x + -0.3f,y +  0.9f);
    glVertex2f(x + 0.4f, y + 0.9f);
    glVertex2f(x + 0.4f, y + 1.0f);

    glEnd();
}

void DrawH(float x, float y)
{
    PlotH1(x, y);
    PlotH2(x, y);
    PlotH3(x, y);
}

void DrawT(float x, float y)
{
	PlotT1(x, y);
	PlotT2(x, y);
}


void DrawGreenCover(void)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0823f, 0.4509f, 0.2470f);
	glVertex3f(-0.8f, 1.0f, 0.0f);
	glVertex3f(0.8f, 1.0f, 0.0f);
	glVertex3f(0.8f, -1.0f, 0.0f);
	glVertex3f(-0.8f, -1.0f, 0.0f);
	glEnd();
}
void DrawC(float fPointX, float fPointY, float radius)
{
	// local variable declarations
	float angle = 0;
	glBegin(GL_LINES);
	glColor3f(0.22f, 0.69f, 0.87f);
	for (angle = 0; angle < 360; angle+=1)
	{
		fPointX = radius * cos(angle);
		fPointY = radius * sin(angle);
		glVertex3f(fPointX, fPointY, 0.0f);
	}
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0823f, 0.4509f, 0.2470f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.8f, 1.0f, 0.0f);
	glVertex3f(0.8f, -1.0f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.8f, 1.0f, 0.0f);
	glVertex3f(-0.4f, 1.0f, 0.0f);
	glVertex3f(-0.8f, 0.6f, 0.0f);
	glEnd();
}