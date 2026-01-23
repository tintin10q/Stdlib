#ifndef _STDLIB_RTCLOCK_H_
#define _STDLIB_RTCLOCK_H_

#include <stdio.h>
#include <errno.h>

#include "sac.h"


sac_int SACsystem (unsigned char *command);
sac_int SACpopen(FILE ** stream, char *command, char *mode);
sac_int SACpopen(FILE ** stream, char *command, char *mode);

#endif