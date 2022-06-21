#include "Character.h"

CCharacter::CCharacter()
{
}

// Obj의 복사생성자를 먼저 호출하여 Obj의 값을 복사하고
// character의 값을 복사하도록 한다.
CCharacter::CCharacter(const CCharacter& character)
	: CObj(character)
{
	m_tInfo = character.m_tInfo;
}

CCharacter::~CCharacter()
{
}

void CCharacter::SetCharacterInfo(int iAtMin, int iAtMax, int iArMin, int iArMax,
	int iHP, int iMP, int iLevel, int iExp)
{
	m_tInfo.iAttackMin = iAtMin;
	m_tInfo.iAttackMax = iAtMax;
	m_tInfo.iArmorMin = iArMin;
	m_tInfo.iArmorMax = iArMax;
	m_tInfo.iHP = iHP;
	m_tInfo.iHPMax = iHP;
	m_tInfo.iMP = iMP;
	m_tInfo.iMPMax = iMP;
	m_tInfo.iLevel = iLevel;
	m_tInfo.iExp = iExp;
}

bool CCharacter::Init()
{
	return true;
}

void CCharacter::Render()
{
}
