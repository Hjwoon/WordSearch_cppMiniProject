#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <Windows.h>
using namespace std;

#include "Start.h"
#include "Wordsearch.h"

#define BLACK 0 
#define BLUE 1
#define WHITE 15

#define WIDTH 120
#define HEIGHT 30

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

void Start::firstWindows() { // 초기 화면 출력
	// 테두리
	gotoxy(0, 0);
	txtColor(BLUE, WHITE);
	for (int i = 0; i < WIDTH; i++) {
		cout << "■";
	}
	gotoxy(0, 1);
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
	gotoxy(17, 6);
	cout << "■       ■       ■ ■■■■■■■■ ■■■■■■■■ ■■■■■■      ■■■■■■■■ ■■■■■■■■ ■■        ■■ ■■■■■■■■";
	gotoxy(17, 7);
	cout << " ■     ■ ■     ■  ■      ■ ■      ■ ■     ■     ■      ■ ■      ■ ■   ■   ■  ■ ■";
	gotoxy(17, 8);
	cout << "  ■   ■   ■   ■   ■      ■ ■■■■■■■■ ■     ■     ■  ■■■■■ ■■■■■■■■ ■    ■ ■   ■ ■■■■■■■■ ";
	gotoxy(17, 9);
	cout << "   ■ ■     ■ ■    ■      ■ ■       ■■     ■     ■      ■ ■      ■ ■     ■    ■ ■";
	gotoxy(17, 10);
	cout << "    ■       ■     ■■■■■■■■ ■       ■■■■■■■      ■■■■■■■■ ■      ■ ■          ■ ■■■■■■■■";
	

	// "보이는 단어를 전부 찾아라!"
	// 닉네임
	gotoxy(41, 13);
	cout << "보 이 는  단 어 를  전 부  찾 아 라 !";
	gotoxy(29, 15);
	cout << "================================================================";
	gotoxy(31, 17);
	cout << "닉 네 임 >> ";
	gotoxy(29, 19);
	cout << "================================================================";
	gotoxy(49, 22);
	cout << "@2291001 JIWOON H";

}

void Start::run() { // 초기 화면 조작 실행(화면 출력, 닉네임 입력, 시작 버튼 활성화)
	removeCursor();
	cls(WHITE, BLUE);
	
	char ch;
	do {
		firstWindows();
		gotoxy(43, 17);
		cin >> name;
		setName(name);

		gotoxy(48, 25);
		cout << "Start? (y/n): ";
		cin >> ch;
		if (ch == 'y' || ch == 'Y') {
			// 시작 버튼을 누르면 다음 화면으로 넘어가는 로직 추가
			cout << "Starting the game..." << endl;
			break;
		}
	} while (ch != 'n' && ch != 'N');

}
