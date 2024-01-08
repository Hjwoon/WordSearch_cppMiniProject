#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set> // STL컨테이너:정렬 저장, 중복된 값 허용x // foundWords 저장하기 위함
#include <thread> 
#include <chrono>
using namespace std;

#include "Wordsearch.h"
#include "Start.h"

#define BLACK 0 
#define BLUE 1
#define RED 12
#define WHITE 15

#define WIDTH 120
#define HEIGHT 30

int life = 5;
int score = 0;
const int SIZE = 4;

void mainGame::print() { // 메인 게임 기본 화면 출력
	Start s;
	// 테두리
	s.gotoxy(0, 0);
	s.txtColor(BLUE, WHITE);
	for (int i = 0; i < WIDTH; i++) {
		cout << "■";
	}
	s.gotoxy(0, 1);
	s.txtColor(BLUE, WHITE);
	for (int i = 0; i < WIDTH; i++) {
		cout << "■";
	}
	s.gotoxy(0, 28);
	s.txtColor(BLUE, WHITE);
	for (int i = 0; i < WIDTH; i++) {
		cout << "■";
	}
	s.gotoxy(0, 29);
	s.txtColor(BLUE, WHITE);
	for (int i = 0; i < WIDTH; i++) {
		cout << "■";
	}

	s.gotoxy(11, 7);
	cout << "■■■■■■■■■■■■■■■■■■■■■■";
	s.gotoxy(11, 8);
	cout << "■";
	s.gotoxy(32, 8);
	cout << "■";
	s.gotoxy(11, 9);
	cout << "■";
	s.gotoxy(32, 9);
	cout << "■";
	s.gotoxy(11, 10);
	cout << "■";
	s.gotoxy(32, 10);
	cout << "■";
	s.gotoxy(11, 11);
	cout << "■";
	s.gotoxy(32, 11);
	cout << "■";
	s.gotoxy(11, 12);
	cout << "■";
	s.gotoxy(32, 12);
	cout << "■";
	s.gotoxy(11, 13);
	cout << "■";
	s.gotoxy(32, 13);
	cout << "■";
	s.gotoxy(11, 14);
	cout << "■";
	s.gotoxy(32, 14);
	cout << "■";
	s.gotoxy(11, 15);
	cout << "■";
	s.gotoxy(32, 15);
	cout << "■";
	s.gotoxy(11, 16);
	cout << "■■■■■■■■■■■■■■■■■■■■■■";


	//
	s.gotoxy(51, 9);
	cout << "==========================================================";
	s.gotoxy(51, 23);
	cout << "==========================================================";


}

void mainGame::fileRead(vector<string>& v, ifstream& fin) { // words.txt 파일 읽기
	string line;
	while (getline(fin, line)) {
		v.push_back(line);
	}
}


void mainGame::randWord(vector<string>& randV, vector<string>& v) { // 랜덤한 단어 추출
	srand((unsigned)time(NULL));
	int num = 0;
	while (true) {
		if (num == 16)
			break;
		int n = rand() % v.size();
		string rword = v[n];

		// 길이가 2 이상 4 이하인 경우에만 벡터에 추가
		if (rword.size() <= 4 && rword.size() >= 2) {
			// 소문자로 변환 후 벡터에 추가
			for (char& c : rword) {
				c = tolower(c);
			}
			randV.push_back(rword);
			num++;
		}
	}
}

// isValid: 데이터가 유효하지 않은 경우 0(false)을, 그렇지 않은 경우 1(true)을 반환
bool isValid(int x, int y) {
	return x >= 0 && x < SIZE&& y >= 0 && y < SIZE;
}

void mainGame::randArr(vector<string>& randV) { // 랜덤한 알파벳 생성(정답 이외의 칸에 랜덤 배치)하여 배열 재 생성
	srand((unsigned)time(NULL)); // 랜덤 시드 설정

	// 방향 상수 정의 (상, 하, 좌, 우, 대각선)
	int px[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
	int py[] = { 0, 1, 1, 1, 0, -1, -1, -1 };


	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			arr[j][i] = ' '; // [세로][가로]
	}

	// 정답 배치
	// 단어 배치 시작점 랜덤

	for (int i = 0; i < randV.size(); i++) {
		int r = rand() % SIZE;
		int c = rand() % SIZE;
		int nx = r, ny = c; // 현재 위치 => 초기 값 : 시작점

		if (randV[i].size() < 2) {
			continue; // 2글자 미만인 단어는 건너뜀
		}

		arr[ny][nx] = randV[i][0];


		int dir = rand() % 8; // 0 ~ 7 방향
		nx += px[dir];
		ny += py[dir];

		for (int j = 1; j < randV[i].size(); j++) {
			if (!isValid(nx, ny)) // 유효하지 않은 위치라면 종료
				break;

			arr[ny][nx] = randV[i][j];
			nx += px[dir];
			ny += py[dir];

		}
	}

	Start s;

	for (int i = 0; i < SIZE; ++i) {
		s.gotoxy(19, i + 10);
		for (int j = 0; j < SIZE; ++j) {
			if (arr[i][j] == ' ') {
				int c = rand() % 26 + 'a';
				cout << (char)c << " ";
			}
			else {
				cout << arr[i][j] << " ";
			}
		}
		cout << endl;
	}
}

void mainGame::scan() {

	// 방향 상수 정의 (상, 하, 좌, 우, 대각선)
	int px[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
	int py[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

	for (int y = 0; y < SIZE; y++) {
		for (int x = 0; x < SIZE; x++) { // 16개의 문자마다
			for (int dir = 0; dir < 8; dir++) { // 8가지 방향
				int nx = x, ny = y; // 현재 위치 => 초기 값 : 시작점

				while (isValid(nx, ny)) {
					word += arr[ny][nx];
					nx = nx + px[dir];
					ny = ny + py[dir];

					if (!isValid(nx, ny)) // 유효하지 않은 위치라면 종료
						break;

					if (word.length() >= 2) {
						foundWords.insert(word);
					}
				}
				word.clear(); // 각 반복문이 끝날 때마다 word를 초기화
			}
		}
	}
}

// 사전 v에 해당 단어가 있는지 검사
bool mainGame::isExi(string word) {
	return find(v.begin(), v.end(), word) != v.end();
}

void mainGame::colorWord(int x, int y, char c, bool isCorrect) {
	Start s;
	if (isCorrect) {
		s.gotoxy(x, y);
		s.txtColor(RED, WHITE);
	}
	else {
		s.gotoxy(x, y);
		s.txtColor(BLUE, WHITE);
	}
	cout << c << " ";
}

bool mainGame::findWord(string input) {
	int px[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
	int py[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
	Start s;
	bool found = false;
	int origX = -1, origY = -1; // 처음 매칭한 위치 저장
	for (int c = 0; c < 4; c++) {
		for (int r = 0; r < 4; r++) {
			if (arr[c][r] == input[0]) { // 입력 단어의 첫 글자와 일치하는 위치 찾기
				for (int dir = 0; dir < 8; dir++) { // 8가지 방향
					int nx = r, ny = c; // 시작 위치 초기화
					string cmp;
					origX = nx; // 매칭 시작 위치 저장
					origY = ny;
					for (int i = 0; i < input.size(); i++) {
						if (!isValid(nx, ny) || arr[ny][nx] != input[i]) {
							break; // 현재 방향으로 매칭되지 않으면 종료
						}
						cmp += arr[ny][nx];
						nx += px[dir];
						ny += py[dir];
					}
					if (cmp == input && cmp.size() == input.size()) { // 입력한 단어가 발견된 경우
						found = true;
						// 정답인 경우에만 색상을 변경하도록 처리
						if (isExi(input)) {
							for (int i = 0; i < input.size(); i++) {
								colorWord((origX * 2) + 19 + px[dir] * i * 2, origY + 10 + py[dir] * i, input[i], true); // 정답인 경우 RED 색상으로 표시
							}
						}
						return true;
					}
				}
			}
		}
	}

	// 입력한 단어와 일치하지 않는 경우에만 색상을 BLUE로 되돌림
	if (!found && origX != -1 && origY != -1) {
		for (int i = 0; i < input.size(); i++) {
			colorWord((origX * 2) + 19 + i * 2, origY + 10, arr[origY][origX + i], false); // BLUE로 색상 변경
		}
	}

	return false; // 단어 발견하지 못한 경우
}

void mainGame::run() { // 메인 게임 실행
	// 파일 읽어들이기
	ifstream fin("c:\\temp\\words.txt");
	if (!fin) {
		cout << "파일 열기 실패" << endl;
		exit(0);
	}
	fileRead(v, fin);
	fin.close();


	Start s;
	s.run();

	s.cls(WHITE, BLUE);
	randWord(randV, v);
	randArr(randV);
	scan();

	for (const string& word : foundWords) {
		if (isExi(word) == true) {
			ansNum++;
		}
	}


	int i = 10; // 단어 출력 라인 
	while (life > 0) {
		print();
		s.gotoxy(51, 7);
		cout << "생명: " << life << endl;
		s.gotoxy(5, 23);
		cout << ">> " << s.getName() << "의 점수: " << score << endl;
		s.gotoxy(5, 18);
		cout << ">> 남은 정답 개수 : " << ansNum << endl;
		if (ansNum == 0)
			break; // 정답을 다 맞추면 종료

		// 입력 받기
		s.gotoxy(51, 25);
		cout << ">>";
		s.gotoxy(53, 25);
		cin >> input;
		this_thread::sleep_for(chrono::seconds(1));  // 2초 동안 대기
		s.gotoxy(51, 25);
		cout << "             "; // 지우기


		// 정답 여부 확인 후 출력
		if (findWord(input) == true && isExi(input) == true) {
			score += 10;
			s.gotoxy(5, 21);
			cout << "정답입니다!!" << endl;
			s.gotoxy(53, i);
			cout << input;
			this_thread::sleep_for(chrono::seconds(2));  // 2초 동안 대기
			s.gotoxy(5, 21);
			cout << "             "; // 지우기
			i++;
			ansNum--; // 정답 맞출 때마다 남은 정답 개수 줄어들음
		} // 중복 단어 검사 기능 추가
		else {
			s.gotoxy(5, 21);
			s.txtColor(RED, WHITE);
			cout << "오답입니다." << endl;
			life--;
			this_thread::sleep_for(chrono::seconds(2));  // 2초 동안 대기
			s.gotoxy(5, 21);
			cout << "             "; // 지우기
		}

		// 입력 버퍼 비우기
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// 입력 화면 지우기
		cout << "\r"; // 지우기
	}

}
