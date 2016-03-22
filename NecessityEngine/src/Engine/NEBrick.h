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
    void    SetCenter(float3 vPos);
    void    SetCenter(float x, float y, float z);
    void    SetScale(float3 vScale);
    void    SetScale(float x, float y, float z);
    void    SetRotation(float fAngle, float3 vAmount);
    void    SetRotation(float fAngle, float x, float y, float z);
    NEError ApplyPipelineStateHash(uint32 nPipelineHash);
    NEError ApplyDrawStateHash(uint32 nDrawState);

    NEError Draw(uint32 nNumInstances = 1);

    mat4x4  GetModelMatrix() const { return m_mModel; };

protected:
    NEBuffer  m_vertexBuffer;
    NEBuffer  m_indexBuffer;
    uint32    m_nNumConstantBuffers;
    mat4x4    m_mModel;
    float3    m_vCenter;
    float3    m_vScale;
    float     m_fRotationAngle;
    float3    m_vRotationAmounts;
    uint32    m_nPipelineStateHash;
    uint32    m_nDrawStateHas;
};
