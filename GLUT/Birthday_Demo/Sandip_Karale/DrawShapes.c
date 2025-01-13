#include <math.h> 
#include <time.h>
#include <RTRShapes.c>
#include <RTRUtils.c>
#include <GL/gl.h>


void DrawRect(float w, float h, float ox, float oy) {
    //glColor3f(0.0, 0.5, 1.0);
    glBegin(GL_TRIANGLES);

	glVertex3f(ox-w/2, oy+h/2, 0.0f);
	glVertex3f(ox-w/2, oy-h/2, 0.0f);
	glVertex3f(ox+w/2, oy-h/2, 0.0f);

	glVertex3f(ox+w/2, oy-h/2, 0.0f);
	glVertex3f(ox+w/2, oy+h/2, 0.0f);
	glVertex3f(ox-w/2, oy+h/2, 0.0f);

    glEnd();
}

void DrawDiagSlash(float w, float h, float ox, float oy, float d) {
    //glColor3f(0.0, 0.5, 1.0);
    glBegin(GL_TRIANGLES);

	glVertex3f(ox-w/2, oy+h/2, 0.0f);
	glVertex3f(d+ox-w/2, oy-h/2, 0.0f);
	glVertex3f(d+ox+w/2, oy-h/2, 0.0f);

	glVertex3f(d+ox+w/2, oy-h/2, 0.0f);
	glVertex3f(ox+w/2, oy+h/2, 0.0f);
	glVertex3f(ox-w/2, oy+h/2, 0.0f);

    glEnd();
}

void DrawDiagBackSlash(float w, float h, float ox, float oy, float d) {
    //glColor3f(0.0, 0.5, 1.0);
    glBegin(GL_TRIANGLES);

	glVertex3f(d+ox-w/2, oy+h/2, 0.0f);
	glVertex3f(ox-w/2, oy-h/2, 0.0f);
	glVertex3f(ox+w/2, oy-h/2, 0.0f);

	glVertex3f(ox+w/2, oy-h/2, 0.0f);
	glVertex3f(d+ox+w/2, oy+h/2, 0.0f);
	glVertex3f(d+ox-w/2, oy+h/2, 0.0f);

    glEnd();
}

void Draw_K(float ox, float oy){
    DrawRect(0.2, 2.0, ox + 0, oy + 0);
    DrawDiagSlash(0.2, 1.2, ox + 0, oy - 0.5, 0.7);
    DrawDiagBackSlash(0.2, 1.2, ox + 0, oy + 0.5, 0.7);
}

void Draw_L(float ox, float oy){
    DrawRect(0.2, 2.0, ox + 0, oy + 0);
    DrawRect(1.0, 0.2, ox + 0.5, oy - 0.9);
}

void Draw_M(float ox, float oy){
    DrawRect(0.2, 2.0, ox - 0.9, oy + 0);
    DrawDiagSlash(0.25, 2, ox - 1, oy + 0.4, 1.0);
    DrawDiagBackSlash(0.25, 2, ox + 0, oy + 0.4, 1.0);
    DrawRect(0.2, 2.0, ox + 0.9, oy + 0);
}

void Draw_N(float ox, float oy){
    DrawRect(0.2, 2.0, ox - 0.9, oy);
    DrawDiagSlash(0.35, 2, ox - 1, oy, 2.0);
    DrawRect(0.2, 2.0, ox + 0.9, oy);
}

void Draw_O(float ox, float oy){
    DrawRect(0.2, 2.0, ox - 0.9, oy);
    DrawRect(0.2, 2.0, ox + 0.9, oy);
    DrawRect(2.0, 0.2, ox, oy - 0.9);
    DrawRect(2.0, 0.2, ox, oy + 0.9);
}

void Draw_P(float ox, float oy){
    DrawRect(0.2, 2.0, ox, oy);
    DrawRect(0.2, 1.0, ox + 0.9, oy + 0.5);
    DrawRect(1.0, 0.2, ox + 0.5, oy);
    DrawRect(1.0, 0.2, ox + 0.5, oy + 0.9);
}

void Draw_S(float ox, float oy){
    DrawRect(2.0, 0.2, ox, oy + 0.9);
    DrawRect(0.2, 1.0, ox - 0.9, oy + 0.5);
    DrawRect(0.2, 1.0, ox + 0.9, oy - 0.5);
    DrawRect(2.0, 0.2, ox, oy);
    DrawRect(2.0, 0.2, ox, oy - 0.9);
}

void Draw_R(float ox, float oy){
    DrawRect(0.25, 2.0, ox - 0.1, oy);
    DrawRect(0.2, 1.0, ox + 0.9, oy + 0.5);
    DrawRect(1.0, 0.2, ox + 0.5, oy);
    DrawRect(1.0, 0.2, ox + 0.5, oy + 0.9);
    DrawDiagSlash(0.35, 1, ox, oy - 0.5, 1.0);
}

void Draw_B(float ox, float oy){
    DrawRect(0.2, 2.0, ox, oy);
    DrawRect(0.2, 1.0, ox + 0.9, oy + 0.5);
    DrawRect(1.0, 0.2, ox + 0.5, oy);
    DrawRect(1.1, 0.2, ox + 0.3, oy + 0.9);
    DrawRect(0.2, 1.0, ox + 0.9, oy - 0.5);
    DrawRect(1.1, 0.2, ox + 0.3, oy - 0.9);
}

void Draw_A(float ox, float oy){
    DrawRect(0.2, 2.0, ox, oy);
    DrawRect(0.2, 1.0, ox + 0.9, oy + 0.5);
    DrawRect(1.0, 0.2, ox + 0.5, oy);
    DrawRect(1.0, 0.2, ox + 0.5, oy + 0.9);
    DrawRect(0.2, 1.0, ox + 0.9, oy - 0.5);
}

void Draw_H(float ox, float oy){
    DrawRect(0.2, 2.0, ox, oy);
    DrawRect(0.2, 1.0, ox + 0.9, oy + 0.5);
    DrawRect(1.0, 0.2, ox + 0.5, oy);
    //DrawRect(1.0, 0.2, ox + 0.5, oy + 0.9);
    DrawRect(0.2, 1.0, ox + 0.9, oy - 0.5);
}

void Draw_E(float ox, float oy){
    DrawRect(0.2, 2.0, ox, oy);
    DrawRect(1.0, 0.2, ox + 0.5, oy);
    DrawRect(1.0, 0.2, ox + 0.5, oy + 0.9);
    DrawRect(1.0, 0.2, ox + 0.5, oy - 0.9);
}

void Draw_I(float ox, float oy){
    DrawRect(0.2, 2.0, ox, oy);
    DrawRect(1.0, 0.2, ox, oy + 0.9);
    DrawRect(1.0, 0.2, ox, oy - 0.9);
}

void Draw_T(float ox, float oy){
    DrawRect(0.2, 2.0, ox, oy);
    DrawRect(1.5, 0.2, ox, oy + 0.9);
    //DrawRect(1.0, 0.2, ox, oy - 0.9);
}

void Draw_V(float ox, float oy){
    DrawDiagSlash(0.25, 2, ox - 1, oy, 1.0);
    DrawDiagBackSlash(0.25, 2, ox, oy, 1.0);
}

void Draw_Y(float ox, float oy){
    DrawDiagSlash(0.25, 1, ox - 1, oy + 0.5, 1.0);
    DrawDiagBackSlash(0.25, 1, ox, oy+ 0.5, 1.0);
    DrawRect(0.2, 1.0, ox, oy - 0.5);

}

void Draw_D(float ox, float oy){
    DrawRect(0.2, 2.0, ox - 0.7, oy);
    DrawRect(0.2, 2.0, ox + 0.9, oy);
    DrawRect(2.0, 0.2, ox, oy - 0.9);
    DrawRect(2.0, 0.2, ox, oy + 0.9);
}

void Draw_G(float ox, float oy){
    DrawRect(0.2, 2.0, ox, oy);
    DrawRect(0.5, 0.2, ox + 0.75, oy);
    DrawRect(1.0, 0.2, ox + 0.5, oy + 0.9);
    DrawRect(0.2, 1.0, ox + 0.9, oy - 0.5);
    DrawRect(1.0, 0.2, ox + 0.5, oy - 0.9);
}

void DrawRectWithColor(float w, float h, float ox, float oy, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);
	glVertex3f(ox-w/2, oy+h/2, 0.0f);
	glVertex3f(ox-w/2, oy-h/2, 0.0f);
	glVertex3f(ox+w/2, oy-h/2, 0.0f);

	glVertex3f(ox+w/2, oy-h/2, 0.0f);
	glVertex3f(ox+w/2, oy+h/2, 0.0f);
	glVertex3f(ox-w/2, oy+h/2, 0.0f);

    glEnd();
}

void DrawRectWithGradient(float w, float h, float ox, float oy, float r1, float g1, float b1, float r2, float g2, float b2, int gradientDirection) {
    glBegin(GL_TRIANGLES);

    if (gradientDirection == -1) {
        // Top-to-bottom gradient
        glColor3f(r1, g1, b1); // Top color
        glVertex3f(ox - w / 2, oy + h / 2, 0.0f);
        glVertex3f(ox + w / 2, oy + h / 2, 0.0f);

        glColor3f(r2, g2, b2); // Bottom color
        glVertex3f(ox - w / 2, oy - h / 2, 0.0f);

        glVertex3f(ox + w / 2, oy + h / 2, 0.0f);
        glVertex3f(ox + w / 2, oy - h / 2, 0.0f);
        glVertex3f(ox - w / 2, oy - h / 2, 0.0f);
    } else {
        // Bottom-to-top gradient
        glColor3f(r2, g2, b2); // Bottom color
        glVertex3f(ox - w / 2, oy + h / 2, 0.0f);
        glVertex3f(ox + w / 2, oy + h / 2, 0.0f);

        glColor3f(r1, g1, b1); // Top color
        glVertex3f(ox - w / 2, oy - h / 2, 0.0f);

        glVertex3f(ox + w / 2, oy + h / 2, 0.0f);
        glVertex3f(ox + w / 2, oy - h / 2, 0.0f);
        glVertex3f(ox - w / 2, oy - h / 2, 0.0f);
    }

    glEnd();
}

void DrawPiano(float originX, float originY) {
    DrawRectWithColor(2.0, 0.8, originX, originY + 0.1, 0.2, 0.2, 0.2);

    float numWhiteKeys = 15;
    float whiteKeyWidth = 1 / numWhiteKeys;

    for (float i = -0.9; i < 0.9; i += whiteKeyWidth) {
        float x = originX + i;
        DrawRectWithColor(whiteKeyWidth - 0.005, 0.5, x, originY, 0.95, 0.95, 0.95);
    }

    int count = 0;
    int maxcount = 2;

    for (float i = -0.9; i < 0.85; i += whiteKeyWidth) {
        if (count == maxcount) {
            maxcount = (maxcount == 2) ? 3 : 2;
            count = 0;
        } else {
            float x = originX + i + (whiteKeyWidth / 2.0);
            float y = originY + (0.5 - 0.32) / 2.0;
            DrawRectWithColor(whiteKeyWidth - 0.02, 0.32, x, y, 0.0, 0.0, 0.0);
            count++;
        }
    }
}

void DrawMusicLines1(void)
{
    int numLines = 2;

        glBegin(GL_LINE_STRIP);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        for(float i = -0.0; i <= 0.5; i = i + 0.01)
        {
            glColor4f(1.0, 1.0, 1.0,  i);
            glVertex3f(i,  0.3+ (float)0.2/numLines  + 0.15*sin(20.0f*(i + getTimeInSeconds()/10.0)), 0.0f);
        }
        glEnd();

        glBegin(GL_LINE_STRIP);

        for(float i = -0.0; i <= 0.3; i = i + 0.01)
        {
            glColor4f(1.0, 1.0, 1.0, i);

            glVertex3f(i,  0.4+ (float)0.2/numLines  + 0.15*sin(3.14 + 20.0f*(i + getTimeInSeconds()/10.0)), 0.0f);
        }
        glEnd();
}

void DrawQuarterNote(float x, float y){
    DrawRectWithColor(0.01, 0.2, x, y, 0.0, 0.0, 0.0);
    struct Circle S = {
                .color = {0, 0, 0},
                .origin = {-0.02 + x , -0.1 + y},
                .radius = 0.02f
            };
    DrawCircle(S);
}

void DrawBeamedEighthNote(float x, float y)
{
    DrawQuarterNote(x,y);
    DrawQuarterNote(x+0.08,y);
    DrawRectWithColor(0.08, 0.02, x+0.04, y+0.09, 0.0, 0.0, 0.0);
}

void DrawBeamedSixteenthNote(float x, float y)
{
    DrawQuarterNote(x,y);
    DrawQuarterNote(x+0.08,y);
    DrawRectWithColor(0.08, 0.02, x+0.04, y+0.09, 0.0, 0.0, 0.0);
    DrawRectWithColor(0.08, 0.01, x+0.04, y+0.06, 0.0, 0.0, 0.0);
}

void DrawSlantedBeamedEighthNote(float x, float y)
{
    DrawQuarterNote(x,y);
    DrawQuarterNote(x+0.08,y+0.05);
    DrawDiagBackSlash(0.015, 0.055, x+0.001, y+0.12, 0.076);
    //DrawRectWithColor(0.08, 0.02, x+0.04, y+0.09, 0.0, 0.0, 0.0);
    //DrawRectWithColor(0.08, 0.01, x+0.04, y+0.06, 0.0, 0.0, 0.0);
}

void DrawSlantedBeamedSixteenthNote(float x, float y)
{
    DrawQuarterNote(x,y);
    DrawQuarterNote(x+0.08,y+0.05);
    DrawDiagBackSlash(0.015, 0.055, x+0.001, y+0.12, 0.076);
    DrawDiagBackSlash(0.02, 0.055, x+0.001, y+0.085, 0.076);
    //DrawRectWithColor(0.08, 0.02, x+0.04, y+0.09, 0.0, 0.0, 0.0);
    //DrawRectWithColor(0.08, 0.01, x+0.04, y+0.06, 0.0, 0.0, 0.0);
}

void DrawEighthNote(float x, float y){
    DrawRectWithColor(0.01, 0.2, x, y, 0.0, 0.0, 0.0);
    struct Circle S = {
                .color = {0, 0, 0},
                .origin = {-0.02 + x , -0.1 + y},
                .radius = 0.02f
            };
    DrawCircle(S);
    DrawDiagSlash(0.01, 0.055, x+0.001, y+0.07, 0.04);
}

void DrawSixteenthNote(float x, float y){
    DrawRectWithColor(0.01, 0.2, x, y, 0.0, 0.0, 0.0);
    struct Circle S = {
                .color = {0, 0, 0},
                .origin = {-0.02 + x , -0.1 + y},
                .radius = 0.02f
            };
    DrawCircle(S);
    DrawDiagSlash(0.01, 0.055, x+0.001, y+0.07, 0.04);
    DrawDiagSlash(0.01, 0.055, x+0.001, y+0.03, 0.04);
}

void DrawThirdySecondNote(float x, float y){
    DrawRectWithColor(0.01, 0.2, x, y, 0.0, 0.0, 0.0);
    struct Circle S = {
                .color = {0, 0, 0},
                .origin = {-0.02 + x , -0.1 + y},
                .radius = 0.02f
            };
    DrawCircle(S);
    DrawDiagSlash(0.01, 0.055, x+0.001, y+0.07, 0.04);
    DrawDiagSlash(0.01, 0.055, x+0.001, y+0.035, 0.04);
    DrawDiagSlash(0.01, 0.055, x+0.001, y, 0.04);
}

void DrawNotesOnSineWave(float amplitude, float frequency, float speed, float originX, float originY) {
    float time = getTimeInSeconds();

    int numNotes = 5;

    float startX = originX - 0.8;
    float endX = originX + 0.8;
    float step = (endX - startX) / (numNotes - 1);

    for (int i = 0; i < numNotes; i++) {
        float x = startX + i * step;
        float y = originY + amplitude * sin(frequency * x + speed * time);

        switch (i) {
            case 0:
                DrawQuarterNote(x, y);
                break;
            case 1:
                DrawEighthNote(x, y);
                break;
            case 2:
                DrawSixteenthNote(x, y);
                break;
            case 3:
                DrawThirdySecondNote(x, y);
                break;
            case 4:
                DrawBeamedSixteenthNote(x, y);
                break;
            case 5:
                DrawBeamedEighthNote(x, y);
                break;
            case 6:
                DrawSlantedBeamedEighthNote(x, y);
                break;
            case 7:
                DrawSlantedBeamedSixteenthNote(x, y);
                break;
        }
    }
}

void DrawRectangleStrip(float originX, float originY, float stripeWidth, float stripeHeight, float r, float g, float b)
{
    int numStripes = 200;
    float frequency = 2.0;
    float amplitude = 0.01;
    float speed = 2;
    float time = getTimeInSeconds(); 

    glBegin(GL_TRIANGLES);
    glColor3f(r, g, b);

    for (int i = 0; i < numStripes; ++i)
    {
        float left = originX + i * stripeWidth;
        float right = left + stripeWidth;

        float waveOffsetTop = 0.5*cos(-frequency*3 * left + 2.0 * time) + (left+1.0)*amplitude * sin(-frequency * left + speed * time);
        waveOffsetTop = waveOffsetTop/7.0;
        float waveOffsetBottom = waveOffsetTop;

        float top = originY + waveOffsetTop;
        top = top/2.0;
        float bottom = originY - stripeHeight + waveOffsetBottom;
        bottom = bottom/2.0;

        glVertex3f(left, top, 0.0f);
        glVertex3f(left, bottom, 0.0f);
        glVertex3f(right, top, 0.0f);

        glVertex3f(left, bottom, 0.0f);
        glVertex3f(right, bottom, 0.0f);
        glVertex3f(right, top, 0.0f);
    }
    glEnd();
}

void DrawIsoscelesTrapezoidWithColor(float topWidth, float bottomWidth, float height, float ox, float oy, float r, float g, float b, float a, int gradient) {
    float halfTopWidth = topWidth / 2.0f;
    float halfBottomWidth = bottomWidth / 2.0f;

    float topAlpha = a;
    float bottomAlpha = a;
    if (gradient == 1) {
        topAlpha = 0.0;
        bottomAlpha = a;
    } else if (gradient == -1) {
        topAlpha  = a;
        bottomAlpha = 0;
    }

    glBegin(GL_TRIANGLES);

    glColor4f(r, g, b, bottomAlpha);
    glVertex3f(ox - halfBottomWidth, oy - height / 2, 0.0f);

    glColor4f(r, g, b, bottomAlpha);
    glVertex3f(ox + halfBottomWidth, oy - height / 2, 0.0f);

    glColor4f(r, g, b, topAlpha);
    glVertex3f(ox - halfTopWidth, oy + height / 2, 0.0f);

    glColor4f(r, g, b, topAlpha);
    glVertex3f(ox + halfTopWidth, oy + height / 2, 0.0f);

    glColor4f(r, g, b, topAlpha);
    glVertex3f(ox - halfTopWidth, oy + height / 2, 0.0f);

    glColor4f(r, g, b, bottomAlpha);
    glVertex3f(ox + halfBottomWidth, oy - height / 2, 0.0f);

    glEnd();
}

void DrawTV(void)
{
    float alphaOfTVScreen = 0.3+0.2*sin(2.0*getTimeInSeconds() + 10.0)*sin(getTimeInSeconds());

    DrawRectWithColor(0.6, 0.3, 0, 0, 0.5,0.3,0.184);
    DrawIsoscelesTrapezoidWithColor(0.4, 0.6, 0.09, 0, 0.2, 0.25,0.13,0.09, 1, 0);

	DrawShadowEllipse(-0.0,0.1,0.3,0.15,0.7);

    DrawRectWithColor(0.62, 0.02, 0, 0.1, 0.1,0.1,0.1);
    DrawDiagSlash(0.02, 0.11, 0.3, 0.05, 0.1);
    DrawDiagBackSlash(0.02, 0.11, -0.4, 0.05, 0.1);
    DrawIsoscelesTrapezoidWithColor(0.59, 0.79, 0.1, 0, 0.05, alphaOfTVScreen, alphaOfTVScreen, 0.6, 1.0 , 0);
    
    DrawIsoscelesTrapezoidWithColor(0.7, 0.3, 0.07, 0, -0.05, .1, .1, .1, 1, 0);

    DrawRectWithColor(0.82, 0.06, 0, -0.03, 0.1,0.1,0.1);

    //TV Lights
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    DrawIsoscelesTrapezoidWithColor(2.0, 0.8, 1.0, 0., 0.5, 0.7, 0.7, 1.0, alphaOfTVScreen, 1);

}


