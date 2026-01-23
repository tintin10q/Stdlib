#ifndef _STDLIB_SYSERR_H_
#define _STDLIB_SYSERR_H_

#include "sacinterface.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>

char *SACstrerror(sac_int num);

bool clear(sac_int err);
bool fail(sac_int err);

sac_int	Eperm(void);     /* Not owner */
sac_int	Enoent(void);    /* No such file or directory */
sac_int	Esrch(void);     /* No such process */
sac_int	Eintr(void);     /* Interrupted system call */
sac_int	Eio(void);       /* I/O error */
sac_int	Enxio(void);     /* No such device or address */
sac_int	E2big(void);     /* Arg list too long */
sac_int	Enoexec(void);   /* Exec format error */
sac_int	Ebadf(void);     /* Bad file number */
sac_int	Echild(void);    /* No children */
sac_int	Eagain(void);    /* No more processes */
sac_int	Enomem(void);    /* Not enough core */
sac_int	Eacces(void);    /* Permission denied */
sac_int	Efault(void);    /* Bad address */
sac_int	Enotblk(void);   /* Block device required */
sac_int	Ebusy(void);     /* Mount device busy */
sac_int	Eexist(void);    /* File exists */
sac_int	Exdev(void);     /* Cross-device link */
sac_int	Enodev(void);    /* No such device */
sac_int	Enotdir(void);   /* Not a directory*/
sac_int	Eisdir(void);    /* Is a directory */
sac_int	Einval(void);    /* Invalid argument */
sac_int	Enfile(void);    /* File table overflow */
sac_int	Emfile(void);    /* Too many open files */
sac_int	Enotty(void);    /* Not a typewriter */
sac_int	Etxtbsy(void);   /* Text file busy */
sac_int	Efbig(void);     /* File too large */
sac_int	Enospc(void);    /* No space left on device */
sac_int	Espipe(void);    /* Illegal seek */
sac_int	Erofs(void);     /* Read-only file system */
sac_int	Emlink(void);    /* Too many links */
sac_int	Epipe(void);     /* Broken pipe */

/* math software */
sac_int	Edom(void);    /* Argument too large */
sac_int	Erange(void);  /* Result too large */


/* operational errors */
sac_int	Enetdown(void);      /* Network is down */
sac_int	Enetunreach(void);   /* Network is unreachable */
sac_int	Enetreset(void);     /* Network dropped connection on reset */
sac_int	Econnaborted(void);  /* Software caused connection abort */
sac_int	Econnreset(void);    /* Connection reset by peer */
sac_int	Enobufs(void);       /* No buffer space available */
sac_int	Eisconn(void);       /* Socket is already connected */
sac_int	Enotconn(void);      /* Socket is not connected */
sac_int	Eshutdown(void);     /* Can't send after socket shutdown */
sac_int	Etoomanyrefs(void);  /* Too many references: can't splice */
sac_int	Etimedout(void);     /* Connection timed out */
sac_int	Econnrefused(void);  /* Connection refused */

/* */
sac_int	Eloop(void);         /* Too many levels of symbolic links */
sac_int	Enametoolong(void);  /* File name too long */

/* should be rearranged */
sac_int	Ehostdown(void);     /* Host is down */
sac_int	Ehostunreach(void);  /* No route to host */
sac_int	Enotempty(void);     /* Directory not empty */

/* quotas & mush */
sac_int	Eusers(void);  /* Too many users */
sac_int	Edquot(void);  /* Disc quota exceeded */

/* network file system */
sac_int	Estale(void);   /* Stale NFS file handle */
sac_int	Eremote(void);  /* Too many levels of remote in path */

#endif