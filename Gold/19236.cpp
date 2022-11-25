#include <iostream>
using namespace std;

#define UP 1
#define LEFTUP 2
#define LEFT 3
#define LEFTDOWN 4
#define DOWN 5
#define RIGHTDOWN 6
#define RIGHT 7
#define RIGHTUP 8
#define NULLPOS pair<int, int>{-1, -1}

struct space { // 공간의 상태 구조체 
	int fishNum[4][4]; // 각 위치별 물고기 번호를 저장. 상어: 0번
	pair<int, int> fishPos[17]; // 물고기 위치를 저장. 죽었으면 NULLPOS
	int fishDir[17]; // 물고기 방향을 저장.
};

space curSpace[16];
int maxNum;

void print(int sum) { // valid
	cout << "---------------\n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << curSpace[0].fishNum[i][j] << " ";
		}
		cout << "\n";
	}
	cout << sum << "\n";
	cout << "---------------\n";
}

void move(pair<int, int>& curPos, int curDir) {
	if (curDir == UP) {
		curPos.first--;
	}
	if (curDir == LEFTUP) {
		curPos.first--;
		curPos.second--;
	}
	if (curDir == LEFT) {
		curPos.second--;
	}
	if (curDir == LEFTDOWN) {
		curPos.first++;
		curPos.second--;
	}
	if (curDir == DOWN) {
		curPos.first++;
	}
	if (curDir == RIGHTDOWN) {
		curPos.first++;
		curPos.second++;
	}
	if (curDir == RIGHT) {
		curPos.second++;
	}
	if (curDir == RIGHTUP) {
		curPos.first--;
		curPos.second++;
	}
}

bool canMove(int cur, pair<int, int> curPos, int curDir) {
	move(curPos, curDir);
	if (curPos.first >= 0 && curPos.first <= 3 && curPos.second >= 0 && curPos.second <= 3 && curSpace[cur].fishPos[0] != curPos)
		return true;
	else
		return false;
}

void backtracking(int cur, int sum) {
	//base
	print(sum);

	// move fish
	for (int i = 1; i <= 16; i++) {
		if (curSpace[cur].fishPos[i] != NULLPOS) {
			pair<int, int> curPos = curSpace[cur].fishPos[i];
			int curDir = curSpace[cur].fishDir[i];
			int checkDir = curDir;
			bool flag = true;
			while (!canMove(cur, curPos, checkDir)) {
				checkDir = checkDir + 1; // 반시계 회전
				if (checkDir == 9) checkDir = 1;
				if (checkDir == curDir) { // 한바퀴 다 돌았으면
					flag = false; // 움직일 수 없음
					break;
				}
			}
			if (flag) {
				pair<int, int> movePos = curPos;
				move(movePos, checkDir);
				int swapFish = curSpace[cur].fishNum[movePos.first][movePos.second];
				int swapFishDir = curSpace[cur].fishDir[swapFish];
				curSpace[cur].fishNum[movePos.first][movePos.second] = i;
				curSpace[cur].fishNum[curPos.first][curPos.second] = swapFish;
				curSpace[cur].fishPos[i] = movePos;
				curSpace[cur].fishPos[swapFish] = curPos;
			}
		}
	}

	// move shark
	while (canMove(cur, curSpace[cur].fishPos[0], curSpace[cur].fishDir[0])) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				curSpace[cur + 1].fishNum[i][j] = curSpace[cur].fishNum[i][j];
				////// 작성중
			}
		}


		int fishNum[4][4]; // 각 위치별 물고기 번호를 저장. 상어: 0번
		pair<int, int> fishPos[17]; // 물고기 위치를 저장. 죽었으면 NULLPOS
		int fishDir[17]; // 물고기 방향을 저장.
	}

	print(sum);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int fishNum;
			cin >> fishNum;
			int fishDir;
			cin >> fishDir;
			curSpace[0].fishNum[i][j] = fishNum;
			curSpace[0].fishPos[fishNum] = { i, j };
			curSpace[0].fishDir[fishNum] = fishDir;
		}
	}
	int curFishNum = curSpace[0].fishNum[0][0];
	maxNum = curFishNum;
	curSpace[0].fishPos[curFishNum] = NULLPOS;
	curSpace[0].fishPos[0] = { 0, 0 };
	curSpace[0].fishDir[0] = curSpace[0].fishDir[curFishNum];
	curSpace[0].fishNum[0][0] = 0;
	backtracking(0, curFishNum);
}