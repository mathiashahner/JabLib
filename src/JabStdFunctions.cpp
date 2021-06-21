#include <JabStdFunctions.h>

size_t JabStdFunctions::strlen( char * buffer, size_t len )
{
   if( buffer != NULL )
   {
      size_t count = 0;
      while ( buffer[count] != '\0' )
      {
         len++;
         count++;
      }
   }
   return len;
}

bool JabStdFunctions::strcpy( char * destination, char * source )
{
   return 0;
}