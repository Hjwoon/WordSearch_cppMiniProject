#ifndef START_H
#define START_H

class Start {
public:
	void removeCursor(); // 커서 숨기기
	void gotoxy(short x, short y); // 내가 원하는 위치로 커서 옮기기
	void cls(int bgColor, int txtColor); // 화면 지우고 원하는 배경색으로 설정
	void init(); // 게임 초기화, 처음 시작과 Restart 때 호출
	void txtColor(int fgColor, int bgColor); // 텍스트 색상
	void firstWindows(); // 초기 화면
	void start(); // 시작 버튼
	void run();
};

#endif
