/*
�������� ���� C++ ���α׷���
OOP �ܰ躰 ������Ʈ
Version : 0.4
Date : `20. 02. 07 (FRI)
YoungWoo Lee
*/

#include <iostream>
#include <cstring>
#include "Account.h"

#define NAME_LEN 20
#define MAX_ACCOUNT 100
using namespace std;

enum { COMPLETE, FAIL };
enum { CREATE = 1, INPUT, OUTPUT, PRINT, EXIT }; // choice

// �Լ� �����
void ShowMenu(void);
int CreatAccount(void);
int InputMoney(void);
int OutputMoney(void);
int PrintAccount(void);
int ExitProgram(void);
void ErrorPrint(void);

Account* accArr[MAX_ACCOUNT]; // Account ������ ���� �迭
int accNum = 0;	// Account ��ȣ

int main() {

	int choice;
	int state = COMPLETE;

	while (1) {
		if (state == FAIL) break;

		ShowMenu();
		cin >> choice;

		switch (choice) {
		case CREATE:
			if (CreatAccount() == FAIL) ErrorPrint();
			break;
		case INPUT:
			if (InputMoney() == FAIL) ErrorPrint();
			break;
		case OUTPUT:
			if (OutputMoney() == FAIL) ErrorPrint();
			break;
		case PRINT:
			if (PrintAccount() == FAIL) ErrorPrint();
			break;
		case EXIT:
			state = ExitProgram();
			break;
		default: cout << "1���� 5������ ���ڸ� �Է����ּ���.\n";
			break;
		}
	}

	return 0;
}

void ShowMenu(void) {
	cout << "-----Menu-----\n" << "1. ���°輳\n" << "2. �� ��\n" << "3. �� ��\n" << "4. �������� ��ü ���\n" << "5. ���α׷� ����\n" << "����: ";
	return;
}

int CreatAccount(void) {
	int num, money;
	char name[NAME_LEN];

	cout << "\n[���� ����]\n";
	cout << "����ID: "; cin >> num;
	cout << "�� ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> money;

	accArr[accNum] = new Account(num, money, name);

	if (strlen(accArr[accNum]->GetName()) == 0) {
		return FAIL;
	}
	else {
		cout << accArr[accNum++]->GetNum() << " ���� ���� �Ϸ�\n\n";
		return COMPLETE;
	}
}
int InputMoney(void) {
	int i, num, money;

	cout << "\n[��     ��]\n";
	cout << "����ID: "; cin >> num;
	cout << "�Աݾ�: "; cin >> money;

	for (i = 0; i < accNum; i++) {
		if (accArr[i]->GetNum() == num) {
			accArr[i]->SetMoney(money);
			cout << accArr[i]->GetNum() << " ���¿� " << money << "�� �Ա� �Ϸ�\n" << "�ܾ� : " << accArr[i]->GetMoney() << endl << endl;
			return COMPLETE;
		}
	}

	cout << "����ID " << num << "�� ���� ����ID�Դϴ�.\n";
	return FAIL;
}
int OutputMoney(void) {
	int i, num, money;

	cout << "\n[��     ��]\n";
	cout << "����ID: "; cin >> num;
	cout << "��ݾ�: "; cin >> money;

	for (i = 0; i < accNum; i++) {
		if (accArr[i]->GetNum() == num) {
			accArr[i]->SetMoney(-money);
			if (accArr[i]->GetMoney() < 0) {
				accArr[i]->SetMoney(money);
				cout << "�ܾ��� �����մϴ�.\n";
				return FAIL;
			}
			cout << accArr[i]->GetNum() << " ���¿��� " << money << "�� ��� �Ϸ�\n" << "�ܾ� : " << accArr[i]->GetMoney() << endl << endl;
			return COMPLETE;
			break;
		}
	}

	cout << "����ID " << num << "�� ���� ����ID�Դϴ�.\n";
	return FAIL;
}
int PrintAccount(void) {

	cout << "\n[�������� ��ü ���]\n";

	for (int i = 0; i < accNum; i++) {
		cout << i + 1 << "��°\n" << "����ID : " << accArr[i]->GetNum() << endl;
		cout << "�� �� : " << accArr[i]->GetName() << endl;
		cout << "�� �� : " << accArr[i]->GetMoney() << endl << endl;
	}
	return COMPLETE;
}
int ExitProgram(void) {
	cout << "���α׷��� �����մϴ�.\n";
	return FAIL;
}

void ErrorPrint(void) {
	cout << "ó������ �ٽ� �õ����ּ���.\n\n";
	return;
}