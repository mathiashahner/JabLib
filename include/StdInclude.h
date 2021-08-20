#ifndef _STDINCLUDE_H_
#define _STDINCLUDE_H_

#define TRUE  1
#define FALSE 0

// #define _BUILD_WINDOWS

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <wchar.h>
#include <time.h>
#include <limits.h>
#include <dirent.h>

#ifdef _BUILD_WINDOWS
   #include <tchar.h>
   #include <windows.h>
   #include <winioctl.h>
   #include <winsock2.h>
   #include <WinCrypt.h>
   #include <winerror.h>
   #include <errno.h>
   #include <Shlwapi.h>
   #include <sys/stat.h>
   #include <sys/types.h>
#endif

#endif