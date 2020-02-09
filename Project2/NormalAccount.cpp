#include "NormalAccount.h"

NormalAccount::NormalAccount(int _account_num, int _money, const char* _name, int _rate)
	: Account(_account_num, _money, _name), rate(_rate)
{}

NormalAccount::~NormalAccount() {
}

void NormalAccount::SetMoney(int _money) {
	Account::SetMoney(_money);	// ���� �߰�
	Account::SetMoney(_money * (this->rate/100.0));	// �⺻ ���� �߰�
}