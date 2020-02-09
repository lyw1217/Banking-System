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
	// 깊은 복사를 위한 복사생성자 정의
	Account(const Account& ref);
	~Account();

	// 멤버 변수의 값 변경을 허용하지 않는 함수들에는
	// const 를 붙여주자
	void PrintAccount(void) const;

	int GetNum() const;
	int GetMoney() const;
	const char* GetName() const;

	void SetMoney(int _money);
};

