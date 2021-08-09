#include <JabLibTest.h>
#include <JabStdFunctions.h>

int main()
{
   bool result;
   JabLibTest Test;

   result = Test.TestJabStdFunctions();
   if ( result )
   {
      result = Test.TestJabMath();
   }

   system("PAUSE");
   return 0;
}

JabLibTest::JabLibTest()
{
   printf("JabLibTest\n");
   count = 0;
   printHeader = TRUE;
}

JabLibTest::~JabLibTest()
{
   printf("~JabLibTest\n");
   printHeader = FALSE;
}

bool JabLibTest::CheckFunction( char * nameFunction, size_t inputValue, size_t expectedReturn, size_t line )
{
   bool result = FALSE;

   result = ( inputValue == expectedReturn );
   if ( !result )
   {
      printf("\n\nERRO | Function=[%s] Line=[%d] inputValue=[%d] expectedReturn=[%d]\n",
         nameFunction, line, inputValue, expectedReturn );

      system("PAUSE");
   }
   else
   {
      printf("%04d | Function=[%s] inputValue=[%d] expectedReturn=[%d]\n",
         count, nameFunction, inputValue, expectedReturn );

      count++;
   }   

   return result;
}

bool JabLibTest::TestJabStdFunctions()
{
   bool result;

   result = CheckFunction((char*)"ToInt", JAB.ToInt((char*)"0"),     0 );
   CheckFunction((char*)"ToInt", JAB.ToInt((char*)"12345"), 12345 );
   CheckFunction((char*)"ToInt", JAB.ToInt((char*)"-123"), -123 );

   int vet[] = {1,3,5,7,13};

   CheckFunction((char*)"Search", JAB.Search( 1,  vet, 5 ),  TRUE );
   CheckFunction((char*)"Search", JAB.Search( 2,  vet, 5 ),  FALSE );
   CheckFunction((char*)"Search", JAB.Search( 3,  vet, 5 ),  TRUE );
   CheckFunction((char*)"Search", JAB.Search( 13, vet, 5 ), TRUE );

   return result;
}

bool JabLibTest::TestJabMath()
{
   bool result;
   JabMath Math;

   result = CheckFunction((char*)"Pot", Math.Pot( -3 ),     9 );
   CheckFunction((char*)"Pot", Math.Pot( 5 ),      25 );
   CheckFunction((char*)"Pot", Math.Pot( 2, 5 ),   32 );
   CheckFunction((char*)"Pot", Math.Pot( 5, 3 ),   125 );
   CheckFunction((char*)"Pot", Math.Pot( -3, 3 ), -27 );

   CheckFunction((char*)"Pot", Math.Factorial( -1 ), 0 );
   CheckFunction((char*)"Pot", Math.Factorial( 0 ),  1 );
   CheckFunction((char*)"Pot", Math.Factorial( 5 ),  120 );
   CheckFunction((char*)"Pot", Math.Factorial( 7 ),  5040 );
   
   return result;
}