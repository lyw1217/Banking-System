#include "AccountHandler.h"

enum {LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2};

AccountHandler::AccountHandler() :accNum(0) {
	// Account 클래스 멤버 변수를 어떻게 초기화 해야 하지..
}
AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++) {
		delete[] accArr[i];
	}
}

void AccountHandler::ShowMenu(void) const {
	std::cout << "-----Menu-----\n" << "1. 계좌계설\n" << "2. 입 금\n" << "3. 출 금\n" << "4. 계좌정보 전체 출력\n" << "5. 프로그램 종료\n" << "선택: ";
	return;
}

bool AccountHandler::CreatAccount(void) {
	int choice;

	std::cout << "\n[계좌종류선택]\n";
	std::cout << "1. 보통예금계좌  2.신용신뢰계좌\n"; std::cin >> choice;

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
		std::cout << "1 또는 2를 입력하세요.\n";
		return false;
	}

	return true;
}
bool AccountHandler::CreatNormalAccount(void) {
	int num, money, rate;
	char name[NAME_LEN];

	std::cout << "\n[보통예금계좌 개설]\n";
	std::cout << "계좌ID: "; std::cin >> num;
	std::cout << "이 름: "; std::cin >> name;
	std::cout << "입금액: "; std::cin >> money;
	std::cout << "이자율: "; std::cin >> rate;

	accArr[accNum] = new NormalAccount(num, money, name, rate);

	if (strlen(accArr[accNum]->GetName()) == 0) {
		return false;
	}
	else {
		std::cout << accArr[accNum++]->GetNum() << " 계좌 개설 완료\n\n";
		return true;
	}
}
bool AccountHandler::CreatCreditAccount(void) {
	int num, money, rate, level;
	char name[NAME_LEN];

	std::cout << "\n[신용신뢰계좌 개설]\n";
	std::cout << "계좌ID: "; std::cin >> num;
	std::cout << "이 름: "; std::cin >> name;
	std::cout << "입금액: "; std::cin >> money;
	std::cout << "이자율: "; std::cin >> rate;
	std::cout << "신용등급(1toA, 2toB, 3toC): "; std::cin >> level;

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
		std::cout << "신용 등급을 잘못 입력했습니다.\n";
		return false;
	}

	if (strlen(accArr[accNum]->GetName()) == 0) {
		return false;
	}
	else {
		std::cout << accArr[accNum++]->GetNum() << " 계좌 개설 완료\n\n";
		return true;
	}
}

bool AccountHandler::InputMoney(void) {
	int i, num, money;

	std::cout << "\n[입     금]\n";
	std::cout << "계좌ID: "; std::cin >> num;
	std::cout << "입금액: "; std::cin >> money;

	for (i = 0; i < accNum; i++) {
		if (accArr[i]->GetNum() == num) {
			accArr[i]->SetMoney(money);
			std::cout << accArr[i]->GetNum() << " 계좌에 " << money << "원 입금 완료\n" << "잔액 : " << accArr[i]->GetMoney() << "\n\n";
			return true;
		}
	}

	std::cout << "계좌ID " << num << "은 없는 계좌ID입니다.\n";
	return false;
}
bool AccountHandler::OutputMoney(void) {
	int i, num, money;

	std::cout << "\n[출     금]\n";
	std::cout << "계좌ID: "; std::cin >> num;
	std::cout << "출금액: "; std::cin >> money;

	for (i = 0; i < accNum; i++) {
		if (accArr[i]->GetNum() == num) {
			accArr[i]->SetMoney(-money);
			if (accArr[i]->GetMoney() < 0) {
				accArr[i]->SetMoney(money);
				std::cout << "잔액이 부족합니다.\n";
				return false;
			}
			std::cout << accArr[i]->GetNum() << " 계좌에서 " << money << "원 출금 완료\n" << "잔액 : " << accArr[i]->GetMoney() << "\n\n";
			return true;
			break;
		}
	}

	std::cout << "계좌ID " << num << "은 없는 계좌ID입니다.\n";
	return false;
}
bool AccountHandler::PrintAccount(void) const {

	std::cout << "\n[계좌정보 전체 출력]\n";

	for (int i = 0; i < accNum; i++) {
		std::cout << i + 1 << "번째\n";
		accArr[i]->PrintAccount();
	}
	return true;
}
bool AccountHandler::ExitProgram(void) const {
	std::cout << "프로그램을 종료합니다.\n";
	return false;
}

void AccountHandler::ErrorPrint(void) const {
	std::cout << "처음부터 다시 시도해주세요.\n\n";
	return;
}