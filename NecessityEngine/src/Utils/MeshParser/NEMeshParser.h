#pragma once

#include "src\Utils\CommonDefs.h"
#include "src\Engine\NEEngineDefs.h"
#include "src\Utils\NEString.h"

class NEMeshParser
{
public:
    NEMeshParser();
    ~NEMeshParser();

    NEError ParseFile(
        const char* pszFileName, 
        uint32*     pNumIndices, 
        uint32**    pIndices, 
        uint32*     pNumVertices, 
        NEFormat*   pPositionFormat, 
        void**      pPositions, 
        NEFormat*   pCoordFormat, 
        void**      pCoords, 
        NEFormat*   pNormalFormat, 
        void**      pNormals);

protected:
    enum ELineType
    {
        LineType_Undefined,
        LineType_Index,
        LineType_Position,
        LineType_Coord,
        LineType_Normal,
    };

    virtual ELineType ParseLine(const char* pszLine, size_t* pSize, uint8** pData);
};
