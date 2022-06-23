#include "Inventory.h"
#include "Item.h"

DEFINITION_SINGLE(CInventory)

CInventory::CInventory()    :
    m_iInvenMax(10)
{
}

CInventory::~CInventory()
{
    Safe_Delete_VecList(m_vecItem);
}

bool CInventory::Init()
{
    return true;
}

void CInventory::AddItem(CItem* pItem)
{
    if (m_iInvenMax == m_vecItem.size())
        return;

    m_vecItem.push_back(pItem);
}

void CInventory::Run()
{
    for (size_t i = 0; i < m_vecItem.size(); ++i)
    {
        cout << i + 1 << ". ";
        m_vecItem[i]->Render();
        cout << endl;
    }

    system("pause");
}
