#include <JabStdFunctions.h>
#include <JabMath.h>

JabStdFunctions JAB;

int JabStdFunctions::ToInt( char * buffer )
{
   return ToInt( buffer, strlen(buffer));
}

int JabStdFunctions::ToInt( char * buffer, size_t len )
{
   int result = 0;
   
   if ( buffer == NULL )
   {
      printf("-> Buffer is NULL.\n");
   }
   else
   {
      char buffTmp[len];

      strncpy( buffTmp, buffer, len );
      result = atoi(buffTmp);
   }
   return result;
}

int JabStdFunctions::CharacterCount( char * Buff, char * BuffCmp )
{
   int count, countAux, result = 0;

   for ( count=0; Buff[count] != '\0'; count++ )
   {
      for ( countAux=0; BuffCmp[countAux] != '\0'; countAux++ )
      {
         if (( Buff[count] == BuffCmp[countAux] ) && ( BuffCmp[countAux] != ' ' ))
         {
            BuffCmp[countAux] = ' ';
            result++;
            break;
         }
      }
   }
   return result;
}