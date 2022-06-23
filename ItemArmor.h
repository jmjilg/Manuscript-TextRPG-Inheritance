#pragma once
#include "Item.h"
class CItemArmor :
    public CItem
{
protected:
    CItemArmor();
    CItemArmor(const CItemArmor& item);
    ~CItemArmor();

private:
    friend class CStore;
    friend class CStoreArmor;

private:
    int     m_iArmorMin;
    int     m_iArmorMax;

public:
    int GetArmorMin()   const
    {
        return m_iArmorMin;
    }

    int GetArmorMax()   const
    {
        return m_iArmorMax;
    }

public:
    void SetArmorInfo(int iMin, int iMax)
    {
        m_iArmorMin = iMin;
        m_iArmorMax = iMax;
    }

public:
    virtual bool Init();
    virtual void Render();
    virtual CItemArmor* Clone();
};

