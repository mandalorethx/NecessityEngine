#include "src\Utils\NELog.h"
#include "src\Utils\NEString.h"

const char* NELog::SeverityStrings[NELog::NumSeverityLevels] = 
{
    "ERROR",
    "Warning",
    "Info",
    "Debug",
};

const NELog* NELog::GetLog()
{
    if (!m_pLogInstance)
    {
        m_pLogInstance = new NELog;
    }
    return m_pLogInstance;
}

const void NELog::DestroyLog()
{
    delete m_pLogInstance;
}

NEError NELog::LogLine(
    ELogSeverity eSeverity,
    const char* pszLine)
{
#ifdef _DEBUG
    NEError eError = Error_Success;

    eError = m_logFile.Open("log.txt", NEFile::FileModeFlags_Append);

    if (eError == Error_Success)
    {
        char pszTimeStamp[LargeStringSize]; // TODO
        printf(pszTimeStamp);
        eError = m_logFile.Write(pszTimeStamp);
    }

    if (eError == Error_Success)
    {
        char pszSeverity[StringSize];
        NEString::SPrintf(pszSeverity, StringSize, " [%s] ", SeverityStrings[eSeverity]);
        printf(pszSeverity);
        eError = m_logFile.Write(pszSeverity);
    }

    if (eError == Error_Success)
    {
        printf(pszLine);
        eError = m_logFile.Write(pszLine);
    }

    if (eError == Error_Success)
    {
        printf("\n");
        eError = m_logFile.Write("\n");
    }

    m_logFile.Close();

    return eError;
#else
    return Error_Success;
#endif // _DEBUG
}
