/*
윤성우의 열혈 C++ 프로그래밍
OOP 단계별 프로젝트
Date : `20. 02. 10 (MON)

Version : 0.7
주요 내용 : 파일 분할을 좀 더 정확하게 하자
공통적으로 포함해야 하는 내용들은 공통헤더를 만들자(std나 enum같이)

미해결
? AccoutHander 생성자에서 Accout 멤버변수 초기화를 어떻게 해야하지?
	전부 0으로 초기화하면 되려나?
? Handler에서, 상속받는 클래스를 생성하는 함수는 왜 protected 일까?

YoungWoo Lee
*/

#include "CommonDecl.h"
#include "Account.h"
#include "AccountHandler.h"

int main() {

	int choice;
	bool state = true;
	AccountHandler manager;

	while (1) {
		if (!state) break;

		manager.ShowMenu();
		cin >> choice;

		switch (choice) {
		case CREATE:
			if (!manager.CreatAccount()) manager.ErrorPrint();
			break;
		case INPUT:
			if (!manager.InputMoney()) manager.ErrorPrint();
			break;
		case OUTPUT:
			if (!manager.OutputMoney()) manager.ErrorPrint();
			break;
		case PRINT:
			if (!manager.PrintAccount()) manager.ErrorPrint();
			break;
		case EXIT:
			state = manager.ExitProgram();
			break;
		default: cout << "1에서 5까지의 숫자를 입력해주세요.\n\n";
			break;
		}
	}

	return 0;
}