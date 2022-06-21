#pragma once
#include "Character.h"
class CPlayer :
    public CCharacter
{
protected:
    CPlayer();
    ~CPlayer();

private:
    friend class CObjectManager;

public:
    virtual bool Init();
};

