#ifndef _STDLIB_COMMANDLINE_H_
#define _STDLIB_COMMANDLINE_H_
/*
 *  Implementation of external standard class CommandLine.
 */

#include <string.h>

#include "sacinterface.h"

typedef struct COMLINE {
    sac_int argc;
    char **argv;
} ComLine;

extern ComLine *SACo_CommandLine__TheCommandLine;

ComLine *create_TheCommandLine(void);
sac_int SACargc(void);
char *SACargv(sac_int n);
char *SACargvall(void);

#endif