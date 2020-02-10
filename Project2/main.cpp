/*
�������� ���� C++ ���α׷���
OOP �ܰ躰 ������Ʈ
Date : `20. 02. 10 (MON)

Version : 0.7
�ֿ� ���� : ���� ������ �� �� ��Ȯ�ϰ� ����
���������� �����ؾ� �ϴ� ������� ��������� ������(std�� enum����)

���ذ�
? AccoutHander �����ڿ��� Accout ������� �ʱ�ȭ�� ��� �ؾ�����?
	���� 0���� �ʱ�ȭ�ϸ� �Ƿ���?
? Handler����, ��ӹ޴� Ŭ������ �����ϴ� �Լ��� �� protected �ϱ�?

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
		default: cout << "1���� 5������ ���ڸ� �Է����ּ���.\n\n";
			break;
		}
	}

	return 0;
}