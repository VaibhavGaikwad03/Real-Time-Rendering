#include "utils.h"
#include "time.h"
#include <Windows.h>

float GetTimeInSeconds(void)
{
	clock_t current_time = clock();
	float time_in_seconds = ((float)current_time) / CLOCKS_PER_SEC;

	return time_in_seconds;
}

float calculateIncrementPerFrame(float increment)
{
	DEVMODE devMode;
	devMode.dmSize = sizeof(DEVMODE);

	if (!EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &devMode))
		return 0.0f;

	float incrementPerSecond = increment * TARGET_REFRESH_RATE;

	float incrementPerFrame = incrementPerSecond / devMode.dmDisplayFrequency;

	return incrementPerFrame;
}

float calculateIncrementPerFrameFromValues(float startValue, float endValue, float totalDistance, float distancePerFrame)
{
    float totalChange = endValue - startValue;

    float numberOfFrames = totalDistance / distancePerFrame;

    float incrementPerFrame = totalChange / numberOfFrames;

    return incrementPerFrame;
}
