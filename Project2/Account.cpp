#include "Account.h"

void Account::PrintAccount(void) const{
	std::cout << "°èÁÂID : " << this->account_num << std::endl;
	std::cout << "ÀÌ ¸§ : " << this->name << std::endl;
	std::cout << "ÀÜ ¾× : " << this->money << std::endl << std::endl;
}

int Account::GetNum() const{
	return this->account_num;
}

int Account::GetMoney() const{
	return this->money;
}

const char* Account::GetName() const{
	return this->name;
}

void Account::SetMoney(int _money) {
	this->money += _money;
}