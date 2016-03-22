#pragma once

#include "src\Utils\CommonDefs.h"
#include "src\Engine\NEEngineDefs.h"

class NEShaderState
{
public:
    NEShaderState();
    ~NEShaderState();

    NEError SetShader(NEShaderStages eStage, const char* pszFileName);
    NEError Compile();
    uint32  GetShaderHash() const { return m_nShaderHash; };

private:
    NEShaderStages m_eShaderStage;
    void*          m_pShaderData;
    size_t         m_nDataSize;
    int32          m_nShaderHash;
};
