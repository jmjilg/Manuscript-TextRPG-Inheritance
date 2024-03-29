#pragma once
#include "Obj.h"
class CItem :
    public CObj
{
public:
protected:
    CItem();
    CItem(const CItem& item);

public:
    virtual ~CItem();

protected:
    ITEMINFO        m_tInfo;
    friend class CEditorItem;

public:
    void SetItemInfo(ITEM_TYPE eType, int iPrice, int iSell, char* pDesc);

public:
    ITEMINFO GetItemInfo()  const
    {
        return m_tInfo;
    }

public:
    virtual bool Init();
    virtual void Render();
    virtual CItem* Clone() = 0;
    virtual void Save(class CFileStream* pFile);
    virtual void Load(class CFileStream* pFile);
};

