#pragma once

#include <stdint.h>
#include <stdlib.h>

typedef char int8;
typedef unsigned char uint8;
typedef short int16;
typedef unsigned short uint16;
typedef int32_t int32;
typedef uint32_t uint32;
typedef uint32 bool32;
typedef int64_t int64;
typedef uint64_t uint64;

typedef uint32 NEFlags;

static const uint32 StringSize = 256;
static const uint32 LargeStringSize = 1024;

enum NEError
{
	Error_Success        =  0,
	Error_Failed         = -1,
	Error_FileNotFound   = -2,
    Error_BufferTooSmall = -3,
};

enum NEFormat
{
    NE_Format_UNDEFINED,
    NE_Format_R8_UNORM,
    NE_Format_R8_SRGB,
    NE_Format_R8G8B8A8_UNORM,
    NE_Format_R8G8B8A8_SRGB,
    NE_Format_R16_UINT,
    NE_Format_R16_SINT,
    NE_Format_R16_SFLOAT,
    NE_Format_R16G16_UINT,
    NE_Format_R16G16_SINT,
    NE_Format_R16G16_SFLOAT,
    NE_Format_R16G16B16_UINT,
    NE_Format_R16G16B16_SINT,
    NE_Format_R16G16B16_SFLOAT,
    NE_Format_R16G16B16A16_UINT,
    NE_Format_R16G16B16A16_SINT,
    NE_Format_R16G16B16A16_SFLOAT,
    NE_Format_R32_UINT,
    NE_Format_R32_SINT,
    NE_Format_R32_SFLOAT,
    NE_Format_R32G32_UINT,
    NE_Format_R32G32_SINT,
    NE_Format_R32G32_SFLOAT,
    NE_Format_R32G32B32_UINT,
    NE_Format_R32G32B32_SINT,
    NE_Format_R32G32B32_SFLOAT,
    NE_Format_R32G32B32A32_UINT,
    NE_Format_R32G32B32A32_SINT,
    NE_Format_R32G32B32A32_SFLOAT,
    NE_Format_D16_UNORM,
    NE_Format_D16_UNORM_S8_UINT,
    NE_Format_D24_UNORM_S8_UINT,
    NE_Format_D32_SFLOAT_S8_UINT,
};