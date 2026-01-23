#ifndef _STDLIB_FILESYSTEM_H_
#define _STDLIB_FILESYSTEM_H_

#include <stdlib.h>
#include <string.h>

#include "sacinterface.h"

void *create_TheEnvironment( void)
{
    return(0);
}

extern char **environ;

sac_int EnvCount(void);
char* IndexEnv(sac_int i);
sac_int ExistEnv(char *envvar);
sac_int ExistEnv(char *envvar);
sac_int SetEnv(char *envvar, char *value, sac_int overwrite);
void UnsetEnv(char *envvar);

#endif