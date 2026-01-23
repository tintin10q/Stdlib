#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "Clock.h"
#include "sacinterface.h"

typedef char* string;

void *create_TheClock( void)
{
    return(0);
}

string SACctime(time_t *t)
{
    string buf, res;
    buf = ctime(t);
    res = (string)malloc(strlen(buf)+1);
    strcpy(res, buf);
    return res;
}

sac_int SACdate(sac_int *mon, sac_int *day, time_t *t)
{
    struct tm *tt = localtime(t);
    *mon = (sac_int)(tt->tm_mon);
    *day = (sac_int)(tt->tm_mday);
    return (sac_int)(tt->tm_year);
}

sac_int SACclock(sac_int *min, sac_int *sec, time_t *t)
{
    struct tm *tt = localtime(t);
    *sec = (sac_int)(tt->tm_sec);
    *min = (sac_int)(tt->tm_min);
    return (sac_int)(tt->tm_hour);
}

double SACdifftime(time_t *t1, time_t *t2)
{
    return difftime(*t1, *t2);
}

sac_int SACsec(time_t *t)
{
    struct tm *tt = localtime(t);
    return (sac_int)(tt->tm_sec);
}

sac_int SACmin(time_t *t)
{
    struct tm *tt = localtime(t);
    return (sac_int)(tt->tm_min);
}

sac_int SAChour(time_t *t)
{
    struct tm *tt = localtime(t);
    return (sac_int)(tt->tm_hour);
}

sac_int SACmday(time_t *t)
{
    struct tm *tt = localtime(t);
    return (sac_int)(tt->tm_mday);
}

sac_int SACmon(time_t *t)
{
    struct tm *tt = localtime(t);
    return (sac_int)(tt->tm_mon);
}

sac_int SACyear(time_t *t)
{
    struct tm *tt = localtime(t);
    return (sac_int)(tt->tm_year);
}

sac_int SACwday(time_t *t)
{
    struct tm *tt = localtime(t);
    return (sac_int)(tt->tm_wday);
}

sac_int SACyday(time_t *t)
{
    struct tm *tt = localtime(t);
    return (sac_int)(tt->tm_yday);
}

time_t *SACgettime( void)
{
    time_t *res = (time_t *)malloc(sizeof(time_t));
    time(res);
    return res;
}

sac_int SACisdst(time_t *t)
{
    struct tm *tt = localtime(t);
    return (sac_int)(tt->tm_isdst);
}

bool SACisleap(sac_int year)
{
    return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

bool SACisleapt(time_t *t)
{
    struct tm *tt = localtime(t);
    int year=tt->tm_year + 1900;
    return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

time_t *SACmktime(bool *success,
                  sac_int year, sac_int mon, sac_int day,
						      sac_int hour, sac_int min, sac_int sec)
{
    struct tm t;
    t.tm_year = year;
    t.tm_mon = mon;
    t.tm_mday = day;
    t.tm_hour = hour;
    t.tm_min = min;
    t.tm_sec = sec;

    time_t *res = (time_t *)malloc(sizeof(time_t));
    *res = mktime(&t);

    *success = (*res < (time_t)0) ? 0 : 1;

    return res;
}

void SACsleep(sac_int sec)
{
  if (sec > 0) {
    sleep( (unsigned) sec);
  }
}

string SACstrftime(sac_int len, string format, time_t *t)
{

    string res = (string)malloc((size_t)len + 1);
    res[0] = '\0';

    struct tm *tt = localtime(t);
    if (tt != NULL) {
        if (strftime(res, len, format, tt) == 0) {
            res[0] = '\0';
        }
    }

    return res;
}

extern char *strptime(const char *, const char *, struct tm *);

/*
 * Unfortunately, the function strptime() is not declared in time.h !
 * Fortunately, the standard library libc.a contains an implementation
 * of  strptime().
 *
 * bro: Actually, time.h does have a prototype for strptime(), but
 * then _XOPEN_SOURCE must be defined before including time.h.
 */

time_t *SACstrptime(string *res, string s, string format)
{
    time_t *t = (time_t *) malloc(sizeof(time_t));

    struct tm tt;
    memset(&tt, 0, sizeof tt);
    string remain = strptime(s, format, &tt);

    /* strptime() may return NULL if it fails to match all of the format string.
    * In that case an error occurred and the contents of tt is undefined.
    */
    if (remain == NULL) {
        *t = 0;
        *res = (string)malloc(1);
        **res = '\0';
    } else {
        *t = mktime(&tt);
        *res = (string)malloc(strlen(remain) + 1);
        strcpy(*res, remain);
    }

    return t;
}

time_t *SACto_time( sac_int secs)
{
    time_t *res = (time_t *)malloc(sizeof(time_t));
    *res = (time_t)secs;
    return res;
}
