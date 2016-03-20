#pragma once

#include "src\Utils\CommonDefs.h"
#include "src\Utils\NEFile.h"
#include "src\Utils\NELog.h"

#include "src\Renderer\NEBuffer.h"

class NEBrick
{
public:
    NEBrick();
    ~NEBrick();

    NEError InitGeometry(const char* pszObjectFile);

protected:
    NEBuffer  m_vertexBuffer;
    NEBuffer  m_indexBuffer;
    uint32    m_nNumConstantBuffers;
    NEBuffer* m_pConstantBuffers;
};
