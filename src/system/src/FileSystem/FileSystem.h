#ifndef _STDLIB_FILESYSTEM_H_
#define _STDLIB_FILESYSTEM_H_

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

void * create_TheFileSystem(void);
sac_int SACaccess(sac_int *success, char *name, sac_int how_in);
char * SACmkdtemp (char *template);
char * SACPtmpdir(void);
sac_int SACremove(char *name);
char * SACgetcwd(void);
sac_int SACchdir(char *name);
sac_int SACmkdir(char *name);
sac_int SACrmdir(char *name);
sac_int SACrename(char *old, char *new);
sac_int SACsymlink(char *name, char *link);
sac_int SACisdir(sac_int *success, char *name)
sac_int SACisreg(sac_int *success, char *name)
sac_int SACislnk(sac_int *success, char *name)
unsigned long long SACfilesize(sac_int *success, char *name)

#endif