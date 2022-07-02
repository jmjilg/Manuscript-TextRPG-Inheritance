#include "ItemArmor.h"
#include "FileStream.h"

CItemArmor::CItemArmor()
{
}

CItemArmor::CItemArmor(const CItemArmor& item)	:
	CItem(item)
{
	m_iArmorMin = item.m_iArmorMin;
	m_iArmorMax = item.m_iArmorMax;
}

CItemArmor::~CItemArmor()
{
}

bool CItemArmor::Init()
{
	return true;
}

void CItemArmor::Render()
{
	cout << "�̸� : " << m_strName << "\t���� : " << m_tInfo.strTypename << endl;
	cout << "���� : " << m_iArmorMin << " ~ " << m_iArmorMax << endl;
	cout << "Price : " << m_tInfo.iPrice << "\tSell : " << m_tInfo.iSell << endl;
	cout << "���� : " << m_tInfo.strDesc << endl;
}

CItemArmor* CItemArmor::Clone()
{
	return new CItemArmor(*this);
}

void CItemArmor::Save(CFileStream* pFile)
{
	CItem::Save(pFile);

	pFile->Write(&m_iArmorMin, 4);
	pFile->Write(&m_iArmorMax, 4);
}

void CItemArmor::Load(CFileStream* pFile)
{
	CItem::Load(pFile);

	pFile->Read(&m_iArmorMin, 4);
	pFile->Read(&m_iArmorMax, 4);
}
