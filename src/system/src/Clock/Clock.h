#ifndef _STDLIB_COMMANDLINE_H_
#define _STDLIB_COMMANDLINE_H_

#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "sac.h"
#include "sacinterface.h"

typedef char* string;

void *create_TheClock( void)
string SACctime(time_t *t)
sac_int SACdate(sac_int *mon, sac_int *day, time_t *t)
sac_int SACclock(sac_int *min, sac_int *sec, time_t *t)
double SACdifftime(time_t *t1, time_t *t2)
sac_int SACsec(time_t *t)
sac_int SACmin(time_t *t)
sac_int SAChour(time_t *t)
sac_int SACmday(time_t *t)
sac_int SACmon(time_t *t)
sac_int SACyear(time_t *t)
sac_int SACwday(time_t *t)
sac_int SACyday(time_t *t)
time_t *SACgettime( void)
sac_int SACisdst(time_t *t)
bool SACisleap(sac_int year)
bool SACisleapt(time_t *t)
time_t *SACmktime(bool *success, sac_int year, sac_int mon, sac_int day,
                  sac_int hour, sac_int min, sac_int sec)
void SACsleep(int sec)
string SACstrftime(sac_int len, string format, time_t *t)
time_t *SACstrptime(string *res, string s, string format)
time_t *SACto_time( int secs)



#endif

