#include "HighCreditAccount.h"

HighCreditAccount::HighCreditAccount(int _account_num, int _money, const char* _name, int _rate, int _level)
	: NormalAccount(_account_num, _money, _name, _rate), level(_level)
{}

HighCreditAccount::~HighCreditAccount(){}

void HighCreditAccount::SetMoney(int _money) {
	NormalAccount::SetMoney(_money);	// ���� + �⺻ ���� �߰�
	Account::SetMoney(_money * (this->level / 100.0));	// ������� �߰�
}