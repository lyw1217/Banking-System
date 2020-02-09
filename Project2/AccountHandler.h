#pragma once
#include <iostream>
#include "Account.h"

#define NAME_LEN 20
#define MAX_ACCOUNT 100

class AccountHandler
{
private:
	Account* accArr[MAX_ACCOUNT]; // Account ������ ���� �迭
	int accNum;	// Account ��ȣ

public:
	AccountHandler();
	~AccountHandler();
	void ShowMenu(void) const;
	bool CreatAccount(void);
	bool InputMoney(void);
	bool OutputMoney(void);
	bool PrintAccount(void) const;
	bool ExitProgram(void) const;
	void ErrorPrint(void) const;
};

