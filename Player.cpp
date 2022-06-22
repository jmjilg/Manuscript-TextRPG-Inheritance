#include "Player.h"

CPlayer::CPlayer()
{
	m_eType = OT_PLAYER;
}

CPlayer::CPlayer(const CPlayer& player) :
	CCharacter(player)
{
	m_eJob = player.m_eJob;
	m_strJobName = player.m_strJobName;
	m_iGold = player.m_iGold;
}

CPlayer::~CPlayer()
{
}

void CPlayer::AddGold(int iGold)
{
	m_iGold += iGold;
}

void CPlayer::DropGold()
{
	m_iGold *= 0.9f;
}

bool CPlayer::Init()
{
	cout << "�̸��� �Է��ϼ��� : ";
	char	strName[32] = {};
	cin.getline(strName, 31);

	SetName(strName);

	int iJob;

	while (true)
	{
		system("cls");
		cout << "1. ���" << endl;
		cout << "2. �ü�" << endl;
		cout << "3. ������" << endl;
		cout << "������ �����ϼ��� : ";
		iJob = Input<int>();

		if (iJob <= JOB_KNIGHT || iJob > JOB_END)
			continue;

		break;
	}

	m_eJob = (JOB)iJob;

	switch (m_eJob)
	{
	case JOB_KNIGHT:
		m_strJobName = "���";
		SetCharacterInfo(10, 15, 15, 20, 500, 100, 1, 0);
		break;
	case JOB_ARCHER:
		m_strJobName = "�ü�";
		SetCharacterInfo(12, 20, 10, 15, 400, 200, 1, 0);
		break;
	case JOB_MAGICION:
		m_strJobName = "������";
		SetCharacterInfo(20, 25, 5, 10, 300, 300, 1, 0);
		break;
	}

	m_iGold = 10000;

	return true;
}

void CPlayer::Render()
{
	cout << "�̸� : " << m_strName << "\t���� : " << m_strJobName << endl;
	cout << "���� : " << m_tInfo.iLevel << "\t����ġ : " << m_tInfo.iExp << endl;
	cout << "���ݷ� : " << m_tInfo.iAttackMin << " - " << m_tInfo.iAttackMax <<
		"\t���� : " << m_tInfo.iArmorMin << " - " << m_tInfo.iArmorMax << endl;
	cout << "ü�� : " << m_tInfo.iHP << " / " << m_tInfo.iHPMax << "\t���� : " <<
		m_tInfo.iMP << " / " << m_tInfo.iMPMax << endl;
	cout << "�����ݾ� : " << m_iGold << " Gold" << endl;
}

CPlayer* CPlayer::Clone()
{
	// this �� �ڱ��ڽ��� �������̴�. �ڱ��ڽ��� �����͸� �������ϸ� �ڱ��ڽ� ��ü
	// ��ü�� �ȴ�. �׷��� ���� �Ҵ��ϴ� �÷��̾� ��ü�� �ڱ��ڽ��� �Ѱ��־
	// �ڱ��ڽ��� �����ϴ� �����ڸ� ȣ���Ͽ� �����ϵ��� ������ش�.
	// �̷��� ���ָ� �� ��ü�� ������ ���ο� ��ü�� �����Ҵ� �Ͽ� �� �޸� �ּҸ�
	// ��ȯ���ְ� �ȴ�.
	return new CPlayer(*this);
}
