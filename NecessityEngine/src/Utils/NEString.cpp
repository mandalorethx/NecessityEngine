#include "src\Utils\NEString.h"

NEError NEString::SPrintf(
    char* pszString, 
    size_t nSize, 
    const char* pszFormat, 
    ...)
{
    va_list args;
    va_start(args, pszFormat);
    int32 nRes = vsnprintf(pszString, nSize, pszFormat, args);
    va_end(args);
    if (nRes < 0)
    {
        return Error_Failed;
    }

    return Error_Success;
}

NEError NEString::Concat(
    char* pszDestination, 
    const char* pszSource, 
    size_t nSize)
{
    char* pRet = strncat(pszDestination, pszSource, nSize);
    if (!pRet)
    {
        return Error_Failed;
    }

    return Error_Success;
}

NEError NEString::Copy(
    char* pszDestination, 
    const char* pszSource, 
    size_t nSize)
{
    char* pRet = strncpy(pszDestination, pszSource, nSize);
    if (!pRet)
    {
        return Error_Failed;
    }

    return Error_Success;
}

NEError NEString::Scan(
    const char* pszString, 
    const char* pszFormat, 
    ...)
{
    va_list args;
    va_start(args, pszFormat);
    int nRet = vsscanf(pszString, pszFormat, args);
    va_end(args);

    if (nRet < 0)
    {
        return Error_Failed;
    }
    
    return Error_Success;
}

size_t  NEString::Size(
    const char* pszString)
{
    return strlen(pszString);
}

const char* FindString(
    const char* pszBaseString, 
    const char* pszSubString)
{
    return strstr(pszBaseString, pszSubString);
}
