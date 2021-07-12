#include <StdInclude.h>
#include <JabStdFunctions.h>

int main()
{
   // Tests for JabLib

   printf("ToInt = %d\n", JAB.ToInt((char *)"12345"));
   printf("Pot = %d\n", JAB.Pot( 5 ));
   printf("Pot = %d\n", JAB.Pot( 5, 3 ));
   printf("Pot = %d\n", JAB.Pot( 2, 5 ));

   system("pause");
   return 0;
}