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

   Test.ComputeResult();

   system("PAUSE");
   return 0;
}

JabLibTest::JabLibTest()
{
   count = 0;
   NeedPrintHeader = TRUE;
}

JabLibTest::~JabLibTest()
{
   NeedPrintHeader = FALSE;
}

bool JabLibTest::CheckFunction( char * nameFunction, char * inputValue, char * expectedReturn, size_t line )
{
   bool result = FALSE;

   if (( nameFunction == NULL ) || ( inputValue == NULL ) || ( expectedReturn == NULL ))
   {
      printf("-> Param is NULL.\n");
   }
   else
   {
      result = ( strcmp( inputValue, expectedReturn ) == 0 );
      if ( !result )
      {
         printf("\n\nERRO | Function=[%s] Line=[%d] inputValue=[%s] expectedReturn=[%s]\n",
            nameFunction, line, inputValue, expectedReturn );

         system("PAUSE");
      }
      else
      {
         PrintLine( nameFunction, inputValue, expectedReturn );
      }   
   }

   return result;
}

bool JabLibTest::CheckFunction( char * nameFunction, size_t inputValue, size_t expectedReturn, size_t line )
{
   bool result = FALSE;

   if ( nameFunction == NULL )
   {
      printf("-> nameFunction is NULL.\n");
   }
   else
   {
      result = ( inputValue == expectedReturn );
      if ( !result )
      {
         printf("\n\nERRO | Function=[%s] Line=[%d] inputValue=[%d] expectedReturn=[%d]\n",
            nameFunction, line, inputValue, expectedReturn );

         system("PAUSE");
      }
      else
      {
         PrintLine( nameFunction, JAB.ToChar(inputValue), JAB.ToChar(expectedReturn));
      }   
   }

   return result;
}

void JabLibTest::PrintLine( char * nameFunction, char * inputValue, char * expectedReturn )
{
   char nameFunctionTmp[20], inputValueTmp[20], expectedReturnTmp[20];

   memset( nameFunctionTmp,   0, 20 );
   memset( inputValueTmp,     0, 20 );
   memset( expectedReturnTmp, 0, 20 );

   JAB.StrPadding( nameFunction,   nameFunctionTmp,   10, ' ' );
   JAB.StrPadding( inputValue,     inputValueTmp,     6,  ' ' );
   JAB.StrPadding( expectedReturn, expectedReturnTmp, 6,  ' ' );

   printf("| %04d | %s | %s | %s |\n", count, nameFunctionTmp, inputValueTmp, expectedReturnTmp );

   count++;
}

void JabLibTest::ComputeResult()
{
   if ( count > 0 )
   {
      printf("\nImplementar %s\n", __FUNCTION__ );
   }
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
      int ArrayTest[] = {1,3,5,7,13};
      int LenArray = sizeof(ArrayTest) / sizeof(ArrayTest[0]);

      result = CheckFunction((char*)"Contains", JAB.Contains( 1, ArrayTest, LenArray ), TRUE );
      if ( result )
      {
         result = CheckFunction((char*)"Contains", JAB.Contains( 2, ArrayTest, LenArray ), FALSE );
         if ( result )
         {
            result = CheckFunction((char*)"Contains", JAB.Contains( 3, ArrayTest, LenArray ), TRUE );
            if ( result )
            {
               result = CheckFunction((char*)"Contains", JAB.Contains( 13, ArrayTest, LenArray ), TRUE );
            }
         }
      }
   }

   if ( result )
   {
      result = CheckFunction((char*)"ToChar", JAB.ToChar( 0 ), (char*)"0" );
      if ( result )
      {
         result = CheckFunction((char*)"ToChar", JAB.ToChar( 123 ), (char*)"123" );
         if ( result )
         {
            result = CheckFunction((char*)"ToChar", JAB.ToChar( -123 ), (char*)"-123" );
            if ( result )
            {
               result = CheckFunction((char*)"ToChar", JAB.ToChar( 13, 2 ), (char*)"1101" );
               if ( result )
               {
                  result = CheckFunction((char*)"ToChar", JAB.ToChar( 1750, 16 ), (char*)"6d6" );
               }
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

   result = CheckFunction((char*)"Pot", Math.Pot( -3 ), 9 );
   if ( result )
   {
      result = CheckFunction((char*)"Pot", Math.Pot( 5 ), 25 );
      if ( result )
      {
         result = CheckFunction((char*)"Pot", Math.Pot( 2, 5 ), 32 );
         if ( result )
         {
            result = CheckFunction((char*)"Pot", Math.Pot( 5, 3 ), 125 );
            if ( result )
            {
               result = CheckFunction((char*)"Pot", Math.Pot( -3, 3 ), -27 );
            }
         }
      }
   }

   if ( result )
   {
      result = CheckFunction((char*)"Factorial", Math.Factorial( -1 ), 0 );
      if ( result )
      {
         result = CheckFunction((char*)"Factorial", Math.Factorial( 0 ), 1 );
         if ( result )
         {
            result = CheckFunction((char*)"Factorial", Math.Factorial( 5 ), 120 );
            if ( result )
            {
               result = CheckFunction((char*)"Factorial", Math.Factorial( 7 ), 5040 );
            }
         }
      }
   }
   
   return result;
}