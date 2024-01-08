#ifndef WORDSEARCH_H
#define WORDSEARCH_H

#include "start.h"

#include <vector>
#include <set>

class mainGame {
	int ansNum; // 정답 개수
	string word = {NULL};
	char arr[4][4] = { NULL };
	vector<string> v; // 사전 단어들 복사
	vector<string> randV; // 랜덤한 단어 추출 후 저장
	string input; // 사용자에게 입력받을 단어
	set<string> foundWords; // 검사 후 배열 안에 있는 정답 단어
public:
	void print(); // 기본 화면 출력
	void fileRead(vector<string>& v, ifstream& fin); // fin 파일 전체를 벡터에 읽어들임
	void randWord(vector<string>& randV, vector<string>& v); // 랜덤한 단어 추출
	void randArr(vector<string>& randV); // 랜덤한 알파벳 생성
	bool isExi(string word); // 사전에 단어가 있는지 확인
	void scan(); // 8가지 방향으로 전부 검사
	void colorWord(int x, int y, char c, bool isCorrect); // 정답인 단어 색상 변경
	bool findWord(string input); // 단어 찾기 // 단어가 있으면 true 리턴
	//bool checkDuplicate(vector<string>& randV); // 중복 단어 검사
	void run();
};

#endif
