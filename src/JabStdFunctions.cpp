#include <JabStdFunctions.h>

JabStdFunctions JAB;

int JabStdFunctions::ToInt( char * buffer )
{
   return( buffer, strlen( buffer ));
}

int JabStdFunctions::ToInt( char * buffer, size_t len )
{
   int result;
   char buffTmp[len];

   if( buffer == NULL )
   {
      printf("-> Buffer is NULL.\n");
   }
   else
   {
      strncpy( buffTmp, buffer, len );
      result = atoi( buffTmp );
   }

   return( result );
}

int JabStdFunctions::CharacterCount(char * Buff, char * BuffCmp)
{
   int i, j, result = 0;

   for( i=0; Buff[i] != '\0'; i++ )
   {
      for( j=0; BuffCmp[j] != '\0'; j++ )
      {
         if(( Buff[i] == BuffCmp[j] ) && ( BuffCmp[j] != ' ' ))
         {
            BuffCmp[j] = ' ';
            result++;
            break;
         }
      }
   }
   return( result );
}