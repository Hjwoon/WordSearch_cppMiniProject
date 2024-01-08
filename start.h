#ifndef START_H
#define START_H

#include "Wordsearch.h"

class Start {
	string name;
public:
	void removeCursor(); // 커서 숨기기
	void gotoxy(short x, short y); // 내가 원하는 위치로 커서 옮기기
	void cls(int bgColor, int txtColor); // 화면 지우고 원하는 배경색으로 설정
	void txtColor(int fgColor, int bgColor); // 텍스트 색상
	void firstWindows(); // 초기 화면
	void setName(string name) { this->name = name; }
	string getName() { return name; }
	void run();
};

#endif
