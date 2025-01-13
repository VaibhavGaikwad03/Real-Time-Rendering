#include <freeglut/GL/freeglut.h>

void DrawFadingRectangle(float width, float height, float startTime, float duration, int fadeIn) {
    float currentTime = getTimeInSeconds();
    float elapsed = currentTime - startTime;
    float fadeFactor;

    if (fadeIn == 1) {
        fadeFactor = (elapsed / duration);
        if (fadeFactor > 1.0f) fadeFactor = 1.0f;
    } 
    else if (fadeIn == 0){
        fadeFactor = 1.0f - (elapsed / duration);
        if (fadeFactor < 0.0f) fadeFactor = 0.0f;
    }

    float halfWidth = width / 2.0f;
    float halfHeight = height / 2.0f;

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_TRIANGLES);

        glColor4f(0.0f, 0.0f, 0.0f, fadeFactor);
        glVertex3f(-halfWidth, -halfHeight, 0.0f);
        glVertex3f(halfWidth, -halfHeight, 0.0f);
        glVertex3f(-halfWidth, halfHeight, 0.0f);
        glVertex3f(halfWidth, -halfHeight, 0.0f);
        glVertex3f(halfWidth, halfHeight, 0.0f);
        glVertex3f(-halfWidth, halfHeight, 0.0f);
    glEnd();

    glDisable(GL_BLEND);
}