#pragma once
#include "Obj.h"
class CCharacter :
    public CObj
{
protected:
    CCharacter();
    CCharacter(const CCharacter& character);
    virtual ~CCharacter() = 0;

protected:
    CHARACTERINFO   m_tInfo;

public:
    CHARACTERINFO GetCharacterInfo()    const
    {
        return m_tInfo;
    }

    void SetCharacterInfo(int iAtmin, int iAtMax, int iArMin, int iArMax,
        int iHP, int iMP, int iLevel, int iExp);

public:
    virtual bool Init();
    virtual void Render();
    virtual CCharacter* Clone() = 0;
};

