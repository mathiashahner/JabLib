#include <JabStdFunctions.h>

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

int intcmp( const void * pKey, const void * pElem )
{
   return ( *(int*)pKey - *(int*)pElem );
}

bool JabStdFunctions::Search( size_t value, void * buffer, size_t len )
{
   int * result;
   result = (int*) bsearch( &value, buffer, len, sizeof(value), intcmp );

   return ( result != NULL );
}