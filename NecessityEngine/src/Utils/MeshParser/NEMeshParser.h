#pragma once

#include "src\Utils\CommonDefs.h"
#include "src\Utils\NEString.h"

class NEMeshParser
{
    NEMeshParser();
    ~NEMeshParser();

    NEError ParseFile(
        const char* pszFileName, 
        uint32 nNumIndices, 
        uint32* pIndices, 
        uint32 nNumVertices, 
        NEFormat ePositionFormat, 
        void* pPositions, 
        NEFormat eCoordFormat, 
        void* pCoords, 
        NEFormat eNormalFormat, 
        void* pNormals);

protected:
    enum ELineType
    {
        LineType_Undefined,
        LineType_Index,
        LineType_Position,
        LineType_Coord,
        LineType_Normal,
    };

    virtual ELineType ParseLine(const char* pszLine, size_t* pSize, void* pData);
};
