#pragma once
#include <iostream>
#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
	int level;
public:
	HighCreditAccount(int _account_num, int _money, const char* _name, int _rate, int _level);
	
	~HighCreditAccount();

	virtual void SetMoney(int _money);
};