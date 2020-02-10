#pragma once
#include "CommonDecl.h"
#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
	int level;
public:
	HighCreditAccount(int _account_num, int _money, const char* _name, int _rate, int _level)
		: NormalAccount(_account_num, _money, _name, _rate), level(_level)
	{}

	~HighCreditAccount() {};

	virtual void SetMoney(int _money) {
		NormalAccount::SetMoney(_money);	// 원금 + 기본 이자 추가
		Account::SetMoney(_money * (this->level / 100.0));	// 등급이자 추가
	};
};