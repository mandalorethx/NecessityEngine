#pragma once

#include "src\Utils\CommonDefs.h"
#include <stdio.h>
#include <stdarg.h>
#include <cstring>

namespace NEString
{
    NEError     SPrintf(char* pszString, size_t nSize, const char* pszFormat, ...);
    NEError     Concat(char* pszDestination, const char* pszSource, size_t nSize);
    NEError     Copy(char* pszDestination, const char* pszSource, size_t nSize);
    NEError     Scan(const char* pszString, const char* pszFormat, ...);
    size_t      Size(const char* pszString);
    const char* FindString(const char* pszBaseString, const char* pszSubString);
}
