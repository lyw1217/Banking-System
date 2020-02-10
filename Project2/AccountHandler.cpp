#include "AccountHandler.h"

AccountHandler::AccountHandler() :accNum(0) {
	// Account Ŭ���� ��� ������ ��� �ʱ�ȭ �ؾ� ����..
}
AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++) {
		delete[] accArr[i];
	}
}

void AccountHandler::ShowMenu(void) const {
	cout << "-----Menu-----\n" << "1. ���°輳\n" << "2. �� ��\n" << "3. �� ��\n" << "4. �������� ��ü ���\n" << "5. ���α׷� ����\n" << "����: ";
	return;
}

bool AccountHandler::CreatAccount(void) {
	int choice;

	cout << "\n[������������]\n";
	cout << "1. ���뿹�ݰ���  2.�ſ�ŷڰ���\n"; cin >> choice;

	switch (choice) {
	case 1:
		if (!CreatNormalAccount())
			return false;
		break;
	case 2:
		if (!CreatCreditAccount())
			return false;
		break;
	default:
		cout << "1 �Ǵ� 2�� �Է��ϼ���.\n";
		return false;
	}

	return true;
}
bool AccountHandler::CreatNormalAccount(void) {
	int num, money, rate;
	char name[NAME_LEN];

	cout << "\n[���뿹�ݰ��� ����]\n";
	cout << "����ID: "; cin >> num;
	cout << "�� ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> money;
	cout << "������: "; cin >> rate;

	accArr[accNum] = new NormalAccount(num, money, name, rate);

	if (strlen(accArr[accNum]->GetName()) == 0) {
		return false;
	}
	else {
		cout << accArr[accNum++]->GetNum() << " ���� ���� �Ϸ�\n\n";
		return true;
	}
}
bool AccountHandler::CreatCreditAccount(void) {
	int num, money, rate, level;
	char name[NAME_LEN];

	cout << "\n[�ſ�ŷڰ��� ����]\n";
	cout << "����ID: "; cin >> num;
	cout << "�� ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> money;
	cout << "������: "; cin >> rate;
	cout << "�ſ���(1toA, 2toB, 3toC): "; cin >> level;

	switch (level) {
	case 1:
		accArr[accNum] = new HighCreditAccount(num, money, name, rate, LEVEL_A);
		break;
	case 2:
		accArr[accNum] = new HighCreditAccount(num, money, name, rate, LEVEL_B);
		break;
	case 3:
		accArr[accNum] = new HighCreditAccount(num, money, name, rate, LEVEL_C);
		break;
	default:
		cout << "�ſ� ����� �߸� �Է��߽��ϴ�.\n";
		return false;
	}

	if (strlen(accArr[accNum]->GetName()) == 0) {
		return false;
	}
	else {
		cout << accArr[accNum++]->GetNum() << " ���� ���� �Ϸ�\n\n";
		return true;
	}
}

bool AccountHandler::InputMoney(void) {
	int i, num, money;

	cout << "\n[��     ��]\n";
	cout << "����ID: "; cin >> num;
	cout << "�Աݾ�: "; cin >> money;

	for (i = 0; i < accNum; i++) {
		if (accArr[i]->GetNum() == num) {
			accArr[i]->SetMoney(money);
			cout << accArr[i]->GetNum() << " ���¿� " << money << "�� �Ա� �Ϸ�\n" << "�ܾ� : " << accArr[i]->GetMoney() << "\n\n";
			return true;
		}
	}

	cout << "����ID " << num << "�� ���� ����ID�Դϴ�.\n";
	return false;
}
bool AccountHandler::OutputMoney(void) {
	int i, num, money;

	cout << "\n[��     ��]\n";
	cout << "����ID: "; cin >> num;
	cout << "��ݾ�: "; cin >> money;

	for (i = 0; i < accNum; i++) {
		if (accArr[i]->GetNum() == num) {
			accArr[i]->SetMoney(-money);
			if (accArr[i]->GetMoney() < 0) {
				accArr[i]->SetMoney(money);
				cout << "�ܾ��� �����մϴ�.\n";
				return false;
			}
			cout << accArr[i]->GetNum() << " ���¿��� " << money << "�� ��� �Ϸ�\n" << "�ܾ� : " << accArr[i]->GetMoney() << "\n\n";
			return true;
			break;
		}
	}

	cout << "����ID " << num << "�� ���� ����ID�Դϴ�.\n";
	return false;
}
bool AccountHandler::PrintAccount(void) const {

	cout << "\n[�������� ��ü ���]\n";

	for (int i = 0; i < accNum; i++) {
		cout << i + 1 << "��°\n";
		accArr[i]->PrintAccount();
	}
	return true;
}
bool AccountHandler::ExitProgram(void) const {
	cout << "���α׷��� �����մϴ�.\n";
	return false;
}

void AccountHandler::ErrorPrint(void) const {
	cout << "ó������ �ٽ� �õ����ּ���.\n\n";
	return;
}