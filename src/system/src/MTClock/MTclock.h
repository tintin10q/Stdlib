#ifndef _STDLIB_RTCLOCK_H_
#define _STDLIB_RTCLOCK_H_

#include <time.h>
#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#endif

void *SAC_MTClock_createTheMTClock(void);
void SAC_MTClock_touch(void *mtclock);
void SAC_MTClock_gettime(long *sec, long *nsec);

#endif