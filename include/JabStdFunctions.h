#ifndef _JABSTDFUNCTIONS_H_
#define _JABSTDFUNCTIONS_H_

#include <StdInclude.h>

class JabStdFunctions
{
public: // Function conversion types
   int ToInt(char *buffer);
   int ToInt(char *buffer, size_t len);
};

extern JabStdFunctions JAB;

#endif