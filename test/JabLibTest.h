#include <StdInclude.h>

class JabLibTest
{
public:
   JabLibTest();
   ~JabLibTest();

public:
   size_t count;
   bool NeedPrintHeader;

   bool RunTestJabStdFunctions;
   bool RunTestJabMath;

   bool TestJabStdFunctions( void );
   bool TestJabMath( void );

   bool CheckFunction( char * nameFunction, size_t inputValue, size_t expectedReturn, size_t line = __LINE__ );
   bool CheckFunction( char * nameFunction, char * inputValue, char * expectedReturn, size_t line = __LINE__ );

   void PrintLine( char * nameFunction, char * inputValue, char * expectedReturn );
   void ComputeResult( void );
};