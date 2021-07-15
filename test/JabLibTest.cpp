#include <StdInclude.h>
#include <JabStdFunctions.h>
#include <JabMath.h>

#define JABUG printf

int main()
{
   printf("ToInt = %d\n", JAB.ToInt((char *)"12345"));

   JabMath Math;

   printf("Pot = %d\n", Math.Pot( 5 ));
   printf("Pot = %d\n", Math.Pot( 5, 3 ));
   printf("Pot = %d\n", Math.Pot( 2, 5 ));
   Math.Factorial( -1 );

   system("pause");
   return 0;
}

BOOL CheckFunction( size_t inputFunction, size_t expectedReturn )
{
   BOOL result = FALSE;

   return result;
}