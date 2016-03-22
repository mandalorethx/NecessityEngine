#include "src\Utils\DataStructures\NEArray.h"

static const uint32 DefaultCapacity = 8;

template <class T>
NEArray<T>::NEArray()
{
    m_pDataArray = NULL;
    m_nGrowAmount = 0;
    m_nCapacity = 0;
    m_nLength = 0;
}

template <class T>
NEArray<T>::~NEArray()
{
    Destroy();
}

template <class T>
NEError NEArray<T>::Create(uint32 nInitCap = 0)
{
    m_nGrowAmount = DefaultCapacity;
    m_nCapacity = DefaultCapacity;
    m_nLength = 0;
    m_pDataArray = static_cast<T*>(calloc(m_nCapacity, sizeof(T)));
}

template <class T>
void NEArray<T>::Destroy()
{
    free(m_pDataArray);
    m_pDataArray = NULL;
    m_nGrowAmount = 0;
    m_nCapacity = 0;
    m_nLength = 0;
}

template <class T>
void NEArray<T>::SetGrowAmount(int32 nAmt)
{
    m_nGrowAmount = NEMax(1, nAmt);
}

template <class T>
NEError NEArray<T>::PushBack(T item)
{
    NEError eError = Error_Success;
    if (m_nLength == m_nCapacity)
    {
        eError = Grow();
        if (eError != Error_Success)
        {
            return eError;
        }
    }

    m_pDataArray[m_nLength] = item;
    m_nLength++;

    return Error_Success;
}

template <class T>
NEError NEArray<T>::PushFront(T item)
{
    size_t nBaseSize = m_nCapacity*sizeof(T);
    T* pTmpArray = static_cast<T*>(calloc(nBaseSize, 1));
    memcpy(pTmpArray, m_pDataArray, nBaseSize);

    if (m_nLength == m_nCapacity)
    {
        eError = Grow();
        if (eError != Error_Success)
        {
            free(pTmpArray);
            return eError;
        }
    }

    memcpy(&m_pDataArray[1], pTmpArray, nBaseSize);
    m_pDataArray[0] = item;
    m_nLength++;

    return Error_Success;
}

template <class T>
int32 NEArray<T>::LookupItem(T item)
{
    for (uint32 ii = 0; ii < m_nLength; ++ii)
    {
        if (m_pDataArray[ii] == item)
        {
            return ii;
        }
    }
    return -1;
}

template <class T>
T NEArray<T>::GetItem(uint32 nId)
{
    if (nId < m_nLength)
    {
        return m_pDataArray[nId];
    }
    else
    {
        T tmp;
        memset(&tmp, 0, sizeof(T));
        return tmp;
    }
}

template <class T>
T NEArray<T>::GetFront()
{
    return GetItem(0);
}

template <class T>
T NEArray<T>::GetBack()
{
    return GetItem(m_nLength - 1);
}

template <class T>
NEError NEArray<T>::Grow()
{
    size_t nBaseSize = m_nCapacity*sizeof(T);
    T* pTmpArray = static_cast<T*>(calloc(nBaseSize, 1));
    memcpy(pTmpArray, m_pDataArray, nBaseSize);

    free(m_pDataArray);

    m_nCapacity += m_nGrowAmount;

    m_pDataArray = static_cast<T*>(calloc(m_nCapacity, sizeof(T));
    memcpy(m_pDataArray, pTmpArray, nBaseSize);

    free(pTmpArray);

    return Error_Success;
}