#include "Account.h"

void Account::PrintAccount(void) {
	std::cout << "����ID : " << this->account_num << std::endl;
	std::cout << "�� �� : " << this->name << std::endl;
	std::cout << "�� �� : " << this->money << std::endl << std::endl;
}

int Account::GetNum() {
	return this->account_num;
}

int Account::GetMoney() {
	return this->money;
}

const char* Account::GetName() {
	return this->name;
}

void Account::SetMoney(int _money) {
	this->money += _money;
}