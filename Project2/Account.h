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
	Account(int _account_num, int _money, const char* _name);
	// ���� ���縦 ���� ��������� ����
	Account(const Account& ref);
	~Account();

	// ��� ������ �� ������ ������� �ʴ� �Լ��鿡��
	// const �� �ٿ�����
	void PrintAccount(void) const;

	int GetNum() const;
	int GetMoney() const;
	const char* GetName() const;

	void SetMoney(int _money);
};

