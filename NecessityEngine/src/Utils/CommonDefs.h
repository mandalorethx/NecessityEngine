#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <cstring>

typedef char int8;
typedef unsigned char uint8;
typedef short int16;
typedef unsigned short uint16;
typedef int32_t int32;
typedef uint32_t uint32;
typedef uint32 bool32;
typedef int64_t int64;
typedef uint64_t uint64;

struct float2
{
    float x;
    float y;
};

struct int2
{
    int32 x;
    int32 y;
};

struct float3
{
    float x;
    float y;
    float z;
};

struct int3
{
    int32 x;
    int32 y;
    int32 z;
};

struct float4
{
    float x;
    float y;
    float z;
    float w;
};

struct int4
{
    int32 x;
    int32 y;
    int32 z;
    int32 w;
};

struct mat4x4
{
    float4 cx;
    float4 cy;
    float4 cz;
    float4 cw;
};

typedef uint32 NEFlags;

static const uint32 StringSize = 256;
static const uint32 LargeStringSize = 1024;

#define NEMax(x, y) (x > y ? x : y)
#define NEMin(x, y) (x < y ? x : y)

enum NEError
{
	Error_Success        =  0,
	Error_Failed         = -1,
	Error_FileNotFound   = -2,
    Error_BufferTooSmall = -3,
};

