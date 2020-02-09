#include "AccountHandler.h"

enum {LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2};

AccountHandler::AccountHandler() :accNum(0) {
	// Account Ŭ���� ��� ������ ��� �ʱ�ȭ �ؾ� ����..
}
AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++) {
		delete[] accArr[i];
	}
}

void AccountHandler::ShowMenu(void) const {
	std::cout << "-----Menu-----\n" << "1. ���°輳\n" << "2. �� ��\n" << "3. �� ��\n" << "4. �������� ��ü ���\n" << "5. ���α׷� ����\n" << "����: ";
	return;
}

bool AccountHandler::CreatAccount(void) {
	int choice;

	std::cout << "\n[������������]\n";
	std::cout << "1. ���뿹�ݰ���  2.�ſ�ŷڰ���\n"; std::cin >> choice;

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
		std::cout << "1 �Ǵ� 2�� �Է��ϼ���.\n";
		return false;
	}

	return true;
}
bool AccountHandler::CreatNormalAccount(void) {
	int num, money, rate;
	char name[NAME_LEN];

	std::cout << "\n[���뿹�ݰ��� ����]\n";
	std::cout << "����ID: "; std::cin >> num;
	std::cout << "�� ��: "; std::cin >> name;
	std::cout << "�Աݾ�: "; std::cin >> money;
	std::cout << "������: "; std::cin >> rate;

	accArr[accNum] = new NormalAccount(num, money, name, rate);

	if (strlen(accArr[accNum]->GetName()) == 0) {
		return false;
	}
	else {
		std::cout << accArr[accNum++]->GetNum() << " ���� ���� �Ϸ�\n\n";
		return true;
	}
}
bool AccountHandler::CreatCreditAccount(void) {
	int num, money, rate, level;
	char name[NAME_LEN];

	std::cout << "\n[�ſ�ŷڰ��� ����]\n";
	std::cout << "����ID: "; std::cin >> num;
	std::cout << "�� ��: "; std::cin >> name;
	std::cout << "�Աݾ�: "; std::cin >> money;
	std::cout << "������: "; std::cin >> rate;
	std::cout << "�ſ���(1toA, 2toB, 3toC): "; std::cin >> level;

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
		std::cout << "�ſ� ����� �߸� �Է��߽��ϴ�.\n";
		return false;
	}

	if (strlen(accArr[accNum]->GetName()) == 0) {
		return false;
	}
	else {
		std::cout << accArr[accNum++]->GetNum() << " ���� ���� �Ϸ�\n\n";
		return true;
	}
}

bool AccountHandler::InputMoney(void) {
	int i, num, money;

	std::cout << "\n[��     ��]\n";
	std::cout << "����ID: "; std::cin >> num;
	std::cout << "�Աݾ�: "; std::cin >> money;

	for (i = 0; i < accNum; i++) {
		if (accArr[i]->GetNum() == num) {
			accArr[i]->SetMoney(money);
			std::cout << accArr[i]->GetNum() << " ���¿� " << money << "�� �Ա� �Ϸ�\n" << "�ܾ� : " << accArr[i]->GetMoney() << "\n\n";
			return true;
		}
	}

	std::cout << "����ID " << num << "�� ���� ����ID�Դϴ�.\n";
	return false;
}
bool AccountHandler::OutputMoney(void) {
	int i, num, money;

	std::cout << "\n[��     ��]\n";
	std::cout << "����ID: "; std::cin >> num;
	std::cout << "��ݾ�: "; std::cin >> money;

	for (i = 0; i < accNum; i++) {
		if (accArr[i]->GetNum() == num) {
			accArr[i]->SetMoney(-money);
			if (accArr[i]->GetMoney() < 0) {
				accArr[i]->SetMoney(money);
				std::cout << "�ܾ��� �����մϴ�.\n";
				return false;
			}
			std::cout << accArr[i]->GetNum() << " ���¿��� " << money << "�� ��� �Ϸ�\n" << "�ܾ� : " << accArr[i]->GetMoney() << "\n\n";
			return true;
			break;
		}
	}

	std::cout << "����ID " << num << "�� ���� ����ID�Դϴ�.\n";
	return false;
}
bool AccountHandler::PrintAccount(void) const {

	std::cout << "\n[�������� ��ü ���]\n";

	for (int i = 0; i < accNum; i++) {
		std::cout << i + 1 << "��°\n";
		accArr[i]->PrintAccount();
	}
	return true;
}
bool AccountHandler::ExitProgram(void) const {
	std::cout << "���α׷��� �����մϴ�.\n";
	return false;
}

void AccountHandler::ErrorPrint(void) const {
	std::cout << "ó������ �ٽ� �õ����ּ���.\n\n";
	return;
}