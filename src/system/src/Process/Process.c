#include "Process.h"

void SACpclose (FILE *f)
{
  pclose( f);
}

sac_int SACsystem (char *command)
{
  const char *  cmd = command;
  return (sac_int)system (cmd);
}

sac_int SACpopen(FILE ** stream, char *command, char *mode)
{
  int error = -1;

  *stream = popen( command, mode);

  if (*stream == NULL)
  {
    error = errno;
  }

  return (error);
}

