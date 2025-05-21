#include "utils.h"
#include "time.h"

float GetTimeInSeconds(void)
{
	clock_t current_time = clock();
	float time_in_seconds = ((float)current_time) / CLOCKS_PER_SEC;

	return time_in_seconds;
}