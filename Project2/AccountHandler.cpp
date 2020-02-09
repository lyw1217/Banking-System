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
	std::cout << "-----Menu-----\n" << "1. ���°輳\n" << "2. �� ��\n" << "3. �� ��\n" << "4. �������� ��ü ���\n" << "5. ���α׷� ����\n" << "����: ";
	return;
}

bool AccountHandler::CreatAccount(void) {
	int num, money;
	char name[NAME_LEN];

	std::cout << "\n[���� ����]\n";
	std::cout << "����ID: "; std::cin >> num;
	std::cout << "�� ��: "; std::cin >> name;
	std::cout << "�Աݾ�: "; std::cin >> money;

	accArr[accNum] = new Account(num, money, name);

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