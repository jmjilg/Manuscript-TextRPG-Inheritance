#include "Core.h"
#include "StageManager.h"
#include "ObjectManager.h"
#include "StoreManager.h"
#include "Inventory.h"

DEFINITION_SINGLE(CCore)

enum MAIN_MENU
{
	MM_NONE,
	MM_STAGE,
	MM_STORE,
	MM_INVENTORY,
	MM_STATUS,
	MM_EXIT
};

CCore::CCore()
{
}

CCore::~CCore()
{
	DESTROY_SINGLE(CInventory);
	DESTROY_SINGLE(CStoreManager);
	DESTROY_SINGLE(CObjectManager);
	DESTROY_SINGLE(CStageManager);
}

bool CCore::Init()
{
	// ������Ʈ ������ �ʱ�ȭ
	if (!GET_SINGLE(CObjectManager)->Init())
		return false;

	// Stage�� �ʱ�ȭ�Ѵ�.
	if (!GET_SINGLE(CStageManager)->Init())
		return false;

	// ���� �����ڸ� �ʱ�ȭ�Ѵ�.
	if (!GET_SINGLE(CStoreManager)->Init())
		return false;

	// �κ��丮�� �ʱ�ȭ�Ѵ�.
	if (!GET_SINGLE(CInventory)->Init())
		return false;

	return true;
}

void CCore::Run()
{
	while (true)
	{
		switch (OutputMenu())
		{
		case MM_STAGE:
			GET_SINGLE(CStageManager)->Run();
			break;
		case MM_STORE:
			GET_SINGLE(CStoreManager)->Run();
			break;
		case MM_INVENTORY:
			GET_SINGLE(CInventory)->Run();
			break;
		case MM_STATUS:
			break;
		case MM_EXIT:
			return;
		}
	}
}

int CCore::OutputMenu()
{
	system("cls");
	cout << "1. ��" << endl;
	cout << "2. ����" << endl;
	cout << "3. �κ��丮" << endl;
	cout << "4. ĳ��������" << endl;
	cout << "5. ����" << endl;
	cout << "�޴��� �����ϼ��� : ";
	int iMenu = Input<int>();

	if (iMenu <= MM_NONE || iMenu > MM_EXIT)
		return MM_NONE;

	return iMenu;
}
