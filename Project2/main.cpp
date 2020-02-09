/*
윤성우의 열혈 C++ 프로그래밍
OOP 단계별 프로젝트
Date : `20. 02. 09 (SUN)

Version : 0.5
주요 내용 : 컨트롤 클래스를 작성하고, 전역변수, 함수를 없애자
- AccountHandler 클래스 작성
- state boolean형으로 바꿈
? AccoutHander 생성자에서 Accout 멤버변수 초기화를 어떻게 해야하지?
	전부 0으로 초기화하면 되려나?

YoungWoo Lee
*/

#include <iostream>
#include <cstring>
#include "Account.h"
#include "AccountHandler.h"

using namespace std;

enum { CREATE = 1, INPUT, OUTPUT, PRINT, EXIT }; // choice

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