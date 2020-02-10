#pragma once

#include <iostream>
#include <cstring>

using namespace std;

#define NAME_LEN 20
#define MAX_ACCOUNT 100

// 사용자 선택 메뉴
enum { CREATE = 1, INPUT, OUTPUT, PRINT, EXIT }; // choice

// 신용 등급
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };