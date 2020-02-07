#pragma once
#include <iostream>
#include <cstring>
class Account
{
private:
	int account_num;
	int money;
	char* name;

public:
	Account(int _account_num, int _money, const char* _name)
		: account_num(_account_num), money(_money)
	{
		this->name = new char[strlen(_name) + 1];
		strcpy(this->name, _name);
	}

	// 깊은 복사를 위한 복사생성자 정의
	Account(const Account& ref)
		: account_num(ref.account_num), money(ref.money)
	{
		this->name = new char[strlen(ref.name) + 1];
		strcpy(this->name, ref.name);
	}

	void PrintAccount(void);

	int GetNum();
	int GetMoney();
	const char* GetName();

	void SetMoney(int _money);
	
	~Account() {
		delete[] name;
	}
};

