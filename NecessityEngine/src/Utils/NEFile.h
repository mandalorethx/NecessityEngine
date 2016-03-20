#pragma once

#include "src\Utils\CommonDefs.h"
#include <stdio.h>

class NEFile
{
public:
    enum NEFileMode
    {
        FileMode_Read = 0x1,
        FileMode_Write = 0x2,
        FileMode_Append = 0x4,
        FileMode_Binary = 0x8,
    };

	enum NEFileModeFlags
	{
        FileModeFlags_None          = 0x0,
		FileModeFlags_Read          = FileMode_Read,
		FileModeFlags_ReadBin       = FileMode_Read | FileMode_Binary,
		FileModeFlags_Write         = FileMode_Write,
		FileModeFlags_WriteBin      = FileMode_Write | FileMode_Binary,
		FileModeFlags_Append        = FileMode_Append,
		FileModeFlags_AppendBin     = FileMode_Append | FileMode_Binary,
		FileModeFlags_ReadWrite     = FileMode_Read | FileMode_Write,
		FileModeFlags_ReadWriteBin  = FileMode_Read | FileMode_Write | FileMode_Binary,
		FileModeFlags_ReadAppend    = FileMode_Read | FileMode_Append,
		FileModeFlags_ReadAppendBin = FileMode_Read | FileMode_Append | FileMode_Binary,
	};

	NEFile();
	~NEFile();

	NEError Open(const char* pszFileName, NEFileModeFlags eMode);
	void    Close();
	size_t  GetSize();
	NEError Seek(uint32 nLocation);
	NEError Read(size_t nMaxSize, char* pBuffer);
	NEError Write(const char* pszLine);

protected:
    bool32 FileModeFlagsToString(NEFileModeFlags eMode, char* pszString, size_t* pSize);

	FILE*              m_pFile;
    NEFileModeFlags    m_eMode;
};