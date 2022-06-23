#pragma once
#include "Character.h"
class CPlayer :
    public CCharacter
{
private:
    enum JOB
    {
        JOB_NONE,
        JOB_KNIGHT,
        JOB_ARCHER,
        JOB_MAGICION,
        JOB_END
    };

private:
    CPlayer();
    CPlayer(const CPlayer& player);
    ~CPlayer();

private:
    friend class CObjectManager;

private:
    JOB     m_eJob;
    string  m_strJobName;
    int     m_iGold;

public:
    void AddGold(int iGold);
    void DropGold();

public:
    int GetGold()   const
    {
        return m_iGold;
    }

public:
    virtual bool Init();
    virtual void Render();
    virtual CPlayer* Clone();
};

