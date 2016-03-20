#pragma once

#include "src\Utils\CommonDefs.h"

class NEBuffer
{
public:
    enum EUsage
    {
        BufferUsage_General   = 0x0,
        BufferUsage_Uniform   = 0x1,
        BufferUsage_Storage   = 0x2,
        BufferUsage_Vertex    = 0x4,
        BufferUsage_Index     = 0x5,
        BufferUsage_Indirect  = 0x6,
        BufferUsage_Transfer  = 0x7,
    };

    typedef NEFlags EUsageFlags;

    enum EMode
    {
        BufferMode_Default,
        BufferMode_Persistent,
    };

    NEBuffer();
    ~NEBuffer();

    NEError Init(size_t nSize, EUsageFlags usage, EMode mode);
    void*   Map(size_t nOffset, size_t nRange);
    void    Unmap();
    NEError UploadData(size_t nOffset, size_t nSize, void* pData);

protected:
    size_t m_nSize;
    EUsage m_eUsage;
    EMode  m_eMode;
    bool32 m_bMapped;
    void*  m_pMappedData;
};
