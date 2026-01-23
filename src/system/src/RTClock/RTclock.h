#ifndef _STDLIB_RTCLOCK_H_
#define _STDLIB_RTCLOCK_H_
/******************************************************************************
 *
 * @file rtclock.c
 *
 * @brief This module implements the functionally sound integration of the
 * real time clock into the world of SAC.
 *
 ******************************************************************************/
#include <time.h>

#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#endif

void *SAC_RTClock_createTheRTClock(void);
void SAC_RTClock_touch(void *rtclock);
void SAC_RTClock_gettime(long *sec, long *nsec);

#endif