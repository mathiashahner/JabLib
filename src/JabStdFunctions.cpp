#include <JabStdFunctions.h>

JabStdFunctions JAB;

int JabStdFunctions::ToInt(char *buffer)
{
   return (buffer, strlen(buffer));
}

int JabStdFunctions::ToInt(char *buffer, size_t len)
{
   int result = 0;
   char buffTmp[len];

   if (buffer == NULL)
   {
      printf("-> Buffer is NULL.\n");
   }
   else
   {
      strncpy(buffTmp, buffer, len);

      result = atoi(buffer);
   }

   return (ToInt(buffTmp));
}