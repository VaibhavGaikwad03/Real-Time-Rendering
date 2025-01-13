float getTimeInSeconds(void)
{
    clock_t current_time = clock();
    float time_in_seconds = ((float)current_time) / CLOCKS_PER_SEC;

    return time_in_seconds;
}

int randInRange(int min, int max) {
    return min + rand() % (max - min + 1);
}