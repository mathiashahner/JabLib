#ifndef _JABSTDFUNCTIONS_H_
#define _JABSTDFUNCTIONS_H_

#include <StdInclude.h>

class JabStdFunctions
{
public: // Function with Strings
   size_t strlen( char * buffer, size_t len = 0 );
   bool strcpy( char * destination, char * source );

public: // Function conversion types
   int ToInt( char * buffer );
   int ToInt( char * buffer, size_t len );
};

extern JabStdFunctions JAB;

#endif