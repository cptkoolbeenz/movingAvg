#include <stdio.h>
#include <stdlib.h>
#include "movingAvg.h"

int main()
{
    int32_t mAvg1_buffer[10] = {0};
    mAvg_t mAvg1 = {0};
    int32_t avg = 0;

    mAvg1.m_readings = mAvg1_buffer;

    movingAvg_init(&mAvg1, 10);

    movingAvg_reading(&mAvg1, 1);
    movingAvg_reading(&mAvg1, 10);
    movingAvg_reading(&mAvg1, 5);
    movingAvg_reading(&mAvg1, 2);
    movingAvg_reading(&mAvg1, 0);
    movingAvg_reading(&mAvg1, 15);
    movingAvg_reading(&mAvg1, 100);
    movingAvg_reading(&mAvg1, 10);
    movingAvg_reading(&mAvg1, 1);
    movingAvg_reading(&mAvg1, 70);
    movingAvg_reading(&mAvg1, 70);
    movingAvg_reading(&mAvg1, 70);
    movingAvg_reading(&mAvg1, 70);

    avg = movingAvg_getAvg(&mAvg1, 10);
    printf("Average: %d\n", avg);

    return 0;
}
