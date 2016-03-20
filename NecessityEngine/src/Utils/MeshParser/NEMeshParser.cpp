#include "src\Utils\MeshParser\NEMeshParser.h"
#include "src\Utils\NEFile.h"
#include "src\Utils\NEString.h"

NEMeshParser::NEMeshParser()
{
    
}

NEMeshParser::~NEMeshParser()
{

}

NEError NEMeshParser::ParseFile(
    const char* pszFileName,
    uint32 nNumIndices,
    uint32* pIndices,
    uint32 nNumVertices,
    NEFormat ePositionFormat,
    void* pPositions,
    NEFormat eCoordFormat,
    void* pCoords,
    NEFormat eNormalFormat,
    void* pNormals)
{
    NEFile meshFile;
    NEError eError = Error_Success;

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
            const char* pszEndLoc = NEString::FindString(pszCurLoc, "\n");

        }
    }

    free(pszFileBuffer);
    meshFile.Close();

    return eError;
}
