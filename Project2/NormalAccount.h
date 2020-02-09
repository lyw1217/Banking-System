#pragma once
#include <iostream>
#include "Account.h"

class NormalAccount : public Account
{
private:
	int rate;
public:
	NormalAccount(int _account_num, int _money, const char* _name, int _rate);
	
	~NormalAccount();

	virtual void SetMoney(int _money);
};

