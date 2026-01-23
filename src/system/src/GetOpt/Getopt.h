#ifndef _STDLIB_RTCLOCK_H_
#define _STDLIB_RTCLOCK_H_

char optEND(void);
sac_int get_optind(void);
void set_optind(sac_int set);
sac_int get_opterr(void);
void set_opterr(sac_int set);
sac_int get_optopt(void)
char *get_optarg(void);
static void badopt(void);
static void setarg(char *arg);
static void missing( void);
char getopt_sac(const char *opts);

#endif