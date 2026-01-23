#include "FileSystem.h"

/*
 *  implementation of class FileSystem
 */


void *create_TheFileSystem(void)
{
    return(0);
}

sac_int SACaccess(sac_int *success, char *name, sac_int how_in)
{
    int how = (int)how_in;
    int result, mode;

    switch (how)
    {
        case 0:
            mode=F_OK;
            break;
        case 1:
            mode=R_OK;
            break;
        case 2:
            mode=W_OK;
            break;
        case 3:
            mode=X_OK;
            break;
        default:
            mode=F_OK;
    }

    errno=0;

    result=access(name, mode);

    if (errno>0)
    {
        *success=errno;
    }
    else
    {
        *success=-1;
    }

    return(result==0);
}


char * SACmkdtemp (char *  template)
{
    return mkdtemp (template);
}

char *SACPtmpdir(void)
{
    char *result;

    const char tmp[] = "/tmp";
    const size_t l = strlen(tmp);

    result=(char *)SAC_MALLOC(l + 1); // null byte
    strcpy(result, tmp);

    return(result);
}


sac_int SACremove(char *name)
{
    sac_int success = remove(name);

    if (success==-1)
    {
        success=errno;
    }
    else
    {
        success=-1;
    }

    return(success);
}


char *SACgetcwd(void)
{
    char *res;
    int size=100;
    char *success;

    res=(char *)SAC_MALLOC(size);

    success=getcwd(res, size);

    while (success!=NULL)
    {
        size*=2;
        SAC_FREE(res);
        res=(char *)SAC_MALLOC(size);
        success=getcwd(res, size);
    }

    return(res);
}



sac_int SACchdir(char *name)
{
    sac_int success;

    success=chdir(name);

    if (success==-1)
    {
        success=errno;
    }
    else
    {
        success=-1;
    }

    return(success);
}


sac_int SACmkdir(char *name)
{
    sac_int success;
    mode_t mask;

    mask=umask(0);
    umask(mask);

    success=mkdir(name, mask);

    if (success==-1)
    {
        success=errno;
    }
    else
    {
        success=-1;
    }

    return(success);
}


sac_int SACrmdir(char *name)
{
    sac_int success;

    success=rmdir(name);

    if (success==-1)
    {
        success=errno;
    }
    else
    {
        success=-1;
    }

    return(success);
}



char * SACmkdtemp (char *  template)
{
    return mkdtemp (template);
}


sac_int SACrename(char *old, char *new)
{
    sac_int success = rename(old, new);

    if (success==-1)
    {
        success=errno;
    }
    else
    {
        success=-1;
    }

    return(success);
}


sac_int SACsymlink(char *name, char *link)
{
    sac_int success = symlink(name, link);

    if (success==-1)
    {
        success=errno;
    }
    else
    {
        success=-1;
    }

    return(success);
}

sac_int SACisdir(sac_int *success, char *name)
{
    struct stat buf;
    sac_int result = 0;

    *success = stat(name, &buf);

    if (*success == -1)
    {
        *success = errno;
    }
    else
    {
        *success = -1;
        result = S_ISDIR(buf.st_mode);
    }

    return (result);
}


sac_int SACisreg(sac_int *success, char *name)
{
    struct stat buf;
    sac_int result = 0;

    *success = stat(name, &buf);

    if (*success == -1)
    {
        *success = errno;
    }
    else
    {
        *success = -1;
        result = S_ISREG(buf.st_mode);
    }

    return (result);
}



sac_int SACislnk(sac_int *success, char *name)
{
    struct stat buf;
    sac_int result = 0;

    *success = stat(name, &buf);

    if (*success == -1)
    {
        *success = errno;
    }
    else
    {
        *success = -1;
        result = S_ISLNK(buf.st_mode);
    }

    return (result);
}



unsigned long long SACfilesize(sac_int *success, char *name)
{
    struct stat buf;
    unsigned long long result = 0;

    *success = stat(name, &buf);

    if (*success == -1)
    {
        *success = errno;
    }
    else
    {
        *success = -1;
        result = (unsigned long long) buf.st_size;
    }

    return (result);
}



