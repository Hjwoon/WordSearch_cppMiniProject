#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <Windows.h>
using namespace std;

#include "Start.h"

#define BLACK 0 
#define BLUE 9
#define WHITE 15

#define WIDTH 56
#define HEIGHT 24

void Start::removeCursor() {
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void Start::gotoxy(short x, short y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Start::cls(int bgColor, int txtColor) {
	char cmd[9];
	system("cls");
	sprintf(cmd, "COLOR %x%x", bgColor, txtColor);
	system(cmd);
}

void Start::txtColor(int fgColor, int bgColor) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fgColor | bgColor << 4);
}

//void Start::init() {
//	
//}

void Start::firstWindows() { // 초기 화면 출력
	// 테두리
	gotoxy(0, 1);
	txtColor(BLUE, WHITE);
	for (int i = 0; i < WIDTH; i++) {
		cout << "■";
	}
	gotoxy(0, 3);
	txtColor(BLUE, WHITE);
	for (int i = 0; i < WIDTH; i++) {
		cout << "■";
	}
	gotoxy(0, 28);
	txtColor(BLUE, WHITE);
	for (int i = 0; i < WIDTH; i++) {
		cout << "■";
	}
	gotoxy(0, 30);
	txtColor(BLUE, WHITE);
	for (int i = 0; i < WIDTH; i++) {
		cout << "■";
	}

	// 게임 제목 출력, "WORD GAME"
	gotoxy(11, 5);
	txtColor(BLUE, WHITE);
	cout << "■                ■■■■■■■■  ■■■        ■■■■■■  ■■  ■ ■■ ■  ■■■■■";
	gotoxy(11, 6);
	txtColor(BLUE, WHITE);
	cout << " ■      ■      ■ ■    ■■    ■■   ■       ■■■■■■  ■■  ■ ■■ ■  ■■■■■";
	gotoxy(11, 7);
	txtColor(BLUE, WHITE);
	cout << "  ■    ■■    ■  ■    ■■    ■■   ■       ■■■■■■  ■■  ■ ■■ ■  ■■■■■";
	gotoxy(11, 8);
	txtColor(BLUE, WHITE);
	cout << "   ■  ■  ■  ■   ■    ■■■■■■   ■       ■■■■■■  ■■  ■ ■■ ■  ■■■■■";
	gotoxy(11, 9);
	txtColor(BLUE, WHITE);
	cout << "    ■■    ■■    ■    ■■    ■■   ■       ■■■■■■  ■■  ■ ■■ ■  ■■■■■";
	gotoxy(11, 10);
	txtColor(BLUE, WHITE);
	cout << "     ■      ■     ■■■■■    ■■■■        ■■■■■■  ■■  ■ ■■ ■  ■■■■■";
}

void Start::run() { // 초기 화면 조작 실행(화면 출력, 닉네임 입력, 시작 버튼 활성화)
	removeCursor();
	cls(WHITE, BLUE);
	firstWindows();
}

