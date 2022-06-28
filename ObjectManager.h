#pragma once

#include "value.h"

class CObj;
class CObjectManager
{
private:
	// map�� �⺻������ key, value�� �����Ǿ� �ִ�.
	// ù��° tamplate Ÿ���� key, �ι�° template Ÿ���� value�̴�.
	// �׷��� Ÿ���� 2���� �������ְ� key�� �̿��ؼ� Ž���� �ϰ� �ȴ�.
	// ���� ���� value�� ������ Ÿ���� ���� �����ϴ� ���̴�.
	unordered_map<string, CObj*>	m_mapObj;

public:
	bool Init();
	CObj* CreateObject(const string& strKey, OBJECT_TYPE eType);
	CObj* FindObject(const string& strKey);
	CObj* CloneObject(const string& strKey);
	CObj* CloneObject(STAGE_TYPE eType);

	DECLARE_SINGLE(CObjectManager)
};

