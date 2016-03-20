#pragma once

#include "src\Utils\NEFile.h"

class NELog
{
public:
    enum ELogSeverity
    {
        Log_Error,
        Log_Warning,
        Log_Info,
        Log_Debug,
        NumSeverityLevels,
    };

    static const NELog* GetLog();
    static const void DestroyLog();

    NEError LogLine(ELogSeverity eSeverity, const char* pszLine);

protected:
    NELog();
    ~NELog();

    static NELog* m_pLogInstance;
    static const char* SeverityStrings[NumSeverityLevels];

    NEFile m_logFile;
};
