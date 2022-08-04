// Moving Average Library
// Adapted from https://github.com/JChristensen/movingAvg
// Copyright (C) 2022 by Christopher Lange and licensed under
// GNU GPL v3.0, https://www.gnu.org/licenses/gpl.html

#include "movingAvg.h"

// initialize - allocate the interval array
void movingAvg_init(mAvg_t *mAvgData, uint16_t maxAvgLength)
{
	mAvgData->m_nbrReadings = 0;
    mAvgData->m_sum = 0;
    mAvgData->m_next = 0;
	mAvgData->m_interval = maxAvgLength;
}

// add a new reading and return the new moving average
int32_t movingAvg_reading(mAvg_t *mAvgData, int32_t newReading)
{
    // add each new data point32_t to the sum until the m_readings array is filled
    if (mAvgData->m_nbrReadings < mAvgData->m_interval) {
        ++mAvgData->m_nbrReadings;
        mAvgData->m_sum += newReading;
    }
    // once the array is filled, subtract the oldest data point32_t and add the new one
    else {
        mAvgData->m_sum = mAvgData->m_sum - mAvgData->m_readings[mAvgData->m_next] + newReading;
    }

    mAvgData->m_readings[mAvgData->m_next] = newReading;
    if (++mAvgData->m_next >= mAvgData->m_interval) mAvgData->m_next = 0;
    return (mAvgData->m_sum + mAvgData->m_nbrReadings / 2) / mAvgData->m_nbrReadings;
}

// return the average for a subset of the data, the most recent nPoints readings.
// for invalid values of nPoints, return zero.
int32_t movingAvg_getAvg(mAvg_t *mAvgData, int32_t nPoints)
{
    if (nPoints < 1 || nPoints > mAvgData->m_interval || nPoints > mAvgData->m_nbrReadings) {
        return 0;
    }
    else {
        int64_t sum = {0};
        int32_t i = mAvgData->m_next;
        int32_t n = 0;
        for (n = 0; n < nPoints; ++n) {
            if (i == 0) {
                i = mAvgData->m_interval - 1;
            }
            else {
                --i;
            }
            sum += mAvgData->m_readings[i];
        }
        return (sum + nPoints / 2) / nPoints;
    }
}

// start the moving average over again
void movingAvg_reset(mAvg_t *mAvgData)
{
    mAvgData->m_nbrReadings = 0;
    mAvgData->m_sum = 0;
    mAvgData->m_next = 0;
}
