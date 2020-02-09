/*
�������� ���� C++ ���α׷���
OOP �ܰ躰 ������Ʈ
Date : `20. 02. 09 (SUN)

Version : 0.6
�ֿ� ���� : Account Ŭ������ ����ϴ� NormalAccount, HighCreditAccout �߰�
			���� ���� �� ������ �Է�
			�Աݽ� �������� ���� ���� ����
			��ſ���´� �ſ��޿� ���� �Աݽ� �߰� ���� ����
���ذ�
? AccoutHander �����ڿ��� Accout ������� �ʱ�ȭ�� ��� �ؾ�����?
	���� 0���� �ʱ�ȭ�ϸ� �Ƿ���?

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
		default: cout << "1���� 5������ ���ڸ� �Է����ּ���.\n\n";
			break;
		}
	}

	return 0;
}