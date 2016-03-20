#include "src\Utils\NEFile.h"
#include "src\Utils\NEString.h"

NEFile::NEFile()
{
    m_pFile = NULL;
    m_eMode = FileModeFlags_None;
}

NEFile::~NEFile()
{
    Close();
}

NEError NEFile::Open(
    const char*     pszFileName, 
    NEFileModeFlags eMode)
{
    if (m_pFile)
    {
        Close();
    }

    char pszFileMode[StringSize];
    FileModeFlagsToString(eMode, pszFileMode, NULL);

    m_pFile = fopen(pszFileName, pszFileMode);
    if (!m_pFile)
    {
        return Error_Failed;
    }

    m_eMode = eMode;
}

void NEFile::Close()
{
    if (m_pFile)
    {
        fclose(m_pFile);
    }
    m_pFile = NULL;
}

size_t NEFile::GetSize()
{
    size_t nStartPos = ftell(m_pFile);
    fseek(m_pFile, 0, SEEK_END);

    size_t nSize = ftell(m_pFile);
    fseek(m_pFile, 0, nStartPos);

    return nSize;
}

NEError NEFile::Seek(uint32 nLocation)
{
    int32 nRet = fseek(m_pFile, 0, nLocation);
    if (nRet)
    {
        return Error_Failed;
    }
    
    return Error_Success;
}

NEError NEFile::Read(size_t nMaxSize, char* pBuffer)
{
    char* pRet = fgets(pBuffer, nMaxSize, m_pFile);
    if (!pRet)
    {
        int32 nCode = ferror(m_pFile);
        if (nCode)
        {
            return Error_Failed;
        }
    }
    return Error_Success;
}

NEError NEFile::Write(const char* pszLine)
{
    int32 nCode = fputs(pszLine, m_pFile);
    if (nCode < 0)
    {
        return Error_Failed;
    }

    return Error_Success;
}

bool32 NEFile::FileModeFlagsToString(
    NEFileModeFlags eMode, 
    char* pszString, 
    size_t* pSize)
{
    char pszTmp[StringSize] = { 0 };
    
    if (FileMode_Read & eMode)
    {
        if (NEString::Concat(pszTmp, "r", StringSize) != Error_Success)
        {
            return false;
        }
    }

    if (FileMode_Write & eMode)
    {
        if (NEString::Concat(pszTmp, "w", StringSize) != Error_Success)
        {
            return false;
        }
    }

    if (FileMode_Append & eMode)
    {
        if (NEString::Concat(pszTmp, "a", StringSize) != Error_Success)
        {
            return false;
        }
    }

    if (FileMode_Binary & eMode)
    {
        if (NEString::Concat(pszTmp, "b", StringSize) != Error_Success)
        {
            return false;
        }
    }

    if (pSize)
    {
        *pSize = NEString::Size(pszTmp);
    }

    if (pszString)
    {
        if (NEString::Copy(pszString, pszTmp, NEString::Size(pszTmp)) != Error_Success)
        {
            return false;
        }
    }

    return true;

}