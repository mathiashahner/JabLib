#include <JabLibTest.h>
#include <JabStdFunctions.h>

int main()
{
   bool result;
   JabLibTest Test;

   Test.RunTestJabStdFunctions = TRUE;
   Test.RunTestJabMath         = TRUE;

   if ( Test.RunTestJabStdFunctions )
   {
      result = Test.TestJabStdFunctions();
      if (( Test.RunTestJabMath ) && ( result ))
      {
         result = Test.TestJabMath();
      }
   }

   system("PAUSE");
   return 0;
}

JabLibTest::JabLibTest()
{
   count = 0;
   printHeader = TRUE;
}

JabLibTest::~JabLibTest()
{
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
      char nameFunctionTmp[20], inputValueTmp[20], expectedReturnTmp[20];

      memset( nameFunctionTmp,   0, 20 );
      memset( inputValueTmp,     0, 20 );
      memset( expectedReturnTmp, 0, 20 );

      JAB.StrPadding( nameFunction,                                  nameFunctionTmp,   10, ' ' );
      JAB.StrPadding( itoa( inputValue, inputValueTmp, 10 ),         inputValueTmp,     6,  ' ' );
      JAB.StrPadding( itoa( expectedReturn, expectedReturnTmp, 10 ), expectedReturnTmp, 6,  ' ' );

      printf("| %04d | %s | %s | %s |\n", count, nameFunctionTmp, inputValueTmp, expectedReturnTmp );

      count++;
   }   

   return result;
}

bool JabLibTest::TestJabStdFunctions()
{
   bool result;

   result = CheckFunction((char*)"ToInt", JAB.ToInt((char*)"0"), 0 );
   if ( result )
   {
      result = CheckFunction((char*)"ToInt", JAB.ToInt((char*)"12345"), 12345 );
      if ( result )
      {
         CheckFunction((char*)"ToInt", JAB.ToInt((char*)"-123"), -123 );
      }
   }

   if ( result )
   {
      int vet[] = {1,3,5,7,13};

      result = CheckFunction((char*)"Search", JAB.Search( 1, vet, 5 ), TRUE );
      if ( result )
      {
         result = CheckFunction((char*)"Search", JAB.Search( 2, vet, 5 ), FALSE );
         if ( result )
         {
            result = CheckFunction((char*)"Search", JAB.Search( 3, vet, 5 ), TRUE );
            if ( result )
            {
               result = CheckFunction((char*)"Search", JAB.Search( 13, vet, 5 ), TRUE );
            }
         }
      }
   }

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