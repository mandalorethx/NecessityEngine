#include "src\Utils\MeshParser\NEMeshParser.h"
#include "src\Utils\NEFile.h"
#include "src\Utils\NEString.h"
#include "src\Utils\DataStructures\NEArray.h"

NEMeshParser::NEMeshParser()
{
    
}

NEMeshParser::~NEMeshParser()
{

}

NEError NEMeshParser::ParseFile(
    const char* pszFileName,
    uint32*     pNumIndices,
    uint32**    pIndices,
    uint32*     pNumVertices,
    NEFormat*   pPositionFormat,
    void**      pPositions,
    NEFormat*   pCoordFormat,
    void**      pCoords,
    NEFormat*   pNormalFormat,
    void**      pNormals)
{
    NEFile meshFile;
    NEError eError = Error_Success;
    
    NEArray<uint8> positionArray;
    positionArray.Create();
    
    NEArray<uint8> texCoordArray;
    texCoordArray.Create();
    
    NEArray<uint8> normalArray;
    normalArray.Create();
    
    NEArray<uint8> indexArray;
    indexArray.Create();

    eError = meshFile.Open(pszFileName, NEFile::FileModeFlags_Read);

    if (eError != Error_Success)
    {
        return eError;
    }

    size_t nBufferSize = meshFile.GetSize();

    char* pszFileBuffer = static_cast<char*>(calloc(nBufferSize, 1));

    eError = meshFile.Read(nBufferSize, pszFileBuffer);

    if (eError == Error_Success)
    {
        char* pszCurLoc = pszFileBuffer;
        while (pszCurLoc)
        {
            size_t nSize = 0;
            uint8* pData = NULL;

            const char* pszEndLoc = NEString::FindString(pszCurLoc, "\n");
            size_t nLineLen = pszEndLoc - pszCurLoc;
            char* pszTmpLine = static_cast<char*>(calloc(nLineLen + 1, sizeof(char)));
            NEString::SPrintf(pszTmpLine, nLineLen, pszCurLoc);

            ELineType type = ParseLine(pszTmpLine, &nSize, &pData);

            free(pszTmpLine);
            
            for (uint32 ii = 0; ii < nSize; ++ii)
            {
                if (type == LineType_Index)
                {
                    indexArray.PushBack(pData[ii]);
                }
                else if (type == LineType_Position)
                {
                    positionArray.PushBack(pData[ii]);
                }
                else if (type == LineType_Coord)
                {
                    texCoordArray.PushBack(pData[ii]);
                }
                else if (type == LineType_Normal)
                {
                    normalArray.PushBack(pData[ii]);
                }

            }

            free(pData);
            pszCurLoc = const_cast<char*>( pszEndLoc );

        }
    }

    *pNumIndices = indexArray.GetArrayLength();
    *pIndices = static_cast<uint32*>(calloc(indexArray.GetArrayLength(), sizeof(uint32)));
    memcpy(*pIndices, indexArray.GetArray(), indexArray.GetArrayLength()*sizeof(uint32));
    indexArray.Destroy();

    *pNumVertices = positionArray.GetArrayLength() / sizeof(float3);

    *pPositionFormat = NE_Format_R32G32B32_SFLOAT;
    *pPositions = calloc(positionArray.GetArrayLength(), sizeof(uint8));
    memcpy(*pPositions, positionArray.GetArray(), positionArray.GetArrayLength()*sizeof(uint8));
    positionArray.Destroy();

    *pCoordFormat = NE_Format_R32G32_SFLOAT;
    *pCoords = calloc(texCoordArray.GetArrayLength(), sizeof(uint8));
    memcpy(*pCoords, texCoordArray.GetArray(), texCoordArray.GetArrayLength()*sizeof(uint8));
    texCoordArray.Destroy();

    *pNormalFormat = NE_Format_R32G32B32_SFLOAT;
    *pNormals = calloc(normalArray.GetArrayLength(), sizeof(uint8));
    memcpy(*pNormals, normalArray.GetArray(), normalArray.GetArrayLength()*sizeof(uint8));
    normalArray.Destroy();

    free(pszFileBuffer);
    meshFile.Close();

    return eError;
}
