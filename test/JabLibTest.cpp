#include <StdInclude.h>
#include <JabStdFunctions.h>
#include <JabMath.h>

int main()
{
   printf("ToInt = %d\n", JAB.ToInt((char *)"12345"));

   JabMath Math;

   printf("Pot = %d\n", Math.Pot( 5 ));
   printf("Pot = %d\n", Math.Pot( 5, 3 ));
   printf("Pot = %d\n", Math.Pot( 2, 5 ));

   system("pause");
   return 0;
}