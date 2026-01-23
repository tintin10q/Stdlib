#ifndef _STDLIB_RTTIMER_H_
#define _STDLIB_RTTIMER_H_

#include <time.h>
#include "sac.h"

#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#endif

struct rtimer
{
    struct timespec elapsed;
    struct timespec started;
    int instance;
};

void current_utc_time(struct timespec *ts);
void SAC_RTimer_createRTimer(struct rtimer **ts);
void SAC_RTimer_destroyRTimer(struct rtimer *ts);
void SAC_RTimer_startRTimer(struct rtimer *timer);
void SAC_RTimer_stopRTimer(struct rtimer *timer);
void SAC_RTimer_resetRTimer(struct rtimer *timer);
void SAC_RTimer_getRTimerLong(struct rtimer *timer, long *sec, long *nsec);
double SAC_RTimer_getRTimerDbl(struct rtimer *timer);

#endif
