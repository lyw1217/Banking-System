#include "Account.h"

Account::Account(int _account_num, int _money, const char* _name)
	: account_num(_account_num), money(_money)
{
	this->name = new char[strlen(_name) + 1];
	strcpy(this->name, _name);
}

// ���� ���縦 ���� ��������� ����
Account::Account(const Account& ref)
	: account_num(ref.account_num), money(ref.money)
{
	this->name = new char[strlen(ref.name) + 1];
	strcpy(this->name, ref.name);
}

Account::~Account() {
	delete[] name;
}

void Account::PrintAccount(void) const{
	std::cout << "����ID : " << this->account_num << std::endl;
	std::cout << "�� �� : " << this->name << std::endl;
	std::cout << "�� �� : " << this->money << std::endl << std::endl;
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