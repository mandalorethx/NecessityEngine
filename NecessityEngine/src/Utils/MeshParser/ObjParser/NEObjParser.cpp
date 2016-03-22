#include "src\Utils\MeshParser\ObjParser\NEObjParser.h"

NEObjParser::NEObjParser()
{

}

NEObjParser::~NEObjParser()
{

}

NEMeshParser::ELineType NEObjParser::ParseLine(const char* pszLine, size_t* pSize, void* pData)
{
    if (IsPositionLine(pszLine))
    {
        float3 vCurPos = { 0 };
        *pSize = sizeof(float3);
        NEString::Scan(pszLine, "v %f %f %f", vCurPos.x, vCurPos.y, vCurPos.z);
        pData = calloc(1, sizeof(float3));
        memcpy(pData, &vCurPos, sizeof(float3));
        return NEMeshParser::LineType_Position;
    }
    else if (IsCoordinateLine(pszLine))
    {
        float3 vCurPos = { 0 };
        *pSize = sizeof(float3);
        NEString::Scan(pszLine, "vt %f %f %f", vCurPos.x, vCurPos.y, vCurPos.z);
        pData = calloc(1, sizeof(float3));
        memcpy(pData, &vCurPos, sizeof(float3));
        return NEMeshParser::LineType_Coord;
    }
    else if (IsNormalLine(pszLine))
    {
        float3 vCurPos = { 0 };
        *pSize = sizeof(float3);
        NEString::Scan(pszLine, "vn %f %f %f", vCurPos.x, vCurPos.y, vCurPos.z);
        pData = calloc(1, sizeof(float3));
        memcpy(pData, &vCurPos, sizeof(float3));
        return NEMeshParser::LineType_Normal;
    }
    else if (IsIndexLine(pszLine))
    {
        int3 vCurIndices = { 0 };
        int3 vCurFace = { 0 };

        *pSize = sizeof(int3);
        NEString::Scan(pszLine, "f %d//%d %d//%d %d//%d",
            vCurIndices.x, vCurFace.x,
            vCurIndices.y, vCurFace.y,
            vCurIndices.z, vCurFace.z);
        pData = calloc(1, sizeof(int3));
        memcpy(pData, &vCurIndices, sizeof(int3));
        return NEMeshParser::LineType_Index;
    }

    return NEMeshParser::LineType_Undefined;
}

bool32 NEObjParser::IsPositionLine(const char* pszLine)
{
    return NEString::FindString(pszLine, "v ") != NULL;
}

bool32 NEObjParser::IsCoordinateLine(const char* pszLine)
{
    return NEString::FindString(pszLine, "vt ") != NULL;
}

bool32 NEObjParser::IsNormalLine(const char* pszLine)
{
    return NEString::FindString(pszLine, "vn ") != NULL;
}

bool32 NEObjParser::IsIndexLine(const char* pszLine)
{
    return NEString::FindString(pszLine, "f ") != NULL;
}

