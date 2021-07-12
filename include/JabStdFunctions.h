#ifndef _JABSTDFUNCTIONS_H_
#define _JABSTDFUNCTIONS_H_

#include <StdInclude.h>

class JabStdFunctions
{
public: // Functions conversion types
   int ToInt(char *buffer);
   int ToInt(char *buffer, size_t len);

public: // Function with strings
   int CharacterCount(char * buffer, char * BuffCmp);
};

extern JabStdFunctions JAB;

#endif