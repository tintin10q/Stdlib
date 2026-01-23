/*
 *  Implementation of class Environment
 */
#include "Environment.h"

void *create_TheEnvironment( void)
{
  return(0);
}

extern char **environ;

sac_int EnvCount( void)
{
    sac_int i = 0;

    if (environ) {
        while (environ[i]) {
            ++i;
        }
    }

    return i;
}

char* IndexEnv( sac_int i)
{
    char* res;
    sac_int k = 0;

    if (environ) {
        while (k < i && environ[k]) {
            ++k;
        }
    }
    if (i != k || !environ || environ[k] == NULL) {
        res = (char*) SAC_MALLOC(1);
        *res = '\0';
    } else {
        res = (char*) SAC_MALLOC(strlen(environ[k]) + 1);
        strcpy(res, environ[k]);
    }

    return res;
}


sac_int ExistEnv(char *envvar)
{
    return (getenv(envvar) != NULL);
}


sac_int ExistEnv(char *envvar)
{
    return (getenv(envvar) != NULL);
}


sac_int SetEnv(char *envvar, char *value, sac_int overwrite)
{
    int res = 0;

    if (overwrite || (getenv(envvar) == NULL))
    {
#if HAVE_SETENV
        res = setenv(envvar, value, overwrite);
#else
        size_t size = strlen(envvar) + 1 + strlen(value) + 1;
        char* buf = (char*) SAC_MALLOC(size);
        strcpy(buf, envvar);
        strcat(buf, "=");
        strcat(buf, value);
        putenv(buf);
#endif
    }

    return (res);
}


void UnsetEnv(char *envvar)
{
#if HAVE_UNSETENV
    unsetenv(envvar);
#else
    putenv(envvar);
#endif
}

