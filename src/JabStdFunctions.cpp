#include <JabStdFunctions.h>

JabStdFunctions JAB;

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

int JabStdFunctions::ToInt( char * buffer )
{
int result = 0;

   if ( buffer == NULL )
   {
      printf("-> Buffer is NULL.\n");
   }
   else
   {
      result = atoi(buffer);
   }

   return result;
}

int JabStdFunctions::ToInt( char * buffer, size_t len )
{
char buffTmp[len];

   if ( buffer == NULL )
   {
      printf("-> Buffer is NULL.\n");
   }
   else
   {
      strncpy(buffTmp, buffer, len);
   }

   return(ToInt(buffTmp));
}