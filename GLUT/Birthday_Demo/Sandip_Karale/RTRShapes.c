#include <RTRMath.c>
#include <freeglut/GL/freeglut.h>

void DrawCircleWithColor(float originX, float originY, float r, float colorR, float colorG, float colorB, float a) {
    const int numSegments = 36;
    float angleIncrement = 2.0f * 3.14159f / numSegments;


    glBegin(GL_TRIANGLE_FAN);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glColor4f(colorR, colorG, colorB, a);
    glVertex3f(originX, originY, 0.0f);

    for (int i = 0; i <= numSegments; ++i) {
        float angle = i * angleIncrement;
        float x = originX + r * cos(angle);
        float y = originY + r * sin(angle);
        glVertex3f(x, y, 0.0f);
    }
    
    glEnd();
}

void DrawShadowCircle(float originX, float originY, float r, float a) {
    const int numSegments = 36;
    float angleIncrement = 2.0f * 3.14159f / numSegments;

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLE_FAN);


    glColor4f(0, 0, 0, a);
    glVertex3f(originX, originY, 0.0f);

    for (int i = 0; i <= numSegments; ++i) {

        glColor4f(0, 0, 0, 0);

        float angle = i * angleIncrement;
        float x = originX + r * cos(angle);
        float y = originY + r * sin(angle);
        glVertex3f(x, y, 0.0f);
    }
    
    glEnd();
}

void DrawShadowEllipse(float originX, float originY, float radiusX, float radiusY, float a) {
    const int numSegments = 36;
    float angleIncrement = 2.0f * 3.14159f / numSegments;

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLE_FAN);

    glColor4f(0, 0, 0, a); 
    glVertex3f(originX, originY, 0.0f);

    for (int i = 0; i <= numSegments; ++i) {
        float angle = i * angleIncrement;
        float x = originX + radiusX * cos(angle);
        float y = originY + radiusY * sin(angle);
        glColor4f(0, 0, 0, 0);
        glVertex3f(x, y, 0.0f);
    }
    
    glEnd();
    glDisable(GL_BLEND);
}
