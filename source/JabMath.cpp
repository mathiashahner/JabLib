#include <JabMath.h>

size_t JabMath::Pot( size_t num )
{
   return Pot( num, 2 );
}

size_t JabMath::Pot( size_t num, size_t exp )
{
   size_t count, result;
   result = num;

   for ( count = 1; count < exp; count++ )
   {
      result *= num;
   }
   return result;
}

size_t JabMath::Factorial( size_t num )
{
   size_t count, result;

   if ( num < 0 )
   {
      result = 0;
      printf("ERROR: factorial can't be calculated\n");
   }
   else if ( num == 0 )
   {
      result = 1;
   }
   else
   {
      result = num;

      for ( count = 1; count < num; count++ )
      {
         result *= ( num - count );
      }
   }
   return result;
}