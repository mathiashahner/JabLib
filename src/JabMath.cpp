#include <JabMath.h>

size_t JabMath::Pot( size_t num )
{
   return( Pot( num, 2 ))
}

size_t JabMath::Pot( size_t num, size_t exp );
{
   size_t count, result;

   result = num;

   for( count = 0; count < exp; count++ )
   {
      result *= num;
   }
   return( result );
}