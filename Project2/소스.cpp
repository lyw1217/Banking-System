//#include <iostream>
//#include <cstring>
//
//#define NAME_LEN 20
//
//using namespace std;
//
//enum { COMPLETE, FAIL};
//enum { CREATE = 1, INPUT, OUTPUT, PRINT, EXIT }; // choice
//
//// 함수 선언부
//void ShowMenu(void);
//int CreatAccount(void);
//int InputMoney(void);
//int OutputMoney(void);
//int PrintAccount(void);
//int ExitProgram(void);
//void ErrorPrint(void);
//
//// Account 구조체 선언부
//typedef struct {
//	int account_num; // 계좌번호
//	int money; // 금액
//	char name[NAME_LEN]; // 고객명
//
//} Account;
//
//Account accArr[100]; // Account 저장을 위한 배열
//int accNum = 0;	// Account 번호
//
//int main() {
//	
//	int choice;
//	int state = COMPLETE;
//	
//	while (1) {
//		if (state == FAIL) break;
//		
//		ShowMenu();
//		cin >> choice;
//
//		switch (choice) {
//		case CREATE:
//			if (CreatAccount() == FAIL) ErrorPrint();
//			break;
//		case INPUT:
//			if (InputMoney() == FAIL) ErrorPrint();
//			break;
//		case OUTPUT:
//			if (OutputMoney() == FAIL) ErrorPrint();
//			break;
//		case PRINT:
//			if (PrintAccount() == FAIL) ErrorPrint();
//			break;
//		case EXIT:
//			state = ExitProgram();
//			break;
//		default: cout << "1에서 5까지의 숫자를 입력해주세요.\n";
//			break;
//		}
//	}
//	
//	return 0;
//}
//
//void ShowMenu(void) {
//	cout << "-----Menu-----\n" << "1. 계좌계설\n" << "2. 입 금\n" << "3. 출 금\n" << "4. 계좌정보 전체 출력\n" << "5. 프로그램 종료\n" << "선택: ";
//	return;
//}
//
//int CreatAccount(void) {
//	int num, money;
//	char name[NAME_LEN];
//
//	cout << "\n[계좌 개설]\n";
//	cout << "계좌ID: "; cin >> num;
//	cout << "이 름: "; cin >> name;
//	cout << "입금액: "; cin >> money;
//
//	accArr[accNum].account_num = num;
//	accArr[accNum].money = money;
//	strcpy(accArr[accNum].name, name);
//
//	if (strlen(accArr[accNum].name) == 0) return FAIL;
//	else {
//		cout << accArr[accNum++].account_num << " 계좌 개설 완료\n\n";
//		return COMPLETE;
//	}
//}
//int InputMoney(void) {
//	int i, num, money;
//
//	cout << "\n[입     금]\n";
//	cout << "계좌ID: "; cin >> num;
//	cout << "입금액: "; cin >> money;
//
//	for (i = 0; i < accNum; i++) {
//		if (accArr[i].account_num == num) {
//			accArr[i].money += money;
//			cout << accArr[i].account_num << " 계좌에 " << money << "원 입금 완료\n" << "잔액 : " << accArr[i].money << endl << endl;
//			return COMPLETE;
//			break;
//		}
//	}
//	
//	cout << "계좌ID " << num << "은 없는 계좌ID입니다.\n";
//	return FAIL;
//}
//int OutputMoney(void) {
//	int i, num, money;
//
//	cout << "\n[출     금]\n";
//	cout << "계좌ID: "; cin >> num;
//	cout << "출금액: "; cin >> money;
//
//	for (i = 0; i < accNum; i++) {
//		if (accArr[i].account_num == num) {
//			accArr[i].money -= money;
//			if (accArr[i].money < 0) {
//				accArr[i].money += money;
//				cout << "잔액이 부족합니다.\n";
//				return FAIL;
//			}
//			cout << accArr[i].account_num << " 계좌에서 " << money << "원 출금 완료\n" << "잔액 : " << accArr[i].money << endl << endl;
//			return COMPLETE;
//			break;
//		}
//	}
//
//	cout << "계좌ID " << num << "은 없는 계좌ID입니다.\n";
//	return FAIL;
//}
//int PrintAccount(void) {
//
//	cout << "\n[계좌정보 전체 출력]\n";
//
//	for (int i = 0; i < accNum; i++) {
//		cout << i+1 << "번째\n" << "계좌ID : " << accArr[i].account_num << endl;
//		cout << "이 름 : " << accArr[i].name << endl;
//		cout << "잔 액 : " << accArr[i].money << endl << endl;
//	}
//	return COMPLETE;
//}
//int ExitProgram(void) {
//	cout << "프로그램을 종료합니다.\n";
//	return FAIL;
//}
//
//void ErrorPrint(void) {
//	cout << "처음부터 다시 시도해주세요.\n\n";
//	return;
//}