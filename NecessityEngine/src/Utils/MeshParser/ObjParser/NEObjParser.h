#pragma once

#include "src\Utils\MeshParser\NEMeshParser.h"

class NEObjParser : protected NEMeshParser
{
public:
    NEObjParser();
    ~NEObjParser();

protected:
    ELineType ParseLine(const char* pszLine, size_t* pSize, void* pData);

    bool32 IsPositionLine(const char* pszLine);
    bool32 IsCoordinateLine(const char* pszLine);
    bool32 IsNormalLine(const char* pszLine);
    bool32 IsIndexLine(const char* pszLine);
};
