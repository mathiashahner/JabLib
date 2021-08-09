#ifndef _JABSTDFUNCTIONS_H_
#define _JABSTDFUNCTIONS_H_

#include <StdInclude.h>
#include <JabMath.h>

class JabStdFunctions
{
public: // Functions conversion types
   int ToInt( char * buffer );
   int ToInt( char * buffer, size_t len );

public: // Function with strings
   int CharacterCount( char * buffer, char * BuffCmp );
   void StrPadding( char * buffer, char * bufferOutput, size_t lenMax, char charPadding );

public:
   bool Search( size_t value, void * buffer, size_t len );
};

extern JabStdFunctions JAB;

#endif