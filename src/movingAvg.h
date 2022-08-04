// Moving Average Library
// Adapted from https://github.com/JChristensen/movingAvg
// Copyright (C) 2022 by Christopher Lange and licensed under
// GNU GPL v3.0, https://www.gnu.org/licenses/gpl.html

#ifndef MOVINGAVG_H_INCLUDED
#define MOVINGAVG_H_INCLUDED

#include <stdint.h>


typedef struct _mAvg_t
{
	int32_t m_interval;     // number of data pointers for the moving average
	int32_t m_nbrReadings;  // number of readings
	int64_t m_sum;         	// sum of the m_readings array
	int32_t m_next;         // index to the next reading
	int32_t* m_readings;    // pointer to the allocated interval array
} mAvg_t;

void movingAvg_init(mAvg_t *mAvgData, uint16_t maxAvgLength);
int32_t movingAvg_reading(mAvg_t *mAvgData, int32_t newReading);
int32_t movingAvg_getAvg(mAvg_t *mAvgData, int32_t nPoints);
void movingAvg_reset(mAvg_t *mAvgData);

#endif
