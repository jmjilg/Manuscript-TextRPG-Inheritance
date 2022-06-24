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

    virtual int GetDamage()
    {
        // Max에서 Min을 빼고 1을 더하면 0에서 Max - Min 값 사이의 값이 나오게 된다.
        // 이 값에 Min을 더해주게 되면 Min 에서 Max - Min 값 사이의 값이 나오게 된다.
        // 즉 Min - Max 사이의 값이 나오게 된다는 것이다.
        return rand() % (m_tInfo.iAttackMax - m_tInfo.iAttackMin + 1) + m_tInfo.iAttackMin;
    }

    virtual int GetArmor()
    {
        return rand() % (m_tInfo.iArmorMax - m_tInfo.iArmorMin + 1) + m_tInfo.iArmorMin;
    }

    bool Damage(int iDamage);
    bool AddExp(int iExp);
    bool CheckLevelUp();
    void DropExp();
    void FullHPMP();
    void LevelUp();
    void AddLevelUpStatus(const LEVELUPINFO& tInfo);

public:
    virtual bool Init();
    virtual void Render();
    virtual CCharacter* Clone() = 0;
};

