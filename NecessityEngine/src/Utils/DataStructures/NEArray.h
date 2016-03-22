#pragma once

#include "src\Utils\CommonDefs.h"

template <class T>
class NEArray
{
public:
    NEArray();
    ~NEArray();

    NEError Create(uint32 nInitCap = 0);
    void    Destroy();
    
    void    SetGrowAmount(int32 nAmt);
    
    NEError PushBack(T item);
    NEError PushFront(T item);
    //NEError SetItem(uint32 nId, T item);
    //NEError RemoveItem(uint32 nId);
    int32   LookupItem(T item);
    T       GetItem(uint32 nId);
    T       GetFront();
    T       GetBack();
    NEError Grow();

    uint32  GetCurrentCapacity() const { return m_nCapacity; };
    uint32  GetArrayLength() const { return m_nLength; };
    T*      GetArray() const { return m_pDataArray; };

private:
    T*     m_pDataArray;
    uint32 m_nGrowAmount;
    uint32 m_nCapacity;
    uint32 m_nLength;
};
