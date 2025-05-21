#ifndef UTILS_H
#define UTILS_H

#define TARGET_REFRESH_RATE 165

float GetTimeInSeconds(void);
float calculateIncrementPerFrame(float increment);
float calculateIncrementPerFrameFromValues(float startValue, float endValue, float totalDistance, float distancePerFrame);

#endif // UTILS_H