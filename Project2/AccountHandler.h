#pragma once
#include "CommonDecl.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"


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

protected:
	// �̰� �ΰ��� �� protected ����?
	bool CreatNormalAccount(void);
	bool CreatCreditAccount(void);
};

