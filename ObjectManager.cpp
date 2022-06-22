#include "ObjectManager.h"
#include "Player.h"
#include "Monster.h"

DEFINITION_SINGLE(CObjectManager)

CObjectManager::CObjectManager()
{
}

CObjectManager::~CObjectManager()
{
}

bool CObjectManager::Init()
{
	// �÷��̾ �����Ѵ�.
	CObj*	pPlayer = CreateObject("Player", OT_PLAYER);
	
	// CreateObject �Լ��� ���͸� �����ϰ� CObj* Ÿ���� �����Ѵ�.
	// �׷��� ������ �⺻ �������� ���� Ŭ������ character Ŭ������ ������ �����Ƿ�
	// ���� Ŭ������ ����ȯ�Ͽ� �����صΰ� ����� ����ϵ��� �Ѵ�.
	CMonster* pMonster = (CMonster*)CreateObject("Goblin", OT_MONSTER);

	pMonster->SetName("���");
	pMonster->SetCharacterInfo(10, 20, 3, 5, 100, 10, 1, 1000);
	pMonster->SetGold(1000, 2000);

	pMonster = (CMonster*)CreateObject("Troll", OT_MONSTER);

	pMonster->SetName("Ʈ��");
	pMonster->SetCharacterInfo(50, 80, 40, 60, 2000, 300, 5, 7000);
	pMonster->SetGold(5000, 10000);

	pMonster = (CMonster*)CreateObject("Dragon", OT_MONSTER);

	pMonster->SetName("�巡��");
	pMonster->SetCharacterInfo(150, 250, 150, 250, 10000, 10000, 10, 25000);
	pMonster->SetGold(30000, 50000);

	return true;
}

CObj* CObjectManager::CreateObject(const string& strKey, OBJECT_TYPE eType)
{
	CObj* pObj = NULL;

	switch (eType)
	{
	case OT_PLAYER:
		pObj = new CPlayer;
		break;
	case OT_MONSTER:
		pObj = new CMonster;
		break;
	}

	if (!pObj->Init())
	{
		SAFE_DELETE(pObj);
		return NULL;
	}

	// ���� key�� value�� �̿��ؼ� �����͸� �����ϱ� ������
	// make_pair�� �̿��ؼ� key�� value�� ��� �ʿ� insert �Ѵ�.
	m_mapObj.insert(make_pair(strKey, pObj));

	return pObj;
}

CObj* CObjectManager::FindObject(const string& strKey)
{
	// map�� find �Լ��� �������ش�. find�Լ��� key�� �־��ָ� �ش� Ű�� Ž���Ͽ�
	// ���� ��� �ش� Ű�� iterator �� ��ȯ�ϰ� ���� ��� end() �� ��ȯ�Ѵ�.
	unordered_map<string, CObj*>::iterator	iter = m_mapObj.find(strKey);

	// end() �� ���� ���� ã�� ���ߴٴ� ���̴�.
	if (iter == m_mapObj.end())
		return NULL;	// NUMM�� 0�̹Ƿ� ã�� ���ߴٴ� �ǹ̷� ����.

	return iter->second;
}

// ���ڷ� ������ Ű�� �̿��ؼ� ��ü�� ã�� �Ŀ� �ش� ��ü�� �����ؼ� ������ ��
// ��ȯ���ִ� �Լ��̴�.
CObj* CObjectManager::CloneObject(const string& strKey)
{
	// ������ ������ü�� ã�´�.
	CObj* pOrigin = FindObject(strKey);

	// pOrigin�� NULL�̶�� ���� ã�� ���ߴٴ� ���̴�.
	if (!pOrigin)
		return NULL;

	// ���� ã�Ҵٸ� ���� ��ü�� ������ ���ο� ��ü�� ���� ��ȯ�Ѵ�.
	return pOrigin->Clone();
}
